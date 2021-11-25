/*
* ��������RLE�㷨�ļ�ѹ��
* ��Ա�����죬������
*/
#define BUFFERSIZE 512*1024 //��󻺴��С���ڽ�ѹģʽ�н������Դ�ļ���С
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

FILE* src;
FILE* dst;

int   fileSize;		 //�ļ���С

int readFromFile(BYTE* srcBuffer, int bufferSize)
{
	static int readed = 0; //�Ѷ�ȡ���ݴ�С
	int remaining = fileSize - readed;
	int toBuffer = remaining > bufferSize ? bufferSize : remaining; //ȷ��һ�ζ��뻺�������������ʣ�����ݴ�С���ڻ�������������뻺��������С�����ݡ��������ȫ��ʣ�����ݡ�
	fread(srcBuffer, 1, toBuffer, src);
	readed += toBuffer;
	return toBuffer;
}

//��[begin, end)�����ݴ浽dst
void storeToBuffer(BYTE* dstBuffer, BYTE index, BYTE* begin, BYTE* end)
{
	*dstBuffer = index;
	dstBuffer++;
	memcpy(dstBuffer, begin, end - begin);
}

//ѹ������
int compress(BYTE* srcBuffer, int bufferSize, BYTE* dstBuffer)
{
	BYTE* end = srcBuffer + bufferSize;
	if (fileSize < 3) //������ݳ���<3�����жϣ�ֱ��ԭ������Ŀ�껺������
	{
		storeToBuffer(dstBuffer, (BYTE)bufferSize, srcBuffer, end);
		return fileSize + 1; //����һ������ָʾ�ֽ�
	}

	int toFile = 0; //����ֵ
	BYTE* bufferPointer = dstBuffer;
	BYTE index; //����ָʾѹ�����ͺͳ��ȵı�������ѹ���������һ��д��Ŀ���ļ����������λ���ڱ�ʾѹ�����ͣ�����λ��ʾ���ȡ�
	BYTE* cur = srcBuffer + 2; //��ԭʼ���ݵĵ������ֽڿ�ʼ�ж��Ƿ���ǰ�����ֽ���ͬ
	BYTE* mark = srcBuffer; //���ڱ��ĳ���жϵ���ʼλ��
	while (cur < end)
	{
		if (*cur == *(cur - 1) && *cur == *(cur - 2)) //�����ǰ������ǰ����������ͬ�������������ֱ����ͬ��Ȼ��ѹ����
		{
			//�Ƚ�ǰ����ͬ�����ݴ��뻺��
			if (cur - 2 - mark > 0)
			{
				index = cur - 2 - mark;
				storeToBuffer(bufferPointer, index, mark, cur - 2);
				toFile += index + 1;
				bufferPointer += index + 1;
			}
			mark = cur - 2;
			while (*cur == *mark && cur - mark < 127 && cur < end && bufferPointer - dstBuffer + cur - mark < BUFFERSIZE) //������ͬ && ���ݳ��� < 127 && curδ����srcBufferĩβ && dstBuffer�����
			{
				cur++;
			}
			index = (cur - mark) | 0b10000000; //�����λ��Ϊ1����ʾ������ֽ��������ֽڡ�
			storeToBuffer(bufferPointer, index, mark, mark + 1);
			toFile += 2; //һ������3�������ϵ��������ݣ����ᱻѹ���������ֽڡ���˴����ļ���������+2��
			bufferPointer += 2;
			mark = cur;
			cur++;
		}
		else if (!(cur - mark < 127 && cur < end && bufferPointer - dstBuffer + cur - mark < BUFFERSIZE)) //������Χ�������ݴ��뻺�壬���¿�ʼ��һ�ּ�����
		{
			index = cur - mark;
			storeToBuffer(bufferPointer, index, mark, cur);
			toFile += index + 1;
			bufferPointer += cur - mark + 1;
			index = 1;
			mark = cur;
			cur++;
		}
		cur++;
	}
	//�������ܳ���cur >= end����ʣ�����ֽ�û�д�����������ʱӦ��ʣ���ֽڴ���dstBuffer��
	if (mark < end)
	{
		index = end - mark;
		storeToBuffer(bufferPointer, index, mark, end);
		toFile += index + 1;
	}
	return toFile;
}

