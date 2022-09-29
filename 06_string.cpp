/*
sastādīt programmu, kas pieprasa ievadīt tekstu, tekstā var būt vairāki teikumi. 
Programma saskaita cik tekstā ir:
teikumi
vārdi
burti (tikai mazie un lielie burti) 
cik tekstā ir lietoti konkrēti burti (skaitīt kopā lielos un mazos burtus, piem. a un A skaitīt pie a burtiem), 
piem. 
a burts … reizes, 
b burts … reizes, 
c burts … reizes
u.t.t.
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string teksts;
    cout << "Ievadiet tekstu bez garumzīmēm: ";
    getline (cin, teksts);
//1 
    int a = teksts.length(), teikumi=0, vardi=1, lielie=0, mazie=0; 
    for(int i=0; i<a; i++){
        if ((char)teksts[i] == 46 || teksts[i]=='!' || teksts[i]=='?'){
            teikumi ++;
        }
    }
    cout<<"Tekstā '"<<teksts<<"' bija "<< teikumi<<" teikumi.\n"; 
//2
    for(int i=0; i<a; i++){
        if ((char)teksts[i] == 32){
            vardi ++;
        }
    }
    cout<<"Tekstā '"<<teksts<<"' bija "<< vardi<<" vārdi.\n";
//3 
    for(int i=0; i<a; i++){
        if((char)teksts[i] > 64){
            if((char)teksts[i] < 91){
                lielie++;
            }
        }
    }
    cout<<"Tekstā '"<<teksts<<"' bija "<< lielie<<" lielie burti.\n";
//4 
    for(int i=0; i<a; i++){
        if((char)teksts[i] > 96){
            if((char)teksts[i] < 123){
                mazie++;
            }
        }
    }
    cout<<"Tekstā '"<<teksts<<"' bija "<< mazie<<" mazie burti.\n";
//5 

    for_each(teksts.begin(), teksts.end(), [](char &c) { c = ::tolower(c); });
    int i = 0, alphabet[26] = {0}, j=0;
    while (teksts[i] != '\0') {
        if (teksts[i] >= 'a' && teksts[i] <= 'z') {
        j = teksts[i] - 'a';
        ++alphabet[j];
        }
        ++i;
    }
    cout << "Burtu biežums:" << endl;
    for (i = 0; i < 26; i++)
        cout << char(i + 'a') << " : " << alphabet[i] << endl;
    return 0;
}


