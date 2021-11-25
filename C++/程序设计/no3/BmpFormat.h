# ifndef BMP_H
# define BMP_H
#pragma pack(1) //�ֶ������ڴ�����ֵ�������ȡbmp�ļ�ʱ�������ݴ�λ 

// �ļ���Ϣͷ�ṹ��
typedef struct tagBITMAPFILEHEADER
{
    unsigned short bfType;        // 19778��������BM�ַ�������Ӧ��ʮ������Ϊ0x4d42,ʮ����Ϊ19778��������bmp��ʽ�ļ�
    unsigned int   bfSize;        // �ļ���С ���ֽ�Ϊ��λ(2-5�ֽ�)
    unsigned short bfReserved1;   // ��������������Ϊ0 (6-7�ֽ�)
    unsigned short bfReserved2;   // ��������������Ϊ0 (8-9�ֽ�)
    unsigned int   bfOffBits;     // ���ļ�ͷ���������ݵ�ƫ��  (10-13�ֽ�)
} BITMAPFILEHEADER;

//ͼ����Ϣͷ�ṹ��
typedef struct tagBITMAPINFOHEADER
{
    unsigned int    biSize;          // ͼ����Ϣͷ�Ĵ�С (14-17�ֽ�)
    long            biWidth;         // ͼ��Ŀ�  (18-21�ֽ�)
    long            biHeight;        // ͼ��ĸ�  (22-25�ֽ�)
    unsigned short  biPlanes;        // ͼƬ��ƽ����  (26-27�ֽ�)
    unsigned short  biBitCount;      // һ������ռ��λ��  (28-29�ֽ�)
    unsigned int    biCompression;   // ͼ������ѹ�������ͣ�0Ϊ��ѹ���� (30-33�ֽ�)
    unsigned int    biSizeImage;     // ͼ��������ռ��С, Ӧ�õ��������ļ�ͷ�ṹ��bfSize-bfOffBits (34-37�ֽ�)
    long            biXPelsPerMeter; // ˮƽ�ֱ��ʣ���λ����/�ס�һ��Ϊ0 (38-41�ֽ�)
    long            biYPelsPerMeter; // ��ֱ�ֱ��ʣ���λ����/�ס�һ��Ϊ0 (42-45�ֽ�)
    unsigned int    biClrUsed;       // λͼʵ��ʹ�õĲ�ɫ���е���ɫ����������Ϊ0�Ļ�����˵��ʹ�����е�ɫ����� (46-49�ֽ�)
    unsigned int    biClrImportant;  // ��ͼ����ʾ����ҪӰ�����ɫ�������������0����ʾ����Ҫ��(50-53�ֽ�)
} BITMAPINFOHEADER;

//�����ǵ�ɫ�壬��24λλͼû�е�ɫ�壬Ϊ�˷����������������ص��RGB����
typedef struct _PixelInfo
{
    unsigned char rgbBlue;     //����ɫ����ɫ����  (ֵ��ΧΪ0-255)
    unsigned char rgbGreen;    //����ɫ����ɫ����  (ֵ��ΧΪ0-255)
    unsigned char rgbRed;      //����ɫ�ĺ�ɫ����  (ֵ��ΧΪ0-255)
    //unsigned char rgbReserved; // ����������Ϊ0
} PixelInfo;
#pragma pack()
#endif
