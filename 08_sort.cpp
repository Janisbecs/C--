/*
Sastādīt programmu, kas ģenerē nejaušu skaitu skaitļu, bet ne mazāk kā 100 un ne vairāk kā 1000 skaitļus. 
Masīvu nosaukt savā vārdā. Skaitļiem jābūt intervālā no no 1 līdz 500. 

1) Veikt ģenerētā skaitļu masīva sakārtošanu augošā secībā. Drīkst izmantot jebkuru no kārtošanas metodēm 
    Skaitļus izvadīt rindā vienu pēc otra atdalot ar komatu un atstarpi 
2) Izvadīt uz ekrāna un ierakstīt failā sākotnējo skaitļu masīvu un zem tā sakārtoto masīvu 
3) Izvadīt uz ekrāna un failā sakārtoto masīvu pretējā/otrādā secībā 
4) Programmā realizēt kārtošanas izvēli, izmantojot sazarojumu (switch) 
5) Katru kārtošanas algoritmu realizēt atsevišķā funkcijā 
    Uzdevumu realizēt ar 1 vienkāršo metodi (piem. burbuļa metodi), kas ir vienkārša no algortima viedokļa, bet neefektīva no
    ātrdarbības viedokļa un 
    pēc izvēles realizēt ar citu metodi, kas ir efektīva no ātrdarbības viedokļa (piem. merge, quicksort, shell vai citu) 
Abos kārtošanas algoritmos nodrošināt salīdzināšanas reižu saskaitīšanu un mainīgo vērtību maiņu skaitu. Izvadīt šos rezultātus uz 
ekrāna un failā 
Pēc vēlēšanās varat papildināt programmu ar citām kārtošanas metodēm, katru savā funkcijā 
Internetā meklējot informāciju par kārtošanas algoritmiem atlasīt vienu, kurā vislabāk būtu demonstrēts, parādīts vai kādā citādā
ziņā noderīgs materiāls - iekopēt saiti programmas teksta komentārāaa. 
*/

#include <math.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std; 


void printArray(int arr[], int size, ofstream &MyFile) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << ", ";
        MyFile << arr[i]<< ", ";
    cout << endl;
    MyFile << endl;
}

void default_sort(int janis[], int n){
    ofstream MyFile("teksts/kartosana.txt");
    sort(janis, janis + n); // default sort
    cout<<"Sakartots saraksts: ";
    MyFile <<"Sakartots saraksts: ";
    printArray(janis, n, MyFile); // izsauc funkciju, kas izvada sarakstu
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}


int main() {
    ofstream MyFile("teksts/kartosana.txt");
    unsigned seed = time(0);
    srand(seed);
    int lenght = rand() % ((30) - (10) + 1)+(10), janis[lenght], izvele; // min=10  max=30
    cout << "---------------------------------------\n";

    for(int i=0; i<lenght; i++){
        janis[i] = rand() % ((500) - (1) + 1)+(1);  //izveido sarakstu
    }

    int n = sizeof(janis) / sizeof(janis[0]);

//1, 2
    cout<<"Nesakartots saraksts: ";
    MyFile <<"Nesakartots saraksts: ";
    printArray(janis, n, MyFile); // izsauc funkciju, kas izvada sarakstu

    default_sort(janis, n); // izsauc funkciju, kurā ir default sort funkcija

    // sort(janis, janis + n); // default sort
    // cout<<"Sakartots saraksts: ";
    // MyFile <<"Sakartots saraksts: ";
    // printArray(janis, n); // izsauc funkciju, kas izvada sarakstu

//3 
    sort(janis, janis + n, greater<int>()); // otrada seciba

    cout<<"Sakartots saraksts otrada seciba: ";
    MyFile <<"Sakartots saraksts otrada seciba: ";

    printArray(janis, n, MyFile); // izsauc funkciju, kas izvada sarakstu
//4 
    
    cout << "Kadu sorting metodi izmantosiet(1- bubble sort  ewfwnj-2): "; // Type a number and press enter
    cin >> izvele; // Get user input from the keyboard
    switch(izvele) {
        case 1:
            bubbleSort(janis, n);
            cout << "Sorted array: \n";
            printArray(janis, n, MyFile);
            break;
        case 2:
            // code block
            break;
        default:
            cout<<"Ievadijat neatbisltošu skaitli";
    }
}


