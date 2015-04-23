/**
* @file		variables.h
* @author	Manuel Caballero
* @date 	25/2/2015
* @brief 	Variables del sistema.
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
#include <stdint.h>

// CONFIG
#pragma config FOSC = XT        /**<  Oscillator Selection bits (XT oscillator)  */
#pragma config WDTE = OFF       /**<  Watchdog Timer (WDT disabled)  */
#pragma config PWRTE = OFF      /**<  Power-up Timer Enable bit (Power-up Timer is disabled)  */
#pragma config CP = OFF         /**<  Code Protection bit (Code protection disabled)  */



/**
 *  \brief     Variables Globales
 *  \details
 * 		- var100ms:     Variable contador encargada de generar un retardo de 0.5 s.
 *                              Esta variable se usa en el servicio de interrupción del
 *                              Timer0.
 */
uint8_t var100ms    =   0;