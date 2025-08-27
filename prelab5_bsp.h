#ifndef _bsp_H_
#define _bsp_H_

#include <msp430g2553.h> ;63F742B
//#include  <msp430.h>          // MSP430x2xx
// #include  <msp430xG46x.h>  // MSP430x4xx

#define  DataSegStart      0x200
#define  CodeSegStart      0xC000
#define  StackTosStart     0x0400

#define   debounceVal      65535
#define   delay62_5ms      0xFFFF

// LEDs abstraction
#define LEDsArrPort        &P1OUT
#define LEDsArrPortDir     &P1DIR
#define LEDsArrPortSel     &P1SEL


// PushButtons abstraction
#define PBsArrPortout	   &P2OUT 
#define PBsArrPort	   &P2IN 
#define PBsArrIntPend	   &P2IFG 
#define PBsArrIntEn	   &P2IE
#define PBsArrIntEdgeSel   &P2IES
#define PBsArrPortSel      &P2SEL 
#define PBsArrPortDir      &P2DIR 
#define PB0                0x01
#define PB1                0x02
#define PB2                0x04
#define PB3                0x08


// Switches abstraction
#define SWsArrPort         &P2IN
#define SWsArrPortDir      &P2DIR
#define SWsArrPortSel      &P2SEL
#define SWmask             0x70

// LCD controls abstraction
#define LCDArrPort         &P1OUT
#define LCDArrCont         &P2OUT
#define LCDArrSel          &P1SEL
#define LCDArrDir          &P1DIR
#define countSecO          R13
#define countSecT          R14
#define countMinO          R15
#define COMBINER           R12
#define init               R10
#define final              R9
#define temp               R8
#define E                  0x20 
#define RS                 0x40 
#define R_W                0x80 
#define ASCIIoffset        0x30



//delay abs.
#define   delay5ms         0x1750
#define   delay15ms        0x5250
#define   delay300us       0x005D
#define   delay200us       0x00BA
#define   delay100us       0x001D


#define   smclk_freq_div_32  32768

//-----------------------------------------

#endif



