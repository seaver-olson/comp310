#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

int main(){
	void *addr = mmap(0, 32, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	char out[32];
	memset(addr,0x00,32);
	memcpy(out,addr,32);//had to use memcpy instead of out = memset(); 
	//doc for memcpy: void* memcpy(void* dest, cons void* src, size_t count);
	for (int i=0;i<32;i++){
		printf("addr[%d] : %02x \n",i ,(unsigned char)out[i]);
	}
	return 0;
}
