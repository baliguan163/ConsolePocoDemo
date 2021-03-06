// ConsoleAppTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//struct 
typedef struct stBmpBufferInfo
{
	int   flag;
	int   n;
	int   w;
	int   h;
	int   size;
	int   dx;
	int   curpos;
	unsigned int   tickbuf[AKK_MAXBMPNUM];
	unsigned char *pbuf;
}BmpBufferInfo;

char g_AkkBmpPath[128] = "/sdcard/bmp";
BmpBufferInfo  g_AkkBmpBuffer;
unsigned char AKK520bmp_header[] =
{
	0x42, 0x4D,
	0x36, 0x54, 0x06, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x36, 0x04, 0x00, 0x00,

	0x28, 0x00, 0x00, 0x00,
	0xD0, 0x02, 0x00, 0x00,
	0x40, 0x02, 0x00, 0x00,
	0x01, 0x00,
	0x08, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x54, 0x06, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00
};

void testPix() {
	/*unsigned int w = 1920;
	unsigned int h = 1080;
	unsigned int size = 3110400;*/

	unsigned int w = 960;
	unsigned int h = 540;
	unsigned int size = 777600;

	float fixSize = (float)size / w / h;
	unsigned int inRowBytes = (unsigned int)(w * fixSize);  //图像每行字节数
	unsigned int bufRowBytes = (unsigned int)(1920 * fixSize);//容器每行字节数
	printf("inRowBytes:%d\n", inRowBytes);
	printf("bufRowBytes:%d\n", bufRowBytes);
	printf("fixSize:%.1f\n", fixSize);
}


void  AKK520SaveBmp_Ex(unsigned char *pD, int w, int h, unsigned char *pfilename)
{
	int  i;
	int  itemp;
	char buf[64];
	DIR *dirptr = NULL;
	FILE *fp;
	//check dir
	dirptr = opendir(g_AkkBmpPath);
	if (NULL == dirptr)
	{
		mkdir(g_AkkBmpPath, 0777);
	}
	else
	{
		closedir(dirptr);
	}
	//open file
	fp = fopen(pfilename, "wb");
	if (NULL == fp)
	{
		return;
	}
	//write bmp file head
	itemp = 54 + 1024 + w * h;
	memcpy(&AKK520bmp_header[2], &itemp, 4);
	memcpy(&AKK520bmp_header[18], &w, 4);
	memcpy(&AKK520bmp_header[22], &h, 4);
	fwrite(AKK520bmp_header, 1, 54, fp);

	for (i = 0; i<256; i++)
	{
		memset(buf, i, 3);
		buf[3] = 0;

		fwrite(buf, 1, 4, fp);
	}
	fwrite(pD, 1, w*h, fp);
	fclose(fp);
}

int main()
{
	testPix();
	getchar();
    return 0;
}



