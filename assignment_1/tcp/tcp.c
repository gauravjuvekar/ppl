#include <inttypes.h>
#include <stddef.h>
#include <arpa/inet.h>
#include <assert.h>

#include "tcp.h"


size_t serialize(uint8_t *dst, size_t n, const Header *header) {
	size_t dst_index = 0;

	assert(dst_index + 2 < n);
	*((uint16_t *)&dst[dst_index]) = htons(header->src_port);
	dst_index += 2;

	assert(dst_index + 2 < n);
	*((uint16_t *)&dst[dst_index]) = htons(header->dst_port);
	dst_index += 2;

	assert(dst_index + 4 < n);
	*((uint16_t *)&dst[dst_index]) = htonl(header->seq_num);
	dst_index += 4;

	assert(dst_index + 4 < n);
	*((uint16_t *)&dst[dst_index]) = htonl(header->ack_num);
	dst_index += 4;

	return dst_index;
}


size_t deserialize(Header *header, const uint8_t *src, size_t n) {
	size_t src_index = 0;

	assert(src_index + 2 < n);
	header->src_port = htons(*(uint16_t *)&src[src_index]);
	src_index += 2;

	assert(src_index + 2 < n);
	header->dst_port = htons(*(uint16_t *)&src[src_index]);
	src_index += 2;

	assert(src_index + 4 < n);
	header->seq_num = htonl(*(uint32_t *)&src[src_index]);
	src_index += 4;

	assert(src_index + 4 < n);
	header->ack_num = htonl(*(uint32_t *)&src[src_index]);
	src_index += 4;

	return src_index;
}
