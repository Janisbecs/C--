// 1. Uzrakstiet programmu, kas izvada pirmos 10 naturālos skaitļus. 
/*
#include <iostream> 
using namespace std; 
int main() 
{ 
 int i; 
 cout << "---------------------------------------\n";  cout << " Naturalie skaitli ir: \n"; 
 for (i = 1; i <= 10; i++) 
 { 
 cout << i << " "; 
 } 
 cout << endl; 
} 
*/

//2. Uzrakstiet programmu, kas aprēķina un izvada pirmo 10 naturālo skaitļu  summu.  
/*
#include <iostream> 
using namespace std; 

int main() 
{ 
 int i; 
 int summa;
 summa = 0; 
 cout << "---------------------------------------\n";  cout << " Naturalie skaitli ir: \n";

 for (i = 1; i <= 10; i++) { 
 summa += i;
 cout << i << " "; 
 } 

 cout << endl; 
 cout << "Pirmo 10 naturālo skaitļu summa ir "<< summa ; 
} 
*/

// 3. Uzrakstiet programmu, kas izvada pirmos N naturālos skaitļus un to summu. 
/*
#include <iostream> 
using namespace std; 

int main() { 
 int i; 
 int n;
 int summa;
 summa = 0; 

 cout << "Ievadiet, cik naturāliem skaitļiem vēlaties aprēķināt summu : ";
 cin >> n;
 cout << "---------------------------------------\n";  cout << " Pirmie "<< n << " naturālie skaitļi ir: \n";

 for (i = 1; i <= n; i++) { 
 summa += i;
 cout << i << " "; 
 } 

 cout << endl; 
 cout << "Pirmo " << n <<" naturālo skaitļu summa ir "<< summa ; 
} 
*/

// 4. Uzrakstiet programmu, kas pārbauda vai ievadītais skaitlis ir pirmskaitlis vai  nav. 
/*
#include <iostream> 
using namespace std; 

int main() { 
    int i; 
    int n;
    bool pirm_sk = true;

    cout << "---------------------------------------\n"; 
    cout << "Ievadiet pozitīvu naturālu skaitli: ";
    cin >> n;

    if(n==0 || n==1){
        pirm_sk = false;
    }
    for (i = 2; i < n; i++) { 
        if(n%i==0 ){
            pirm_sk = false;
            break;
        }
    } 
    if(pirm_sk){
        cout << "Ievadītais skaitlis "<< n << " ir pirmskaitlis";
    } else{
        cout << "Ievadītais skaitlis "<< n << " nav pirmskaitlis";
    }
    cout << endl; 
} 
*/

// 5. Uzrakstiet programmu, kas atrod visus pirmskaitļus skaitļu intervālā no N līdz  M. 
/*
#include <iostream> 
using namespace std; 

int main() { 
    int i, n, m, nn; 
    bool pirm_sk = true;

    cout << "---------------------------------------\n"; 
    cout << "Ievadiet pozitīvu sākuma intervālu: ";
    cin >> nn;
    cout << "Ievadiet pozitīvu beigu intervālu: ";
    cin >> m;

    for(n = nn; n <= m; n++ ){
        if(n==0 || n==1){
            pirm_sk = false;
        }
        for (i = 2; i < n; i++) { 
            if(n%i==0 ){
                pirm_sk = false;
                break;
            }
        }
    if(pirm_sk){
        cout << "Ievadītais skaitlis "<< n << " ir pirmskaitlis \n";
    } else{
        cout << "Ievadītais skaitlis "<< n << " nav pirmskaitlis \n";
    }   
    pirm_sk = true;
    } 
    cout << endl; 
} 
*/

// 6. Uzrakstiet programmu, kas atrod aprēķina skaitļa faktoriālu. 
/*
#include <iostream>
using namespace std;

int main() {
    int n, i, fakt;
    fakt = 1;

    cout << "Ievadiet pozitīvu skaitli, kuram noteikt faktoriālu: ";
    cin >> n;

    if (n < 0)
        cout << "Negatīvam skaitlim nav fakrtoriāla";
    else {
        for(i = 1; i <= n; ++i) {
            fakt *= i;
        }
        cout << "Skaitļa " << n << " faktoriāls ir " << fakt;    
    }
    return 0;
}
*/

// 7. Uzrakstiet programmu, kas atrod pēdējo pirmskaitli pirms lietotāja ievadītā  skaitļa. 
/*
#include <iostream> 
using namespace std; 

int main() { 
    int i, n, nn, ped_pirm; 
    bool pirm_sk = true;

    cout << "---------------------------------------\n"; 
    cout << "Ievadiet skaitli, kuram atradīsim pēdējo pirmskaitli pirms tā: ";
    cin >> nn;

    for(n = 1; n <=nn ; n++ ){
        if(n==0 || n==1){
            pirm_sk = false;
        }
        for (i = 2; i < n; i++) { 
            if(n%i==0 ){
                pirm_sk = false;
                break;
            }
        }
    if(pirm_sk){
        ped_pirm = n; 
    } 
    pirm_sk = true;
    } 

    cout <<"Pēdējais pirmskaitlis pirms "<< nn <<" ir " << ped_pirm;
    cout << endl; 
} 
*/

// 8. Uzrakstiet programmu, kas saskaita ievadītā skaitļa ciparu summu. 

#include <iostream> 
using namespace std; 

int main() { 
    int i; 
    int n;
    int summa, garums;
    summa = 0; 
    cin >> n;
    cout << "---------------------------------------\n";
    cout << "Ievadiet, kādu skaitli: ";
    cin >> n;
    string n;
    garums = n.lenght();


    for (i = 1; i <= garums; i++) { 
    summa += i;
    cout << i << " "; 
    } 

    cout << endl; 
    cout << "Pirmo " << n <<" naturālo skaitļu summa ir "<< summa ; 
} 
