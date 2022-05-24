/**
 * @file timer0.h
 * @brief Datoteka koja deklarise funkcije za upravljanje tajmerom 0
 * @author Ime Prezime
 * @date dd-mm-yyyy
 * @version 1.0
 */
#ifndef TIMER0_H_
#define TIMER0_H_

#include <avr/interrupt.h>

/**
 * timer0DelayMs - Funkcija koja implementira pauzu u broju milisekundi koji je prosledjen
 * kao parametar
 * @param delay_length - ulaz tipa uint32_t - Duzina pauze u milisekundama
 * @return Nema povratnu vrednost
 */
void timer0DelayMs(uint32_t delay_length);

/**
 * timer0Millis - Funkcija koja, na bezbedan nacin, vraca kao povratnu vrednost broj
 * milisekundi proteklih od pocetka merenja vremena
 * @return Broj milisekundi proteklih od pocetka merenja vremena
 */
uint32_t timer0Millis();

/**
 * timer0Init - Funkcija koja inicijalizuje timer 0 tako da pravi prekide
 * svake milisekunde
 * @return Nema povratnu vrednost
 */
void timer0Init();

#endif /* TIMER0_H_ */
