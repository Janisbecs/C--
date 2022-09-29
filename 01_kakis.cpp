#include <iostream>
using namespace std;
// komentars

int main() {
  std::cout << R"(
 _._     _,-'""`-._
(,-.`._,'(       |\`-/|
    `-.-' \ )-`( , o o)
          `-    \`_`"'-       
)" << '\n';

  int a = 15;
  int b = 12;
  int c = 42;
  double x = a / c + b * c - c;
  std::cout << x << "\n";
  cout << sizeof(a) << "\n"; // noteikt mainīgā izmeru

  int myNum = 5;            // Integer (whole number withoutdecimals)
  double myFloatNum = 5.99; // Floating point number (with decimals)
  char myLetter = 'D';      // Character
  string myText = "Hello";  // String (text)
  bool myBoolean = true;    // Booleeeean (true or false)
}
