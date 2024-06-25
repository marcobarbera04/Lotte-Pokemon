#include "funzioniSetters.h"

//funzione che setta la vita massima, il suo utilizzo non è previsto nel codice
void setVitaMax(int nuovaVitaMax, int indexPokemon, struct Pokemon rosterPokemon[]){
    rosterPokemon[indexPokemon].vita = nuovaVitaMax;
}

//funzione che setta la vita
void setVita(int nuovaVita, int indexPokemon, struct Pokemon rosterPokemon[]){
    rosterPokemon[indexPokemon].vita = nuovaVita;
}

//funnzioni non usate perchè nel codice è previsto solo che venga modificata la vita
void setAttacco(int nuovoAttacco, int indexPokemon, struct Pokemon rosterPokemon[]){
    rosterPokemon[indexPokemon].attacco = nuovoAttacco;
}

void setDifesa(int nuovaDifesa, int indexPokemon, struct Pokemon rosterPokemon[]){
    rosterPokemon[indexPokemon].difesa = nuovaDifesa;
}

void setVelocita(int nuovaVelocita, int indexPokemon, struct Pokemon rosterPokemon[]){
    rosterPokemon[indexPokemon].velocita = nuovaVelocita;
}