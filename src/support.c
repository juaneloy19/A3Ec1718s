#include <stdio.h>
#include <stdlib.h>

#define f_width 352
#define f_height 288
#define b_size 8

FILE* input_i = NULL;
FILE* output_o = NULL;

int b_width  = f_width/b_size;
int b_height = f_height/b_size;
unsigned int picbuff[f_width][f_height];

unsigned int get_approx_2n(unsigned int num){
    unsigned int approx_2n = 1;
    if(num<2) approx_2n = 1;
    else if(num<4) approx_2n = 2;
    else if(num<8) approx_2n = 4;
    else if(num<16) approx_2n = 8;
    else if(num<32) approx_2n = 16;
    else if(num<64) approx_2n = 32;
    else if(num<128) approx_2n = 64;
    else if(num<512) approx_2n = 128;
    else approx_2n = 0;

    return approx_2n;
}

void write_init()
{
	output_o = fopen("foreman_sad.txt", "w");

	if(output_o == NULL)
	{
		printf("Unable to open file %s\nExit\n", "foreman_sad.txt");
		fclose(output_o);
		exit(0);
	}
	else {
		printf("Opened file %s\n", "foreman_sad.txt");
	}
}

void write_o(int num,int frame)
{
    printf("Trying to write\n");
	if(output_o != NULL)
	{
        fprintf(output_o,"SAD: %d Frame: %d\n",num,frame);
	    printf("Wrote %d Frame %d\n", num,frame);
	}
}

void write_close()
{
	if(output_o != NULL)
	{
		fputc('\n', output_o);
		fclose(output_o);
		output_o = NULL;
	}
}

void updateFrame(int in_pix, int x_pix, int y_pix)
{
    picbuff[x_pix][y_pix] = in_pix;
    printf("X:%d, Y:%d = %d\n", x_pix, y_pix, in_pix);
}

int getBlockPixel(int w_block_num, int h_block_num, int x, int y)
{
    int pixel = picbuff[(w_block_num*b_size)+x][(h_block_num*b_size)+y];
    printf("Block X:%d, Block:%d, X:%d, Y:%d = %d \n",w_block_num, h_block_num, x, y, pixel);
    return pixel;
}
