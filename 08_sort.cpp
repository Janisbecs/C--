/*
Sastādīt programmu, kas ģenerē nejaušu skaitu skaitļu, bet ne mazāk kā 100 un ne vairāk kā 1000 skaitļus. 
Masīvu nosaukt savā vārdā. Skaitļiem jābūt intervālā no no 1 līdz 500. 

1) Veikt ģenerētā skaitļu masīva sakārtošanu augošā secībā. Drīkst izmantot jebkuru no kārtošanas metodēm 
    Skaitļus izvadīt rindā vienu pēc otra atdalot ar komatu un atstarpi 
2) Izvadīt uz ekrāna un ierakstīt failā sākotnējo skaitļu masīvu un zem tā sakārtoto masīvu 
3) Izvadīt uz ekrāna un failā sakārtoto masīvu pretējā/otrādā secībā 
4) Programmā realizēt kārtošanas izvēli, izmantojot sazarojumu (switch) 
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
    ofstream MyFile("teksts/kartosana.txt");
    unsigned seed = time(0);
    srand(seed);
    int lenght = rand() % ((100) - (10) + 1)+(10), janis[lenght]; // min=10  max=100
    cout << "---------------------------------------\n";

    for(int i=0; i<lenght; i++){
        janis[i] = rand() % ((500) - (1) + 1)+(1);  //izveido sarakstu
    }

//1, 2
    cout<<"Nesakartots saraksts: ";
    MyFile <<"Nesakartots saraksts: ";

    for(int i=0; i<lenght; i++){ // izvada nesakartotu sarakstu 
        cout<< janis[i]<< ", ";
        MyFile << janis[i]<< ", ";
    }
    cout<< endl;
    MyFile << endl;

    int n = sizeof(janis) / sizeof(janis[0]);
    sort(janis, janis + n); // default sort

    cout<<"Sakartots saraksts: ";
    MyFile <<"Sakartots saraksts: ";

    for(int i=0; i<lenght; i++){ // izvada sakartotu sarakstu 
        cout<< janis[i]<< ", ";
        MyFile << janis[i]<< ", ";
    }
    cout<<endl;
    MyFile<<endl;
//3 
    sort(janis, janis + n, greater<int>());

    cout<<"Sakartots saraksts otrada seciba: ";
    MyFile <<"Sakartots saraksts otrada seciba: ";

    for(int i=0; i<lenght; i++){ // izvada sakartotu sarakstu otrada seciba 
        cout<< janis[i]<< ", ";
        MyFile << janis[i]<< ", ";
    }



}


