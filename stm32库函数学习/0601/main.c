

int main()
{
	*(unsigned int*)(0x40021018)|=(1<4);//����GPIOʱ��
	
	//����IO��ģʽ
	*(unsigned int*)0x40011004&=~(0x0f<<(4*5));//��Ӧ��λ���㣬��20-23λ����
	*(unsigned int*)0x40011004|=(0x01<<(4*5));//������Ӧ��λ��11

		//��I��ӦIO��д��Ӧ����
	*(unsigned int*)0x4001100c&=0<<13;//��13λ������0
	*(unsigned int*)0x4001100c|=1<<13;//����13λ��λ�ߵ�ƽ
	
	while(1)
	{
		
	}	
}

void SystemInit(void)
{

}
