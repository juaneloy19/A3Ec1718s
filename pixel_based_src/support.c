#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define f_width 352
#define f_height 288
#define fp_height f_height*2
#define b_size 8

int b_width  = f_width/b_size;
int b_height = f_height/b_size;
int fv_height = f_height*1.5;
unsigned int picbuff[f_width][fp_height];
uint8_t outbuff[f_width][fp_height];

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

void updateFrame(int in_pix, int x_pix, int y_pix)
{
    picbuff[x_pix][y_pix] = in_pix;
    printf("F2B X:%d, Y:%d = %x\n", x_pix, y_pix, in_pix);
}

int getBlockPixel(int w_block_num, int h_block_num, int x, int y)
{
    int pixel = picbuff[(w_block_num*b_size)+x][(h_block_num*b_size)+y];
    printf("F2B Block X:%d, Block:%d, X:%d, Y:%d = %x \n",w_block_num, h_block_num, x, y, pixel);
    return pixel;
}

int getYBlockPixel(int w_block_num, int h_block_num, int x, int y)
{
    int pixel = picbuff[(w_block_num*b_size)+x][(h_block_num*(b_size/2))+y];
    printf("F2B Y Block X:%d, Block:%d, X:%d, Y:%d = %x \n",w_block_num, h_block_num, x, y, pixel);
    return pixel;
}

int getUBlockPixel(int w_block_num, int h_block_num, int x, int y)
{
    int pixel = picbuff[(w_block_num*b_size)+x][f_height+(h_block_num*(b_size/4))+y];
    printf("F2B U Block X:%d, Block:%d, X:%d, Y:%d = %x \n",w_block_num, h_block_num, x, y, pixel);
    return pixel;
}

int getVBlockPixel(int w_block_num, int h_block_num, int x, int y)
{
    int pixel = picbuff[(w_block_num*b_size)+x][fv_height+(h_block_num*(b_size/4))+y];
    printf("F2B V Block X:%d, Block:%d, X:%d, Y:%d = %x \n",w_block_num, h_block_num, x, y, pixel);
    return pixel;
}

void updateBlock(int in_pix, int w_block_num, int h_block_num, int x, int y)
{
    outbuff[(w_block_num*b_size)+x][(h_block_num*b_size)+y] = in_pix;
    printf("B2F Block X:%d, Block:%d, X:%d, Y:%d = %x \n",w_block_num, h_block_num, x, y, in_pix);
}

void updateYBlock(int in_pix, int w_block_num, int h_block_num, int x, int y)
{
    outbuff[(w_block_num*b_size)+x][(h_block_num*(b_size/2))+y] = in_pix;
    printf("B2F Y Block X:%d, Block:%d, X:%d, Y:%d = %x \n",w_block_num, h_block_num, x, y, in_pix);
}

void updateUBlock(int in_pix, int w_block_num, int h_block_num, int x, int y)
{
    outbuff[(w_block_num*b_size)+x][f_height+(h_block_num*(b_size/4))+y] = in_pix;
    printf("B2F U Block X:%d, Block:%d, X:%d, Y:%d = %x \n",w_block_num, h_block_num, x, y, in_pix);
}

void updateVBlock(int in_pix, int w_block_num, int h_block_num, int x, int y)
{
    outbuff[(w_block_num*b_size)+x][fv_height+(h_block_num*(b_size/4))+y] = in_pix;
    printf("B2F V Block X:%d, Block:%d, X:%d, Y:%d = %x \n",w_block_num, h_block_num, x, y, in_pix);
}

int getFramePixel(int x, int y)
{
    int pixel = outbuff[x][y];
    printf("B2F X:%d, Y:%d = %x\n", x, y, pixel);
    return pixel;
}
