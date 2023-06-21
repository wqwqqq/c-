#include "TM1668.h"
#include <intrins.h>       /* ??void _nop_(void); */
#include "GPIO.h"

unsigned char code CODE[]={
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x3F+0x80,0x06+0x80,0x5B+0x80,0x4F+0x80,0x66+0x80,0x6D+0x80,0x7D+0x80,0x07+0x80,0x7F+0x80,0x6F+0x80,0x40,0x00,0x79};
unsigned char TAB[10]={
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

static void Delay(unsigned char n)
{
	unsigned char i = 0;
	for (i = 0; i < n; i++)
	{
		_nop_();	
	}
}

/*
    开始
*/
void TM1668_Start(void)
{
	GPIO_CLK  = 1;
    GPIO_DIO  = 1;
    GPIO_STB  = 0;
	Delay(1);
}

/*
    结束
*/
void TM1668_End(void)
{
	GPIO_CLK  = 1;
    GPIO_DIO  = 1;
    GPIO_STB  = 1;
	Delay(1);
}

/*
    写一个字节
*/
void TM1668_WriteByte(unsigned char byte)
{
	unsigned char i = 0;

	for(i=0; i<8; i++)
	{
		GPIO_CLK = 0;
		Delay(1);
		GPIO_DIO = (byte&0x01);
		Delay(1);
		GPIO_CLK = 1;
		Delay(1);
		byte>>=1;
		Delay(1);
	}
}


/*
	固定地址写，地址增加模式，从第一个位置开始
	p:要写的数据首地址		nBytes:个数(<=14)		brightness:亮度
 */
void TM1668_WriteBytesAddrIncrease(unsigned char *p, unsigned char nBytes, unsigned char brightness)
{
	unsigned char i = 0;

	TM1668_Start();
	TM1668_WriteByte(GRID7_SEG10);				/* 7位10段 */
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(CMD_DataWriteIncrease);	/* 固定地址模试增加模式 */
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(ADD_00H);					/* 从第一个地址开始 */
	for (i = 0; i < nBytes; i++)
	{
		TM1668_WriteByte(p[i]);						//要写1-8位的字节，
		TM1668_WriteByte(p[i]);							//写9——14的字节，因为没有用到可以写00
	}
	TM1668_End();													//结束

	TM1668_Start();												//开始
	TM1668_WriteByte(brightness);				/* 调节亮度 */
	TM1668_End();
}

/*
	固定地址模式，这个函数是从第一个地址往后增加了，后上面一样
	p:???????		nBytes:??????(<=14)		brightness:????
 */
void TM1668_WriteBytesAddrFixed(unsigned char *p, unsigned char nBytes, unsigned char brightness)
{
	unsigned char i = 0;

	TM1668_Start();
	TM1668_WriteByte(GRID7_SEG10);				/*7位10段*/
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(CMD_DataWriteFixed);		/* 固定地址 */
	TM1668_End();

	for (i = 0; i < nBytes; i++)
	{
		TM1668_Start();
		TM1668_WriteByte(ADD_00H + i);			/* 地址 */
		TM1668_WriteByte(p[i]);
		TM1668_End();
	}

	TM1668_Start();
	TM1668_WriteByte(brightness);				/* 亮度 */
	TM1668_End();
}

void TM1668_WriteBytesAddrF(unsigned char *p, unsigned char nBytes, unsigned char ADD)
{
	unsigned char i = 0;

	TM1668_Start();
	TM1668_WriteByte(GRID7_SEG10);				/* 7位10段 */
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(CMD_DataWriteFixed);		/* 固定地址模式 */
	TM1668_End();

	for (i = 0; i < nBytes; i++)
	{
		TM1668_Start();
		TM1668_WriteByte(ADD + i);			/* 地址 */
		TM1668_WriteByte(p[i]);
		TM1668_End();
	}

	TM1668_Start();
	TM1668_WriteByte(0x8F);				/* 亮度 */
	TM1668_End();
}


/*
    防止出现乱码
*/
void TM1668_Init(void)
{
	
	unsigned char i = 0;

	GPIO_InitTypeDef GPIOx;
	GPIOx.Mode=GPIO_OUT_PP;
	GPIOx.Pin=GPIO_Pin_6|GPIO_Pin_5|GPIO_Pin_7;
	
	GPIO_Inilize(GPIO_P0,&GPIOx);
	
	TM1668_Start();
	TM1668_WriteByte(GRID7_SEG10);				/* 设置7位10段模式 */
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(CMD_DataWriteIncrease);	/* 地址增加 */
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(ADD_00H);					/* 从第一地址开始写 */
	for (i = 0; i < 14; i++)
	{
		TM1668_WriteByte(0);
	}
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(DSP_OFF);				    /* 显示关 */
	TM1668_End();
	

}

void TM1668_DisPlay(unsigned char wei,unsigned char duan)
{
	TAB[wei-1]=CODE[duan];
	TM1668_WriteBytesAddrIncrease(TAB,7,0x8F);
}
