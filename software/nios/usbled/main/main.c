

/*--------------------------------------------------------------------------------------
 *  Include
 *-------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <unistd.h>
#include "../inc/usb.h"
#include "../inc/sopc.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main()
{
    unsigned char tmp[] = "Connecting!\n";
    int i;
    initialize_usb();

    while(1){ 
        if(usb.receive_ok_flag){
            printf("%s\n",usb.receive_buffer);
            LED->DATA = 15;
            usleep(1000000);
            usb.receive_ok_flag = 0;
        }
        LED->DATA = 0 ;
        send_string_to_usb(tmp,sizeof(tmp));
        usleep(100000);
    }
    return 0;
}

