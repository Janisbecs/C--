/* C++ valodā sastādīt programmu, kas aprēķina kvadrātvienādojuma (ax^2+bx+c=0) saknes.
Koeficientus a, b, c programma uzaicina ievadīt lietotājam. 
Ja a ir 0, tad uzdevumu nerisina, jo tas nav kvadrātvienādojums, par ko izvada atbilstošu paziņojumu.
D=b^2−4ac
*/

#include <cmath>
#include <iostream>
using namespace std;

int main() {
  float a, b, c, dis;
  float sum;
  float x1, x2; 

  std::cout << "Ievadiet kvadrātvienādojuma ax^2+bx+c=0 koeficientus!"<< "\n";
  cout << "Ievadiet koeficientu a: ";
  cin >> a;
  cout << "Ievadiet koeficientu b: ";
  cin >> b;
  cout << "Ievadiet koeficientu c: ";
  cin >> c;

  if (a==0 || b==0 || c==0){
    std::cout << "Ievadījāt 0 , uzdevumu nerisināšu! "<< "\n";
    return 0;
  }

  dis = pow(b, 2)-4*a*c;

  if (dis>0){
    x1 = (-b+sqrt(dis))/(2*a);
    x2 = (-b-sqrt(dis))/(2*a);
    std::cout <<"Kvadrātvienādojumam ir 2 saknes: "<< x1 << " un " << x2 << "\n";
  } else if (dis==0){
    x1 = -b/(2*a);
    std::cout <<"Kvadrātvienādojumam ir 1 sakne: "<< x1;
  } else if (dis<0){
    std::cout <<"Kvadrātvienādojumam sakņu nav!";
  }
  
  return 0;
}