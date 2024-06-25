//implementazione di tutte le funzioni principali utili allo svolgimento del programma
#include "funzioni.h"

//funzione che genera un seed tramite l'ora attuale, servirà a generare numeri random
void generaSeed(){
    srand(time(NULL));
}

//funzione per istanziare una "istanza" della struttura di tipo Pokemon
void istanziaPokemon(struct Pokemon *pokemon, char *nome, int vitaMax,int vita, int attacco, int difesa, int velocita,
                     char *mossa1, int potenza1, int precisione1,
                     char *mossa2, int potenza2, int precisione2){
    //istanziare dati pokemon
    strcpy(pokemon->nomePokemon, nome);
    pokemon->vitaMax = vita;
    pokemon->vita = vita;
    pokemon->attacco = attacco;
    pokemon->difesa = difesa;
    pokemon->velocita = velocita;
    
    //istanziare mossa 1(indice 0)
    strcpy(pokemon->mosse[0].nomeMossa, mossa1);
    pokemon->mosse[0].potenzaMossa = potenza1;
    pokemon->mosse[0].precisioneMossa = precisione1;
    
    //istanziare mossa 2(indice 1)
    strcpy(pokemon->mosse[1].nomeMossa, mossa2);
    pokemon->mosse[1].potenzaMossa = potenza2;
    pokemon->mosse[1].precisioneMossa = precisione2;
}

//funzione che calcola il danno tramite formula: (attacco * potenza)/difesa
int calcoloDanno(int indexPokemonAttaccante, int indexPokemonAttaccato, int indexMossa,struct Pokemon rosterPokemon[]){
    int attacco = getAttacco(indexPokemonAttaccante, rosterPokemon);
    int difesa = getDifesa(indexPokemonAttaccato, rosterPokemon);
    int potenzaMossa = getPotenza(indexPokemonAttaccante, indexMossa, rosterPokemon);
    int danno = (attacco * potenzaMossa)/difesa;
    return danno;
}

//funzione che sceglie il pokemon del giocatore casualmente fra uno di quelli presenti nel roster
int scegliMioPokemon(){
    int indexPokemon = rand() % ROSTER_MAX;
    return indexPokemon;
}

//funzione che sceglie il pokemon avversario casualmente fra uno di quelli presenti nel roster escluso quello del giocatore
int scegliPokemonAvversario(int mioPokemon){
    int indexPokemonAvversario = rand() % ROSTER_MAX;
    while(indexPokemonAvversario == mioPokemon){
        indexPokemonAvversario = rand() % ROSTER_MAX;
    }
    return indexPokemonAvversario;
}

//funzione che restituisce l'indice del pokemon con una velocità maggiore, servirà a determinare nella funzione lotta() chi attaccherà per primo
int pokemonPiuVeloce(int indexMioPokemon, int indexPokemonAvversario, struct Pokemon rosterPokemon[]){
    int velocitaMia = getVelocita(indexMioPokemon, rosterPokemon);
    int velocitaAvversario = getVelocita(indexPokemonAvversario, rosterPokemon);
    if(velocitaMia >= velocitaAvversario){
        return indexMioPokemon;
    }else
    return indexPokemonAvversario;
}

//funzione che restituirà vero o falso se una mossa andrà a segno, tramite un calcolo che generà un numero da 0 a 100 e se il numero generato è più basso della precisione andrà a segno
bool haColpito(int precisioneMossa){
    int numeroGenerato = rand() % 101;
    if(numeroGenerato <= precisioneMossa){
        return 1;
    }else
    return 0;
}

//funzione che permette al giocatore di attaccare il pokemon avversario, determina se il colpo va a segno e calcola il danno, in caso contrario viene mostrato che il pokemon ha tentennato
void attacco(int indexMioPokemon, int indexPokemonAvversario, struct Pokemon rosterPokemon[], int mossaSelezionata){        
    int precisioneMossaScelta = getPrecisione(indexMioPokemon, mossaSelezionata, rosterPokemon);
    bool colpito = haColpito(precisioneMossaScelta);
    if(colpito){
        int danno = calcoloDanno(indexMioPokemon, indexPokemonAvversario, mossaSelezionata, rosterPokemon);
        //usando la funzione setVita()
        int vita = getVita(indexPokemonAvversario, rosterPokemon);
        int nuovaVita = vita - danno;
        setVita(nuovaVita, indexPokemonAvversario, rosterPokemon);
        //rosterPokemon[indexPokemonAvversario].vita -= danno; //senza usare la funzione setVita()
        printf("%s usa %s con successo[Premi INVIO]\n", getNomePokemon(indexMioPokemon, rosterPokemon), getNomeMossa(indexMioPokemon, mossaSelezionata, rosterPokemon));
    }else if(!colpito){
        printf("%s ha tentennato[Premi INVIO]\n", getNomePokemon(indexMioPokemon, rosterPokemon));
    }
}
//funzione che permette al nemico di attaccare, sceglie una mossa casuale, determina se il colpo va a segno e calcola il danno, in caso contrario viene mostrato che il pokemon ha tentennato
void attaccoNemico(int indexMioPokemon, int indexPokemonAvversario, struct Pokemon rosterPokemon[]){
    //scelta casuale mossa
    int mossaSelezionata = rand() % 2;
    int precisioneMossaSelezionata = getPrecisione(indexPokemonAvversario, mossaSelezionata, rosterPokemon);
    bool colpito = haColpito(precisioneMossaSelezionata);
    if(colpito){
        int danno = calcoloDanno(indexPokemonAvversario, indexMioPokemon, mossaSelezionata, rosterPokemon);
        //usando la funzione setVita()
        int vita = getVita(indexMioPokemon, rosterPokemon);
        int nuovaVita = vita - danno;
        setVita(nuovaVita, indexMioPokemon, rosterPokemon);
        //rosterPokemon[indexMioPokemon].vita -= danno; //senza usare la funzione setVita()
        printf("%s avversario usa %s con successo[Premi INVIO]\n", getNomePokemon(indexPokemonAvversario, rosterPokemon), getNomeMossa(indexPokemonAvversario, mossaSelezionata, rosterPokemon)); 
    }else if(!colpito){
        printf("%s avversario ha tentennato[Premi INVIO]\n", getNomePokemon(indexPokemonAvversario, rosterPokemon));
    }   
}

