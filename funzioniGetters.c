//implementazione di tutte le funzioni getters
#include "funzioniGetters.h"

char *getNomePokemon(int indexPokemon, struct Pokemon rosterPokemon[]){
    return rosterPokemon[indexPokemon].nomePokemon;
}

int getVitaMax(int indexPokemon, struct Pokemon rosterPokemon[]){
    return rosterPokemon[indexPokemon].vitaMax;
}

int getVita(int indexPokemon, struct Pokemon rosterPokemon[]){
    return rosterPokemon[indexPokemon].vita;
}

int getAttacco(int indexPokemon, struct Pokemon rosterPokemon[]){
    return rosterPokemon[indexPokemon].attacco;
}

int getDifesa(int indexPokemon, struct Pokemon rosterPokemon[]){
    return rosterPokemon[indexPokemon].difesa;
}

int getVelocita(int indexPokemon, struct Pokemon rosterPokemon[]){
    return rosterPokemon[indexPokemon].velocita;
}

char *getNomeMossa(int indexPokemon, int mossaSelezionata, struct Pokemon rosterPokemon[]){
    return rosterPokemon[indexPokemon].mosse[mossaSelezionata].nomeMossa;
}

int getPotenza(int indexPokemon, int mossaSelezionata, struct Pokemon rosterPokemon[]){
    return rosterPokemon[indexPokemon].mosse[mossaSelezionata].potenzaMossa;
}

int getPrecisione(int indexPokemon, int mossaSelezionata, struct Pokemon rosterPokemon[]){
    return rosterPokemon[indexPokemon].mosse[mossaSelezionata].precisioneMossa;
}