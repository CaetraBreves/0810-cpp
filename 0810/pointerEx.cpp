#include <iostream>
using namespace std;

int main(){

    int Numero = 234;
    int *pNumero = &Numero;

    *pNumero = 1456;

    cout << *pNumero << "\n";
    
    cout << &Numero << "\n";
    cout << &*pNumero << "\n";

    *pNumero = *pNumero + 200;

    cout << Numero;

    return 0;
}