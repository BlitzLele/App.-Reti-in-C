#define funzioni_h_included
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#define N 4

void input(int dec[]);                                                  //Funzione che si occupa dell'Inserimento
void verifica_ip(int dec[]);                                                //Funzione che si occupa del Controllo
void primo_ip(int dec[],int bin[]);                                     //Funzione che si occupa dell'Inserimento
void secondo_ip(int dec2[],int bin2[]);                                     //Funzione che si occupa dell'Inserimento
void subnet(int sm[],int smbin[]);                                      //Funzione che si occupa dell'Inserimento
void netid(int dec[],int dec2[],int sm[],int ris[],int ris2[]);             //Funzione che esegue uno o più Calcoli
void confronto(int ris[],int ris2[]);                                   //Funzione che permette il Confronto
void maschera_fissa(int dec[],int bin[],int smbin[],int bit_sub);           //Funzione che si occupa dell'Inserimento
void subnetting_maskfissa(int dec[], int nsot, int bit_sub);            //Funzione che esegue uno o più Calcoli
void vlsm(int dec[],int bin[]);                                             //Funzione che esegue uno o più Calcoli
void clear();                                                           //Funzione che fa una chiamata a Sistema
void intestazione();                                                        //Funzione che genera una tabella di caratteri ASCII

void input(int dec[])                                                   //Tramite questa funzione l'utente inserisce l'indirizzo IP che poi verrà controllato
{
    printf("\n");
    int i=0;
    for (i=0;i<N;i++)
    {
        do
        {
            printf("Inserire il %d ottetto del indirizzo IP in decimale: ",i+1);
            scanf("%d",&dec[i]);
            if (dec[i] < 0 || dec[i] >= 256)                //Controllo che l'indirizzo IP inserito dall'utente sia corretto
            {
                printf("\nErrore di inserimento\n\n");
            }
        }
        while (dec[i] <0 || dec[i] > 256);              //L'inserimento dell'indirizzo IP funzionerà fin quando i valori inseriti non supereranno 256
    }
    printf("\n");
    printf("L'Indirizzo IP inserito e' il seguente: \n");
    for(i=0;i<N;i++)
    {
        printf("%d",dec[i]);                    //Stampo l'indirizzo IP
        printf(".");
    }
    printf("\n");
}

void verifica_ip(int dec[])                                             //Tramite questa funzione l'indirizzo IP inserito dall'utente viene controllato e viene stabilito se è privato, pubblico e a che classe appartiene
{
    printf("\n");
    int i=0;
    if (dec[i] >= 0 && dec[i] <= 127)               //Tramite i controlli verifico a quale classe appartiene l'indirizzo IP
        {
            printf("L'indirizzo ip e' di classe A \n");
        }
        if (dec[i] >= 128 && dec[i] <= 191)
        {
            printf("L'indirizzo ip e' di classe B \n");
        }
            if (dec[i] >= 192 && dec[i] <= 223)
            {
                printf("L'indirizzo ip e' di classe C \n");
            }
                if (dec[i] >= 224 && dec[i] <= 239)
                {
                    printf("L'indirizzo ip e' di classe D \n");
                }
                    if (dec[i] >= 240 && dec[i] <= 255)
                    {
                        printf("L'indirizzo ip e' di classe E \n");
                    }
                    printf("\n");
                        if (dec[i] == 10)
                        {
                            printf("L'indirizzo ip e' privato \n");             //Tramite i controlli verifico se l'indirizzo IP è privato o pubblico
                        }
                        else
                        {
                            if (dec[i] == 172)
                            {
                                printf("L'indirizzo ip e' privato \n");
                            }
                            else
                            {
                                if (dec[i] == 192)
                                {
                                    printf("L'indirizzo ip e' privato \n");
                                }
                            }
                        }
}

