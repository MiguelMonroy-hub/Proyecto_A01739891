#include "Mago.hpp"
#include "Guerrero.hpp"
#include <iostream>
using namespace std;

Mago::Mago() : Personaje(), mana(0),elemento("desconocido"), hechizo(0){}
Mago::~Mago(){}
Mago::Mago(string nombre, float critico, int salud, int ataque, int defensa, int vida, int nivel, int experiencia, int mana, string elemento, int hechizo)
    : Personaje (nombre, critico, salud, ataque, defensa, vida, nivel,experiencia), mana(mana), elemento(elemento), hechizo(hechizo) {}

int Mago::getMana() const { return mana; }
void Mago::setMana(int m) { mana = m; }

string Mago::getElemento() const { return elemento; }
void Mago::setElemento(string e) { elemento = e; }  

int Mago::getHechizo() const { return hechizo; }
void Mago::setHechizo(int h) { hechizo = h; }

void Mago::generarMana() {
    int cantidadGenerada = 10;  

    mana += cantidadGenerada;

    if (mana > 100) mana = 100; 

    cout << nombre << " ha generado " << cantidadGenerada << " puntos de maná. ";
    cout << "Maná actual: " << mana << endl;
}

void Mago::puedeRevivir(){
    if(salud == 0 && mana >= 50){
        salud = vida / 5;
        mana -= 20;
        cout << nombre << " ha revivido" << endl;
    }
}

int Mago::porcentajeSalud()const{
    return (vida > 0) ? static_cast<int>((100 * salud) / vida) : 0;
}

void Mago::imprimeBarra() const {
    int porcentaje = porcentajeSalud();
    int llenos = (porcentaje * 20) / 100;
    for (int i = 0; i < llenos; ++i) cout << '%';
    for (int i = llenos; i < 20; ++i) cout << '.';
    cout << " (" << porcentaje << "%)\n";
}

void Mago::calcularAtributos() {
    float porcentajeSaludActual = static_cast<float>(salud) / vida;
    vida = 100 + (nivel - 1) * 100;
    ataque = 75 * nivel;
    defensa = 50 * nivel;
    salud = static_cast<int>(vida * porcentajeSaludActual);
}

bool Mago::activarCritico(){
    float probabilidad = critico;
    if (mana >= 80){
        mana = 20;
        return true;
    }
    if (mana >= 50){
        probabilidad += 0.2f;
    }
    if (probabilidad > 1.0f) probabilidad = 1.0f;
    float oportunidad = static_cast<float>(rand()) / RAND_MAX;
    return oportunidad <= probabilidad;
}

int Mago::recibeAtaque(int ptosAtaque) {
    int danio = ptosAtaque - defensa;
    if (danio < 0) danio = 0;
    salud -= danio;
    if (salud < 0) salud = 0;
    return danio;
}

void Mago::atacar(Personaje& objetivo) {
    if (objetivo.getSalud() <= 0) {
        cout << objetivo.getNombre() << " ya está derrotado. No puedes atacarlo." << endl;
        return;
    }

    int damage = ataque;

    if (activarCritico()) {
        damage = static_cast<int>(ataque * 1.5);
        cout << "Se realizó un ataque crítico." << endl;
    }

    bool estabaVivo = objetivo.getSalud() > 0;

    int danoReal = objetivo.recibeAtaque(damage);

    Guerrero* ptrGuerrero = dynamic_cast<Guerrero*>(&objetivo);
    if (ptrGuerrero != nullptr) {
        if (mana >= 40) {
            ptrGuerrero->debilitarPorMagia(mana);
        } else {
            cout << nombre << " no tiene suficiente maná para debilitar a " << ptrGuerrero->getNombre() << "." << endl;
        }
    }
    
    cout << nombre << " ataca a " << objetivo.getNombre() << " con " << damage << " puntos de ataque." << endl;
    cout << objetivo.getNombre() << " recibe " << danoReal << " puntos de daño." << endl;

    obtenerExperiencia(25);

    if (estabaVivo && objetivo.getSalud() <= 0) {
        cout << objetivo.getNombre() << " ha sido derrotado." << endl;
        obtenerExperiencia(75);
    }

    generarMana(); // Para que genere mas mana despues de atacar
}

void Mago::obtenerExperiencia(int exp) {
    experiencia += exp;
    subirNivel();
}

void Mago::subirNivel() {
    while (experiencia >= 100) {
        nivel++;
        experiencia -= 100;
        calcularAtributos();
        cout << nombre << " subió de nivel (" << nivel << ")" << endl;
    }
}

bool Mago::estaVivo()const{
    if(salud > 0){
        return true;
    }
    else{
    return false;
    }
}
void Mago::imprimir() const {
    cout << "Nombre: " << getNombre() << endl;
    cout << "Nivel: " << getNivel() << endl;
    cout << "Salud: " << getSalud() << "/" << vida << endl;
    cout << "Ataque: " << getAtaque() << endl;
    cout << "Defensa: " << getDefensa() << endl;
    cout << "Porcentaje de crítico: " << getCritico() << endl;
    cout << "Experiencia: " << getExperiencia() << endl;
    cout << "Maná: " << mana << endl;
    cout << "Elemento: " << elemento << endl;
    cout << "Hechizo: " << hechizo << endl;
    cout << "Porcentaje de salud: ";
    imprimeBarra();
    cout << "Estado actual: " << (estaVivo() ? "Vivo" : "Muerto") << endl;
}