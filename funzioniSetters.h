#ifndef FUNZIONISETTERS_H
#define FUNZIONISETTERS_H

#include "librerie.h"
#include "pokemon.h"

//funzione per cambiare il valore della vita massima, non è previsto il suo utilizzo
void setVitaMax(int nuovaVitaMax, int indexPokemon, struct Pokemon rosterPokemon[]);

//funzione per cambiare il valore della vita
void setVita(int nuovaVita, int indexPokemon, struct Pokemon rosterPokemon[]);

//funnzioni non usate perchè nel codice è previsto solo che venga modificata la vita
void setAttacco(int nuovoAttacco, int indexPokemon, struct Pokemon rosterPokemon[]);
void setDifesa(int nuovaDifesa, int indexPokemon, struct Pokemon rosterPokemon[]);
void setVelocita(int nuovaVelocita, int indexPokemon, struct Pokemon rosterPokemon[]);

#endif //FUNZIONISETTERS_H