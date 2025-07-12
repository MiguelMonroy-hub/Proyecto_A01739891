#include "Elfo.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Elfo::Elfo():Personaje(),precision(0.0),velocidad(0),disparos(0){}
Elfo::Elfo(float precision,int velocidad,int vida, int salud, int ataque, int nivel, int defensa, std::string nombre,float critico,int disparos)
    :Personaje(vida,salud,ataque,nivel,defensa,nombre,critico),precision(precision),velocidad(velocidad),disparos(disparos){}
float Elfo::getPrecision(){return precision;}
void Elfo::setPrecision(float p){precision = p;}
int Elfo::getVelocidad(){return velocidad;}
void Elfo::setVelocidad(int v){velocidad = v;}
int Elfo::getDisparos(){return disparos;}
void Elfo::setDisparos(int dis){disparos = dis;}

bool Elfo::activarCritico(){
    if(disparos >= 3 && precision >= 0.7){
        float chance = static_cast<float>(rand())/RAND_MAX;
        if (chance <= getCritico()){
            disparos -= 3;
            return true;
        }
    }
    return false;
}

void Elfo::imprimir()const{
    cout << "Nombre: " << getNombre() << endl;
    cout << "Nivel: " << getNivel() << endl;
    cout << "Vida maxima: " << getVida() << endl;
    cout << "Salud actual: " << getSalud() << "%" << endl;
    cout << "Defensa: " << getDefensa() << endl;
    cout << "Ataque: " << getAtaque() << endl;
    cout << "Probabilidad del critico: " << getCritico() * 100 << " % "<< endl;
    cout << "Precision: " << precision << " % " << endl;
    cout << "Velocidad: " << velocidad << endl;
    cout << "Disparos disponibles: " << disparos << endl;
}