void primo_ip(int dec[],int bin[])                                      //Tramite questa funzione l'utente inserisce il primo indirizzo IP per il confronto
{
    printf("\n");
    int i,i2,n,k,j,l,t,flag;                     //Variabili che verranno usate nella conversione decimale-binario
    for (i=0;i<N;i++)
    {
        do
        {
            printf("Inserire il %d ottetto del primo indirizzo IP in decimale: ",i+1);                  //L'utente inserisce il primo indirizzo IP
            scanf("%d",&dec[i]);
            if (dec[i] < 0 || dec[i] >= 256)
            {
                printf("\nErrore di inserimento\n\n");
            }
        }
        while (dec[i] <0 || dec[i] > 256);
    }
    printf("\n");
    printf("Il primo Indirizzo IP inserito e' il seguente: \n");                //Stampa del primo indirizzo IP
    for(i=0;i<N;i++)
    {
        printf("%d",dec[i]);
        printf(".");
    }
    printf("\n");
    printf("\n");
    printf("In Binario: \n");
    for (i=0 ; i<4 ; i++)
    {
        n=dec[i];               //n prende il primo blocco dell'indirizzo IP che poi verrà convertito
        k=0;
        flag=1;
        while (n != 0)
        {
            flag=0;
            if (n % 2 == 1)                  //Conversione Decimale-Binario
                bin[k] = 1;
            else
                bin[k] = 0;
                n /= 2;
                k++;                //k viene incrementato per permettere al vettore di acquisire i prossimi valori
        }
        if(flag!=0)
        {
            k=0;
        }
        if(k!=8)
        {
            t=k;
            l=8-t;
            for(i2=0 ; i2<l ; i2++)
            {
                bin[t]=0;
                t++;
            }
        }
        for (j=7 ; j>=0 ; j--)              //Stampa del Risultato
        {
            printf("%d", bin[j]);
        }
        printf(".");
    }
    printf("\n");
    printf("\n");
}

void secondo_ip(int dec2[],int bin2[])                                  //Tramite questa funzione l'utente inserisce il secondo indirizzo IP che deve essere confrontato
{
    printf("\n");
    int i,i2,n,k,j,l,t,flag;                //Variabili che verranno usate nella conversione decimale-binario
    for (i=0;i<N;i++)
    {
        do
        {
            printf("Inserire il %d ottetto del secondo indirizzo IP in decimale: ",i+1);                //L'utente inserisce il primo indirizzo IP
            scanf("%d",&dec2[i]);
            if (dec2[i] < 0 || dec2[i] >= 256)
            {
                printf("\nErrore di inserimento\n\n");
            }
        }
        while (dec2[i] <0 || dec2[i] > 256);
    }
    printf("\n");
    printf("IL secondo Indirizzo IP inserito e' il seguente: \n");              //Stampa dell'indirizzo IP
    for(i=0;i<N;i++)
    {
        printf("%d",dec2[i]);
        printf(".");
    }
    printf("\n");
    printf("\n");

    printf("In Binario: \n");
    for (i=0 ; i<4 ; i++)               //Conversione Decimale-Binario
    {
        n=dec2[i];                  //n prende il primo blocco dell'indirizzo IP che poi verrà convertito
        k=0;
        flag=1;
        while (n != 0)
        {
            flag=0;
            if (n % 2 == 1)
                bin2[k] = 1;
            else
                bin2[k] = 0;
                n /= 2;
                k++;                //k viene incrementato per permettere di acquisire i prossimi valori
        }
        if(flag!=0)
        {
            k=0;
        }
        if(k!=8)
        {
            t=k;
            l=8-t;
            for(i2=0 ; i2<l ; i2++)
            {
                bin2[t]=0;
                t++;
            }
        }
        for (j=7 ; j>=0 ; j--)
        {
            printf("%d", bin2[j]);              //Stampa del Risultato
        }
        printf(".");
    }
    printf("\n");
    printf("\n");

}

void subnet(int sm[],int smbin[])                                       //Tramite questa funzione l'utente inserisce la subnet per il confronto dei due indirizzi IP
{
    int i;
    for (i=0 ; i<N ; i++)
    {
        do
        {
            printf("Inserire il %d ottetto della subnetmask in decimale: ",i+1);            //L'utente inserisce la subet in decimale
            scanf("%d",&sm[i]);                                 //Il vettore sm[i] contiene la subnet inserita dall'utente a blocchi
            if (sm[i] < 0 || sm[i] >= 256)              //Controllo che la subnet inserita dall'utente sia corretta
            {
                printf("\nErrore di inserimento\n\n");
            }
        }
        while (sm[i] <0 || sm[i] > 256);            //Inserimento valido finchè il valore inserito non supera 256
    }
    printf("\n");
    printf("La Subnet Mask e': \n");                //Stampa della subnet in decimale
    for(i=0 ; i<N ; i++)
    {
        printf("%d",sm[i]);
        printf(".");
    }
}

