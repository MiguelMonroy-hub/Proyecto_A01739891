#include "Guerrero.hpp"
#include <iostream>
using namespace std;

Guerrero::Guerrero():Personaje(),fuerza(0),ira(0),armadura(0){}
Guerrero::Guerrero(int fuerza, int ira, int armadura,int vida,int salud,int ataque, int nivel, int defensa, std::string nombre, float critico)
    :Personaje(vida,salud,ataque,nivel,defensa,nombre,critico),fuerza(fuerza),ira(ira),armadura(armadura){}
int Guerrero::getFuerza(){return fuerza;}
void Guerrero::setFuerza(int f){fuerza = f;}
int Guerrero::getIra(){return ira;}
void Guerrero::setIra(int i){i = ira;}
int Guerrero::getArmadura(){return armadura;}
void Guerrero::setArmadura(int arm){arm = armadura;}
bool Guerrero::defensaExtra()const{
    float chance = static_cast<float>(rand()) / RAND_MAX;
    return chance < .25;
}
bool Guerrero::activarIra()const{
    return ira >= 50;
}
bool Guerrero::activarCritico()const{
    float chance = static_cast<float>(rand()) / RAND_MAX;
        return (chance <= (getCritico() + fuerza * .005));
}
void Guerrero::imprimir()const{
    cout << "Nombre: " << getNombre() << endl;
    cout << "Nivel: " << getNivel() << endl;
    cout << "Vida maxima: " << getVida() << endl;
    cout << "Salud actual: " << getSalud() << "%" << endl;
    cout << "Defensa: " << getDefensa() << endl;
    cout << "Ataque: " << getAtaque() << endl;
    cout << "Probabilidad del critico: " << getCritico() * 100 << " % "<< endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Armadura(Defensa extra): " << armadura << endl;
    cout << "Ira: " << ira << endl;
}