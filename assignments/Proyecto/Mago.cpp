#include "Mago.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;


Mago::Mago():Personaje(),mana(0),elemento("Sin elemento"),hechizos(0){}
Mago::Mago(int mana,string elemento,int hechizos,int vida, int salud, int ataque, int nivel, int defensa, string nombre, float critico)
    :Personaje(vida,salud,ataque,nivel,defensa,nombre,critico),mana(mana),elemento(elemento),hechizos(hechizos){}
    
int Mago::getMana(){return mana;}
void Mago::setMana(int m){mana = m;}
    
int Mago::getHechizos(){return hechizos;}
void Mago::setHechizos(int h){hechizos = h;}
    
string Mago::getElemento(){return elemento;}
void Mago::setElemento(string el){elemento = el;}

bool Mago::activarCritico()const{
    return mana >= 50 && (static_cast<float>(rand())/RAND_MAX <= critico);{
        return true;
    }
        return false;
}
void Mago::imprimir()const{
    cout << "Nombre: " << getNombre() << endl;
    cout << "Nivel: " << getNivel() << endl;
    cout << "Vida maxima: " << getVida() << endl;
    cout << "Salud actual: " << getSalud() << "%" << endl;
    cout << "Defensa: " << getDefensa() << endl;
    cout << "Ataque: " << getAtaque() << endl;
    cout << "Probabilidad del critico: " << getCritico() * 100 << " % "<< endl;
    cout << "Mana: " << mana << endl;
    cout << "Elemento: " << elemento << endl;
    cout << "Numero de hechizos: " << hechizos << endl;
}