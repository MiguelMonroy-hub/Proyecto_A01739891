#include "Elfo.hpp"
#include <iostream>
#include <cstdlib> 
using namespace std;


Elfo::Elfo() : Personaje(), precision(0.0f), velocidad(0), disparos(0) {}


Elfo::Elfo(int vida, int salud, int ataque, int nivel, int defensa, std::string nombre, float critico,
           float precision, int velocidad, int disparos)
    : Personaje(vida, salud, ataque, nivel, defensa, nombre, critico),
      precision(precision), velocidad(velocidad), disparos(disparos) {}


float Elfo::getPrecision() const { return precision; }
void Elfo::setPrecision(float p) { precision = p; }

int Elfo::getVelocidad() const { return velocidad; }
void Elfo::setVelocidad(int v) { velocidad = v; }

int Elfo::getDisparos() const { return disparos; }
void Elfo::setDisparos(int dis) { disparos = dis; }


void Elfo::recibeAtaque(int ptosAtaque) {
    int danio = ptosAtaque - defensa;
    if (danio > 0) {
        salud -= danio;
        if (salud < 0) salud = 0;
    }


    if (!estaVivo() && velocidad >= 5) {
        salud = 15;
        velocidad -= 5;
    }
}


void Elfo::atacar(Personaje& objetivo) {
    int danio = ataque;
    if (activarCritico()) {
        danio *= 2;
    }
    objetivo.recibeAtaque(danio);
}


bool Elfo::activarCritico() {
    if (disparos >= 3 && precision >= 0.7f) {
        float chance = static_cast<float>(rand()) / RAND_MAX;
        if (chance <= critico) {
            disparos -= 3;
            return true;
        }
    }
    return false;
}


bool Elfo::estaVivo() const {
    return salud > 0 || velocidad >= 20;
}


void Elfo::imprimir() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Vida maxima: " << vida << endl;
    cout << "Salud actual: " << salud << "%" << endl;
    cout << "Defensa: " << defensa << endl;
    cout << "Ataque: " << ataque << endl;
    cout << "Probabilidad del critico: " << critico * 100 << " % " << endl;
    cout << "Precision: " << precision * 100 << " % " << endl;
    cout << "Velocidad: " << velocidad << endl;
    cout << "Disparos disponibles: " << disparos << endl;
    imprimeBarra();
}