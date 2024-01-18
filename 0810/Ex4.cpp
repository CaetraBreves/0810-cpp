#include <iostream>
using namespace std;

const int maxTrabalhadores = 100;

//CURRENT_STATE:_FINAL
//HAVENT_TESTED
// IF THERE'S ANYTHING MISSING NOTIFY ME.
//@CaetraBreves

/*

4. Empresa de construção civil

Uma empresa de construção civil pretende uma aplicação informática de gestão de recursos humanos. A empresa não prevê ultrapassar os 100 funcionários. Os dados dos funcionários são os seguintes: o número, o nome, a categoria, o vencimento e a data de entrada dos funcionários da empresa

4.1 Defina as estruturas de dados;

4.2 Escreva uma função para ler os dados de um funcionário;

4.3 Escreva uma função para listar os dados de um funcionário;

4.4 Escreva uma função para ler os dados dos n funcionários da empresa;

4.5 screva uma função para listar os dados dos n funcionários da empresa.

Um pouco confuso....
*/

//=====================STRUCTS===========================

struct Trabalhador
{
   int numero;
   string nome;
   string categoria;
   double vencimento;
   string dataDeEntrada;

};



//=====================FUNCITONS=========================
void LerNTrab(Trabalhador (*Trabalhadores)[maxTrabalhadores], int (*nTrabalhadores)){
    
    for (int i = 0; i < (*nTrabalhadores); i++)
    {
        cout << "\n";
        cout << "--------------------------------------------------\n";
        cout << "TRABALHADOR N: "<< i;
        cout << "NUMERO: \t" <<  (*Trabalhadores)[i].numero;
        cout << "NOME: \t" <<  (*Trabalhadores)[i].nome;
        cout << "CATEGORIA: \t" <<  (*Trabalhadores)[i].categoria;
        cout << "VENCIMENTO: \t" <<  (*Trabalhadores)[i].vencimento;
        cout << "DATA DE ENTRADA: \t" <<  (*Trabalhadores)[i].dataDeEntrada;
        cout << "--------------------------------------------------\n";
        cout << "\n";
    }
    
}

void EditarTrab(Trabalhador (*Trabalhadores)[maxTrabalhadores]){
    int tempTrab = 0;

    

    cout << "insira o trabalhador do qual deseja editar \n";
    cin >> tempTrab;

    cout << "Insira o novo nome do trabalhador: " << tempTrab << "\n";
    cin >> (*Trabalhadores)[tempTrab].nome;
    cout << "Insira a nova categoria do trabalhador: " << tempTrab << "\n";
    cin >> (*Trabalhadores)[tempTrab].categoria;
    cout << "Insira o novo vencimento do trabalhador: " << tempTrab << "\n";
    cin >> (*Trabalhadores)[tempTrab].vencimento;
    cout << "Insira a nova data de entrada do trabalhador: " << tempTrab << "\n";
    cin >> (*Trabalhadores)[tempTrab].dataDeEntrada;


}

void RegistrarNTrab(Trabalhador (*Trabalhadores)[maxTrabalhadores], int (*nTrabalhadores)){
    int quantidReg = 0;
    bool valid = false;

    do
    {
        cout << "insira a quantidade de trabalhadores que quer registar: \n";
    cin >> quantidReg;
    if (quantidReg + (*nTrabalhadores) <= maxTrabalhadores)
    {
        valid= true;
    }else{

    }
    } while (valid != true);

    cout << "Os trabalhadores: \n";

    for (int i = 0; i < quantidReg; i++)
    {
        (*nTrabalhadores)++;

        Trabalhador tempTrab;

        tempTrab.numero = (*nTrabalhadores);

        (*Trabalhadores)[*nTrabalhadores] = tempTrab;
        
        
        cout <<(*nTrabalhadores)<< "\n";
    }
    cout << "Foram registrados (sem infos, so numero)\n";
    
}

void RegistrarTrab(Trabalhador (*Trabalhadores)[maxTrabalhadores], int (*nTrabalhadores)){
    (*nTrabalhadores)++;
    
    cout << "Insira o numero do trabalhador \n";
    cin >> (*Trabalhadores)[*nTrabalhadores].numero; 

    cout << "Insira o nome do trabalhador \n";
    cin >>  (*Trabalhadores)[*nTrabalhadores].nome; 

    cout << "Insira a categoria do trabalhador \n";
    cin >>  (*Trabalhadores)[*nTrabalhadores].categoria; 

    cout << "Insira o vencimento do trabalhador \n";
    cin >>  (*Trabalhadores)[*nTrabalhadores].vencimento; 

    cout << "Insira a Data de Entrada do trabalhador \n";
    cin >>  (*Trabalhadores)[*nTrabalhadores].dataDeEntrada; 


}

void LerTrab(Trabalhador (*Trabalhadores)[maxTrabalhadores], int (*nTrabalhadores)){


    int tempTrab = 0;

    cout << "Insira o numero do trabalhador do qual deseja ver os dados: \n\n";
    cin >> tempTrab;

    if (tempTrab <= (*nTrabalhadores))
    {
        cout << "DATA DO TRABALHADOR "<< tempTrab;
        cout << "NUMERO: \t" <<  (*Trabalhadores)[tempTrab].numero;
        cout << "NOME: \t" <<  (*Trabalhadores)[tempTrab].nome;
        cout << "CATEGORIA: \t" <<  (*Trabalhadores)[tempTrab].categoria;
        cout << "VENCIMENTO: \t" <<  (*Trabalhadores)[tempTrab].vencimento;
        cout << "DATA DE ENTRADA: \t" <<  (*Trabalhadores)[tempTrab].dataDeEntrada;
    }
    
    
}
//=====================MAIN==============================

int main(){
    int opc = 0;

    int nTrabalhadores = 0;
    Trabalhador trabalhadores[maxTrabalhadores];
    
    do
    {
        cout << "=X=X=X=X=X=X=X=X=X=X=X=X=X=X= \n";
        cout << "BEM VINDO \n";
        cout << "1-registrar um trabalhador \n";
        cout << "2-ler um trabalhador \n";
        cout << "3-registrar n trabalhadores (Criacao sem dados) \n";
        cout << "4-editar dados do trabalhador x \n";
        cout << "5-Ler todos os trabalhadores \n";
        cout << "9-Sair \n";
        cout << "=X=X=X=X=X=X=X=X=X=X=X=X=X=X= \n";
        cin >> opc;

        switch (opc)
        {
        case 1:
            RegistrarTrab(&trabalhadores, &nTrabalhadores);

        break;
        
        case 2:
            LerTrab(&trabalhadores, &nTrabalhadores);

        break;
        case 3:
            RegistrarNTrab(&trabalhadores, &nTrabalhadores);

        break;
        case 4:
            EditarTrab(&trabalhadores);

        break;
        case 5:
            LerNTrab(&trabalhadores, &nTrabalhadores);

        break;

        default:
            break;
        }
    } while (opc != 9);
    
    
}