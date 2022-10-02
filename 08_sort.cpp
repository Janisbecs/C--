/*
Sastādīt programmu, kas ģenerē nejaušu skaitu skaitļu, bet ne mazāk kā 100 un ne vairāk kā 1000 skaitļus. 
Masīvu nosaukt savā vārdā. Skaitļiem jābūt intervālā no no 1 līdz 500. 

Veikt ģenerētā skaitļu masīva sakārtošanu augošā secībā. Drīkst izmantot jebkuru no kārtošanas metodēm 
Skaitļus izvadīt rindā vienu pēc otra atdalot ar komatu un atstarpi 
Izvadīt uz ekrāna un ierakstīt failā sākotnējo skaitļu masīvu un zem tā sakārtoto masīvu 
Izvadīt uz ekrāna un failā sakārtoto masīvu pretējā/otrādā secībā 
Programmā realizēt kārtošanas izvēli, izmantojot sazarojumu (switch) 
Katru kārtošanas algoritmu realizēt atsevišķā funkcijā 
Uzdevumu realizēt ar 1 vienkāršo metodi (piem. burbuļa metodi), kas ir vienkārša no algortima viedokļa, bet neefektīva no
ātrdarbības viedokļa un 
pēc izvēles realizēt ar citu metodi, kas ir efektīva no ātrdarbības viedokļa (piem. merge, quicksort, shell vai citu) 
Abos kārtošanas algoritmos nodrošināt salīdzināšanas reižu saskaitīšanu un mainīgo vērtību maiņu skaitu. Izvadīt šos rezultātus uz 
ekrāna un failā 
Pēc vēlēšanās varat papildināt programmu ar citām kārtošanas metodēm, katru savā funkcijā 
Internetā meklējot informāciju par kārtošanas algoritmiem atlasīt vienu, kurā vislabāk būtu demonstrēts, parādīts vai kādā citādā
 ziņā noderīgs materiāls - iekopēt saiti programmas teksta komentārā. 
*/

#include <math.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std; 


int main() {
    unsigned seed = time(0);
    srand(seed);
    int a, b;
    cout << "---------------------------------------\n";

    a = rand() % ((50) - (-50) + 1)+(-50); // izveidu random sarakstu (-50/+50)
    b = rand() % ((50) - (-50) + 1)+(-50); // izveidu random sarakstu (-50/+50)
    int numbers[a][b];
}


