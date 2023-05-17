#ifndef __I2C_H
#define __I2C_H

void I2C_Start(void);
void I2C_Stop(void);
void I2C_SendByte(unsigned char Byte);
unsigned char I2_ReceiveByte(void);
void I2C_SendAck(bit AckBit);
unsigned char I2C_ReceiveAck(void);

#endif