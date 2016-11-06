/*
 * Testing programme to know the CPU "endianness":
 * - little endian: stores firstly in memory the less significant byte
 * - big endian: stores firstly in memory the more significant byte
 * Author: Carlos Prieto-Saiz <carlosprieto@gmail.com>
 * Date: 03-Nov-16
 */

#include <stdint.h>
#include <stdio.h>


union test {
		
	uint16_t word;

	struct {
		uint8_t lsb;		// less significant byte
		uint8_t msb;		// more significant byte
	} byte;
 
} TEST;
		 

int main(){

	union test * prueba = &TEST;	// Creation of a pointer in the stack to the general variable space

	prueba->word=0xAF8C;	   	// Setting a 16 bit value to "word" 

	char* arqui[] = {'\0'};    	// Creation and initialization of the string for the final sentence

	printf("\n16 bit word: %x\n", prueba->word);	// Showing the value of the "word" component

	printf("More significant byte: %x\n", prueba->byte.msb);	// Showing the more significant byte (half left of the value)
   
	printf("Less significant byte: %x\n\n", prueba->byte.lsb);	// Showing the less significant byte (half right of the value)

	// Now we will show the memory addresses of the "msb" and "lsb" bytes through the pointers

	printf("Show the bytes in an memory way: \n\tMore significant byte = %x\n\tLess significat byte  = %x\n\n", &prueba->byte.msb, &prueba->byte.lsb); 

	if ( &prueba->byte.msb > &prueba->byte.lsb ) { *arqui = "LITTLE ENDIAN";	// Comparition to check the order in which the CPU allocates the memory
	} else { *arqui = "BIG ENDIAN";}


	printf("Your architecture is: %s\n\n", *arqui);
}  
