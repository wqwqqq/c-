#ifndef __TM1668_H
#define __TM1668_H


#ifndef _TM1668_H
#define _TM1668_H

/*******************************************************************************
                                ?????                                
*******************************************************************************/
#include "config.h"   /* ??MCU???? */

sbit GPIO_DIO=P0^5;    /* ??????    */
sbit GPIO_CLK=P0^6;    /* ????        */
sbit GPIO_STB=P0^7;    /* ????        */

/*******************************************************************************
                                ????????
*******************************************************************************/
#define GRID4_SEG13 0x00    /* 4?13? */
#define GRID5_SEG12 0x01    /* 5?12? */
#define GRID6_SEG11 0x02    /* 6?11? */
#define GRID7_SEG10 0x03    /* 7?10? */

/*******************************************************************************
                                ??????
*******************************************************************************/
#define CMD_DataWriteIncrease   0x40    /* ??????? */
#define CMD_DataWriteFixed      0x44    /* ??????? */


/*******************************************************************************
                                ????????
*******************************************************************************/
#define DSP_01_16   0x88    /* ???????1/16  */
#define DSP_02_16   0x89    /* ???????2/16  */
#define DSP_04_16   0x8A    /* ???????4/16  */
#define DSP_10_16   0x8B    /* ???????10/16 */
#define DSP_11_16   0x8C    /* ???????11/16 */
#define DSP_12_16   0x8D    /* ???????12/16 */
#define DSP_13_16   0x8E    /* ???????13/16 */
#define DSP_14_16   0x8F    /* ???????14/16 */
#define DSP_OFF     0x80    /* ??? */

/*******************************************************************************
                                ??????
*******************************************************************************/
#define ADD_00H     0xC0    /* ????: GRID1     */
#define ADD_01H     0xC1    /* ????: GRID1     */
#define ADD_02H     0xC2    /* ????: GRID2     */
#define ADD_03H     0xC3    /* ????: GRID2     */
#define ADD_04H     0xC4    /* ????: GRID3     */
#define ADD_05H     0xC5    /* ????: GRID3     */
#define ADD_06H     0xC6    /* ????: GRID4     */
#define ADD_07H     0xC7    /* ????: GRID4     */
#define ADD_08H     0xC8    /* ????: GRID5     */
#define ADD_09H     0xC9    /* ????: GRID5     */
#define ADD_0AH     0xCA    /* ????: GRID6     */
#define ADD_0BH     0xCB    /* ????: GRID6     */
#define ADD_0CH     0xCC    /* ????: GRID7     */
#define ADD_0DH     0xCD    /* ????: GRID7     */


void TM1668_WriteBytesAddrIncrease(unsigned char *p, unsigned char nBytes, unsigned char brightness);
void TM1668_WriteBytesAddrFixed(unsigned char *p, unsigned char nBytes, unsigned char brightness);
void TM1668_WriteBytesAddrF(unsigned char *p, unsigned char nBytes, unsigned char ADD);

/*第一个参数是位1-7，第二个参数是显示的数字范围是0-21，分别对应下面的数字*/
/*  0 1 2 3 4 5 6 7 8 9 0. 1. 2. 3. 4. 5. 6. 7. 8. 9. - 关*/
/*  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21*/
void TM1668_DisPlay(unsigned char wei,unsigned char duan);

void TM1668_Init(void);

#endif



#endif