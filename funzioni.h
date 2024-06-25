//definizione di tutte le funzioni principali utili allo svolgimento del programma
#ifndef FUNZIONI_H
#define FUNZIONI_H

#include "librerie.h"
#include "pokemon.h"
#include "funzioniGetters.h"
#include "funzioniSetters.h"
#include "listaPartite.h"

void generaSeed();

//struct Pokemon *pokemon puntatore ad una struttura di tipo Pokemon
void istanziaPokemon(struct Pokemon *pokemon, char *nome, int vitaMax,int vita, int attacco, int difesa, int velocita,
                     char *mossa1, int potenza1, int precisione1,
                     char *mossa2, int potenza2, int precisione2);

int calcoloDanno(int indexPokemonAttaccante, int indexPokemonAttaccato, int indexMossa,struct Pokemon rosterPokemon[]);

int scegliMioPokemon();

int scegliPokemonAvversario(int mioPokemon);

int pokemonPiuVeloce(int indexMioPokemon, int indexPokemonAvversario, struct Pokemon rosterPokemon[]);

bool haColpito(int precisioneMossa);

void attacco(int indexMioPokemon, int indexPokemonAvversario, struct Pokemon rosterPokemon[], int mossaSelezionata);

void attaccoNemico(int indexMioPokemon, int indexPokemonAvversario, struct Pokemon rosterPokemon[]);

void lotta(int indexMioPokemon, int indexPokemonAvversario, struct Pokemon rosterPokemon[], struct listaPartite **testa);

void resetVita(struct Pokemon rosterPokemon[]);

#endif //FUNZIONI_H