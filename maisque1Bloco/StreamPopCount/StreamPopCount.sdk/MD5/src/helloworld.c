#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "mb_interface.h"
#include "xuartlite_l.h"

#define N 16

int main(){
	//unsigned int i, v, r;
	int r;

    init_platform();

    xil_printf("\n\r%sHello Stream Coprocessor\n\r");
/*
    char array[5];
	unsigned int ch;

	char message[] = "Ol� eu sou o Pedro";
	double initial_len_double = (double) sizeof(message);
	int initial_len = sizeof(message);

	int numberOfBlocks = (int)ceil(initial_len/448.0);


	char *block;*/
	/* Define the amount of memory required, 64 * 8=512 -> it will reserve 512 bits *//*
	size_t length = 64;

/*
	block = (char *)calloc(length, sizeof(char));

	/* Check to see if we were successful */
	/*
	if (block == NULL)
	{
	    /* We were not so display a message */
	/*    printf("Could not allocate required memory\n");

	    /* And exit */
	/*    exit(1);
	}
  char *subBlock;
  /* Define the amount of memory required, 64 * 8=512 -> it will reserve 512 bits */

  /*subBlock = (char *)calloc(4, sizeof(char));

	int i;
	int c;
	for( i = 0; i < numberOfBlocks; i = i + 1 ){
	    memset(block, 0, 512);
	    if(i==numberOfBlocks-1){
	        strcpy(block, message);
	        block[initial_len] = 128; // write the "1" bit

	        uint32_t bits_len = 8*initial_len; // note, we append the len
	        memcpy(&bits_len,block + (448-initial_len), 8);           // in bits at the end of the buffer

          for(c=0;c<16;c=c+1){
            memcpy(subBlock,block+(c*32),32);
            //putfsl(subBlock, 0);
          }

	    }else{
	    	memcpy(block,message+(i*512),i*512);

        for(c=0;c<16;c=c+1){
          memcpy(subBlock,block+(c*32),32);
          //putfsl(subBlock, 0);
        }
	    }

	 }
*/	  char *subBlockTemp;
	  /* Define the amount of memory required, 64 * 8=512 -> it will reserve 512 bits */

	  subBlockTemp = (char *)calloc(4, sizeof(char));

	  char *blockTemp;
	  /* Define the amount of memory required, 64 * 8=512 -> it will reserve 512 bits */
	  size_t lengthTemp = 64;
	  xil_printf("\nsubBlock______asd______________>__>_%s", subBlockTemp);


	  blockTemp = (char *)calloc(lengthTemp, sizeof(char));
	  int i;
	  for(i=0;i<lengthTemp;i++){
		  blockTemp[i]='a';
	  }
	  xil_printf("\nbasePtr_%s", blockTemp);
	  xil_printf("\nsubBlock____________________>__>_%s", subBlockTemp);
	  int c;

	  /*  for(c=0;c<16;c=c+1){
	     memcpy(subBlockTemp,blockTemp+(c*4),4);
	     xil_printf("\nsubBlock size -> %d", (int) (sizeof(subBlockTemp)));
	     putfsl(*subBlockTemp, 0);
	     xil_printf("\nsubBlock_%s", *subBlockTemp);
	  }*/

	  for(c=0;c<lengthTemp;c=c+4){
		  xil_printf("\nDecode-> %x", *((unsigned int*)(blockTemp+c)));
		  putfsl(*((unsigned int*)(blockTemp+c)), 0);
	  }

	  int u;
	  for(u = 0;u < lengthTemp; u++){
		  blockTemp[u]='b';
	  }

	  for(c=0;c<lengthTemp;c=c+4){
		  xil_printf("\nDecode-> %x", *((unsigned int*)(blockTemp+c)));
		  putfsl(*((unsigned int*)(blockTemp+c)), 0);
	  }

	  int j;
	  for(j=0; j < 4; j++){
		  getfsl(r, 0);
		  xil_printf("\n%08x", r);
	  }

	  xil_printf("\n\rDone!");

	  cleanup_platform();
	  return 0;
}
