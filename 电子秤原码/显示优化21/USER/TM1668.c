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
    ��ʼ
*/
void TM1668_Start(void)
{
	GPIO_CLK  = 1;
    GPIO_DIO  = 1;
    GPIO_STB  = 0;
	Delay(1);
}

/*
    ����
*/
void TM1668_End(void)
{
	GPIO_CLK  = 1;
    GPIO_DIO  = 1;
    GPIO_STB  = 1;
	Delay(1);
}

/*
    дһ���ֽ�
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
	�̶���ַд����ַ����ģʽ���ӵ�һ��λ�ÿ�ʼ
	p:Ҫд�������׵�ַ		nBytes:����(<=14)		brightness:����
 */
void TM1668_WriteBytesAddrIncrease(unsigned char *p, unsigned char nBytes, unsigned char brightness)
{
	unsigned char i = 0;

	TM1668_Start();
	TM1668_WriteByte(GRID7_SEG10);				/* 7λ10�� */
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(CMD_DataWriteIncrease);	/* �̶���ַģ������ģʽ */
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(ADD_00H);					/* �ӵ�һ����ַ��ʼ */
	for (i = 0; i < nBytes; i++)
	{
		TM1668_WriteByte(p[i]);						//Ҫд1-8λ���ֽڣ�
		TM1668_WriteByte(p[i]);							//д9����14���ֽڣ���Ϊû���õ�����д00
	}
	TM1668_End();													//����

	TM1668_Start();												//��ʼ
	TM1668_WriteByte(brightness);				/* �������� */
	TM1668_End();
}

/*
	�̶���ַģʽ����������Ǵӵ�һ����ַ���������ˣ�������һ��
	p:???????		nBytes:??????(<=14)		brightness:????
 */
void TM1668_WriteBytesAddrFixed(unsigned char *p, unsigned char nBytes, unsigned char brightness)
{
	unsigned char i = 0;

	TM1668_Start();
	TM1668_WriteByte(GRID7_SEG10);				/*7λ10��*/
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(CMD_DataWriteFixed);		/* �̶���ַ */
	TM1668_End();

	for (i = 0; i < nBytes; i++)
	{
		TM1668_Start();
		TM1668_WriteByte(ADD_00H + i);			/* ��ַ */
		TM1668_WriteByte(p[i]);
		TM1668_End();
	}

	TM1668_Start();
	TM1668_WriteByte(brightness);				/* ���� */
	TM1668_End();
}

void TM1668_WriteBytesAddrF(unsigned char *p, unsigned char nBytes, unsigned char ADD)
{
	unsigned char i = 0;

	TM1668_Start();
	TM1668_WriteByte(GRID7_SEG10);				/* 7λ10�� */
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(CMD_DataWriteFixed);		/* �̶���ַģʽ */
	TM1668_End();

	for (i = 0; i < nBytes; i++)
	{
		TM1668_Start();
		TM1668_WriteByte(ADD + i);			/* ��ַ */
		TM1668_WriteByte(p[i]);
		TM1668_End();
	}

	TM1668_Start();
	TM1668_WriteByte(0x8F);				/* ���� */
	TM1668_End();
}


/*
    ��ֹ��������
*/
void TM1668_Init(void)
{
	
	unsigned char i = 0;

	GPIO_InitTypeDef GPIOx;
	GPIOx.Mode=GPIO_OUT_PP;
	GPIOx.Pin=GPIO_Pin_6|GPIO_Pin_5|GPIO_Pin_7;
	
	GPIO_Inilize(GPIO_P0,&GPIOx);
	
	TM1668_Start();
	TM1668_WriteByte(GRID7_SEG10);				/* ����7λ10��ģʽ */
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(CMD_DataWriteIncrease);	/* ��ַ���� */
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(ADD_00H);					/* �ӵ�һ��ַ��ʼд */
	for (i = 0; i < 14; i++)
	{
		TM1668_WriteByte(0);
	}
	TM1668_End();

	TM1668_Start();
	TM1668_WriteByte(DSP_OFF);				    /* ��ʾ�� */
	TM1668_End();
	

}

void TM1668_DisPlay(unsigned char wei,unsigned char duan)
{
	TAB[wei-1]=CODE[duan];
	TM1668_WriteBytesAddrIncrease(TAB,7,0x8F);
}
