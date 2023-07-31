#include <mega164a.h>
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



char real_pw[4] , try_pw[4];


bool compare(char s1[4] , char s2[4]) 
{
    int i;
    for(i = 0; i < 4 ; i++)
    {
        if(s1[i] != s2[i])
        {
            return false;
        }
    }

    return true;
}


int read_key1(int indx)
{
    
    
    int keycode_c = PINC;
    int tmp;
    int keycode_r;
    int keycode;
    lcd_gotoxy(indx + 7,0);
    DDRA ^= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
    DDRC ^= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);    
    
    PORTC ^= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
    PORTA ^= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);   
    
    delay_ms(5);
    
    tmp = PINA;
    keycode_r = tmp << 4;
    
    keycode = keycode_r | keycode_c;
     
    //ROW 1
    if(keycode == 0b11100111)
    {
        delay_ms(200); //debounce  
        lcd_putchar('*'); 
        real_pw[indx] = '1'; 
        indx++;    
    } 
    
    if(keycode == 0b11101011)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] = '2'; 
        indx++; 
    }
    
    if(keycode == 0b11101101)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] =  '3';
        indx++;  
    }
    
    if(keycode == 0b11101110)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] =  'A';
        indx++;  
    }
    
    //ROW 2
    if(keycode == 0b11010111)
    {
        delay_ms(200); //debounce  
        lcd_putchar('*'); 
        real_pw[indx] =  '4';
        indx++;      
    } 
    
    if(keycode == 0b11011011)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] =  '5';
        indx++;  
    }
    
    if(keycode == 0b11011101)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] =  '6';
        indx++;  
    }
    
    if(keycode == 0b11011110)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] =  'B';
        indx++;  
    }
    
    //ROW 3
    if(keycode == 0b10110111)
    {
        delay_ms(200); //debounce  
        lcd_putchar('*'); 
        real_pw[indx] =  '7';
        indx++;      
    } 
    
    if(keycode == 0b10111011)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] =  '8';
        indx++;
    }
    
    if(keycode == 0b10111101)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] =  '9';  
        indx++;  
    }
    
    if(keycode == 0b10111110)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] =  'C';
        indx++;  
    }
    
    //ROW 4
    if(keycode == 0b01110111)
    {
        delay_ms(200); //debounce  
        lcd_putchar('*'); 
        real_pw[indx] =  '*';         
        indx++;  
    } 
    
    if(keycode == 0b01111011)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] =  '0';
        indx++;  
    }
    
    if(keycode == 0b01111101)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] =  '#';
        indx++;  
    }
    
    if(keycode == 0b01111110)
    {
        delay_ms(200);
        lcd_putchar('*');
        real_pw[indx] =  'D';
        indx++;  
    }
    return indx;
    
        
}

int read_key2(int indx)
{
    int keycode_c = PINC;
    int tmp;
    int keycode_r;
    int keycode;
    lcd_gotoxy(indx + 9, 1);
    DDRA ^= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
    DDRC ^= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);    
    
    PORTC ^= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
    PORTA ^= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);   
    
    delay_ms(5);
    
    tmp = PINA;
    keycode_r = tmp << 4;
    
    keycode = keycode_r | keycode_c;
     
    //ROW 1
    if(keycode == 0b11100111)
    {
        delay_ms(200); //debounce  
        lcd_putchar('1'); 
        try_pw[indx] = '1'; 
        indx++;    
    } 
    
    if(keycode == 0b11101011)
    {
        delay_ms(200);
        lcd_putchar('2');
        try_pw[indx] = '2'; 
        indx++; 
    }
    
    if(keycode == 0b11101101)
    {
        delay_ms(200);
        lcd_putchar('3');
        try_pw[indx] =  '3';
        indx++;  
    }
    
    if(keycode == 0b11101110)
    {
        delay_ms(200);
        lcd_putchar('A');
        try_pw[indx] =  'A';
        indx++;  
    }
    
    //ROW 2
    if(keycode == 0b11010111)
    {
        delay_ms(200); //debounce  
        lcd_putchar('4'); 
        try_pw[indx] =  '4';
        indx++;      
    } 
    
    if(keycode == 0b11011011)
    {
        delay_ms(200);
        lcd_putchar('5');
        try_pw[indx] =  '5';
        indx++;  
    }
    
    if(keycode == 0b11011101)
    {
        delay_ms(200);
        lcd_putchar('6');
        try_pw[indx] =  '6';
        indx++;  
    }
    
    if(keycode == 0b11011110)
    {
        delay_ms(200);
        lcd_putchar('B');
        try_pw[indx] =  'B';
        indx++;  
    }
    
    //ROW 3
    if(keycode == 0b10110111)
    {
        delay_ms(200); //debounce  
        lcd_putchar('7'); 
        try_pw[indx] =  '7';
        indx++;      
    } 
    
    if(keycode == 0b10111011)
    {
        delay_ms(200);
        lcd_putchar('8');
        try_pw[indx] =  '8';
        indx++;
    }
    
    if(keycode == 0b10111101)
    {
        delay_ms(200);
        lcd_putchar('9');
        try_pw[indx] =  '9';  
        indx++;  
    }
    
    if(keycode == 0b10111110)
    {
        delay_ms(200);
        lcd_putchar('C');
        try_pw[indx] =  'C';
        indx++;  
    }
    
    //ROW 4
    if(keycode == 0b01110111)
    {
        delay_ms(200); //debounce  
        lcd_putchar('*'); 
        try_pw[indx] =  '*';         
        indx++;  
    } 
    
    if(keycode == 0b01111011)
    {
        delay_ms(200);
        lcd_putchar('0');
        try_pw[indx] =  '0';
        indx++;  
    }
    
    if(keycode == 0b01111101)
    {
        delay_ms(200);
        lcd_putchar('#');
        try_pw[indx] =  '#';
        indx++;  
    }
    
    if(keycode == 0b01111110)
    {
        delay_ms(200);
        lcd_putchar('D');
        try_pw[indx] =  'D';
        indx++;  
    }
    return indx;
    
        
}


  

    
    


void main(void)
{   
    int i;
    DDRA = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
    DDRC = (0 << 0) | (0 << 1) | (0 << 2) | (0 << 3);
    PORTA = (0 << 0) | (0 << 1) | (0 << 2) | (0 << 3);
    PORTC = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);  
    
    lcd_init(16);

    while (1)
          {     
                int tries = 3;
                char buffer[2];
                lcd_clear();
                lcd_gotoxy(0,0);
                lcd_puts("New pw:"); 
                i = 0;
                while(i < 4)
                {
                    i = read_key1(i);
                }                  
                delay_ms(1000);
                
                
                try: //Guessing the pw
                i = 0;
                lcd_gotoxy(0,1);
                lcd_puts("Enter pw:");
                while(i < 4)
                {
                    i = read_key2(i);
                }
                
                lcd_clear();
                delay_ms(1000);
                
                if(compare(try_pw , real_pw) == true) // right pw 
                {
                    lcd_puts("ENTER!");
                    break;
                }
                
                else if(tries > 1) //wrong pw | still have tries
                {
                    tries --;
                    lcd_gotoxy(0,0);
                    lcd_puts("WRONG!");
                    lcd_gotoxy(0,1);
                    itoa(tries,buffer);
                    lcd_puts(buffer);
                    lcd_puts("tries left");
                    delay_ms(3000);
                    lcd_clear();
                    goto try; 
                }
                
                else //wrong pw || 0 tries left
                {
                    lcd_puts("LOCKDOWN!");
                    break;
                
                }
                
          }     
}
