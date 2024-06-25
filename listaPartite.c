#include "listaPartite.h"

void inserisciPartita(struct listaPartite **testa, int indexMioPokemon, int vitaMioPokemon, int indexPokemonAvversario, int vitaPokemonAvversario, struct Pokemon rosterPokemon[]){
    //Crea nuovo nodo
    struct listaPartite *nuovoNodo = malloc(sizeof(struct listaPartite));

    //Controllo quale pokemon ha vinto e quale ha perso
    int indexPokemonSconfitto = 0;
    int indexPokemonVincitore = 0;
    int vitaPokemonVincitore = 0;
    int vitaPokemonSconfitto = 0;
    bool haVintoGiocatore = 0;
    if(getVita(indexMioPokemon, rosterPokemon) <= 0){
        indexPokemonSconfitto = indexMioPokemon;
        indexPokemonVincitore = indexPokemonAvversario;
        vitaPokemonVincitore = vitaPokemonAvversario;
        vitaPokemonSconfitto = vitaMioPokemon;
        haVintoGiocatore = 0;
    }else{
        indexPokemonSconfitto = indexPokemonAvversario;
        indexPokemonVincitore = indexMioPokemon;
        vitaPokemonVincitore = vitaMioPokemon;
        vitaPokemonSconfitto = vitaPokemonAvversario;
        haVintoGiocatore = 1;
    }

    //Assegno i dati
    nuovoNodo->indexPokemonSconfitto = indexPokemonSconfitto;
    nuovoNodo->indexPokemonVincitore = indexPokemonVincitore;
    nuovoNodo->vitaPokemonVincitore = vitaPokemonVincitore;
    nuovoNodo->vitaPokemonSconfitto = vitaPokemonSconfitto;
    nuovoNodo->haVintoGiocatore = haVintoGiocatore;

    //Collego il nuovo nodo alla testa
    nuovoNodo->next = *testa;
    *testa = nuovoNodo;
}

//stamperà le partite, ma lo farà dall'ultima giocata alla prima giocata perchè la lista ha l'inserimento in testa
void stampaPartite(struct listaPartite *testa, struct Pokemon rosterPokemon[]){
    struct listaPartite *nodoCorrente = testa;
    // Attraversa la lista
    while(nodoCorrente != NULL){
        printf("-------------------------------------------------\n");
        printf("Ha vinto il giocatore: %s\n", nodoCorrente->haVintoGiocatore ? "Si" : "No"); // ? restituisce "Si" se true mentre restituisce "No" se false
        printf("Pokemon vincitore: %s\n", getNomePokemon(nodoCorrente->indexPokemonVincitore, rosterPokemon));
        printf("Vita Pokemon vincitore: %d\n", nodoCorrente->vitaPokemonVincitore);
        printf("Pokemon sconfitto: %s\n", getNomePokemon(nodoCorrente->indexPokemonSconfitto, rosterPokemon));
        printf("Vita Pokemon sconfitto: %d\n", nodoCorrente->vitaPokemonSconfitto);
        printf("-------------------------------------------------\n");
        
        // Passa al prossimo nodo
        nodoCorrente = nodoCorrente->next;
    }
}