void netid(int dec[],int dec2[],int sm[],int net1[],int net2[])         //Tramite questa funzione vengono calcolati e stampati i netid dei due indirizzi IP inseriti
{
    printf("\n");
    int i;
    for(i=0 ; i<4 ; i++)
    {
        net1[i]=dec[i]&sm[i];               //Calcolo il primo netid facendo l'and bit a bit tra l'indirizzo IP decimale racchiuso in dec[i] e tra la subnet in decimale racchiusa in sm[i], con la funzione "&"
    }
    printf("\n");
    printf("\n");
    printf("Il netid del primo indirizzo IP e': \n");       //Stampo il primo netid in decimale
    for(i=0 ; i<4 ; i++)
    {
        printf("%d", net1[i]);              //Stampa del primo netid a blocchi
        printf(".");
    }
    printf("\n");

    for(i=0 ; i<4 ; i++)
    {
        net2[i]=dec2[i]&sm[i];              //Calcolo il secondo netid facendo l'and bit a bit tra l'indirizzo IP decimale racchiuso in dec[i] e tra la subnet in decimale racchiusa in sm[i], con la funzione "&"
    }
    printf("\n");
    printf("\n");
    printf("Il netid del secondo indirizzo IP e': \n");         //Stampo il secondo netid
    for(i=0 ; i<4 ; i++)
    {
        printf("%d", net2[i]);                  //Stampa del secondo netid a blocchi
        printf(".");
    }
    printf("\n");
}

void confronto(int net1[],int net2[])                                   //Tramite questa funzione vengono confrontati i netid degli indirizzi IP inseriti nelle funzioni primo_ip e secondo_ip
{
    printf("\n");
    int i;
    int cont=0;             //Contatore che verrà usato successivamente nel confronto
    for(i=0 ; i<4 ; i++)
    {
        if(net1[i]==net2[i])                //Confronto i due netid dei due indirizzi IP contenuti in dec[i] e dec2[i]
        {
            cont++;
        }
    }
    if(cont==4)             //Se il contatore è uguale a 4, i netid sono uguali e appartengono alla stessa rete
    {
        printf("Gli IP appartengono alla stessa rete");
    }
    else
    {
        printf("Gli IP non appartengono alla stessa rete");
    }
    printf("\n");
    printf("\n");
}

