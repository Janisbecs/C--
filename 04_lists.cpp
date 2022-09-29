 /*
Sastādīt programmu, kas ģenerē nejaušu skaitļu (skaitļu vērtības ir no - - 750 līdz +750) sarakstu, kas satur n elementus 
(1<n<150 ievada lietotājs).  
 
Ar saraksta elementiem veikt sekojošus uzdevumus (katra uzdevuma atrisinājumu izvadīt jaunā rindā):  
1) Skaitļus izvadīt uz ekrāna vienu aiz otra atdalot ar komatu un atstarpi,   
2) Saskaitīt un izvadīt uz ekrāna jaunā rindā cik iegūtajā virknē ir negatīvi un cik pozitīvi skaitļi,  
3) Visu skaitļu vidējo aritmētisko vērtību,  
4) Izvada visus saraksta pāra skaitļus vienu aiz otra, atdalot ar komatu, pa 15 skaitļiem 1 rindā,  
5) Cik sarakstā ir skaitļu, kas ir lielāki vai vienādi ar visu saraksta skaitļu vidējo aritmētisko
(kas ir noapaļots līdz veselam skaitlim), Izvadīt visus pirmskaitļus,  
6) Katru saraksta pozitīvo skaitli sadalīt pirmreizinātājos. Katru izvadīt jaunā rindā, piem. 12 = 2*2*3 
*/
#include <math.h>
#include <iostream> 
using namespace std; 

void pirmreiz(int n) {
   while (n%2 == 0){
      cout<<"2*";
      n = n/2;
   }
   for (int i = 3; i <= sqrt(n); i = i+2){
      while (n%i == 0){
         cout<<i<<"*";
         n = n/i;
      }
   }
   if (n > 2)
   cout<<n<<" ";
}

int main() { 
    int n=1, i, neg=0, poz=0, summa=0, liel=0, j=0;
    bool nosacijums=true, pirm_sk=true;
    cout << "---------------------------------------\n";

    while (nosacijums){
        cout << "Cik elemenus saturēs saraksts: ";
        cin >> n;
        if(1<n && 150>n){
            nosacijums=false;
        }
    }
    
    int numbers[n];

    for(int i=0;i<n;i++){
        numbers[i]= rand() % (+750) + (-200); 
    }
// 1
    for(int i=0;i<n;i++){
        cout<<numbers[i]<<", ";
    }
    cout<< endl;
//2 
    for(int i=0;i<n;i++){
        if(numbers[i]>0){
            poz++ ; 
        }else if(numbers[i]<0){
            neg++ ;
        }

    }
    cout << "Rindā ir "<<poz<<" pozitīvie skaitļi.\n"; 
    cout << "Rindā ir "<<neg<<" negatīvie skaitļi.\n"; 
//3 
    for(int i=0;i<n;i++){
        summa += numbers[i];
    }
    cout<<"Visu skaitļu vidējais aritmētiskais: "<< summa/n << endl;
//4
    cout<< "Pāra skaitļi: ";
    for(int i=0;i<n;i++){
        if(numbers[i]%2==0){
            if(j%15==0 && j!=0){
                cout<< endl;
            }
            cout<< numbers[i]<< ", ";
            j++;
        }
    }
    cout<< endl;
//5.1 
    for(int i=0;i<n;i++){
        summa += numbers[i];
        if (numbers[i]>=(summa/n)){
            liel ++;
        }
    }
    cout << "Sarakstā ir "<< liel << " skaitļi, kas lielāki vai vienādi ar vidējo aritmētisko - "<< summa/n;
    cout << endl; 
//5.2
    cout<< "Pirmskaitļi: ";
    for(int i=0;i<n;i++){
        if(numbers[i]<=0 || numbers[i]==1){
            pirm_sk = false;
        }
        for (j = 2; i < numbers[j]; j++) { 
            if(numbers[i]%j==0){
                pirm_sk = false;
                break;
            }
        } 
    if(pirm_sk){
        cout<< numbers[i] << ", ";
    }
    pirm_sk = true;
    }
    cout<< endl;
//6 
    cout<<"Pirmreizinātāji: \n";
    for(int i=0;i<n;i++){
        if (numbers[i]>0){
            cout<< numbers[i] <<" = ";
            pirmreiz(numbers[i]);
            cout<< endl;
        }
    }
    cout<< endl;
}




