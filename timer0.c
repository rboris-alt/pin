/**
 * @file timer0.c
 * @brief Datoteka koja definise funkcije za upravljanje tajmerom 0
 * @author Ime Prezime
 * @date dd-mm-yyyy
 * @version 1.0
 */

#include "timer0.h"

/// Promenljiva koja skladisti broj milisekundi proteklih od pokretanja aplikacije
volatile uint32_t ms = 0;

void timer0DelayMs(uint32_t delay_length)
{
	// trenutak pocevsi od kog se racuna pauza
	uint32_t t0 = timer0Millis();
	// implementacija pauze
	while (timer0Millis() - t0 < delay_length)
		;
}

/***********************************************************/

uint32_t timer0Millis()
{
	uint32_t tmp;
	cli(); 			// Zabrana prekida
	tmp = ms; 		// Ocitavanje vremena
	sei(); 			// Dozvola prekida

	return tmp;
}

/***********************************************************/

void timer0Init()
{
	TCCR0A = 0x02; // tajmer 0: CTC mod

	// Provera frekvencije takta prilikom kompilacije
	#if F_CPU > 20000000
	#error "Frekvencija takta mora biti manja od 20 MHz!"
	#endif

	// Inicijalizacija promenljivih za preskaler i periodu tajmera 0
	uint32_t n = F_CPU / 1000;
	uint8_t clksel = 1;

	// Odredjivanje vrednosti preskalera i periode tajmera 0
	while (n > 255)
	{
		n /= 8;
		clksel++;
	}

	TCCR0B = clksel; 					// tajmer 0: Podesavanje preskalera
	OCR0A = (uint8_t)(n & 0xff) - 1;	// tajmer 0: Podesavanje periode
	TIMSK0 = 0x02;						// tajmer 0: Dozvola prekida
	sei();								// Globalna dozvola prekida
}

/***********************************************************/

/**
 * ISR - prekidna rutina tajmera 0 u modu CTC
 */
ISR(TIMER0_COMPA_vect)
{
	// Inkrementovanje broja milisekundi koje su prosle od pokretanja aplikacije
	ms++;
}
