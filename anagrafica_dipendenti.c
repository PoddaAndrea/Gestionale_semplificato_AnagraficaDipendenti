#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function.h"



void Inserimento_dipendente(){


    FILE *fp=fopen("DB_dipendenti.dat", "ab");
    dipendente *nuovo_dip=malloc(sizeof(dipendente));

    if(fp==NULL){
        fprintf(stderr, "Errore scrittuta file");
        exit(1);
    }

    generazionePassword(nuovo_dip->id);

    printf("Nome > ");
    gets(nuovo_dip->nome);

    printf("Cognome > ");
    gets(nuovo_dip->cognome);

    printf("Mansione > ");
    gets(nuovo_dip->mansione);

    fwrite(nuovo_dip, sizeof(dipendente), 1, fp);

    fclose(fp);
}

void stampa_lista_dipendenti_da_file(){

    FILE *fp=fopen("DB_dipendenti.dat", "rb");
    dipendente *dip=malloc(sizeof(dipendente));

    if(fp==NULL){
        fprintf(stderr, "Errore nella lettura del file");
        exit(1);
    }

    while(fread(dip, sizeof(dipendente), 1, fp)> 0){

        printf("ID: %s", dip->id);
        printf("\nNome: %s", dip->nome);
        printf("\nCognome: %s", dip->cognome);
        printf("\nMansione: %s", dip->mansione);
        printf("\n--------------------------\n\n");

    }

    fclose(fp);

}

/*void inserimento_dip(){

    dipendente *nuovo_dip=malloc(sizeof(dipendente));


    generazionePassword(nuovo_dip->id);

    printf("Nome > ");
    gets(nuovo_dip->nome);

    printf("Cognome > ");
    gets(nuovo_dip->cognome);

    printf("Mansione > ");
    gets(nuovo_dip->mansione);

    nuovo_dip->next=NULL;

    if(lista_dipendenti== NULL){

        lista_dipendenti=nuovo_dip;

    }else{

        dipendente *current_dip=lista_dipendenti;

        while(current_dip->next != NULL){

            current_dip=current_dip->next;
        }

        current_dip->next=nuovo_dip;
    }

    salva_da_lista(nuovo_dip);

}*/

void stampa_lista_dipendenti(dipendente *lista_dipendenti){

    while(lista_dipendenti != NULL){

        printf("ID: %s", lista_dipendenti->id);
        printf("\nNome: %s", lista_dipendenti->nome);
        printf("\nCognome: %s", lista_dipendenti->cognome);
        printf("\nMansione: %s", lista_dipendenti->mansione);
        printf("\n--------------------------\n\n");

        lista_dipendenti=lista_dipendenti->next;

    }
}


