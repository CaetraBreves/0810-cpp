#include <iostream>
using namespace std;


struct Ponto3D
{
    int x;
    int y;
    int z;

};

void DesenharPontos3D(Ponto3D pontos);
    

int main(){

    Ponto3D pontos1;
    pontos1.x = 3;
    pontos1.y = 4;
    pontos1.z = 5;

    DesenharPontos3D(pontos1);

}

void DesenharPontos3D(Ponto3D pontos){
    cout<< "X: " << pontos.x << " Y: " << pontos.y << " Z: " << pontos.z << "\n";
}