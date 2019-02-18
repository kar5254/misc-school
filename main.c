#include "stm32l476xx.h"
#include "SysClock.h"
#include "LED.h"
#include "UART.h"

#include <string.h>
#include <stdio.h>

char RxComByte = 0;
uint8_t buffer[BufferSize];
char str[] = "Give Red LED control input (Y = On, N = off):\r\n";

int main(void){
	char rxByte;
	int		a ;
	int		n ;
	int		i ;
	float b;
	
	System_Clock_Init(); // Switch System Clock = 80 MHz
	LED_Init();
	UART2_Init();
		
	/*
	forever loop
call USART_Read and save its return value
If return value is non-zero
If Enter key see if we have a valid command
Else if a Backspace remove the previous character from the command buffer and display result
Else echo the character and add it to the command buffer
Delay one millisecond (you can use USART_Delay for this if you want)
If one or both LEDs are flashing
Increment the loop counter
If loop counter is 1000 then change state of LEDs and reset counter to 0
end of forever loop
	*/

while (1){
	rxByte = USART_Read(USART2); //Read byte
	if (rxByte != 0){
		if(rxByte == '\n' || rxByte = '\r'){ //If enter, check the command
			//check command
		}
		else if (rxByte == '\b'){ //If backspace, remove the last character
			buffer = buffer[]
			USART_Write(USART2, buffer, n);
		}
		else{

		}
	}
}




/*
	while (1){
		n = sprintf((char *)buffer, "a = %d\t", a);
		n += sprintf((char *)buffer + n, "b = %f\r\n", b);
		USART_Write(USART2, buffer, n);		
		a = a + 1;
		b = (float)a/100;
		// now spin for a while to slow it down
		for (i = 0; i < 4000000; i++)
			;
*/
		
//		USART_Write(USART2, (uint8_t *)str, strlen(str));	
//		rxByte = USART_Read(USART2);
//		if (rxByte == 'N' || rxByte == 'n'){
//			Red_LED_Off();
//			USART_Write(USART2, (uint8_t *)"LED is Off\r\n\r\n", 16);
//		}
//		else if (rxByte == 'Y' || rxByte == 'y'){
//			Red_LED_On();
//			USART_Write(USART2, (uint8_t *)"LED is on\r\n\r\n", 15);
//		}
}

