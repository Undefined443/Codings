# ifndef BMP_H
# define BMP_H
#pragma pack(1) //手动更改内存对齐的值，避免读取bmp文件时产生数据错位 

// 文件信息头结构体
typedef struct tagBITMAPFILEHEADER
{
    unsigned short bfType;        // 19778，必须是BM字符串，对应的十六进制为0x4d42,十进制为19778，否则不是bmp格式文件
    unsigned int   bfSize;        // 文件大小 以字节为单位(2-5字节)
    unsigned short bfReserved1;   // 保留，必须设置为0 (6-7字节)
    unsigned short bfReserved2;   // 保留，必须设置为0 (8-9字节)
    unsigned int   bfOffBits;     // 从文件头到像素数据的偏移  (10-13字节)
} BITMAPFILEHEADER;

//图像信息头结构体
typedef struct tagBITMAPINFOHEADER
{
    unsigned int    biSize;          // 图像信息头的大小 (14-17字节)
    long            biWidth;         // 图像的宽  (18-21字节)
    long            biHeight;        // 图像的高  (22-25字节)
    unsigned short  biPlanes;        // 图片的平面属  (26-27字节)
    unsigned short  biBitCount;      // 一像素所占的位数  (28-29字节)
    unsigned int    biCompression;   // 图象数据压缩的类型，0为不压缩。 (30-33字节)
    unsigned int    biSizeImage;     // 图像数据所占大小, 应该等于上面文件头结构中bfSize-bfOffBits (34-37字节)
    long            biXPelsPerMeter; // 水平分辨率，单位像素/米。一般为0 (38-41字节)
    long            biYPelsPerMeter; // 垂直分辨率，单位像素/米。一般为0 (42-45字节)
    unsigned int    biClrUsed;       // 位图实际使用的彩色表中的颜色索引数（设为0的话，则说明使用所有调色板项）。 (46-49字节)
    unsigned int    biClrImportant;  // 对图象显示有重要影响的颜色索引数，如果是0，表示都重要。(50-53字节)
} BITMAPINFOHEADER;

//本来是调色板，但24位位图没有调色板，为了方便我用它储存像素点的RGB数据
typedef struct _PixelInfo
{
    unsigned char rgbBlue;     //该颜色的蓝色分量  (值范围为0-255)
    unsigned char rgbGreen;    //该颜色的绿色分量  (值范围为0-255)
    unsigned char rgbRed;      //该颜色的红色分量  (值范围为0-255)
    //unsigned char rgbReserved; // 保留，必须为0
} PixelInfo;
#pragma pack()
#endif