void maschera_fissa(int dec[],int bin[],int smbin[],int bit_sub)		//Tramite questa funzione l'utente inserisce l'indirizzo IP e il numero di sottoreti per il subnetting a maschera fissa
{
    int i=0,j=0;             //Variabili che verranno usate come indici nei cicli
    int cont=0;                       //Variabile che viene successivamente usata nei cicli per calcolare i bit della subnet[RIGA 389-390-394]
    int pot=0;                    //Variabile che viene usata per calcolare i bit della subnet che utilizzerò come blocco per fare il subnetting[RIGA 417-419]
    int nsot=0;                           //Variabile che contiene il numero di sottoreti inserite dall'utente
    printf("\n");
    for (i=0;i<N;i++)
    {
        do
        {
            printf("Inserire il %d ottetto dell' indirizzo IP in decimale: ",i+1);              //L'utente inserisce l'indirizzo IP
            scanf("%d",&dec[i]);
            if (dec[i] < 0 || dec[i] >= 256)
            {
                printf("\nErrore di inserimento\n\n");
            }
        }
        while (dec[i] <0 || dec[i] > 256);
    }
    printf("\n");
    printf("L'Indirizzo Indirizzo IP inserito e' il seguente: \n");         //Stampa dell'indirizzo IP
    for(i=0 ; i<N ; i++)
    {
        printf("%d",dec[i]);
        printf(".");
    }
    printf("\n");
    i=0;
    printf("\n");
    printf("\n");                               //Tramite i controlli vedo a quale classe appartiene l'indirizzo IP inserito dall'utente per eseguire il subnetting

    if (dec[i] >= 0 && dec[i] <= 127)
    {
        printf("L'indirizzo ip e' di classe A \n");
        printf("\n");
        do
        {
            if(nsot==0)
            {
                printf("Inserisci il numero di sottoreti [Massimo 4194304 Sottoreti]: \n");         //L'utente inserisce il numero di sottoreti
                scanf("%d", &nsot);
            }
            else
            {
                printf("\nNumero Di Sottoreti non Accettabile\nReinserisci il numero di sottoreti: \n");            //L'utente reinserisce il numero di sottoreti
                scanf("%d", &nsot);
            }
        }
        while (nsot < 0 || nsot > 4194304);                      //Controllo del numero di sottoreti
        do
        {
            i++;
        }
        while(nsot>pow(2,i));
        if(nsot>65536)                                          //Ricavo i bit dedicati alla rete per la classe A, in base al numero di sottoreti
            {
                bit_sub = 24 - i;
            }
            else if (nsot>255)
            {
                if(i==15)
                {
                    bit_sub = 24 - i;
                }
                else
                {
                    bit_sub = 16 - i;
                }
            }
            else
            {
                bit_sub = 8 - i;
            }
        printf("\n");
        subnetting_maskfissa(dec,nsot,bit_sub);                             //Richiamo la funzione che esegue il subnetting a maschera fissa del indirizzo IP
    }
        if (dec[i] >= 128 && dec[i] <= 191)
        {
            printf("L'indirizzo ip e' di classe B \n");
            printf("\n");
            do
            {
                if(nsot==0)
                {
                    printf("Inserisci il numero di sottoreti [Massimo 16384 Sottoreti]: \n");         //L'utente inserisce il numero di sottoreti
                    scanf("%d", &nsot);
                }
                else
                {
                    printf("\nNumero Di Sottoreti non Accettabile\nReinserisci il numero di sottoreti: \n");            //L'utente reinserisce il numero di sottoreti
                    scanf("%d", &nsot);
                }
            }
            while (nsot < 0 || nsot > 16384);                      //Controllo del numero di sottoreti
            do
            {
                i++;
            }
            while (nsot > pow(2, i));
            if(nsot>255)
            {
                bit_sub = 16 - i;                                       //Ricavo i bit dedicati alla rete per la classe B, in base alle sottoreti
            }
            else
            {
                bit_sub = 8 - i;
            }
            printf("\n");
            subnetting_maskfissa(dec,nsot,bit_sub);                                     //Richiamo la funzione che esegue il subnetting a maschera fissa del indirizzo IP
        }
            if (dec[i] >= 192 && dec[i] <= 223)
            {
                printf("L'indirizzo ip e' di classe C \n");
                printf("\n");
                do
                {
                    if(nsot==0)
                    {
                    printf("Inserisci il numero di sottoreti [Massimo 64 Sottoreti]: \n");         //L'utente inserisce il numero di sottoreti
                    scanf("%d", &nsot);
                    }
                    else
                    {
                        printf("\nNumero Di Sottoreti non Accettabile\nReinserisci il numero di sottoreti: \n");            //L'utente reinserisce il numero di sottoreti
                        scanf("%d", &nsot);
                    }
                }
                while (nsot < 0 || nsot > 64);                      //Controllo del numero di sottoreti
                do
                {
                    i++;
                }
                while(nsot>pow(2,i));
                bit_sub = 8 - i;                                                //Ricavo i bit dedicati alla rete per la classe C, in base alle sottoreti
                printf("\n");
                subnetting_maskfissa(dec,nsot,bit_sub);                                     //Richiamo la funzione che esegue il subnetting a maschera fissa del indirizzo IP
            }
                if (dec[i] >= 224 && dec[i] <= 239)
                {
                    printf("L'indirizzo ip e' di classe D \n");
                    printf("Il Programma non supporta questa classe");
                }
                    if (dec[i] >= 240 && dec[i] <= 255)
                    {
                        printf("L'indirizzo ip e' di classe E \n");
                        printf("Il Programma non supporta questa classe");
                    }
                    printf("\n");
}

