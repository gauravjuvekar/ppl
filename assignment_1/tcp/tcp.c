#include <inttypes.h>
#include <stddef.h>
#include <arpa/inet.h>
#include <string.h>
#include <assert.h>

#include "tcp.h"


size_t serialize(uint8_t *dst, size_t n, const Header *header) {
	size_t dst_index = 0;
	uint16_t buf_16;
	uint32_t buf_32;

	/* Source port */
	assert(dst_index + sizeof(buf_16) < n);
	buf_16 = htons(header->src_port);
	memcpy(&dst[dst_index], &buf_16, sizeof(buf_16));
	dst_index += sizeof(buf_16);

	/* Destination port */
	assert(dst_index + sizeof(buf_16) < n);
	buf_16 = htons(header->dst_port);
	memcpy(&dst[dst_index], &buf_16, sizeof(buf_16));
	dst_index += sizeof(buf_16);

	/* Sequence number */
	assert(dst_index + sizeof(buf_32) < n);
	buf_32 = htons(header->seq_num);
	memcpy(&dst[dst_index], &buf_32, sizeof(buf_32));
	dst_index += sizeof(buf_32);

	/* Acknowledgement number */
	assert(dst_index + sizeof(buf_32) < n);
	buf_32 = htons(header->ack_num);
	memcpy(&dst[dst_index], &buf_32, sizeof(buf_32));
	dst_index += sizeof(buf_32);

	assert(dst_index + sizeof(buf_16) < n);
	buf_16 = 0;
	/* Data offset */
	buf_16 |= ((header->options_n / 4) + (header->options_n % 4 ? 1 : 0)) << 12;
	/* Flags */
	if (header->urg_flag) buf_16 |= (1 << 5);
	if (header->ack_flag) buf_16 |= (1 << 4);
	if (header->psh_flag) buf_16 |= (1 << 3);
	if (header->rst_flag) buf_16 |= (1 << 2);
	if (header->syn_flag) buf_16 |= (1 << 1);
	if (header->fin_flag) buf_16 |= (1 << 0);
	memcpy(&dst[dst_index], &buf_32, sizeof(buf_32));
	dst_index += sizeof(buf_16);

	/* Window */
	assert(dst_index + sizeof(buf_16) < n);
	buf_16 = htons(header->window);
	memcpy(&dst[dst_index], &buf_16, sizeof(buf_16));
	dst_index += sizeof(buf_16);

	/* Checksum (initially zeroed) */
	assert(dst_index + sizeof(buf_16) < n);
	buf_16 = 0;
	memcpy(&dst[dst_index], &buf_16, sizeof(buf_16));
	dst_index += sizeof(buf_16);

	/* Urgent pointer TODO: unimplemented */
	assert(dst_index + sizeof(buf_16) < n);
	buf_16 = 0;
	memcpy(&dst[dst_index], &buf_16, sizeof(buf_16));
	dst_index += sizeof(buf_16);

	/* Options */
	memcpy(&dst[dst_index], header->options, header->options_n);
	dst_index += header->options_n;
	/* Padding */
	uint8_t pad_len = (header->options_n % sizeof(uint32_t));
	memset(&dst[dst_index], 0, pad_len);
	dst_index += pad_len;

	return dst_index;
}


size_t deserialize(Header *header, const uint8_t *src, size_t n) {
	size_t src_index = 0;

	assert(src_index + sizeof(header->src_port) < n);
	memcpy(&(header->src_port), &src[src_index], sizeof(header->src_port));
	header->src_port = ntohs(header->src_port);
	src_index += sizeof(header->src_port);

	assert(src_index + sizeof(header->dst_port) < n);
	memcpy(&(header->dst_port), &src[src_index], sizeof(header->dst_port));
	header->dst_port = ntohs(header->dst_port);
	src_index += sizeof(header->dst_port);

	assert(src_index + sizeof(header->seq_num) < n);
	memcpy(&(header->seq_num), &src[src_index], sizeof(header->seq_num));
	header->seq_num = ntohl(header->seq_num);
	src_index += sizeof(header->seq_num);

	assert(src_index + sizeof(header->ack_num) < n);
	memcpy(&(header->ack_num), &src[src_index], sizeof(header->ack_num));
	header->ack_num = ntohl(header->ack_num);
	src_index += sizeof(header->ack_num);

	assert(src_index + 1 < n);
	header->data_off = src[src_index] >> 4;
	src_index += 1;

	assert(src_index + 1 < n);
	header->urg_flag = (src[src_index] >> 5) & 1;
	header->ack_flag = (src[src_index] >> 4) & 1;
	header->psh_flag = (src[src_index] >> 3) & 1;
	header->rst_flag = (src[src_index] >> 2) & 1;
	header->fin_flag = (src[src_index] >> 1) & 1;
	src_index += 1;

	assert(src_index + sizeof(header->window) < n);
	memcpy(&(header->window), &src[src_index], sizeof(header->window));
	header->window = ntohs(header->window);
	src_index += sizeof(header->window);

	assert(src_index + sizeof(header->checksum) < n);
	memcpy(&(header->checksum), &src[src_index], sizeof(header->checksum));
	header->checksum = ntohs(header->checksum);
	src_index += sizeof(header->checksum);

	assert(src_index + sizeof(header->urg_ptr) < n);
	memcpy(&(header->urg_ptr), &src[src_index], sizeof(header->urg_ptr));
	header->urg_ptr = ntohs(header->urg_ptr);
	src_index += sizeof(header->urg_ptr);

	return src_index;
}
