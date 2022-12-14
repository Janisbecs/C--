/*
Programma ģenerē K (2<=K<=50) nejaušu punktu koordinātes plaknē un saglabā tās
masīvā. Programma nodrošina, ka punkti tiks ģenerēti koordinātu plaknei robežās (no
-50 līdz 50) gan pa X, gan Y asīm. K – ievada lietotājs, bet programma pārbauda vai
ievadītais skaitlis ir nepieciešamajā intervālā.
Savienojot iegūtos punktus veidojas lauzta līnija. Aprēķināt un izvadīt uz ekrāna un
failā rezult.txt:
    1) punktu koordinātas piem. (4;-7),(-45;-22),(-9;0),(0;49), ...
    2) visu nogriežņu garumus, kas savieno šos punktus (nogriežņi veidojas savienojot
    punktus tādā secībā kā tie tika ģenerēti, t.n. 1. punkts ar 2., 2. ar 3., 3. ar 4. u.t.t. n-1. ar n.),
    3) visgarākā un visīsākā nogriežņa garumu,
    4) lauztās līnijas kopējo garumu,
    5) cik punkti atrodas uz X ass, cik - uz Y ass, cik punktu ir katrā kvadrantā.
*/
#include <math.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std; 

float distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

float sum(float arr[], int n)
{
    float sum = 0; 
    for (int i = 0; i < n; i++)
    sum += arr[i];
    return sum;
}


int main() {
    ofstream MyFile("teksts/rezultati.txt");
    unsigned seed = time(0);
    srand(seed);
    int k=1;
    bool nosacijums=true;
    cout << "---------------------------------------\n";

    while (nosacijums){
        cout << "Cik punktus atliksiet koordinātu plaknē(2 līdz 50): ";
        cin >> k;
        if(2<=k && 50>=k){ // skaitļu intervāls
            nosacijums=false;
        }
    }

    int numbers[k][2];

    for (int i=0; i<k; i++){
        for (int j=0; j<2; j++){
            numbers[i][j] = rand() % ((50) - (-50) + 1)+(-50); // izveidu random sarakstu (-50/+50)
        }
    }
// 1 
    for (int i=0; i<k; i++){
        cout << i+1 <<". punkta koordinates: ";
        MyFile << i+1 <<". punkta koordinates: ";
        for (int j=0; j<2; j++){
            cout <<numbers[i][j] << "  "; // izvada sarakstu
            MyFile <<numbers[i][j] << "  ";
        }
    cout << endl;
    MyFile <<endl;
    }
//2 
    int j=0;
    float attalumi[k-1];

    for (int i=0; i<k; i++){
        if(i==k-1){
            break;
        }
        cout<<"Distance starp "<<i+1<<". un "<<i+2<<". punktu: "<< distance(numbers[i][j], numbers[i][j+1], numbers[i+1][j], numbers[i+1][j+1])<< endl;
        MyFile<<"Distance starp "<<i+1<<". un "<<i+2<<". punktu: "<< distance(numbers[i][j], numbers[i][j+1], numbers[i+1][j], numbers[i+1][j+1])<< endl;
        attalumi[i]=distance(numbers[i][j], numbers[i][j+1], numbers[i+1][j], numbers[i+1][j+1]);
    }
//3 
    int big=0, small=0;

    for (int i=0; i<k-1; i++){
        if(attalumi[i] >= attalumi[big]){
            big = i;
        }
    }
    cout<<"Visgaraka nogriezna garums: "<<attalumi[big]<< endl;
    MyFile<<"Visgarāka nogriezna garums: "<<attalumi[big]<< endl;
    
    for (int i=0; i<k-1; i++){
        if(attalumi[i] <= attalumi[small]){
            small = i;
        }
    }
    cout<<"Visisaka nogriezna garums: "<<attalumi[small]<< endl;
    MyFile<<"Visīsākā nogriežņa garums: "<<attalumi[small]<< endl;
// 4
    int n = sizeof(attalumi) / sizeof(attalumi[0]);
    cout<<"Lauztās līnijas kopējais garumms: "<<sum(attalumi, n)<< endl;
    MyFile<<"Lauztās līnijas kopējais garumms: "<<sum(attalumi, n)<< endl;

//5 (katrā kvadrantā, jo nesapratu, ko nozīmē "uz asīīm")
    int pirm_kv=0, otr_kv=0, tres_kv=0, cet_kv=0, x_ass=0, y_ass=0  ;

    for (int i=0; i<k; i++){
        if(numbers[i][j]>0 && numbers[i][j+1]>0){
            pirm_kv++;
        } else if(numbers[i][j]<0 && numbers[i][j+1]>0){
            otr_kv++;
        }else if(numbers[i][j]<0 && numbers[i][j+1]<0){
            tres_kv++;
        }else if(numbers[i][j]>0 && numbers[i][j+1]<0){
            cet_kv++;
        }else if(numbers[i][j]==0){
            x_ass++;
        }else if(numbers[i][j+1]==0){
            y_ass++;
        }
    int j=0;
    }
    cout<<"Pirmajā kvadrantā: "<< pirm_kv<< endl;
    cout<<"Otrajā kvadrantā: "<< otr_kv<< endl;
    cout<<"Trešajā kvadrantā: "<< tres_kv<< endl;
    cout<<"Ceturtajā kvadrantā: "<< cet_kv<< endl;
    cout<<"UZ x ass: "<< x_ass<< endl;
    cout<<"Uz y ass: "<< y_ass<< endl;

    MyFile<<"Pirmajā kvadrantā: "<< pirm_kv<< endl;
    MyFile<<"Otrajā kvadrantā: "<< otr_kv<< endl;
    MyFile<<"Trešajā kvadrantā: "<< tres_kv<< endl;
    MyFile<<"Ceturtajā kvadrantā: "<< cet_kv<< endl;
    MyFile<<"UZ x ass: "<< x_ass<< endl;
    MyFile<<"Uz y ass: "<< y_ass<< endl;
    MyFile.close();
    return 0; 
}