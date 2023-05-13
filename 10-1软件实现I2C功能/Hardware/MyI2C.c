#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void MyI2C_W_SCL(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOB,GPIO_Pin_10,(BitAction)BitValue);
	Delay_us(10);
}

void MyI2C_W_SDA(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOB,GPIO_Pin_11,(BitAction)BitValue);
	Delay_us(10);
}

uint8_t MyI2C_R_SDA()
{
	uint8_t BitValute;
	BitValute=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11);
	Delay_us(10);
	return BitValute;
}

void MyI2C_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_10 | GPIO_Pin_11);

}

void MyI2C_Start()
{
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(0);
}

void MyI2C_Stop()
{
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(1);	
}

void MyI2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{	
	MyI2C_W_SDA(Byte&(0x80>>i));//��ʼ�󣬷�������SCL�ǵ͵�Ƶ���͵�Ƶֱ�ӽ����ݷ���SDA��
	MyI2C_W_SCL(1);//�ߵ�ƽ���Ǵӻ���ȡ���ݣ�����Ҫ�����ٿ�
	MyI2C_W_SCL(0);
	}	
}

uint8_t MyI2C_ReceiveByte(void)
{
		uint8_t i;
		uint8_t Byte=0;
		MyI2C_W_SDA(1);//�����ͷ�SDA������
		MyI2C_W_SCL(1);//�����ͷ�SDA�ſ��Զ�ȡ���ݣ��ߵ�ƽ��ȡ����ΪSDA�������������ƣ�ֻҪ�����У�����Ҫ�����ı�SDA��������
		for(i=0;i<8;i++)
		{
		MyI2C_W_SCL(1);//�����ͷ�SDA�ſ��Զ�ȡ���ݣ��ߵ�ƽ��ȡ����ΪSDA�������������ƣ�ֻҪ�����У�����Ҫ�����ı�SDA��������			
		if(MyI2C_R_SDA()==1){Byte|=(0x80>>i);}//��ȡSDA��Ƶ�仯������8��BITλ���������ɴӻ�����SDA
		MyI2C_W_SCL(0);//��ȡ�����ݺ�SCL����	
		}
		return Byte;
}

void MyI2C_SendAck(uint8_t AckBit)//����Ӧ��λ���൱�ڷ���һ���ֽ�
{
	MyI2C_W_SDA(AckBit);
	MyI2C_W_SCL(1);
	MyI2C_W_SCL(0);	
}

uint8_t MyI2C_ReceiveAck(void)//����Ӧ��λ���൱�ڽ���һ���ֽ�
{
		uint8_t AckBit;
		MyI2C_W_SDA(1);
		MyI2C_W_SCL(1);		
		AckBit=MyI2C_R_SDA();
		MyI2C_W_SCL(0);
		return AckBit;
}
