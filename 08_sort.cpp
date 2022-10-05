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
ziņā noderīgs materiāls - iekopēt saiti programmas teksta komentārāaaa. 
*/

#include <math.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std; 
int quick_reizes = 0, marge_reizes = 0, bubble_reizes=0 ;

int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);
void merge(int array[], int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);
void printArray(int arr[], int size);
void default_sort(int janis[], int n);
void bubbleSort(int arr[], int n);

int main() {
    ofstream MyFile("teksts/kartosana.txt");
    unsigned seed = time(0);
    srand(seed);
    int lenght = rand() % ((30) - (10) + 1)+(10), janis[lenght], janis_2[lenght], janis_3[lenght], janis_4[lenght], izvele; // min=10  max=30
    cout << "---------------------------------------\n";

    for(int i=0; i<lenght; i++){
        janis[i] = rand() % ((500) - (1) + 1)+(1);  //izveido sarakstu
    }

    int n = sizeof(janis) / sizeof(janis[0]);

    for(int i=0; i<lenght; i++){
        janis_2[i] = janis[i];
        janis_3[i] = janis[i];
        janis_4[i] = janis[i];
    }

//1, 2
    cout<<"Nesakartots sarakstss: ";
    MyFile <<"Nesakartots sarakstss: ";
    printArray(janis, n); // izsauc funkciju, kas izvada sarakstu
    default_sort(janis, n); // izsauc funkciju, kurā ir default sort funkcija
//3 
    cout<<"Sakartots saraksts otrada seciba: ";
    MyFile <<"Sakartots saraksts otrada seciba: ";
    sort(janis, janis + n, greater<int>()); // otrada seciba
    printArray(janis, n); // izsauc funkciju, kas izvada sarakstu
//4 
    while(true){
        cout << "Kadu sorting metodi izmantosiet(1- bubble sort : 2-merge : 3-quick sort) ievadiet tikai ciparu: "; // Type a number and press enter
        cin >> izvele; // Get user input from the keyboard

        switch(izvele) {
            case 1:
                bubbleSort(janis_2, n);
                cout << "Sakārtots saraksts ar "<< bubble_reizes<<" mainīgo maiņām pielietojot bubble sort metodi: ";
                printArray(janis_2, n);
                break;
            case 2:
                mergeSort(janis_3, 0, n - 1);
                cout << "Sakārtots saraksts ar "<<marge_reizes <<" mainīgo maiņām pielietojot merge sort metodi: ";
                printArray(janis_3, n);
                break;
            case 3: 
                quickSort(janis_4, 0, n - 1);
                cout << "Sakārtots saraksts ar "<< quick_reizes<<" mainīgo maiņām izmantojot quick sort metodi: ";
                printArray(janis_4, n);
                break;
            default:
                cout<<"Ievadijat neatbisltošu skaitli";
        }
    }
}


void printArray(int arr[], int size) {
    ofstream MyFile("teksts/kartosana.txt");
    for (int i = 0; i < size; i++){
        cout << arr[i] << ", ";
        MyFile << arr[i]<< ", ";
    }
    cout << endl;
    MyFile << endl;
}

void default_sort(int janis[], int n){
    ofstream MyFile("teksts/kartosana.txt");
    sort(janis, janis + n); // default sort
    cout<<"Sakartots saraksts: ";
    MyFile <<"Sakartots saraksts: ";
    printArray(janis, n); // izsauc funkciju, kas izvada sarakstu
}

void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                bubble_reizes++ ;
            }
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
        *rightArray = new int[subArrayTwo];
    marge_reizes++;
    marge_reizes++;
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++){
        leftArray[i] = array[left + i];
        marge_reizes++;
    }
    for (auto j = 0; j < subArrayTwo; j++){
        rightArray[j] = array[mid + 1 + j];
        marge_reizes++;
    }
 
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
                marge_reizes++;
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
            marge_reizes++;
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    quick_reizes++;
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
            quick_reizes++;
        }
    }
 
    return pivotIndex;
}
 