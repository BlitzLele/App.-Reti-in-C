//Sorrentino Samuele
//4°INA

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include "funzioni.h"                               //Includo il FILE funzioni.h dove sono contenute le funzioni del programma
#define N 4

int main()
{
    intestazione();                 //Funzione che genera la tabella per l'intestazione

    int dec[N];                     //Vettore che contiene, a blocchi, l'indirizzo IP che l'utente inserisce
    int dec2[N];                        //Vettore che contiene, a blocchi,il secondo indirizzo IP che l'utente inserisce
    int sm[4];                      //Vettore che contiene la subnet mask in decimale inserita dall'utente
    int smbin[32];                      //Vettore che contiene la subnet mask in binario
    int bin[32];                    //Vettore che contiene, a blocchi, l'indirizzo IP che l'utente inserisce, convertito in binario
    int bin2[32];                       //Vettore che contiene, a blocchi, il secondo indirizzo IP che l'utente inserisce, convertito in binario
    int net1[4];                    //Vettore che contiene, a blocchi, il net id dell'indirizzo IP che l'utente inserisce
    int net2[4];                        //Vettore che contiene, a blocchi, il net id del secondo indirizzo IP che l'utente inserisce

    int scelta, fine;               //Variabili che vengono usate nel menù di scelta
    int bit_sub=0;                      //Variabile che contiene i bit dedicati alla rete utilizzati per il subetting a maschera fissa
    do
    {
        printf("\n");
        printf (" ||Scegliere una tra le seguenti operazioni||\n [1]Verificare la classe e se l'IP e' pubblico o privato\n [2]Verificare se due Indirizzi IP appartengono alla stessa rete\n [3]Eseguire Subnetting a Maschera Fissa di un IP\n [4]Eseguire Subnetting a Maschera Variabile di un IP\n [5]Pulire la Schermata di Esecuzione\n [0]Fine\n");
        printf("\n");
        scanf ("%d",& scelta);
        switch (scelta)
        {
                default:
                        printf("\n--Il Carattere Inserito non e' Accettabile--\n\n");
                        sleep(3);
                        exit(0);

            case 1:

                input(dec);
                verifica_ip(dec);
                break;

            case 2:

                primo_ip(dec,bin);
                secondo_ip(dec2,bin2);
                subnet(sm,smbin);
                netid(dec,dec2,sm,net1,net2);
                confronto(net1,net2);
                break;

            case 3:

                maschera_fissa(dec,bin,smbin,bit_sub);
                break;

            case 4:

                vlsm(dec,bin);
                break;

            case 5:

                clear();
                break;

            case 0:

                fine=1;
                break;

        }
    }
    while(scelta!=0);               //Il menù di scelta continuerà ad essere eseguito correttamente fino a quando non verrà inserito il carattere "0"
    return 0;
}

