#include <iostream>
using namespace std;

class skolens {        // klase
  public:        
    string vards;  // atribūts
    string uzvards;  // atribūts
    int dz_gads;      // atribūts
    skolens(string x, string y, int z) {  // konstruktors ar parametru
      vards = x;
      uzvards = y;
      dz_gads = z;
    }
};

class sakums {        // klase
  public:              
    void myMethod() {  // funkcija definēta klasē
      cout << "Skolēni: \n";
    }
};


int main() {
    sakums myObj;
    skolens skolens_1("Djanis", "Vercinskii", 1969); // Izveido skolens objektu un izsauc konstruktoru ar dažādām vērtībām
    skolens skolens_2("Brunis", "Becsssss", 2004);

    myObj.myMethod();  // izsauc metodi

    // izvada vērtības
    cout << skolens_1.vards << " " << skolens_1.uzvards << " - " << skolens_1.dz_gads << "\n";
    cout << skolens_2.vards << " " << skolens_2.uzvards << " - " << skolens_2.dz_gads << "\n";
    return 0;
}
