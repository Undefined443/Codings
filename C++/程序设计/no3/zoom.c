/*
* ��������λͼ����
* ���ܣ�����24λλͼ
* ��Ա�����죬������
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
    //���ļ�
    if (argc < 3)
    {
        printf("��������\n");
        return -1;
    }
    src = fopen(argv[1], "rb");
    if (src == NULL)
    {
        printf("��\"%s\"ʧ�ܣ�\n", argv[1]);
        return -1;
    }

    //��ȡԴbmp�ļ���Ϣ
    fread(&src_fh, sizeof(BITMAPFILEHEADER), 1, src);
    fread(&src_ih, sizeof(BITMAPINFOHEADER), 1, src);

    if (src_fh.bfType == 0x4d42) //����򿪵��ļ��ǲ���bmp�ļ�
    {
        double zoom = atoi(argv[2]) / 100.0; //�����Ų����ַ���ת��Ϊdouble��ʽ

        //����Ŀ��bmp�ļ���Ϣ
        dst_fh = src_fh;
        dst_ih = src_ih;

        //�޸�Ŀ��bmp�ļ�ͼ���С����Ϣ������ 
        dst_ih.biWidth *= zoom;
        dst_ih.biHeight *= zoom;

        long srcRowSize = ((24 * src_ih.biWidth + 31) / 32) * 4; //ÿ�е��ֽ�������Ϊ���Զ����㣬���ֽ�����һ����������ʵ�ʴ�С��������Ҫ��������
        long dstRowSize = ((24 * dst_ih.biWidth + 31) / 32) * 4;
        long srcSkipSize = srcRowSize % 3; //ÿ����Ҫ�����Ĳ����ֽ���
        long dstSkipSize = dstRowSize % 3;
        long srcRowPixSize = srcRowSize - srcSkipSize; //ÿ��ͼ����������ռ�õ��ֽ�����ȥ�����㣩
        long dstRowPixSize = dstRowSize - dstSkipSize;

        dst_ih.biSizeImage = dstRowSize * dst_ih.biHeight;
        dst_fh.bfSize = dst_ih.biSizeImage + dst_fh.bfOffBits;

        //��Դdmp�ļ�ͼ�����ݴ��浽src_pix����
        long srcPixSize = src_ih.biHeight * srcRowPixSize; //ͼ������ռ�õ����ֽ�����ȥ�����㣩
        long dstPixSize = dst_ih.biHeight * dstRowPixSize;

        PixelInfo* src_pix = (PixelInfo*)malloc(srcPixSize);
        PixelInfo* dst_pix = (PixelInfo*)malloc(dstPixSize);
        if (src_pix == NULL || dst_pix == NULL)
        {
            printf("�ڴ�����ʧ�ܣ����ǽ��ͷŴ�����\n");
            return -1;
        }
        long i = 0;
        for (long row = 0; row < src_ih.biHeight; row++)
        {
            fread(&src_pix[i], sizeof(PixelInfo), src_ih.biWidth, src); //ÿ�ν�һ�е����ݶ���src_pix
            fseek(src, srcSkipSize, SEEK_CUR); //������������
            i += src_ih.biWidth;
        }

        //�����ź��Ӧ��ͼ�����ݴ��浽dst_pix����
        for (long row = 0; row < dst_ih.biHeight; row++)
        {
            for (long col = 0; col < dst_ih.biWidth; col++)
            {
                dst_pix[row * dst_ih.biWidth + col] = src_pix[(long)(row / zoom) * src_ih.biWidth + (long)(col / zoom)];
            }
        }

        //�����ݴ���Ŀ���ļ�
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

        //��������ǰ������
        free(src_pix);
        free(dst_pix);
        fclose(src);
        fclose(dst);
        printf("���ųɹ�\n");
    }
    else
    {
        printf("\"%s\"������Ч��bmp�ļ�\n", argv[1]);
        return -1;
    }
    return 0;
}
