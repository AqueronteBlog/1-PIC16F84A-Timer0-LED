/**
* @file		interrupts.c
* @author	Manuel Caballero
* @date 	25/2/2015
* @brief 	Interrupciones del sistema.
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
#include "interrupts.h"


/**
 *  \brief     void ISR (void) interrupt service routine
 *  \details   Subrutina de interrupción. El Timer0 se debe desbordar cada,
 *             aproximadamente 50 ms, generando interrupción.
 *
 *             En caso de que se transcurra 0.5 s, se cambiará el estado del LED.
 *
 *             El flag de interrupción del Timer0 debe ser puesto a cero por
 *             software.
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      25/2/2015
 */
void interrupt ISR ( void )
{
    // Comprueba si la interrupción es por Timer0
    if(INTCONbits.T0IF == 1)
    {
        if ( var100ms == 10 )                   // ¿Han pasado 0.5s?
        {
            PORTBbits.RB3 = ~PORTBbits.RB3;     // Cambia estado del LED
            var100ms      =  0;                 // Reset variable
        }
        else
            var100ms++;                         // No se cambia estado de LED hasta 0.5s

        INTCONbits.T0IF = 0;                    // Reset flag
    }
}