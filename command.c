#include "LED.h"
#include "UART.h"
#include <string.h>

int redflash = 0;
int greenflash = 0;
char rxByte;
uint8_t buffer[BufferSize];
int loopcounter = 0;
int counter = 0;

void parsecommand(char* cmd){
	if(strncmp(cmd, "RON", strlen(cmd))){
		Red_LED_On();
		redflash = 0;
	}
	else if(strncmp(cmd, "ROFF", strlen(cmd))){
		Red_LED_Off();
		redflash = 0;
	}
	else if(strncmp(cmd, "GON", strlen(cmd))){
		Green_LED_On();
		greenflash = 0;
	}
	else if(strncmp(cmd, "GOFF", strlen(cmd))){
		Green_LED_Off();
		greenflash = 0;
	}
	else if(strncmp(cmd, "RFLASH", strlen(cmd))){
		redflash = 1;
	}
	else if(strncmp(cmd, "GFLASH", strlen(cmd))){
		greenflash = 1;
	}
	else if(strncmp(cmd, "GFLASH", strlen(cmd))){
		greenflash = 0;
		redflash = 0;
	}
}
void readcommand(){
	rxByte = USART_Read(USART2); //Read byte
		if (rxByte != 0){
			if(rxByte == 015){ //If enter, check the command
				buffer[counter] = "\0";
				parsecommand(buffer);
			}
			else if (rxByte == 010){ //If backspace, remove the last character
				buffer = buffer[];
				//USART_Write(USART2, buffer, );
			}
			else{
			
			}
		}
}

//green is false, red is true
void flash(){
	if (redflash || greenflash){
			USART_Delay(1000);
			loopcounter++;
			if(loopcounter > 1000){
				loopcounter = 0;
				if(redflash)
					Red_LED_Toggle();
				if(greenflash)
					Green_LED_Toggle();
			}
		}
}

void commandloop(){
	while (1){
		readcommand();
		flash();
	}
}
