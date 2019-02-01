/*
 * Copyright (c) 2015-2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== empty.c ========
 */
/* XDCtools Header files */
/* XDCtools Header files */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>


/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26XX.h>

/* TI-RTOS Header files */
#include <ti/drivers/I2C.h>
#include <ti/drivers/PIN.h>
// #include <ti/drivers/SPI.h>
 #include <ti/drivers/UART.h>
// #include <ti/drivers/Watchdog.h>
#include <ti/drivers/pin/PINCC26XX.h>

/* Board Header files */
#include "Board.h"

#define TASKSTACKSIZE   2048
#define Board_initI2C() I2C_init();

#define CMD_CONFIG 0x00
#define CMD_ID 0x39
#define CMD_IDLE 0x58



Task_Struct task1Struct;
Char task1Stack[TASKSTACKSIZE];

/* Pin driver handle */
//static PIN_Handle ledPinHandle;
static PIN_State ledPinState;

static PIN_Handle buttonPinHandle;
static PIN_State buttonPinState;

 uint8_t tx_buffer_data[6];
/*
 * Application LED pin configuration table:
 *   - All LEDs board LEDs are off.
 */
PIN_Config ledPinTable[] = {
    Board_LED0 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    Board_LED1 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PIN_TERMINATE
};
 PIN_Config buttonPinTable[] = {
        Board_BUTTON0  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_POSEDGE,
        Board_BUTTON1  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_POSEDGE,
        Board_BUTTON2  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_POSEDGE,
        Board_BUTTON3  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_POSEDGE,
        PIN_TERMINATE
       };

/*
 *  ======== taskFxn ========
 *  Toggle the Board_LED0. The Task_sleep is determined by arg0 which
 *  is configured for the temperature Task instance.
 */


 uint8_t tempData1[20];
 uint8_t tempData2[20];
 Task_Params taskParams1;
 unsigned int r=0;
 unsigned int task_create=1;



Void taskFxn(UArg arg0, UArg arg1)
 /* TI-RTOS Header files */