void subnetting_maskfissa(int dec[],int nsot,int bit_sub)   //Tramite questa funzione viene eseguito il subnetting a maschera fissa dell'indirizzo IP inserito
{
    printf("\n");
    int i,j;
    int blocco_c=0;                 //Variabile che contiene il blocco di bit che mi servirà nel subnetting di classe c a maschera fissa
    int blocco_b=0;             //Variabile che contiene il blocco di bit che mi servirà nel subnetting di classe b a maschera fissa
    int blocco_a=0;                 //Variabile che contiene il blocco di bit che mi servirà nel subnetting di classe a
    int broad=0;                //Variabile che contiene il broadcast
    int gateway;                    //Variabile che contiene il gateway
    int range=0;                //Variabile che contiene il range
    int range2=0;                   //Variabile che contiene il range
    int flag;
    FILE *fp;

    printf("Desideri Stampare le Sottoreti anche su FILE?  SI[1]   NO[0]\n");
    printf("La tua scelta: \t");
    scanf("%d",&flag);

    if(flag==1)
    {
        if ((fp=fopen("database.txt","w"))==NULL)                                       //Controllo l'esistenza del FILE. Se il FILE non esiste viene creato
        {
            printf("Errore nell’apertura del file");
        }
    }

    if(flag==1)
    {
        fprintf(fp, "      NET ID       \t       BROADCAST        \t        GATEWAY         \t          PRIMO HOST-ULTIMO HOST                     \n");
    }

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",218 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,194 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,194 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("%c                  %c                  %c                          %c                                      %c          \n", 179, 179, 179, 179, 179);
    printf("%c    NET ID        %c    BROADCAST     %c         GATEWAY          %c       PRIMO HOST-ULTIMO HOST         %c          \n", 179, 179, 179, 179, 179);
    printf("%c                  %c                  %c                          %c                                      %c          \n", 179, 179, 179, 179, 179);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",192 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,193 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,193 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    
    for(j=0 ; j<nsot ; j++)                                             //Controllo a quale classe appartiene il primo ottetto per eseguire il subnetting a maschera fissa dell'indirizzo IP
    if (dec[0] >= 192 && dec[0] <= 223)                                 //CLASSE C
    {
        if(flag==1)
            {
                for(j=0 ; j<nsot ; j++)                                                             //Eseguo il subnetting
                {
                    fprintf(fp, "\n %d.%d.%d.%d\t",dec[0],dec[1],dec[2],blocco_c);                           //Calcolo il netid
                    gateway=blocco_c+1;                                                                         //Calcolo il Gateway
                    blocco_c=blocco_c+pow(2,bit_sub);
                    fprintf(fp, "%d.%d.%d.%d\t",dec[0],dec[1],dec[2],blocco_c-1);                                 //Calcolo il BroadCast
                    fprintf(fp, "\t%d.%d.%d.%d\t",dec[0],dec[1],dec[2],gateway);
                    fprintf(fp, "%d.%d.%d.%d - %d.%d.%d.%d",dec[0],dec[1],dec[2],gateway+1,dec[0],dec[1],dec[2],blocco_c-2);                     //Calcolo il range
                }
                fclose(fp);
            }
            blocco_c=0;
            gateway=0;
            for(j=0 ; j<nsot ; j++)                                                                 //Eseguo il subnetting
            {
                printf("\n %d.%d.%d.%d\t",dec[0],dec[1],dec[2],blocco_c);                                   //Calcolo il netid
                gateway=blocco_c+1;                                                                             //Calcolo il Gateway
                blocco_c=blocco_c+pow(2,bit_sub);
                printf("\t%d.%d.%d.%d\t",dec[0],dec[1],dec[2],blocco_c-1);                                          //Calcolo il BroadCast
                printf("\t%d.%d.%d.%d\t",dec[0],dec[1],dec[2],gateway);
                printf("\t%d.%d.%d.%d - %d.%d.%d.%d",dec[0],dec[1],dec[2],gateway+1,dec[0],dec[1],dec[2],blocco_c-2);                           //Calcolo il range
            }
            printf("\n\nSottoreti Stampate anche nel FILE <database.txt>\n\n");
    }
    if (dec[0] >= 128 && dec[0] <= 191)                                     //CLASSE B
    {
        if(nsot>255)                                                        //Controllo se le sottoreti inserite sono maggiori di 255. Se sono maggiori il subnetting si sposta sul 3°ottetto
        {
            if(flag==1)
            {
                for(j=0 ; j<nsot ; j++)                                                         //Eseguo il subnetting
                {
                    fprintf(fp, "\n %d.%d.%d.%d\t", dec[0], dec[1], blocco_b, blocco_c);                 //Calcolo il netid
                    gateway = blocco_c + 1;                                                     //Calcolo il Gateway
                    blocco_c = blocco_c + pow(2,bit_sub);
                    broad = blocco_c -1;                                                            //Calcolo il BroadCast
                    fprintf(fp, "\t%d.%d.%d.%d\t", dec[0], dec[1], blocco_b, broad);
                    fprintf(fp, "\t%d.%d.%d.%d\t", dec[0], dec[1], blocco_b, gateway);
                    fprintf(fp, "\t%d.%d.%d.%d - %d.%d.%d.%d", dec[0], dec[1], blocco_b, gateway + 1, dec[0], dec[1], blocco_b, broad-1);     //Calcolo il Range
                    if (blocco_c > 255)                                                                                                     //Quando l'ultimo ottetto raggiunge 255, il 3°ottetto si incrementa
                    {
                        blocco_b++;
                        blocco_c=0;
                    }
                }
            }
            blocco_c=0;
            blocco_b=0;
            gateway=0;
            broad=0;
            for(j=0 ; j<nsot ; j++)                                                         //Eseguo il subnetting
            {
                printf("\n %d.%d.%d.%d\t", dec[0], dec[1], blocco_b, blocco_c);                 //Calcolo il netid
                gateway = blocco_c + 1;                                                     //Calcolo il Gateway
                blocco_c = blocco_c + pow(2,bit_sub);
                broad = blocco_c -1;                                                            //Calcolo il BroadCast
                printf("\t%d.%d.%d.%d\t", dec[0], dec[1], blocco_b, broad);
                printf("\t%d.%d.%d.%d\t", dec[0], dec[1], blocco_b, gateway);
                printf("\t%d.%d.%d.%d - %d.%d.%d.%d", dec[0], dec[1], blocco_b, gateway + 1, dec[0], dec[1], blocco_b, broad-1);     //Calcolo il Range
                if (blocco_c > 255)                                                                                                     //Quando l'ultimo ottetto raggiunge 255, il 3°ottetto si incrementa
                {
                    blocco_b++;
                    blocco_c=0;
                }
            }
        }
        else if(nsot<255)
        {
            if(flag==1)
            {
                for(j=0 ; j<nsot ; j++)
                {
                    fprintf(fp, "\n %d.%d.%d.0\t",dec[0],dec[1],blocco_c);
                    gateway=blocco_c;
                    blocco_c=blocco_c+pow(2,bit_sub);
                    fprintf(fp, "\t%d.%d.%d.255\t",dec[0],dec[1],blocco_c-1);
                    fprintf(fp, "\t%d.%d.%d.1\t ",dec[0],dec[1],gateway);
                    fprintf(fp, "\t%d.%d.%d.2 - %d.%d.%d.254",dec[0],dec[1],gateway,dec[0],dec[1],blocco_c-1);
                }
                fclose(fp);
            }
            blocco_c=0;
            gateway=0;

            for(j=0 ; j<nsot ; j++)
            {
                printf("\n %d.%d.%d.0\t",dec[0],dec[1],blocco_c);
                gateway=blocco_c;
                blocco_c=blocco_c+pow(2,bit_sub);
                printf("\t%d.%d.%d.255\t",dec[0],dec[1],blocco_c-1);
                printf("\t%d.%d.%d.1\t ",dec[0],dec[1],gateway);
                printf("\t%d.%d.%d.2 - %d.%d.%d.254",dec[0],dec[1],gateway,dec[0],dec[1],blocco_c-1);
            }
            
        }
    }
    if (dec[0] >= 0 && dec[0] <= 127)                                           //CLASSE A
    {
        if(nsot>16384)                                                              //Controllo se il numero di sottoreti super 16384. Se sono maggiori il subnetting si sposta sul 2°ottetto
        {
            if(bit_sub!=9)                                                          //Quando bit_sub è diverso da 9[bit massimi per le sottoreti in classe b] il secondo ottetto non si incrementa
            {                                                               //CLASSE A
                for(j=0 ; j<nsot ; j++)
                {
                    printf("\n %d.%d.%d.%d\t",dec[0], blocco_a, blocco_b, blocco_c);       //Calcolo il netid
                    gateway = blocco_c + 1;                                                     //Calcolo il gateway
                    blocco_c = blocco_c + pow(2,bit_sub);
                    broad = blocco_c - 1;                                                   //Calcolo il broad
                    range= gateway + 1;                                                         //Calcolo il range
                    range2= broad -1;                                                       //Calcolo il range
                    if (blocco_c > 255)                                 //Quando l'ultimo ottetto raggiunge 255, il 3°ottetto si incrementa
                    {
                        blocco_b++;
                        blocco_c=0;
                    }
                    if (blocco_b > 255)                                  //Quando il 3° ottetto raggiunge 255, il 2°ottetto si incrementa
                    {
                        blocco_a++;
                        blocco_b=0;
                        blocco_c=0;
                    }
                    printf("%d.%d.%d.%d\t", dec[0], blocco_a, blocco_b, broad);
                    printf("%d.%d.%d.%d\t", dec[0], blocco_a, blocco_b, gateway);
                    printf("%d.%d.%d.%d - %d.%d.%d.%d", dec[0], blocco_a, blocco_b, range, dec[0], blocco_a, blocco_b, range2);
                }
            }
            else if(bit_sub==9)                                             //Quando bit_sub è uguale a 9[bit massimi per le sottoreti in classe] il secondo ottetto si incrementa
            {
                for (j = 0; j < nsot; j++)
                {
                    printf("\n %d.%d.%d.%d\t",dec[0], blocco_a, blocco_b, blocco_c);                   //Calcolo il netid
                    gateway = 1;                                                                            //Calcolo il gateway
                    blocco_c = blocco_c + pow(2, bit_sub);
                    broad = 255;                                                                        //Calcolo il broad
                    range = 2;                                                                              //Calcolo il range
                    range2 = 254;                                                                       //Calcolo il range
                    if (blocco_c > 255)                                                                     //Quando l'ultimo ottetto raggiunge 255, il 3°ottetto si incrementa
                    {
                        blocco_b++;
                        blocco_c = 0;
                    }
                    if (blocco_b > 255)                                     //Quando il 3° ottetto raggiunge 255, il 2°ottetto si incrementa
                    {
                        blocco_a++;
                        blocco_b = 0;
                        blocco_c = 0;
                    }
                    printf("\t%d.%d.%d.255\t", dec[0], blocco_a, blocco_b);
                    printf("\t%d.%d.%d.1\t", dec[0], blocco_a, blocco_b);
                    printf("\t%d.%d.%d.2 - %d.%d.%d.254", dec[0], blocco_a, blocco_b, dec[0], blocco_a, blocco_b);
                }
            }

        }
        else if (nsot >255 && nsot <16384)
        {
            bit_sub = 8-bit_sub;
            for (j=0 ; j<nsot ; j++)
            {
                if(blocco_c < 255)
                {
                    printf("\n %d.%d.%d.0\t",dec[0],blocco_a,blocco_c);
                    gateway = blocco_c;
                    blocco_c = blocco_c + pow(2, bit_sub);
                    printf("\t%d.%d.%d.255\t", dec[0], blocco_a, blocco_c - 1);
                    printf("\t%d.%d.%d.1\t ", dec[0], blocco_a, gateway);
                    printf("\t%d.%d.%d.2 - %d.%d.%d.254", dec[0], blocco_a, gateway, dec[0], blocco_a, blocco_c - 1);
                }
                else
                {
                    blocco_c=0;
                    blocco_a++;
                }
            }
        }
        else if(nsot<255)
        {
            for (j=0 ; j<nsot ; j++)
            {
                printf("\n %d.%d.0.0\t", dec[0], blocco_c);
                gateway = blocco_c;
                blocco_c = blocco_c + pow(2, bit_sub);
                printf("\t%d.%d.255.255\t", dec[0], blocco_c - 1);
                printf("\t%d.%d.0.1\t ", dec[0], gateway);
                printf("\t%d.%d.0.2 - %d.%d.255.254", dec[0], gateway, dec[0], blocco_c - 1);
            }
        }
    }
}

