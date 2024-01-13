#include <iostream>
using namespace std;

const int MaxProdutos = 1;
const int MaxCartoes = 600; 


//CURRENT-STATE:_3.4


/*
=========================STRUCTS======================
=========================STRUCTS======================
*/
struct Produtos
{
    int cod;
    string descProd;
    double preco;
};

struct Carta{
    int id;
    int prodConsumidos;
    int conta;
};

/*
============================FUNCOES================================
============================FUNCOES================================
*/



void Listagem(Produtos produtos1[MaxProdutos]) {

        for (int i = 0; i < MaxProdutos; i++)
        {
            Produtos produto;

            cout << "Insira o codico do produto: "<< i << "\n";
            cin >> produto.cod;
        
            cout << "Insira a descricao do produto: "<< i << "\n";
            cin >> produto.descProd;
            
            cout << "Insira o preco do produto: "<< i << "\n";
            cin >> produto.preco;
            

            produtos1[i] = produto;

            
          
        }  

    }
void Vizualizar(Produtos a[MaxProdutos]) {
        for (int i = 0; i < MaxProdutos; i++)
        {

            cout << "\n";

            cout << "O codigo do produto: "<< i << ": " << a[i].cod << "\n";
            
            cout << "A descricao do produto: "<< i << ": " << a[i].descProd << "\n";
            
            cout << "O preco do produto: "<< i << ": " << a[i].preco << "\n";

            cout << "\n";
            
        }
    }


void numDeNumero() {
    int num;
    cout << "Insira o numero que o qual quira contar a partir de: \n";
    cin >> num;

    for (int i = num; i <= 600; i++)
    {
        cout << i << "\n";
    }
    
}

void ListVizNumero(){
    int opc = 0;

    Produtos produtos1[MaxProdutos];
    produtos1[MaxProdutos].cod;
    produtos1[MaxProdutos].descProd;
    produtos1[MaxProdutos].preco;

    Produtos * pProd1[MaxProdutos];
   

    cout << "Deseja: 1-Preencher Lista || 2-Vizualizar Lista ? \n";
    cin >> opc;

    switch (opc)
    {
    case 1:
    
        Listagem(produtos1);

       
        for (int i = 0; i < MaxProdutos; i++)
        {
            *pProd1[i] = produtos1[i];        
        
        }
        break;
    case 2:
  
        Vizualizar(*pProd1);

        break;
    default:
        break;
    }
    
}

/*
============================MAIN====================================
============================MAIN====================================
*/


int main() {
    int opc = 0;

    do{
        cout << "=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X= \n";
        cout << "               Bem Vindo                \n";
        cout << "        1- Numerar numeros ate 600      \n";
        cout << "  2- Listagem/Vizualizacao de produtos  \n";
        cout << "                9- sair                 \n";
        cout << "=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X= \n";
        cin >> opc;


        switch (opc)
        {
        case 1 :
            numDeNumero();

        break;

        case 2:
            ListVizNumero();    
            
        break;
        default:
            break;
        }

    }while(opc != 9);
}