//definizione di tutte le funzioni getters usate nel codice per ottenere i dati inerenti a pokemon e mosse
#ifndef FUNZIONI_GETTERS_H
#define FUNZIONI_GETTERS_H

#include "librerie.h"
#include "pokemon.h"

char *getNomePokemon(int indexPokemon, struct Pokemon rosterPokemon[]);
int getVitaMax(int indexPokemon, struct Pokemon rosterPokemon[]);
int getVita(int indexPokemon, struct Pokemon rosterPokemon[]);
int getAttacco(int indexPokemon, struct Pokemon rosterPokemon[]);
int getDifesa(int indexPokemon, struct Pokemon rosterPokemon[]);
int getVelocita(int indexPokemon, struct Pokemon rosterPokemon[]);
char *getNomeMossa(int indexPokemon, int mossaSelezionata, struct Pokemon rosterPokemon[]);
int getPotenza(int indexPokemon, int mossaSelezionata, struct Pokemon rosterPokemon[]);
int getPrecisione(int indexPokemon, int mossaSelezionata, struct Pokemon rosterPokemon[]);

#endif //FUNZIONI_GETTERS_H