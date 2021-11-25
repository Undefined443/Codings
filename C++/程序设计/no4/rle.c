/*
* 程序名：RLE算法文件压缩
* 成员：李潇，吴兴祺
*/
#define BUFFERSIZE 512*1024 //最大缓存大小，在解压模式中建议大于源文件大小
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

FILE* src;
FILE* dst;

int   fileSize;		 //文件大小

int readFromFile(BYTE* srcBuffer, int bufferSize)
{
	static int readed = 0; //已读取数据大小
	int remaining = fileSize - readed;
	int toBuffer = remaining > bufferSize ? bufferSize : remaining; //确定一次读入缓存的数据量。若剩余数据大小大于缓存容量，则读入缓存容量大小的数据。否则读入全部剩余数据。
	fread(srcBuffer, 1, toBuffer, src);
	readed += toBuffer;
	return toBuffer;
}

//将[begin, end)的数据存到dst
void storeToBuffer(BYTE* dstBuffer, BYTE index, BYTE* begin, BYTE* end)
{
	*dstBuffer = index;
	dstBuffer++;
	memcpy(dstBuffer, begin, end - begin);
}

//压缩操作
int compress(BYTE* srcBuffer, int bufferSize, BYTE* dstBuffer)
{
	BYTE* end = srcBuffer + bufferSize;
	if (fileSize < 3) //如果数据长度<3则不用判断，直接原样存入目标缓存区。
	{
		storeToBuffer(dstBuffer, (BYTE)bufferSize, srcBuffer, end);
		return fileSize + 1; //多了一个长度指示字节
	}

	int toFile = 0; //返回值
	BYTE* bufferPointer = dstBuffer;
	BYTE index; //用于指示压缩类型和长度的变量，和压缩后的数据一起写入目标文件。其中最高位用于表示压缩类型，后七位表示长度。
	BYTE* cur = srcBuffer + 2; //从原始数据的第三个字节开始判断是否与前两个字节相同
	BYTE* mark = srcBuffer; //用于标记某次判断的起始位置
	while (cur < end)
	{
		if (*cur == *(cur - 1) && *cur == *(cur - 2)) //如果当前数据与前两个数据相同，则继续向后检索直到不同。然后压缩。
		{
			//先将前面相同的数据存入缓存
			if (cur - 2 - mark > 0)
			{
				index = cur - 2 - mark;
				storeToBuffer(bufferPointer, index, mark, cur - 2);
				toFile += index + 1;
				bufferPointer += index + 1;
			}
			mark = cur - 2;
			while (*cur == *mark && cur - mark < 127 && cur < end && bufferPointer - dstBuffer + cur - mark < BUFFERSIZE) //数据相同 && 数据长度 < 127 && cur未到达srcBuffer末尾 && dstBuffer存得下
			{
				cur++;
			}
			index = (cur - mark) | 0b10000000; //将最高位变为1，表示后面的字节是连续字节。
			storeToBuffer(bufferPointer, index, mark, mark + 1);
			toFile += 2; //一旦遇到3个及以上的连续数据，都会被压缩成两个字节。因此存入文件的数据量+2。
			bufferPointer += 2;
			mark = cur;
			cur++;
		}
		else if (!(cur - mark < 127 && cur < end && bufferPointer - dstBuffer + cur - mark < BUFFERSIZE)) //超出范围，将数据存入缓冲，重新开始下一轮检索。
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
	//到最后可能出现cur >= end但还剩几个字节没有处理的情况，此时应将剩余字节存入dstBuffer。
	if (mark < end)
	{
		index = end - mark;
		storeToBuffer(bufferPointer, index, mark, end);
		toFile += index + 1;
	}
	return toFile;
}

//解压操作
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
		//flag的首位为1说明后面是重复的数据
		if (flag == 0b10000000)
		{
			index &= 0b01111111; //将指示变量转换成重复次数
			//如果存得下就memcpy到dstBuffer
			if (bufferPointer + index < end)
			{
				for (int i = 0; i < index; i++)
				{
					memcpy(bufferPointer, cur, 1);
					bufferPointer++;
				}
			}
			//存不下就先将dstBuffer的数据存入文件，然后再存。
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
	//打开文件
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

	//获取文件大小，以便确定缓存大小
	fseek(src, 0L, SEEK_END);
	fileSize = ftell(src);
	rewind(src);

	//给缓存分配内存
	BYTE* srcBuffer = malloc(BUFFERSIZE);
	BYTE* dstBuffer = malloc(BUFFERSIZE);

	if (strcmp(argv[2], "-c") == 0) //压缩模式
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

	//释放缓存内存
	free(srcBuffer);
	free(dstBuffer);
	return 0;
}
