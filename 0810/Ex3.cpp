#include <iostream>
using namespace std;

const int MaxProdutos = 2;
const int MaxCartoes = 600;

// CURRENT-STATE:_FINAL.
// IF THERE'S ANYTHING MISSING NOTIFY ME.
//@CaetraBreves

/*
=========================STRUCTS======================
=========================STRUCTS======================
*/
struct Produto
{
    int cod;
    string descProd;
    double preco;
};

struct Carta
{
    int id;
    int prodConsumidos;
    double conta;
    bool pago = false;
};

/*
============================FUNCOES================================
============================FUNCOES================================
*/
void ClientDataView(Carta (*clientes)[MaxCartoes]){
        int tempCarta = 0;

        cout << "=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X= \n";
         cout << "\n";
         cout << "INSIRA O ID DO CLIENTE QUE DESEJA VER A DATA \n";
         cout << "\n";
         cout << "=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X= \n";
         cout << "\n";
         cin >> tempCarta;
        
         cout << "CLIENT DATA" << "\n";
        cout << (*clientes)[tempCarta].id << "\n";
        cout << (*clientes)[tempCarta].conta << "\n";
        cout << (*clientes)[tempCarta].prodConsumidos << "\n";
        if((*clientes)[tempCarta].pago == true){
            cout << "Cartao pago (true) \n"
        }else{
            cout << "Cartao nao pago (false) \n"
        }
        cout << "\n";
}

void FuncaoCaixa(Carta (*clientes)[MaxCartoes], int (*countClient)){
    int tempCarta = 0;

    cout << "Insira o ID do cartao do cliente que vai sair: \n";
    cin >> tempCarta;

    cout << "O cliente n " << tempCarta << " devera pagar: " << (*clientes)[tempCarta].conta << "\n";

    (*clientes)[tempCarta].pago = true;
}

void qDeClientesAtivos(int (*countClient)) {
    cout << "De momento existem na discoteca " << (*countClient) << " clientes\n";
}

void EntradaCliente(Carta (*clientes)[MaxCartoes], int (*countClient)) {
        (*countClient)++;

        Carta tempCarta;

        tempCarta.id = (*countClient);

        tempCarta.conta = 0;

        tempCarta.prodConsumidos = 0;

        (*clientes)[*countClient] = tempCarta;
        

        cout << "cliente n " << (*countClient) << " registrado" << "\n";
         
        cout << "a-------------------- \n";
            cout << (*countClient) << "\n";
            cout <<  (*clientes)[*countClient].id << "\n";
            cout <<  (*clientes)[*countClient].conta << "\n";
            cout <<  (*clientes)[*countClient].prodConsumidos<< "\n";
            cout << "\n";
        
}

void VerfDespesas(Carta (*clientes)[MaxCartoes]){
    int tempCarta = 0;

    cout << "Insira o ID do cliente que deseja calcular a despesa de: \n";
    cin >> tempCarta;

    cout << "A despesa do cliente " << tempCarta << " e de: " << (*clientes)[tempCarta].conta << "\n"; 
}

void Listagem(Produto (*produtos)[MaxProdutos])

{

    for (int i = 0; i < MaxProdutos; i++)
    {
        Produto produto;

        cout << "Insira o codico do produto: " << i << "\n";
        cin >> produto.cod;

        cout << "Insira a descricao do produto: " << i << "\n";
        cin >> produto.descProd;

        cout << "Insira o preco do produto: " << i << "\n";
        cin >> produto.preco;

        (*produtos)[i] = produto;
    }
}

void Vizualizar(Produto (*produtos)[MaxProdutos])
{
    for (int i = 0; i < MaxProdutos; i++)
    {

        cout << "\n";

        cout << "O codigo do produto: " << i << ": " << (*produtos)[i].cod << "\n";

        cout << "A descricao do produto: " << i << ": " << (*produtos)[i].descProd << "\n";

        cout << "O preco do produto: " << i << ": " << (*produtos)[i].preco << "\n";

        cout << "\n";
    }
}

