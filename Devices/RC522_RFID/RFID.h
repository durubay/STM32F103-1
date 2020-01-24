#ifndef _RFID_
#define _RFID_


#include "stm32f10x.h"
#include "SPI.h"


/*
PIN 1 -> VCC
PIN 2 -> RST
PIN 3 -> GND
PIN 4 -> IRQ
PIN 5 -> MISO / SCL / TX
PIN 6 -> MOSI
PIN 7 -> SCK
PIN 8 -> RX / SDA / SS
*/


//Commands
#define	Idle 0b0000
#define Mem  0b0001
#define Generate_RandomID 0b0010
#define CalcCRC 0b0011
#define Transmit 0b0100
#define NoCmdChange 0b0111
#define Transceive 0b1100
#define MFAuthent 0b1110
#define SoftReset 0b1111

//   int  Buff_1[] = {
//	0x00, 0xC6, 0x37, 0xD5, 0x32, 0xB7, 0x57, 0x5C,
//  0xC2, 0xD8, 0x7C, 0x4D, 0xD9, 0x70, 0xC7, 0x73,
//	0x10, 0xE6, 0xD2, 0xAA, 0x5E, 0xA1, 0x3E, 0x5A,
//	0x14, 0xAF, 0x30, 0x61, 0xC9, 0x70, 0xDB, 0x2E,
//	0x64, 0x22, 0x72, 0xB5, 0xBD, 0x65, 0xF4, 0xEC,
//	0x22, 0xBC, 0xD3, 0x72, 0x35, 0xCD, 0xAA, 0x41,
//	0x1F, 0xA7, 0xF3, 0x53, 0x14, 0xDE, 0x7E, 0x02,
//	0xD9, 0x0F, 0xB5, 0x5E, 0x25, 0x1D, 0x29, 0x79	
//};

//	const uint8_t Buffer_2[]=
//{
//	00h, EBh, 66h, BAh, 57h, BFh, 23h, 95h,
//	D0h, E3h, 0Dh, 3Dh, 27h, 89h, 5Ch, DEh,
//	9Dh, 3Bh, A7h, 00h, 21h, 5Bh, 89h, 82h,
//	51h, 3Ah, EBh, 02h, 0Ch, A5h, 00h, 49h,
//	7Ch, 84h, 4Dh, B3h, CCh, D2h, 1Bh, 81h,
//	5Dh, 48h, 76h, D5h, 71h, 061h, 21h, A9h,
//	86h, 96h, 83h, 38h, CFh, 9Dh, 5Bh, 6Dh,
//	DCh, 15h, BAh, 3Eh, 7Dh, 95h, 03Bh, 2Fh

//};

//	


#ifdef RFID_SPI 

#define Read_Register  0x80
#define Write_Register 0x00

//Page 0
#define CommandReg 0x01 << 1
#define ComlEnReg	 0x02 << 1
#define DivlEnReg  0x03 << 1
#define ComIrqReg  0x04 << 1
#define DivIrqReg	 0x05 << 1
#define ErrorReg   0x06 << 1
#define Status1Reg 0x07 << 1
#define Status2Reg 0x08 << 1
#define FIFODataReg 0x09 << 1
#define FIFOLevelReg 0x0a << 1
#define WaterLevelReg 0x0b << 1
#define ControlReg  0x0c << 1
#define BitFramingReg 0x0d << 1
#define CollReg     0x0e << 1

//Page 1
#define ModeReg 	0x11 << 1
#define TxModeReg 0x12 << 1
#define RxModeReg 0x13 << 1
#define TxControlReg 0x14 << 1
#define TxASKReg	0x15 << 1
#define TxSelReg 0x16 << 1
#define RxSelReg 0x17 << 1
#define RxThresholdReg 0x18 << 1
#define DemodReg 0x19 << 1
#define MfTxReg 0x1c << 1
#define MfRxReg 0x1d << 1
#define SerialSpeedReg 0x1f << 1

//Page 2
#define CRCResultReg_1 0x21 << 1
#define CRCResultReg_2 0x22 << 1
#define ModWidthReg 0x24 << 1
#define RFCfgReg 0x26 << 1
#define GsNReg 0x27 << 1
#define CWGsPReg 0x28 << 1
#define ModGsPReg 0x29 << 1
#define TModeReg 0x2a << 1
#define TPrescalerReg 0x2b << 1
#define TReloadReg_1 0x2c << 1
#define TReloadReg_2 0x2d << 1
#define TCounterValReg_1 0x2e << 1
#define TCounterValReg_2 0x2f << 1

//Page 3
#define TestSel1Reg 0x31 << 1
#define TestSel2Reg 0x32 << 1
#define TestPinEnReg 0x33 << 1
#define TestPinValueReg 0x34 << 1
#define TestBusReg 0x35 << 1
#define AutoTestReg 0x36 << 1
#define VersionReg 0x37 << 1
#define AnalogTestReg 0x38 << 1
#define TestDAC1Reg 0x39 << 1
#define TestDAC2Reg 0x3a << 1
#define TestADCReg 0x3b << 1




#endif

#ifdef RFID_I2C

 void RFID_I2C_Init(void);
 void 
#endif

#ifdef RFID_UART

 void RFID_I2C_UART(void);
 
#endif


#endif
