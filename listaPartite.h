#ifndef LISTAPARTITE_H
#define LISTAPARTITE_H

#include "librerie.h"
#include "funzioniGetters.h"
#include "pokemon.h"

//questa lista serve a conservare i dati di tutte le partite giocate
struct listaPartite{
    bool haVintoGiocatore;
    int indexPokemonVincitore;
    int indexPokemonSconfitto;
    int vitaPokemonVincitore;
    int vitaPokemonSconfitto;
    struct listaPartite *next;
};

//funzione per inserire nodo nella lista
void inserisciPartita(struct listaPartite **testa, int indexPokemon1, int vitaPokemon1, int indexPokemon2, int vitaPokemon2, struct Pokemon rosterPokemon[]);
//funzione per stampare tutti i nodi della lista
void stampaPartite(struct listaPartite *testa, struct Pokemon rosterPokemon[]);

#endif //LISTAPARTITE_H