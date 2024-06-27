/******************************************************************************
                 Design with Embedded Systems​
                  Spring 2022 - Final Project​

             Voice Command Controlled Automatic Door​
*******************************************************************************/

#include "mbed.h"
#include <string.h>
#include <stdio.h>
#include "Servo.h"
#define PERIOD    0.02
#define WIDTH    0.0015

//Initialize ports
Serial pc (USBTX, USBRX); // tx, rx
PwmOut servo(PTC3);
Serial bt(PTC17, PTC16);
char mit[10];
float period = PERIOD;
float width = WIDTH;
int main()
{  
    bt.baud(9600);
    pc.baud(9600);
    servo.period(PERIOD);
    while(1) 
    {
            bt.gets(mit,5);
            bt.printf("'%s' is recieved.\r\n",mit);
            pc.printf("'%s' is recieved.\r\n",mit);
            
            if(strstr(mit,"open")) 
            {
                width=0.0245;
                servo.write(width);
            pc.printf("door open!\n");  
            wait(0.25);
                     }      
            else if (strstr(mit,"lock"))
                       {
                 width=0.075;
                 servo.write(width);
             pc.printf("door close!\n");
                wait(0.25);
            }
          else 
           {
                  width=0.075; 
                  servo.write(width);
                pc.printf("Keep door close!\n");
               wait(0.25);
            }
       } //while loop close
} //main loop close
