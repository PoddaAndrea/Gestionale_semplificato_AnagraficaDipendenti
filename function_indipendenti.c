#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "function.h"

dipendente *lista_dipendenti=NULL;

char* generazionePassword(char password[]){

    /**Manca il controllo delle password uguali**/

    char *random_alph="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    FILE *fp=fopen("Password_generate.txt", "a");

    srand(time(NULL));

    for(int i=0; i<11; i++){

        if(i<10){

            password[i]=random_alph[rand()%62];

        }else{
            password[i]= '\0';
        }
    }

    if(fp==NULL){

        fprintf(stderr, "Errore scrittura file");
        exit(2);

    }

    fprintf(fp,"%s\n", password);

    fclose(fp);

    return password;

}

void salva_da_lista(dipendente *nodo){

    FILE *fp=fopen("DB_dipendenti.dat", "ab");

    if(fp==NULL){
        fprintf(stderr, "Errore scrittura file");
        exit(1);
    }

    fwrite(nodo, sizeof(dipendente), 1, fp);
    fclose(fp);
}

char* input_stringa(){

    char *str, c;
    int i;

    str = (char*)malloc(1*sizeof(char));

    while(c = getc(stdin),c!='\n')
    {
        str[i] = c;
        i++;
        realloc(str,i*sizeof(char));
    }
    str[i] = '\0';

    return str;
}

void carica_da_file(){

    FILE *file_dip=fopen("DB_dipendenti.dat", "rb");
    dipendente *buffer=malloc(sizeof(dipendente));

    while(fread(buffer, sizeof(dipendente), 1, file_dip)> 0){
        inserisci_testa(buffer);
    }

    fclose(file_dip);

}

void inserisci_testa(dipendente *buffer){

    dipendente *nodo=malloc(sizeof(dipendente));

    nodo=buffer;
    nodo->next=NULL;

    if(buffer == NULL){
        buffer=nodo;
    }else{
        dipendente *current=buffer;

        while(current->next != NULL){
            current=current->next;
        }

        current->next=nodo;
    }

}

