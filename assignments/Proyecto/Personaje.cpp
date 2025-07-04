//GEnera la implementación de la clase base Personaje
#include "Personaje.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Personaje::Personaje()
    : vida(100), salud(100), ataque(10), nivel(1), defensa(5), nombre("Desconocido"){}
Personaje::Personaje(int vida, int salud, int ataque, int nivel, int defensa, string nombre)
    : vida(vida),salud(salud),ataque(ataque),nivel(nivel),defensa(defensa),nombre(nombre){}

int Personaje::getVida()const{return vida;}
void Personaje::setVida(int v){vida = v;}

int Personaje::getSalud()const{return salud;}
void Personaje::setSalud(int s){salud = (s > vida) ? vida : s;}

int Personaje::getAtaque()const{return ataque;}
void Personaje::setAtaque(int a){ataque = a;}

int Personaje::getNivel()const{return nivel;}
void Personaje::setNivel(int n){nivel = n;}

int Personaje::getDefensa()const{return defensa;}
void Personaje::setDefensa(int d){defensa = d;}

string Personaje::getNombre()const{return nombre;}
void Personaje::setNombre(const std::string& nom){nombre= nom;}

int Personaje::porcentajeSalud()const{
    return (int)(((double)salud / vida)*100);
}

void Personaje::imprimeBarra()const{
    int porcentaje = porcentajeSalud();
    int llenos = (porcentaje * 20) / 100;
    for (int i = 0; i < llenos; ++i) cout << '%';
    for (int i = llenos; i < 20; ++i) cout << '.';
    cout << "(" << porcentaje << "%)\n";
}

void Personaje::recibeAtaque(int ptosAtaque){
    int damage = ptosAtaque - defensa;
    if (damage < 0) damage = 0;
    salud -= damage;
    if (salud < 0) salud = 0;
}

void Personaje::atacar(Personaje& objetivo){
    srand(time(0));
    int minDmg, maxDmg;
    if(objetivo.getNivel() > nivel){
        minDmg = 1;
        maxDmg = ataque / 2;
    } else{
        minDmg = ataque / 2;
        maxDmg = ataque;
    }
    int damage = minDmg + rand() % (maxDmg - minDmg + 1);
    cout << nombre << " ataca a " << objetivo.getNombre() << "con " << damage << " puntos de fuerza " << endl;
    objetivo.recibeAtaque(damage);
}

void Personaje::imprimir()const{
    cout << "Nombre: " << nombre << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Vida maxima: " << vida << endl;
    cout << "Ataque: " << salud << endl;
    cout << "Defensa: " << ataque << endl;
    cout << "Barra de vida: ";
    imprimeBarra();
}