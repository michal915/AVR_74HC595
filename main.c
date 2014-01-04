/* Shif register 74HC595
 *
 *
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/iom2560.h>
#include <util/delay.h>

#define SCK PB1 	//pin 52 - 11 SHCP - CLK
#define MOSI PB2	//pin 51 - 14 DS - Serial Data
#define LT PB0 		//pin 53 - 12 STCP - Latch Clock

#define LATCH_ON PORTB |= (1<<PB0)
#define LATCH_OFF PORTB &= ~(1<<PB0)

void InitSpi(void);
void SendSpi(uint8_t bajt);

int main()  {

	InitSpi();

	SendSpi(0xF0);



	while(1)  {
		/*uint8_t data = 1;

		while(data)	{
			SendSpi(data);
			_delay_ms(100);

			data <<= 1;
		}

		data = 0x80;

		while(data)	{
			SendSpi(data);
			_delay_ms(50);

			data >>=1;
		}
*/


	}
}

void InitSpi(void)	{

	DDRB |= (1<<SCK) | (1<<MOSI) | (1<<LT);
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR1);
}


void SendSpi(uint8_t bajt)	{

	SPDR = bajt;
	while( !(SPSR & (1<<SPIF)) );

	LATCH_ON;
	LATCH_OFF;
}
