/*
 * File:   main.c
 * Author: :C
 *
 * Created on June 19, 2022, 4:00 PM
 */


#include "config.h"
#include "teclado.h"

// Procedimientos

void Prender_Verde(){
    RC0 = 1;
}
void Apagar_Verde(){
    RC0 = 0;
}
void Prender_Rojo(){
    RC1 = 1;
}
void Apagar_Rojo(){
    RC1 = 0;
}
void pulsar_boton(){
    RC2=1;
    __delay_ms(100);
    RC2=1;
    __delay_ms(100);  
}
void alarma(){
    for(int a=0; a<=4; a++){
        RC2=1;
        __delay_ms(1000);
         RC2=0;
        __delay_ms(1000); 
        
    }
}
//Variables
int Try=0,True=0; //Intentos para digitar la clave correctamente
int X,XD,XC,XM=0; //Digitos de la Clave
int Clave, Tecla; //Leer la tecla que se digite
int Bandera = 0;
//Contraseña
int Password=1202;
//Main
int main()
{ 
  char Cadena[20];
  TRISD = 0x00;  //Salida LCD 
  TRISC = 0x00;  //Salida LED y BUCER
  TRISB = 0xF0; //4 menos significativos salidas, más entradas 
  PORTD = 0;
  PORTC = 0;
  PORTB = 0;
  
  Lcd_Init();
  Lcd_Clear();
  Lcd_Set_Cursor(1,4);
  Lcd_Write_String("Cerradura");
  Lcd_Set_Cursor(2,3);
  Lcd_Write_String("Electronica");
  Prender_Rojo();
   __delay_ms(1000);
   
   
  while((Try < 3) && (True == 0) ){//Contraseña Incorrecta
    Apagar_Verde();  
    
    //Ingreso de Contraseña 
      
    Tecla= Leer_tecla();// en teclado.c
    
      if((Tecla != 100) && (Tecla!=42) && (Tecla!=35) ){// Se digite algo (=!100)) y no sea un * o #
          if (Bandera==0){
              pulsar_boton();
              sprintf (Cadena, "Primer digito: %i", Tecla);//Concatenar, se guarda tecla en Cadena
               Lcd_Clear();
               Lcd_Set_Cursor(1,1);
               Lcd_Write_String(Cadena);
               __delay_ms(500);

               XM = Tecla * 1000;// Para que se muestre en orden
               Bandera ++;
               
           }

        else if (Bandera == 1){
               pulsar_boton();
               sprintf (Cadena, "Segundo digito %i", Tecla);//Concatenar, se guarda tecla en Cadena
               Lcd_Clear();
               Lcd_Set_Cursor(1,1);
               Lcd_Write_String(Cadena);
               __delay_ms(500);

               XC = Tecla * 100;// Para que se muestre en orden
               Bandera ++;
        }
        else if (Bandera == 2){
               pulsar_boton();
               sprintf (Cadena, "Tercer Digito %i", Tecla);//Concatenar, se guarda tecla en Cadena
               Lcd_Clear();
               Lcd_Set_Cursor(1,1);
               Lcd_Write_String(Cadena);
               __delay_ms(500);

               XD = Tecla * 10;// Para que se muestre en orden
               Bandera ++;
        }
        else if(Bandera == 3){
               pulsar_boton();
               sprintf (Cadena, "Cuarto digito %i", Tecla);//Concatenar, se guarda tecla en Cadena
               Lcd_Clear();
               Lcd_Set_Cursor(1,1);
               Lcd_Write_String(Cadena);
               __delay_ms(500);

               X = Tecla;// Para que se muestre en orden
               Bandera ++;
        }
    // Clave:
      Clave= X + XD + XC + XM;
    }
       if(Clave == Password){
           
       True = 1;
       Apagar_Rojo();
       Prender_Verde();
       Lcd_Clear();
       Lcd_Set_Cursor(1,4);
       Lcd_Write_String("Cerradura");
       Lcd_Set_Cursor(2,5);
       Lcd_Write_String("Abierta");
       __delay_ms(5000);
       }
       
       else if(Bandera ==4){
           Lcd_Clear();
           Lcd_Set_Cursor(1,6);
           Lcd_Write_String("Contraseña");
           Lcd_Set_Cursor(2,5);
           Lcd_Write_String("Incorrecta");
           __delay_ms(2000);
           Try ++;
           Bandera=0;
           
            if(Try==3){
             Lcd_Clear();
             Lcd_Set_Cursor(1,4);
             Lcd_Write_String("Bloqueada");
             __delay_ms(3000);
             True=3;//Reset
             __delay_ms(500);
             alarma();

            }
            else {
             Lcd_Clear();
             Lcd_Set_Cursor(1,4);
             Lcd_Write_String("Intente de nuevo");
             __delay_ms(1500); 
             Lcd_Clear();
             Lcd_Set_Cursor(1,5);
             Lcd_Write_String("Presione #");
             Tecla = Leer_tecla();
              __delay_ms(500); 

              while(Tecla!=35){
                  Tecla= Leer_tecla();
                  __delay_ms(500);
              }
             Lcd_Clear();
             Lcd_Set_Cursor(1,3);
             Lcd_Write_String("Ingrese clave");
             Lcd_Set_Cursor(2,4);
             Lcd_Write_String("Otra vez");
            }
       }
    } 
     
  return 0;
}
      
