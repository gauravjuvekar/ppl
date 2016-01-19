#include <stdio.h>

#include "tcp.h"

void print_header(Header *header) {
	printf("Source port:            %u\n"
	       "Destination port:       %u\n"
	       "Sequence number:        %u\n"
	       "Acknowledgement number: %u\n"
	       "Data offset:            %u\n"
	       "URG flag:               %u\n"
	       "ACK flag:               %u\n"
	       "PSH flag:               %u\n"
	       "RST flag:               %u\n"
	       "SYN flag:               %u\n"
	       "FIN flag:               %u\n"
	       "Window:                 %u\n"
	       "Urgent pointer:         %u\n"
	       "Options count:          %zu\n",
	       header->src_port, header->dst_port,
	       header->seq_num,
	       header->ack_num,
	       header->data_off,
	       header->urg_flag,
	       header->ack_flag,
	       header->psh_flag,
	       header->rst_flag,
	       header->syn_flag,
	       header->fin_flag,
	       header->window,
	       header->urg_ptr,
	       header->options_n);
}


int main(int argc, char *argv[]) {
	Header header;
	header.src_port = 22;
	header.dst_port = 2022;
	header.seq_num  = 3;
	header.ack_num  = 2;
	header.urg_flag = 0;
	header.ack_flag = 1;
	header.psh_flag = 0;
	header.rst_flag = 0;
	header.syn_flag = 0;
	header.fin_flag = 0;
	header.window = 5;
	header.urg_ptr = 0;
	header.options = NULL;
	header.options_n = 0;

	print_header(&header);

	uint8_t bytearray[64];
	size_t head_len = serialize(bytearray, 64, &header);
	size_t i;
	for (i = 0; i < head_len; i++) {
		printf("%02x ", bytearray[i]);
	}
	printf("\n");

	Header conv_back;
	deserialize(&conv_back, bytearray, head_len);
	print_header(&conv_back);
}

