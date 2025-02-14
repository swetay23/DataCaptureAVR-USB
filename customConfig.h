/*==============================================================================
== FUNCTION :
==    Header file for USB hardware configuration for AVR microcontroller
================================================================================
==
== FILE NAME :
==    customConfig.h
==
== Description :
==		Define maximum in and out data buffer lengths (REPORT_LEN) and device
==		description. The description mast match the description in the firmware.
==		USB_CFG_SERIAL_NUMBER, and USB_CFG_SERIAL_NUMBER_LEN are optional.
==
==============================================================================*/
#ifndef __customConfig_h_included__
#define __customConfig_h_included__

/* ---------------------------- Memory and Data buffers -------------------*/

#define REPORT_LEN	128		// indata and outdata maximum length 

/* -------------------------- Device Description --------------------------- */

#define USB_CFG_VENDOR_NAME      'H', 'B'
#define USB_CFG_VENDOR_NAME_LEN  3
#define USB_CFG_DEVICE_NAME      'U', 'S', 'B', ' ', 'T', 'e', 's', 't'
#define USB_CFG_DEVICE_NAME_LEN  8


#define USB_CFG_VENDOR_ID       0xc0, 0x16
#define USB_CFG_DEVICE_ID       0xdf, 0x05 
//#define USB_CFG_DEVICE_VERSION  0x00, 0x01

//#define USB_CFG_SERIAL_NUMBER   'N', 'o', 'n', 'e' 
//#define USB_CFG_SERIAL_NUMBER_LEN   0 

#endif // __customConfig_h_included__ 
