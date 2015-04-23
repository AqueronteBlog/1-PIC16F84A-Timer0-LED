/**
* @file		main.c
* @author	Manuel Caballero
* @date 	25/2/2015
* @brief 	Archivo principal.
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
#include <xc.h>
#include <stdint.h>
#include "variables.h"
#include "functions.h"
#include "interrupts.h"

/**
 *  \brief     void main( void )
 *  \details   Este programa consiste en hacer parpadear un LED cada,
 *             aproximadamente 0.5 s.
 *
 *             Para tal fin, se usará el Timer 0.
 *
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      25/2/2015
 *  \pre       Este firmware está probado para el PIC16F84A.
 *  \pre       El LED estará conectado al pin RB3
 *             ( un resistor de 220 Ohms en serie ).
 *  \pre       El reloj externo es de 4 MHz.
 *
 *  \pre       MPLAB X IDE v2.30.
 *  \pre       Compiler XC8 v1.33.
 */
void main( void ) {

    conf_IO     ();     // Configura Pins
    conf_TA0    ();     // Configura Timer0

    ei  ();             // enable interrupts
    
    while ( 1 );        // Espera a que se produzca interrupción Timer0
}

