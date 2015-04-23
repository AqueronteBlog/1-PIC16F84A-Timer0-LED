/**
* @file		functions.c
* @author	Manuel Caballero
* @date 	25/2/2015
* @brief 	Funciones del sistema.
* \copyright
* 	AqueronteBlog@gmail.com
*
* Este archivo es propiedad intelectual del blog Aqueronte,
* cuya direccion web, es la siguiente:
*
* 	http://unbarquero.blogspot.com/
*
* Se permite cualquier modificacion del archivo siempre y cuando
* se mantenga la autoria del autor.
*/
#include "functions.h"


/**
 *  \brief     void conf_IO (void)
 *  \details   Configura los pines del MCU a usar en este proyecto.
 *                  - Puerto B: LED.
 *  			- RB3:	Salida.	  LED  ( RESISTOR 220 Ohms en serie)
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      25/2/2015
 */
void conf_IO (void)
{
    TRISBbits.TRISB3    =   0;

    PORTBbits.RB3       =   0;      // Reset: RB3 = 0
}



/**
 *  \brief     void conf_TimerA (void)
 *  \details   Configura el Timer0 como 8-bit timer.
 *
 *             El Timer0 será el encargado de cambiar el estado del LED cada
 *             aproximadamente 0.5 s por interrupción.
 *
 *             Teniendo en cuenta la expresión del Timer0:
 *
 *                  Interrupt_Timer0 = 4·( 1/f_Timer0_OSC )·( 256 - TMR0)·Prescaler
 *
 *            Tenemos que:
 *
 *                  0.5s = 4·( 1/4MHz )·( 256 - TMR0)·256
 *
 *                  TMR0 = 256 - 1953.125 = - 1697.125
 *
 *            Con la frecuencia del Timer0 actual, no se puede llegar a dicha
 *            cuenta, por lo que necesitaremos una variable que haga de cuenta.
 *
 *            Asi que la misión es configurar la interrupción del Timer0 a un
 *            valor conocido y usar la variable para generar el retardo deseado.
 *
 *            Vamos a configurar el Timer0 para que genere interrupción cada
 *            aproximadamente, 50ms.
 *
 *            Por lo tanto:
 *
 *                  50ms = 4·( 1/4MHz )·( 256 - TMR0)·256
 *
 *                  TMR0 = 256 - 195.3125 = 60.6875 ? 61  ( 0x3D )
 *
 *  \pre       El reloj externo debe ser 4 MHz.
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      25/2/2015
 */
void conf_TA0 (void)
{
    OPTION_REG      &=   0xD7;
    TMR0             =   0x3D;      

    INTCONbits.T0IE  =   1;
    INTCONbits.T0IF  =   0;     // Reset flag
}