{
unsigned int i;
//uint8_t txBuffer[1];
//uint8_t rxBuffer[2];

//char input;
//unsigned int j=0;
UART_Handle uart;
UART_Params uartParams;
//const char echoPrompt[] = "0x00";
uint8_t tx_buffer_config[1];
uint8_t rx_buffer_config[1];
//uint8_t tx_buffer_data[2];
uint8_t rx_buffer_id[13];


/* Create I2C for usage */

UART_Params_init(&uartParams);
uartParams.writeDataMode = UART_DATA_BINARY;
uartParams.readDataMode = UART_DATA_BINARY;
uartParams.readReturnMode = UART_RETURN_NEWLINE;
uartParams.readEcho = UART_ECHO_OFF;
uartParams.baudRate =19200;

uart = UART_open(Board_UART0, &uartParams);

 if (uart == NULL) {
         System_abort("Error opening the UART");
     }

tx_buffer_config[0]=CMD_CONFIG;
UART_write(uart, &tx_buffer_config, 1);
UART_read(uart, &rx_buffer_config, 1);
System_printf("sending the request for config mode\n");
System_printf("received ACK %d\n",rx_buffer_config[0]);
System_flush();


tx_buffer_config[0]=CMD_ID;
UART_write(uart, &tx_buffer_config, 1);
//UART_read(uart, &rx_buffer_id, 12);

tx_buffer_config[0]=CMD_IDLE;
UART_write(uart, &tx_buffer_config, 1);
System_printf("sending the IDLE mode Req\n");
System_flush();

while(1)
{
 arg0 = r;
if(arg0==1)
{
                        tx_buffer_data[0]=0x1;
                        tx_buffer_data[1]='F';
                        UART_write(uart, &tx_buffer_data,2);
                        System_printf("sending Data \n");
                        System_flush();

                        for(i=4;i>0;i--) {
                        UART_write(uart, &tx_buffer_data, 2);
                        System_printf("sending Data \n");
                        System_flush();
                        //Task_sleep(900000);

                        System_printf("shot in front");
                        r = 0;
                        }


     }
else if(arg0==2)
{
                        tx_buffer_data[0]=0x1;
                        tx_buffer_data[1]='B';
                        UART_write(uart, &tx_buffer_data,2);
                        System_printf("sending Data \n");
                        System_flush();

                        for(i=4;i>0;i--) {
                        UART_write(uart, &tx_buffer_data, 2);
                        System_printf("sending Data \n");
                        System_flush();
                        //Task_sleep(900000);

                        System_printf("shot at the back");

                        r = 0;
                        }
}

else if(arg0==3)
                        {
                                           tx_buffer_data[0]=0x1;
                                                tx_buffer_data[1]='R';
                                                UART_write(uart, &tx_buffer_data,2);
                                                System_printf("sending Data \n");
                                                System_flush();

                                                for(i=4;i>0;i--)
                                                {
                                                UART_write(uart, &tx_buffer_data, 2);
                                                System_printf("sending Data \n");
                                                System_flush();
                                                //Task_sleep(900000);

                                                System_printf("shot on the right");
                                                r = 0;

                                                }

     }
else if(arg0==4)
                {
                                        tx_buffer_data[0]=0x1;
                                        tx_buffer_data[1]='L';

                                        UART_write(uart, &tx_buffer_data,2);
                                        System_printf("sending Data \n");
                                        System_flush();

                                        for(i=4;i>0;i--) {
                                        UART_write(uart, &tx_buffer_data, 2);
                                        System_printf("sending Data \n");
                                        System_flush();
                                       // Task_sleep(900000);

                                        System_printf("shot on the left");
                                        r = 0;
                                        }
                }

/*else
       {
            System_printf("I2C Bus fault\n");
        }*/
Task_sleep(900000);

}

//System_flush();
//task_create= 1;
}


void buttonCallbackFxn(PIN_Handle handle,PIN_Id pinID)
{
    //CPUdelay(80000*50);
    //if(!PIN_getInputValue(pinID))
        PIN_getInputValue(pinID);
  //  {
        switch(pinID)
        {
        case Board_BUTTON0:
            r=1;
            break;
        case Board_BUTTON1:
            r=2;
            break;
        case Board_BUTTON2:
            r=3;
            break;
        case Board_BUTTON3:
            r=4;
            break;

        }
        Board_initUART();
if(task_create==1){
                  Task_Params_init(&taskParams1);
                  taskParams1.arg0 = r; //literally already the sleep cycle
                  taskParams1.stackSize = TASKSTACKSIZE;
                  taskParams1.stack = &task1Stack;
                  Task_construct(&task1Struct, (Task_FuncPtr)taskFxn, &taskParams1, NULL);
                  task_create=0;
}
    //}
}



/*
 *  ======== main ========
 */
int main(void)

{
    PIN_Handle ledPinHandle;

    /* Call board init functions */
    Board_initGeneral();
//    Board_initI2C();

    /* Open LED pins */

             ledPinHandle = PIN_open(&ledPinState, ledPinTable);
             if(!ledPinHandle)
             {
                 System_abort("Error initializing board LED pins\n");
             }



    buttonPinHandle = PIN_open(&buttonPinState, buttonPinTable);
       if(!buttonPinHandle)
       {
           System_abort("Error initializing button pins\n");
       }

       /* Setup callback for button pins */
    if (PIN_registerIntCb(buttonPinHandle, &buttonCallbackFxn) != 0)
       {
           System_abort("Error registering button callback function");
       }


    System_printf("Starting the I2C example\nSystem provider is set to SysMin."
                  " Halt the target to view any SysMin contents in ROV.\n");

    /* SysMin will only print to the console when you call flush or exit */
    System_flush();

    /* Start BIOS */
    BIOS_start();
    return (0);
}
