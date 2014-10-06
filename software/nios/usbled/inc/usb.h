

#ifndef __usb_h__
#define __usb_h__


/*--------------------------------------------------------------------------------------
 *  Include
 *-------------------------------------------------------------------------------------*/ 
#include "system.h"
/*--------------------------------------------------------------------------------------
 *  Define
 *-------------------------------------------------------------------------------------*/ 

//common
#define USB_HOST    0X06
#define USB_DEVICE  0x02
#define USB_DISABLE 0X00

#define RESET_ALL   0X05
#define CHECK_EXIST 0X06
#define SET_USB_ID  0X12
#define SET_USB_MODE    0X15
#define GET_STATUS  0X22
#define UNLOCK_USB  0X23
#define RD_USB_DATA 0X28
#define WR_USB_DATA5    0X2A
#define WR_USB_DATA7    0X2B
#define GET_IC_VER  0X01
#define ENTER_SLEEP 0X03
#define CHK_SUSPEND 0X0B
#define RD_USB_DATA0    0X27

#define RET_SUCCESS 0X51
#define RET_ABORT   0X5B

#define INT_EP2_OUT 0x02
#define INT_EP2_IN  0x0a

//host
#define DISK_READ   0X54
#define DISK_RD_GO  0X55

#define DISK_READY  0X59
#define DISK_INIT   0X51

//status
#define USB_INT_CONNECT 0x15
#define USB_INT_DISCONNECT 0X16
#define USB_INT_SUCCESS 0X14
#define USB_INT_DISK_READ   0X1D

//usb
#define PIO_USB_DB      *(volatile unsigned long int *)USB_DB_BASE
#define PIO_USB_WR      *(volatile unsigned long int *)USB_WR_BASE
#define PIO_USB_RD      *(volatile unsigned long int *)USB_RD_BASE
#define PIO_USB_A0      *(volatile unsigned long int *)USB_A0_BASE
#define PIO_USB_INT     *(volatile unsigned long int *)USB_INT_BASE

#define PIO_USB_DB_DIR  *(volatile unsigned long int *)(USB_DB_BASE+4)

#define VID 0X0FFE
#define PID 0X1000

/*--------------------------------------------------------------------------------------
 *  Struct
 *-------------------------------------------------------------------------------------*/ 
typedef struct{
	char receive_buffer[200];
    int send_ok_flag;
	int receive_ok_flag;
}USB_T;

/*--------------------------------------------------------------------------------------
 *  Extern
 *-------------------------------------------------------------------------------------*/ 
extern USB_T usb;
extern int initialize_usb(void);
extern int set_usb_mode(unsigned char);
extern int send_string_to_usb(char *str,int str_len);
extern void write_command_to_usb(unsigned char command);
extern void write_data_to_usb(unsigned char data);

#endif //__usb_h__
