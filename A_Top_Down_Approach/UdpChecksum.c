// #include <stdio.h>

// int main(){
// 	unsigned short IPv4_Pseudo_Header[] = {
// 		// IPv4 Header
// 		0xc0ff, 0xff32, // c0 ff ff 32 => Source IP Address : 192.255.255.50
// 		0xc0ff, 0xff33, // c0 ff ff 33 => Destination IP Address : 192.255.255.51
// 		0x0011,         // Zero(0x00), Protocol(0x11)
// 		0x000c,         // UDP Length

// 		// UDP Header
// 		0xa45c,         // a4 5c => Source Port : 0xa45c = 42076
// 		0x270f,         // 27 0f => Destination Port : 0x270f = 9999
// 		0x000c,         // UDP Length
// 		0x7465, 0x7374  // 74 65 73 74 => "test"
// 	};

// 	printf("IPv4 Header Checksum\n");

// 	// step 1. summation
// 	int sum = 0;
// 	for(unsigned long i = 0; i < sizeof(IPv4_Pseudo_Header) / 2; i++)
// 		sum += IPv4_Pseudo_Header[i];

// 	printf("sum      : %#x\n", sum);

// 	// step 2. bit[:15] + bit[16:19]
// 	int carry_bit = (sum & 0xF0000) >> 16;
// 	int result = (sum & 0xFFFF) + carry_bit;

// 	printf("result   : %#x\n", result);

// 	// step 3. ones' complement
// 	int checksum = ~result;
// 	checksum &= 0xFFFF;
// 	printf("checksum : %#x\n", checksum);

// 	return 0;
// }


#include <stdio.h>
#include <stdint.h>

// 이진수 출력 함수
void print_binary(uint16_t num) {
	for (int i = 15; i >= 0; i--) {
		printf("%d", (num >> i) & 1);
		if (i % 4 == 0) printf(" ");
	}
	printf("\n");
}

int main() {
	uint16_t IPv4_Pseudo_Header[] = {
		// IPv4 Header
		0xc0ff, 0xff32, // c0 ff ff 32 => Source IP Address : 192.255.255.50
		0xc0ff, 0xff33, // c0 ff ff 33 => Destination IP Address : 192.255.255.51
		0x0011,         // Zero(0x00), Protocol(0x11)
		0x000c,         // UDP Length

		// UDP Header
		0xa45c,         // a4 5c => Source Port : 0xa45c = 42076
		0x270f,         // 27 0f => Destination Port : 0x270f = 9999
		0x000c,         // UDP Length
		0x7465, 0x7374  // 74 65 73 74 => "test"
	};

	printf("IPv4 Header Checksum\n");

	// Step 1: Summation
	uint32_t sum = 0;
	for (unsigned long i = 0; i < sizeof(IPv4_Pseudo_Header) / 2; i++)
		sum += IPv4_Pseudo_Header[i];

	printf("Step 1: Sum      : ");
	print_binary(sum);

	// Step 2: Bit[:15] + Bit[16:19]
	uint16_t carry_bit = (sum & 0xF0000) >> 16;
	uint16_t result = (sum & 0xFFFF) + carry_bit;

	printf("Step 2: Result   : ");
	print_binary(result);

	// Step 3: One's Complement
	uint16_t checksum = ~result;
	checksum &= 0xFFFF;
	printf("Step 3: Checksum : ");
	print_binary(checksum);

	remove("a.out");
	remove("tempCodeRunnerFile.c");
	return 0;
}
