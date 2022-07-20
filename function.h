#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct dipendente{

    char id[11];
    char nome[31];
    char cognome[31];
    char mansione[31];
    struct dipendente *next;

}dipendente;



#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

char* generazionePassword();    //Genera una password in modalita' random (Allocazione dinamica mem: malloc)

char* input_stringa();  //Legge da uno stream di input una stringa senza spreco di byte (Allocazione dinamica mem: realloc)

void Inserimento_dipendente();  //Inserisce il dipendente direttamente all'interno di un File (Stream)

void inserimento_dip();

void stampa_lista_dipendenti_da_file(); //Stampa la lista direttamente da un File (Stream)

void salva_da_lista(dipendente *nodo);  //Salva in un File il nodo di una linked_list (Memo primaria -> Memo secondaria)

void carica_da_file();

void inserisci_testa(dipendente *buffer);

#endif // FUNCTION_H_INCLUDED