//��ѹ����
int decompress(BYTE* srcBuffer, int bufferSize, BYTE* dstBuffer)
{
	int toFile = 0;
	BYTE* end = dstBuffer + BUFFERSIZE;
	BYTE* bufferPointer = dstBuffer;
	BYTE* cur = srcBuffer;
	BYTE index;
	while (cur < srcBuffer + bufferSize)
	{
		index = *cur;
		BYTE flag = index & 0b10000000;
		cur++;
		//flag����λΪ1˵���������ظ�������
		if (flag == 0b10000000)
		{
			index &= 0b01111111; //��ָʾ����ת�����ظ�����
			//�������¾�memcpy��dstBuffer
			if (bufferPointer + index < end)
			{
				for (int i = 0; i < index; i++)
				{
					memcpy(bufferPointer, cur, 1);
					bufferPointer++;
				}
			}
			//�治�¾��Ƚ�dstBuffer�����ݴ����ļ���Ȼ���ٴ档
			else
			{
				fwrite(dstBuffer, 1, bufferPointer - dstBuffer, dst);
				bufferPointer = dstBuffer;
				for (int i = 0; i < index; i++)
				{
					memcpy(bufferPointer, cur, 1);
					bufferPointer++;
				}
			}
			toFile += index;
		}
		else
		{
			if (bufferPointer + index < end)
			{
				memcpy(bufferPointer, cur, index);
				bufferPointer += index;
			}
			else
			{
				fwrite(dstBuffer, 1, bufferPointer - dstBuffer, dst);
				memcpy(dstBuffer, cur, index);
				bufferPointer = dstBuffer + index;
			}
			cur += index - 1;
			toFile += index;
		}
		cur++;
	}
	return toFile;
}

int main(int argc, char** argv)
{
	//���ļ�
	if (argc == 4)
	{
		src = fopen(argv[1], "rb");
		dst = fopen(argv[3], "wb");
		if (src == NULL)
		{
			printf("File open failur!\n");
			return -1;
		}
	}
	else
	{
		printf("I need some more parameters!\n");
		return -1;
	}

	//��ȡ�ļ���С���Ա�ȷ�������С
	fseek(src, 0L, SEEK_END);
	fileSize = ftell(src);
	rewind(src);

	//����������ڴ�
	BYTE* srcBuffer = malloc(BUFFERSIZE);
	BYTE* dstBuffer = malloc(BUFFERSIZE);

	if (strcmp(argv[2], "-c") == 0) //ѹ��ģʽ
	{
		while (ftell(src) != fileSize)
		{
			int toBuffer = readFromFile(srcBuffer, BUFFERSIZE > fileSize ? fileSize : BUFFERSIZE);
			int toFile = compress(srcBuffer, toBuffer, dstBuffer);
			fwrite(dstBuffer, 1, toFile, dst);
		}
		printf("File \"%s\" has been compressed to \"%s\"!\n", argv[1], argv[3]);
	}
	else if (strcmp(argv[2], "-d") == 0)
	{
		while (ftell(src) != fileSize)
		{
			int toBuffer = readFromFile(srcBuffer, BUFFERSIZE > fileSize ? fileSize : BUFFERSIZE);
			int toFile = decompress(srcBuffer, toBuffer, dstBuffer);
			fwrite(dstBuffer, 1, toFile, dst);
		}
		printf("File \"%s\" has been decompressed to \"%s\"!\n", argv[1], argv[3]);
	}
	else
	{
		printf("Wrong command! Check it again!\n");
		return -1;
	}

	//�ͷŻ����ڴ�
	free(srcBuffer);
	free(dstBuffer);
	return 0;
}