void numDeNumero()
{
    int num;
    cout << "Insira o numero que o qual quira contar a partir de: \n";
    cin >> num;

    for (int i = num; i <= 600; i++)
    {
        cout << i << "\n";
    }
}

void ListVizNumero(Produto (*produtos)[MaxProdutos])
{
    int opc = 0;

    cout << "Deseja: 1-Preencher Lista || 2-Vizualizar Lista ? \n";
    cin >> opc;

    switch (opc)
    {
    case 1:
    {
         Listagem(produtos);

        break;
    case 2:
    {
        Vizualizar(produtos);
    }


    break;
    default:
        break;
    }
    }
}

void InserirConsumos(Produto (*produtos)[MaxProdutos], Carta (*clientes)[MaxCartoes]){
    int prodCod = 0;
    int clientID = 0;

    bool verf = false;
    

    cout << "Insira o ID do cliente que deseja inserir um consumo. \n";
    cin >> clientID;
    
    cout << "Insira o codigo do produto que deseja inserir.\n";
    cin >> prodCod;

    for (int i = 0; i < MaxProdutos; i++ && (*clientes)[clientID].pago == false;)
    {
       if ((*produtos)[i].cod == prodCod)
       {

        (*clientes)[clientID].prodConsumidos++;
        (*clientes)[clientID].conta = (*clientes)[clientID].conta + (*produtos)[i].preco;
       
        verf = true;
       }
    }


    if((*clientes)[clientID].prodConsumidos == 10){
         cout << "=X=X=X=X=X=X=X=X=X=X=X=X=\n";
         cout << "\n";
         cout << "CARTAO CHEGOU AO LIMITE \n";
         cout << "\n";
         cout << "=X=X=X=X=X=X=X=X=X=X=X=X=\n";
         cout << "\n";

         cout << "O cliente n " << clientID << " devera pagar: " << (*clientes)[clientID].conta << "\n";

        (*clientes)[clientID].pago = true;

        cout << "NOVO CARTAO TERA QUE SER CRIADO \n";
         
    }


    if (verf == true)
    {
         
         cout << "=X=X=X=X=X=X=X=X= \n";
         cout << "\n";
         cout << "PRODUTO ACEITO \n";
         cout << "\n";
         cout << "=X=X=X=X=X=X=X=X= \n";
         cout << "\n";
         
    }
    else{
        cout << "=X=X=X=X=X=X=X=X= \n";
         cout << "\n";
        cout << "PRODUTO INVALIDO \n";
        cout << "\n";
         cout << "=X=X=X=X=X=X=X=X= \n";
         cout << "\n";
    }
    
    
    
}
/*
============================MAIN====================================
============================MAIN====================================
*/

int main()
{
    int opc = 0;
    Produto produtos[MaxProdutos];
    Carta clientes[MaxCartoes];
    int countClient = 0;

    do
    {
        cout << "=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X= \n";
        cout << " Bem Vindo \n";
        cout << " 1- Numerar numeros ate 600 \n";
        cout << " 2- Listagem/Vizualizacao de produtos \n";
        cout << " 3- Entrada de cliente \n";
        cout << " 4- Inserir consumos em um cliente \n";
        cout << " 5- Calcular despesas de um cliente \n";
        cout << " 6- Quantidade de clientes \n";
        cout << " 7- Saida de um cliente \n";
        cout << " 8- Ver info de um cliente \n";
        cout << " 9- sair \n";
        cout << "=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X= \n";
        cin >> opc;

        switch (opc)
        {
        case 1:
            numDeNumero();

            break;

        case 2:
            ListVizNumero(&produtos);

            break;
        case 3:
            EntradaCliente(&clientes, &countClient);
            
        break;
        case 4:
            InserirConsumos(&produtos, &clientes);

        break;
        case 5:
            VerfDespesas(&clientes);

        break;
        case 6:
            qDeClientesAtivos(&countClient);

        break;
        case 7:
            FuncaoCaixa(&clientes, &countClient);

        break;
        case 8:
            ClientDataView(&clientes);
            //FOR DEBUGING ((NOT REQUIRED IN EXCERSICE))

        break;
        default:
            break;
        }

    } while (opc != 9);
}
