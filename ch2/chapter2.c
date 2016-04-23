#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned char* byte_pointer;

void show_byte(byte_pointer start, int len) {
	int i;
	for(i = 0;i < len;i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_int(int x) {
	show_byte((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_byte((byte_pointer) &x, sizeof(float));
}

void show_pointer(void* p) {
	show_byte((byte_pointer) &p,sizeof(void*));
}

void test_show_bytes() {
	fprintf(stdout,"mac os x 10.10 output:\n");
	int val = 12345;
	int ival = val;
	float fval = (float) val;
	int* pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

void pp25() {
	fprintf(stdout,"practice problem2.5:\n");
	int val = 0x87654321;
	byte_pointer valp = (byte_pointer) &val;
	show_byte(valp,1);
	show_byte(valp,2);
	show_byte(valp,3);
	fprintf(stdout,"seems it's a little endian machine\n");
}

void pp27() {
	const char* s = "abcdef";
	show_byte((byte_pointer) s,strlen(s));
}
void swapInPlace(int* a, int* b) {
	*b = *a ^ *b;
	*a = *a ^ *b;
	*b = *a ^ *b;
}
void pp210() {
	int x=10,y=5;
	fprintf(stdout,"before swap: %d %d\n",x,y);
	swapInPlace(&x,&y);
	fprintf(stdout,"after swap: %d %d\n",x,y);
}
void revArray(int a[], int len) {
	int first, last;
	for(first = 0,last = len-1;first < last;
		first++, last--) 
		swapInPlace(a+first,a+last);
}
void pp211() {
	int a[] = {1,2,3,4,5};
	revArray(a,5);
	int i;
	for(i=0;i<5;i++)
		fprintf(stdout, " %d",a[i]);
	fprintf(stdout,"\n");
}
void pp212() {
//note that bitwise operation has a low priority...
	int x = 0x87654321;
	int a = x & 0xFF;
	int b = ((~x) & (~0xFF))+ a;
	int c = (x & (~0xFF)) + 0xFF;
	fprintf(stdout, "%x %x %x\n",a,b,c);
}
void page277code() {
	unsigned length;
	int i;
	i = 0;length = 0;
	fprintf(stdout, "i <= length-1 evaluated to: %d\n",i<= length-1);
}

int strlonger(char* s, char* t) {
	return strlen(s) - strlen(t) > 0;
}
int strlonger1(char* s, char* t) {
	return (int)strlen(s) - (int)strlen(t) > 0;
}
void pp226() {
	char s[] = "a string A";
	char t[] = "a longer stringB";
	char x[] = "shorterC";
	int a1,a2;
	a1 = strlonger(s,t);
	a2 = strlonger(s,x);
	fprintf(stdout, "comparison result: %d %d\n",a1,a2);
	a1 = strlonger1(s,t);
	a2 = strlonger1(s,x);
	fprintf(stdout, "edited version: %d %d\n",a1,a2);

}

int uadd_ok(unsigned x, unsigned y) {
	unsigned min = x > y ? y:x;
	unsigned sum = x+y;
	if(sum < min)
		return(0);
	return(1);
}
void pp227() {
	unsigned a = 1,b=2,c = UINT_MAX;
	fprintf(stdout, "uadd_ok: %d %d \n",uadd_ok(a,b),uadd_ok(a,c));
}
int main(int argc, char** argv) {
	test_show_bytes();
	pp25();
	pp27();
	pp210();
	pp211();
	pp212();
	page277code();
	pp226();
	pp227();
	return(0);
}
