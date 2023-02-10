#include "s21_decimal.h"

void printBits(s21_decimal num) {
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for(int i = 31; i >= 0; i--) { printf("%-5d", i); }
	printf("\n");
	for(int i = 31; i >= 0; i--) { printf("%-5d", getBit(num, i)); }
	printf("\n\n");
	for(int i = 63; i >= 32; i--) { printf("%-5d", i); }
	printf("\n");
	for(int i = 63; i >= 32; i--) { printf("%-5d", getBit(num, i)); } 
	printf("\n\n");
	for(int i = 95; i >= 64; i--) { printf("%-5d", i); }
	printf("\n");
	for(int i = 95; i >= 64; i--) { printf("%-5d", getBit(num, i)); }
	printf("\n\n");
	for(int i = 127; i >= 96; i--) { printf("%-5d", i); }
	printf("\n");
	for(int i = 127; i >= 96; i--) { printf("%-5d", getBit(num, i)); }
	printf("\n-----------------------------------------------------------------\n");
	printf("sign\n127\n%-5d", getBit(num, 127)); 
	printf("\n-----------------------------------------------------------------\n");
	printf("scale\n");
	for(int i = 119; i >= 112; i--) { 
		printf("%-5d", i); 
	}
	printf("\n");
	for(int i = 119; i >= 112; i--) { 
		printf("%-5d", getBit(num, i)); 
	}
	printf("\n");
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}