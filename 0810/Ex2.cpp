#include <iostream>
using namespace std;


struct Livros
{
    int ID;
    string titulo;
    string autor;
    string editora;
    int ano;
};


int main(){

    const int total = 5;

   Livros livro[total];

    for (int i = 0; i < total; i++)
    {
        cout << "\n";
        cout << "Livro n "<< i + 1 << "\n"; 
        
        cout << "ID \n";
        cin >> livro[i].ID;
        cout << "titulo \n";
        cin >> livro[i].titulo;
        cout << "autor \n";
        cin >> livro[i].autor;
        cout << "editora \n";
        cin >> livro[i].editora;
        cout << "ano \n";
        cin >> livro[i].ano;
    }

     for (int i = 0; i < total; i++)
    {
        cout << "\n";
        cout << "Livro n "<< i + 1 << "\n"; 
        
        cout << "ID " << livro[i].ID << "\n";
        
        cout << "ID " << livro[i].titulo << "\n";

        cout << "ID " << livro[i].autor << "\n";

        cout << "ID " << livro[i].editora << "\n";

        cout << "ID " << livro[i].ano << "\n";
    }


}
    