#ifndef TCP_H
#define TCP_H 1

#include <inttypes.h>
#include <stddef.h>

typedef struct Header {
	uint16_t src_port;
	uint16_t dst_port;
	uint32_t seq_num;
	uint32_t ack_num;
	uint8_t data_off:4;
	uint8_t urg_flag:1;
	uint8_t ack_flag:1;
	uint8_t psh_flag:1;
	uint8_t rst_flag:1;
	uint8_t syn_flag:1;
	uint8_t fin_flag:1;
	uint16_t window;
	uint16_t checksum;
	uint16_t urg_ptr;
	uint8_t *options;
	size_t options_n;
} Header;


size_t serialize(uint8_t *dst, size_t n, const Header *header);
size_t deserialize(Header *header, const uint8_t *src, size_t n);

#endif
