/*
1.	Sastādīt programmu, kas ģenerē nejaušu skaitļu (nejauši skaitļi intervālā no [-50,50]) 
    sarakstu ar n rindām un m kolonām, n un m ievada lietotājs, pie tam 2<n,m<10. Veikt n un m pārbaudi uz piederību minētajam 
    skaitļu intervālam.   
2.	Skaitļu sarakstu (matricu) izvadīt uz ekrāna.   
3.	Aprēķināt saraksta to skaitļu skaitu, kas ir mazāki par visu skaitļu vidējo aritmētisko. 
4.	Izvadīt atbildi “ir” vai “nav” atkarībā no tā, vai dotajā sarakstā ir vai nav sastopams skaitlis `7`
    un ja ir, tad izvadīt pirmā atrastā skaitļa atrašanās vietas rindas un kolonas indeksu.   
5.	Saskaitīt un izvadīt uz ekrāna kuru skaitļu ir vairāk – pāra vai nepāra, un par cik vairāk. 
6.	Saskaitīt saraksta katras rindas esošo skaitļu summu un izvadīt uz ekrāna katras skaitļu rindas beigās, 
    summu no matricas atdalīt ar simbolu “|”.  
7.	Saskaitīt saraksta katras kolonas esošo skaitļu summu un izvadīt uz ekrāna katras skaitļu kolonas beigās, 
    summu no matricas atdalīt ar simbolu “_”. 
*/
#include <math.h>
#include <iostream> 
using namespace std; 

int main(){ 
    int n=1, m=1, i, summa=0, mazaki=0, para=0, nepara=0, row_summa=0, col_summa=0;
    bool nosacijums=true;
    cout << "---------------------------------------\n";
//1 
    while (nosacijums){
        cout << "Cik rindu būs sarakstam: ";
        cin >> n;
        if(2<n && 10>n){
            nosacijums=false;
        }
    }
    nosacijums=true;

    while (nosacijums){
        cout << "Cik kolonu būs sarakstam: ";
        cin >> m;
        if(2<m && 10>m){
            nosacijums=false;
        }
    }


    int arr[n][m];

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            arr[i][j] = -50 + (rand() % 50);
        }
    }
//2
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
//3 
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
        summa += arr[i][j];    
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            if((summa/(n*m)) > arr[i][j]){
                mazaki ++;
            }
    }
    cout<<"Sarakstā ir "<< mazaki <<" skaitļi, kas mazāki par vidējo aritmētisko "<< summa/(n*m)<<"\n";
//4 
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            if(arr[i][j]==7){
                cout<<"Sarakstā ir skaitlis 7. Rindas indekss - "<< i <<". Kolonnas indekss - "<< j <<".\n";
            }
    }
//5 
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            if(arr[i][j]%2==0){
                para++;
            } else{
                nepara++;
            }
    }
    if(para>nepara){
        cout<<"Sarakstā vairāk bija pāra skaitļu. Pāra skaitļu bija par "<< para-nepara<< " skaitļiem vairāk.\n";
    }else if(nepara>para){
        cout<<"Sarakstā vairāk bija nepāra skaitļu. Nepāra skaitļu bija par "<< nepara-para<< " skaitļiem vairāk.\n";
    }else{
        cout<<"Sarakstā bija vienāds nepāra un pāra skaitļu skaits.\n";
    }
//6 
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            row_summa += arr[i][j];
            cout << arr[i][j] << " ";
            if(j==(m-1)){
                cout<<"| "<< row_summa;
                row_summa=0;
            }
        }
        cout << endl;
    }
    cout<< endl;
//7
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    for (int i=0; i<m; i++){
        cout<<"_    ";
    }
    cout<< endl;

    for (int j=0; j<m; j++){
        for (int i=0; i<n; i++){
            col_summa += arr[i][j];
            if(i==(n-1)){
                cout<< col_summa<< " ";
                col_summa=0;
            }
        }
    }
}


