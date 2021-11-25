/*
* 程序名：位图缩放
* 功能：缩放24位位图
* 成员：李潇，吴兴祺
*/
#include <stdio.h>
#include <stdlib.h>
#include "BmpFormat.h"

BITMAPFILEHEADER src_fh;
BITMAPINFOHEADER src_ih;

BITMAPFILEHEADER dst_fh;
BITMAPINFOHEADER dst_ih;

FILE* src;
FILE* dst;

int main(int argc, char** argv)
{
    //打开文件
    if (argc < 3)
    {
        printf("参数错误！\n");
        return -1;
    }
    src = fopen(argv[1], "rb");
    if (src == NULL)
    {
        printf("打开\"%s\"失败！\n", argv[1]);
        return -1;
    }

    //获取源bmp文件信息
    fread(&src_fh, sizeof(BITMAPFILEHEADER), 1, src);
    fread(&src_ih, sizeof(BITMAPINFOHEADER), 1, src);

    if (src_fh.bfType == 0x4d42) //检验打开的文件是不是bmp文件
    {
        double zoom = atoi(argv[2]) / 100.0; //将缩放参数字符串转换为double格式

        //创建目标bmp文件信息
        dst_fh = src_fh;
        dst_ih = src_ih;

        //修改目标bmp文件图像大小等信息并储存 
        dst_ih.biWidth *= zoom;
        dst_ih.biHeight *= zoom;

        long srcRowSize = ((24 * src_ih.biWidth + 31) / 32) * 4; //每行的字节数；因为有自动补零，行字节数不一定等于像素实际大小，所以需要单独计算
        long dstRowSize = ((24 * dst_ih.biWidth + 31) / 32) * 4;
        long srcSkipSize = srcRowSize % 3; //每行需要跳过的补零字节数
        long dstSkipSize = dstRowSize % 3;
        long srcRowPixSize = srcRowSize - srcSkipSize; //每行图像数据真正占用的字节数（去除补零）
        long dstRowPixSize = dstRowSize - dstSkipSize;

        dst_ih.biSizeImage = dstRowSize * dst_ih.biHeight;
        dst_fh.bfSize = dst_ih.biSizeImage + dst_fh.bfOffBits;

        //将源dmp文件图像数据储存到src_pix数组
        long srcPixSize = src_ih.biHeight * srcRowPixSize; //图像数据占用的总字节数（去除补零）
        long dstPixSize = dst_ih.biHeight * dstRowPixSize;

        PixelInfo* src_pix = (PixelInfo*)malloc(srcPixSize);
        PixelInfo* dst_pix = (PixelInfo*)malloc(dstPixSize);
        if (src_pix == NULL || dst_pix == NULL)
        {
            printf("内存申请失败（考虑降低放大倍数）\n");
            return -1;
        }
        long i = 0;
        for (long row = 0; row < src_ih.biHeight; row++)
        {
            fread(&src_pix[i], sizeof(PixelInfo), src_ih.biWidth, src); //每次将一行的数据读入src_pix
            fseek(src, srcSkipSize, SEEK_CUR); //跳过补零数据
            i += src_ih.biWidth;
        }

        //将缩放后对应的图像数据储存到dst_pix数组
        for (long row = 0; row < dst_ih.biHeight; row++)
        {
            for (long col = 0; col < dst_ih.biWidth; col++)
            {
                dst_pix[row * dst_ih.biWidth + col] = src_pix[(long)(row / zoom) * src_ih.biWidth + (long)(col / zoom)];
            }
        }

        //将数据存入目标文件
        dst = fopen(argv[3], "wb");
        fwrite(&dst_fh, sizeof(BITMAPFILEHEADER), 1, dst);
        fwrite(&dst_ih, sizeof(BITMAPINFOHEADER), 1, dst);
        char* buffer = (char*)calloc(1, dstSkipSize);
        i = 0;
        for (int row = 0; row < dst_ih.biHeight; row++)
        {
            fwrite(&dst_pix[i], dstRowPixSize, 1, dst);
            fwrite(buffer, 1, dstSkipSize, dst);
            i += dst_ih.biWidth;
        }

        //结束程序前的清理
        free(src_pix);
        free(dst_pix);
        fclose(src);
        fclose(dst);
        printf("缩放成功\n");
    }
    else
    {
        printf("\"%s\"不是有效的bmp文件\n", argv[1]);
        return -1;
    }
    return 0;
}
