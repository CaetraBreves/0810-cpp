#include <iostream>
using namespace std;

const int MaxProdutos = 10;
const int MaxCartoes = 600;


/*
=========================STRUCTS======================
=========================STRUCTS======================
*/
struct Produto
{
    
    int cod = 0;
    string descProd = "NULL";
    double preco = 0;
};

struct Consumo {
    int quantidade = 0;
    Produto produtoss;
};

struct Carta
{
    int id = 0;
    int prodConsumidos = 0;
    Consumo consumos[10];
    int nConsumos = 0;
    double conta = 0;
    bool pago = false;
};

/*
============================FUNCOES================================
============================FUNCOES================================
*/
void ClientDataView(Carta (*clientes)[MaxCartoes]){
        int tempCarta = 0;
        int opc = 0;
        int numDoConsumo;
        int quantityCount = 0;

        int count;

        bool verf = false;
        
        

        cout << "=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X= \n";
         cout << "\n";
         cout << "INSIRA O ID DO CLIENTE QUE DESEJA VER A DATA \n";
         cout << "\n";
         cout << "=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X= \n";
         cout << "\n";
         cin >> tempCarta; 

         count = (*clientes)[tempCarta].prodConsumidos;
         cout << count << "\n";
         
         cout << "CLIENT DATA" << "\n";
        cout << "ID: " << (*clientes)[tempCarta].id << "\n";
        cout << "CONTA: " << (*clientes)[tempCarta].conta << "\n";
        cout << "Consumos: " << (*clientes)[tempCarta].prodConsumidos << "\n";
        cout << "Quantidade de produtos total: ";
        for (int i = 0; i < MaxProdutos; i++)
        {
           quantityCount = quantityCount + (*clientes)[tempCarta].consumos[i].quantidade;
        }
        
        cout << "==================================================================== " << "\n";
        if((*clientes)[tempCarta].pago == true){
            cout << "Cartao pago (true) \n";
        }else{
            cout << "Cartao nao pago (false) \n";
        }
        cout << "\n";
              
        do
        {
            cout << "1- Para ver um consumo || 2- Para ver todos os consumos \n";
            cin >> opc;

            switch (opc)
            {
            case 1:
                cout << "Insira o consumo que deseja conferir:  \n";
                cin >> numDoConsumo;

                if (numDoConsumo > (*clientes)[tempCarta].prodConsumidos)
                {
                    cout << "Insira um numero de consumo valido \n";
                }else{

                    cout << "--------------------------------\n";
                    cout << "Consumo n " << numDoConsumo << " do cliente:"  << tempCarta <<"\n";
                    cout << "COD do produto no consumo selecionado: " <<(*clientes)[tempCarta].consumos[numDoConsumo].produtoss.cod << "\n";
                    cout << "Descricao do produto no consumo selecionado: " <<(*clientes)[tempCarta].consumos[numDoConsumo].produtoss.descProd << "\n";
                    cout << "preco do produto no consumo selecionado: " <<(*clientes)[tempCarta].consumos[numDoConsumo].produtoss.preco << "\n";
                    cout << "--------------------------------------------------------------\n";
                    cout << "Quantidade do produto no consumo selecionado: " <<(*clientes)[tempCarta].consumos[numDoConsumo].quantidade << "\n";
                    cout << "--------------------------------\n";
                    verf = true;
                }
                
            break;
            case 2:

                for (int i = 0; i < (*clientes)[tempCarta].prodConsumidos; i++)
                {

                    cout << "\n";
                    cout << "--------------------------------\n";
                    cout << "Consumo n " << i << " do cliente: "  << tempCarta <<"\n";
                    cout << "COD do produto no consumo selecionado: " <<(*clientes)[tempCarta].consumos[i].produtoss.cod << "\n";
                    cout << "Descricao do produto no consumo selecionado: " <<(*clientes)[tempCarta].consumos[i].produtoss.descProd << "\n";
                    cout << "preco do produto no consumo selecionado: " <<(*clientes)[tempCarta].consumos[i].produtoss.preco << "\n";
                    cout << "--------------------------------------------------------------\n";
                    cout << "Quantidade do produto no consumo selecionado: " <<(*clientes)[tempCarta].consumos[i].quantidade << "\n";
                    cout << "--------------------------------\n";              
                    cout << "\n";
                    verf = true;
                }
                
                
            default:

            break;
            }

        } while (verf == false);
        
        verf = false;
        if((*clientes)[tempCarta].pago == true){
            cout << "Cartao pago (true) \n";
        }else{
            cout << "Cartao nao pago (false) \n";
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
        
        cout << "\n";
        cout << "cliente n " << (*countClient) << " registrado" << "\n";
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

        cout << "Insira o codigo do produto: " << i << "\n";
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
    int tempQuant = 0;
    

    bool verf = false;
    

    cout << "Insira o ID do cliente que deseja inserir um consumo. \n";
    cin >> clientID;
    
    cout << "Insira o codigo do produto que deseja inserir.\n";
    cin >> prodCod;

    do //para não preencher acima do limite do cartão
    {
        cout << "insira a quantidade do produto. \n";
        cin >> tempQuant; 

        if (tempQuant > 10)
        {
            cout << "insira uma quantidade Valida \n\n";
        }
        
    } while (tempQuant > 10);;
     

    (*clientes)[clientID].consumos[(*clientes)[clientID].prodConsumidos].quantidade = tempQuant;
    //(*clientes)[clientID].consumos->quantidade Está sempre a escrever em cima do 1º
    

    

    for (int i = 0; i < MaxProdutos; i++ && (*clientes)[clientID].pago == false)  //ver se o prod é valido e se o cartão está pago
    {
       if ( prodCod == (*produtos)[i].cod) //Encontrar o produto
       {

        for (int y = 0; y < MaxProdutos; y++)// Não havia construtor a passar no (*produtos) assim, corro array dos produtos verificando se realmente correspondem (evitando reescrever o mesmo espaço)
        {
            if ((*produtos)[y].cod == prodCod)//Encontrar o produto
            {
                (*clientes)[clientID].consumos[(*clientes)[clientID].prodConsumidos].produtoss.cod = (*produtos)[y].cod; 

                (*clientes)[clientID].consumos[(*clientes)[clientID].prodConsumidos].produtoss.descProd = (*produtos)[y].descProd; 
                
                (*clientes)[clientID].consumos[(*clientes)[clientID].prodConsumidos].produtoss.preco = (*produtos)[y].preco; 
                
            }      
        }


        (*clientes)[clientID].prodConsumidos++;
        (*clientes)[clientID].conta = (*clientes)[clientID].conta + (*produtos)[i].preco * tempQuant;

        

       
       
       
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
            //listar e vizualizar produtos

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
            

        break;
        default:
            break;
        }

    } while (opc != 9);
}