void vlsm(int dec[],int bin[])                                          //Tramite questa funzione viene eseguito il subnetting a maschera variabile
{
    printf("\n");
    int i,j;                            //Variabili che verranno usate nei cicli
    int somma=0;                            //Somma degli host che verrà usata nel controllo degli host
    int tmp;                            //Variabile usata all'intero dell'ordinamento
    int reti;                               //Variabile che contiene il numero di reti inserite dall'utente
    int host[125];                      //Vettore che contiene i vari host, per le reti, inseriti dall'utente
    for (i=0 ; i<N ; i++)                   //Chiedo all'utente di inserire l'indirizzo IP
    {
        do
        {
            printf("Inserire il %d ottetto dell' indirizzo IP in decimale: ",i+1);
            scanf("%d",&dec[i]);
            if (dec[i] < 0 || dec[i] >= 256)
            {
                printf("\nErrore di inserimento\n\n");
            }
        }
        while (dec[i] <0 || dec[i] > 256);
    }
    printf("\n");
    printf("L'Indirizzo Indirizzo IP inserito e' il seguente: \n");     //Stampo l'indirizzo IP
    for(i=0 ; i<N ; i++)
    {
        printf("%d",dec[i]);
        printf(".");
    }
    i=0;
    printf("\n");
    printf("\n");                                                       //Tramite i controlli vedo a quale classe appartiene l'indirizzo IP inserito dall'utente
    if (dec[i] >= 0 && dec[i] <= 127)
    {
        printf("Inserisci il numero di reti: \n");                      //Chiedo all'utente di inserire il numero di reti
        scanf("%d",&reti);

        printf("\n");
        printf("Inserisci il numero di host per ogni rete: \n");        //Chiedo all'utente di inserire gli host per ogni rete inserita precedentemente
        for(i=0 ; i<reti ; i++)
        {
            scanf("%d",&host[i]);
        }
        for (i=0; i<reti-1; i++)                                    //Tramite questo ordinamento bubble sort ordino il numero di host in modo decrescente
        {
            for (j=i+1; j<reti; j++)
            {
                if (host[i] < host[j])
                {
                    tmp = host[i];
                    host[i] = host[j];
                    host[j] = tmp;
                }
            }
        }
        printf("\n");
        for(j=0 ; j<reti ; j++)                                     //Stampo tutte le reti inserite dall'utente con i rispettivi host
        {
            printf("La %d rete ha %d host: \n",j+1, host[j]);
        }
    }
        if (dec[i] >= 128 && dec[i] <= 191)
        {
            printf("Inserisci il numero di reti: \n");                      //Chiedo all'utente di inserire il numero di reti
            scanf("%d",&reti);

            printf("\n");
            printf("Inserisci il numero di host per ogni rete: \n");        //Chiedo all'utente di inserire gli host per ogni rete inserita precedentemente
            for(i=0 ; i<reti ; i++)
            {
                scanf("%d",&host[i]);
            }
            for (i=0; i<reti-1; i++)                                    //Tramite questo ordinamento bubble sort ordino il numero di host in modo decrescente
            {
                for (j=i+1; j<reti; j++)
                {
                    if (host[i] < host[j])
                    {
                        tmp = host[i];
                        host[i] = host[j];
                        host[j] = tmp;
                    }
                }
            }
            printf("\n");
            for(j=0 ; j<reti ; j++)                                     //Stampo tutte le reti inserite dall'utente con i rispettivi host
            {
                printf("La %d rete ha %d host: \n",j+1, host[j]);
            }
        }
            if (dec[i] >= 192 && dec[i] <= 223)
            {
                do
                {
                    printf("Inserisci il numero di reti: \n");                      //Chiedo all'utente di inserire il numero di reti
                    scanf("%d",&reti);
                }
                while(reti > 64);
                printf("\n");
                for (i=0; i<reti; i++)
                {
                    printf("Inserisci il numero di host per ogni rete: \n");        //Chiedo all'utente di inserire gli host per ogni rete inserita precedentemente
                    scanf("%d",&host[i]);
                }
                for (i=0; i<reti-1; i++)                                    //Tramite questo ordinamento selection sort ordino il numero di host in modo decrescente
                {
                    for (j=i+1; j<reti; j++)
                    {
                        if (host[i] < host[j])
                        {
                            tmp = host[i];
                            host[i] = host[j];
                            host[j] = tmp;
                        }
                    }
                }
                printf("\n");
                i=0;
                j=0;
                for (j=0; j<reti; j++)
                {
                    do
                    {
                        i++;
                    }
                    while(host[j]>pow(2,i));                                    //Ricavo i bit degli host che mi serviranno per il controllo
                    host[j]=pow(2,i);
                    i=0;
                }
                for (j=0; j<reti; j++)                                          //Eseguo il controllo della somma degli host
                {
                    somma=somma+host[j];
                }
                if(somma>253)
                {
                    printf("Non si può eseguire la richiesta");
                }
                else
                {
                    for(j=0 ; j<reti ; j++)                                     //Stampo tutte le reti inserite dall'utente con i rispettivi host
                    {
                      printf("La %d rete ha %d host: \n",j+1, host[j]);
                    }
                }
            }
}

void clear()                                                            //Tramite questa funzione l'utente richiede che venga pulita la schermata di esecuzione tramite una chiamata a sistema
{
    printf("Pulizia della Schermata in Corso");
    sleep(3);
    system("cls");                                                      //Chiamata a sistema
}

void intestazione()                                                     //Tramite questa funzione all'avvio del programma viene generata una tabella di intestazione
{
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n" , 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c\tSORRENTINO SAMUELE 4 INA\t  %c \n", 179, 179);
    printf(" %c    PROGRAMMA APP. RETI 2021/2022       %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n" , 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
}