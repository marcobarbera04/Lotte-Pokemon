#include "librerie.h"
#include "pokemon.h"
#include "listaPartite.h"
#include "funzioniGetters.h"
#include "funzioniSetters.h"
#include "funzioni.h"

int main(){
    generaSeed();
    system("cls");
    struct Pokemon rosterPokemon[ROSTER_MAX]; //array di strutture, le strutture contengono i dati dei pokemon

    //passaggio di riferimento con & per modificare i dati originali piuttosto che passare per valore
    istanziaPokemon(&rosterPokemon[0], "Pickachu", 274/*vitaMax*/,274/*vita*/, 229/*attacco*/, 196/*difesa*/, 306/*velocita*/,
                    "Tuonoshock", 40, 100,  // danno, precisione
                    "Tuono", 110, 70);      // danno, precisione

    istanziaPokemon(&rosterPokemon[1], "Bulbasaur", 294/*vitaMax*/,294/*vita*/, 216/*attacco*/, 216/*difesa*/, 207/*velocita*/,
                    "Frustata", 45, 100,    // danno, precisione 
                    "Vigorcolpo", 120, 85); // danno, precisione
    
    istanziaPokemon(&rosterPokemon[2], "Charmander", 282/*vitaMax*/,282/*vita*/, 223/*attacco*/, 203/*difesa*/, 251/*velocita*/,
                    "Braciere", 40, 100,    // danno, precisione
                    "Marchiatura", 100, 50);// danno, precisione
    
    istanziaPokemon(&rosterPokemon[3], "Squirtle", 292/*vitaMax*/,292/*vita*/, 214/*attacco*/, 251/*difesa*/, 203/*velocita*/,
                    "Pistolacqua", 40, 100, // danno, precisione
                    "Idropompa",110, 80);   // danno, precisione

    printf("-------------------------------------------------\n");
    printf("Gioco di lotte pokemon\nil gioco scegliera' il tuo pokemon e quello\navversario, avrai 2 mosse a disposizione:\nla prima e' molto precisa ma poco potente\nla seconda e' molto potente ma poco precisa\n");
    printf("-------------------------------------------------\n");
    printf("[Premi INVIO]\n");
    getchar();
    system("cls");

    struct listaPartite *testa = NULL;

    bool esciProgramma = 0; 
    while(!esciProgramma){
        int indexMioPokemon = scegliMioPokemon();
        int indexPokemonAvversario = scegliPokemonAvversario(indexMioPokemon);

        printf("-------------------------------------------------\n");
        printf("Il tuo pokemon e' %s\n", getNomePokemon(indexMioPokemon, rosterPokemon));
        printf("Il tuo avversario e' %s\n", getNomePokemon(indexPokemonAvversario, rosterPokemon));
        printf("-------------------------------------------------\n");
        printf("[Premi INVIO]");
        getchar();

        //la funzione lotta contiene tutte le funzioni che permettono lo svolgimento della partita come attacco e attaccoNemico
        lotta(indexMioPokemon, indexPokemonAvversario, rosterPokemon, &testa);

        //finita la lotta resetta la vita dei pokemon a quella originale
        resetVita(rosterPokemon);
        
        char scelta = '\0'; //come stringa per facilitare l'input
        do{
            printf("Vuoi continuare?[y/n]: ");
            scelta = getchar();
            if(scelta != 'y' && scelta != 'n'){
                printf("[ERRORE] Inserisci un carattere tra y o n\n");
            }
            while ((getchar()) != '\n'); // svuota il buffer di input
        }while(scelta != 'y' && scelta != 'n');
        switch (scelta)
        {
        case 'y':
            break;
        case 'n':
            esciProgramma = 1; //cambia il flag che farà uscire dal while e finirà il programma
            break;
        default:
            break;
        }
        system("cls");
    }

    //uscendo dal ciclo while che avvia una nuova partita a ogni iterazione, stampo i risultati delle partite
    stampaPartite(testa, rosterPokemon);
    printf("[Premi INVIO per chiudere il programma]");
    getchar();

    return 0;
}