//funzione principale che cicla fino a quando uno dei due pokemon perde tutti i punti vita, 
//dopo la grafica e l'input della mossa, vengono chiamate le funzioni di attacco in base al pokemon più veloce, si ripete fino a quando uno dei due pokemon non è esausto
//non appena uno dei due pokemon perde tutti i punti salute viene cambiato un flag(hoVinto/hoPerso) che se true uscirà dal while e mostrerà la grafica aggiornata col pokemon esausto ed una scritta (HAI VINTO/HAI PERSO)
void lotta(int indexMioPokemon, int indexPokemonAvversario, struct Pokemon rosterPokemon[], struct listaPartite **testa){
    bool hoVinto = false;
    bool hoPerso = false;
    while(getVita(indexMioPokemon, rosterPokemon) > 0 && getVita(indexPokemonAvversario, rosterPokemon) > 0){
        system("cls");
        printf("-------------------------------------------------\n");
        printf("%s\nHP: %d\n\n\n\n", getNomePokemon(indexPokemonAvversario, rosterPokemon), getVita(indexPokemonAvversario, rosterPokemon));
        printf("\t\t\t\t\t%s\n\t\t\t\t\tHP: %d\n\n", getNomePokemon(indexMioPokemon, rosterPokemon), getVita(indexMioPokemon, rosterPokemon));
        printf("[Scegli mossa]\t1)%s\t2)%s\n", getNomeMossa(indexMioPokemon, 0, rosterPokemon), getNomeMossa(indexMioPokemon, 1, rosterPokemon));
        printf("-------------------------------------------------\n");
        int mossaSelezionata;
        scanf("%d", &mossaSelezionata);
        mossaSelezionata--;//le mosse partono dal numero 0
        while(mossaSelezionata > 1 || mossaSelezionata < 0){
            printf("[ERRORE] Inserisci un numero valido\nRiprova:");
            scanf("%d", &mossaSelezionata);
            mossaSelezionata--;
        }
        int indicePokemonPiuVeloce = pokemonPiuVeloce(indexMioPokemon, indexPokemonAvversario, rosterPokemon); //restituisce l'indice del pokemon più veloce
        if(indicePokemonPiuVeloce == indexMioPokemon){
            attacco(indexMioPokemon, indexPokemonAvversario, rosterPokemon, mossaSelezionata);
            getchar();
            while ((getchar()) != '\n'); // svuota il buffer di input
            if(getVita(indexPokemonAvversario, rosterPokemon) <= 0){
                hoVinto = true;
                break;
            }
            attaccoNemico(indexMioPokemon, indexPokemonAvversario, rosterPokemon);
            getchar();
                if(getVita(indexMioPokemon, rosterPokemon) <= 0){
                    hoPerso = true;
                    break;
                }   
        }else if(indicePokemonPiuVeloce == indexPokemonAvversario){
            attaccoNemico(indexMioPokemon, indexPokemonAvversario, rosterPokemon);
            getchar();
            while ((getchar()) != '\n'); // svuota il buffer di input
            if(getVita(indexMioPokemon, rosterPokemon) <= 0){
                hoPerso = true;
                break;
            }
            attacco(indexMioPokemon, indexPokemonAvversario, rosterPokemon, mossaSelezionata);
            getchar();
                if(getVita(indexPokemonAvversario, rosterPokemon) <= 0){
                    hoVinto = true;
                    break;
                }
        }   
    }
    //inserimento dati nella lista
    inserisciPartita(testa, indexMioPokemon, getVita(indexMioPokemon, rosterPokemon), indexPokemonAvversario, getVita(indexPokemonAvversario, rosterPokemon), rosterPokemon);

    system("cls");
    if(hoVinto){
        printf("-------------------------------------------------\n");
        printf("%s\nHP: 0\n\n\n\n", getNomePokemon(indexPokemonAvversario, rosterPokemon));
        printf("\t\t\t\t\t%s\n\t\t\t\t\tHP: %d\n", getNomePokemon(indexMioPokemon, rosterPokemon), getVita(indexMioPokemon, rosterPokemon));
        printf("-------------------------------------------------\n");
        printf("HAI VINTO COMPLIMENTI :)\n[PREMI INVIO PER CONCLUDERE]");
        getchar();
    }else if(hoPerso){
        printf("-------------------------------------------------\n");
        printf("%s\nHP: %d\n\n\n\n", getNomePokemon(indexPokemonAvversario, rosterPokemon), getVita(indexPokemonAvversario, rosterPokemon));
        printf("\t\t\t\t\t%s\n\t\t\t\t\tHP: 0\n", getNomePokemon(indexMioPokemon, rosterPokemon));
        printf("-------------------------------------------------\n");
        printf("HAI PERSO :(\n[PREMI INVIO PER CONCLUDERE]");
        getchar();     
    }
}

//funzione che resetta la vita dei pokemon una volta finita una lotta
void resetVita(struct Pokemon rosterPokemon[]){
    for(int i = 0; i < ROSTER_MAX; i++){
        int vitaMax = getVitaMax(i, rosterPokemon);
        setVita(vitaMax, i, rosterPokemon);
    }
}