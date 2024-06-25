//definizione delle strutture che contengono i pokemon e le loro mosse
#ifndef POKEMON_H
#define POKEMON_H

#define ROSTER_MAX 4 //numero di pokemon nel roster(deve corrispondere al numero di quelli istanziati)

struct Mossa{
    char nomeMossa[16];
    int potenzaMossa;
    int precisioneMossa;
};
struct Pokemon{
    char nomePokemon[32];
    int vitaMax;
    int vita;
    int attacco;
    int difesa;
    int velocita;
    struct Mossa mosse[2]; //array che contiene 2 strutture di tipo Mossa
};

#endif //POKEMON_H