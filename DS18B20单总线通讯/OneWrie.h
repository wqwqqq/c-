#ifndef __OneWire_h__
#define __OneWire_h__

unsigned char OneWire_Init();
void OneWire_SendByte(unsigned char Byte);
unsigned char OneWire_ReceiveByte();

#endif