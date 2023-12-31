/*
 * File:   main.c
 * Author: Jose Eduardo Sanchez
 *
 * Created on 2 de febrero de 2023, 08:09 AM
 */


#include <xc.h>
#include "lcd2.h"
#include "percep.h"

int hardlim(float value){
    
    int n;
    if (value>0){
        
        n = 1;
    }
    else {
        
        n = 0;
    }
    return n;
}


void main() {
    
    ADCON1 = 0B00000111; // DESABILITAMOS EL ADC
    TRISB = 0x00;   // CONFIGURAMOS LOS PINES DIGITALES DE PUERTO B SALIDAS
    TRISC = 0xFF;   // CONFIGURACIONES LOS PINES DIGITALES 
    
    lcd_init();
    lcd_clear();
    lcd_gotoxy(1,1);
    lcd_putc("Este numero es: ");
    
    float W[7] = {-1.82756658, 1.0254548, -2.19729144, -1.32409806, 6.09865493, 2.08681678, 1.71551054}
    float b = -1.81400596;
    
    while(1){
        
        float sum = 0;
        if(PORTCbits.RC0 == 1){
            
            sum = sum + W[1];
        }
        
        if (PORTCbits.RC1 == 1) {
            
            sum = sum + W[2]
        }
        
        if(PORTCbits.RC2 == 1){
            
            sum = sum + W[2];
        }
        
        if (PORTCbits.RC3 == 1) {
            
            sum = sum + W[3]
        }
        
        if(PORTCbits.RC4 == 1){
            
            sum = sum + W[4];
        }
        
        if (PORTCbits.RC5 == 1) {
            
            sum = sum + W[5]
        }
        
        if(PORTCbits.RC6 == 1){
            
            sum = sum + W[16];
        }
        
        if (PORTCbits.RC7 == 1) {
            
            sum = sum + W[7]
        }
        
        perceptron = hardlim(sum+b);
        
        if (perceptron == 1){
            
            lcd_gotxy(2,1);
            lcd_putc("MAyor a 5");
        }
        else {
            
            lcd_gotoxy(2,1);
            lcd_putc("Menor a 5");
        }
    }
            
    
}
