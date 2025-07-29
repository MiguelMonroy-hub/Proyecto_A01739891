#include "Personaje.hpp"
#include <iostream>
using namespace std;

Personaje::Personaje()
    : nombre("Desconocido"), critico(0.0), salud(0), ataque(0), defensa(0), vida(0), nivel(0), experiencia(0) {}

Personaje::~Personaje(){}

Personaje::Personaje(string nombre, float critico, int salud, int ataque, int defensa, int vida, int nivel, int experiencia)
    : nombre(nombre), critico(critico), salud(salud), ataque(ataque), defensa(defensa), vida(vida), nivel(nivel), experiencia(experiencia) {}

string Personaje::getNombre() const { return nombre; }
void Personaje::setNombre(string nom) { nombre = nom; }

float Personaje::getCritico() const { return critico; }
void Personaje::setCritico(float c) { critico = c; }

int Personaje::getSalud() const { return salud; }
void Personaje::setSalud(int s) { salud = s; }

int Personaje::getAtaque() const { return ataque; }
void Personaje::setAtaque(int a) { ataque = a; }

int Personaje::getDefensa() const { return defensa; }
void Personaje::setDefensa(int d) { defensa = d; }

int Personaje::getVida() const { return vida; }
void Personaje::setVida(int v) { vida = v; }

int Personaje::getNivel() const { return nivel; }
void Personaje::setNivel(int n) { nivel = n; }

int Personaje::getExperiencia() const { return experiencia; }
void Personaje::setExperiencia(int exp) { experiencia = exp; }

ostream& operator <<(ostream& os, const Personaje& p){
    p.imprimir();
    return os;
}

//TODA ESTA SECCION SE CONVIRTIO EN CLASE ABSTRACTA, ESTO SE COPIARA CASI IGUAL EN LAS CLASES DERIVADAS
/*int Personaje::porcentajeSalud() const {
    return (vida > 0) ? static_cast<int>((100 * salud) / vida) : 0;
}

void Personaje::imprimeBarra() const {
    int porcentaje = porcentajeSalud();
    int llenos = (porcentaje * 20) / 100;
    for (int i = 0; i < llenos; ++i) cout << '%';
    for (int i = llenos; i < 20; ++i) cout << '.';
    cout << " (" << porcentaje << "%)\n";
}

void Personaje::calcularAtributos() {
    vida = 100 + (nivel - 1) * 100;
    ataque = 75 * nivel;
    defensa = 50 * nivel;
    salud = vida;
}

bool Personaje::activarCritico() const {
    float oportunidad = static_cast<float>(rand()) / RAND_MAX;
    return oportunidad <= critico;
}

void Personaje::recibeAtaque(int ptosAtaque) { 
    int danio = ptosAtaque - defensa;
    if (danio < 0) danio = 0;
    salud -= danio;
    if (salud < 0) salud = 0;
}

void Personaje::atacar(Personaje& objetivo) {
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

    objetivo.recibeAtaque(damage);

    cout << nombre << " ataca a " << objetivo.getNombre() << " con " << damage << " puntos de ataque." << endl;
    cout << objetivo.getNombre() << " recibe " << damage << " puntos de daño." << endl;

    obtenerExperiencia(25);

    if (estabaVivo && objetivo.getSalud() <= 0) {
        cout << objetivo.getNombre() << " ha sido derrotado." << endl;
        obtenerExperiencia(75);
    }
}

void Personaje::obtenerExperiencia(int exp) {
    experiencia += exp;
    subirNivel();
}

void Personaje::subirNivel() {
    while (experiencia >= 100) {
        nivel++;
        experiencia -= 100;
        calcularAtributos();
        cout << nombre << " subió de nivel (" << nivel << ")" << endl;
    }
}

bool Personaje::estaVivo()const{
    return salud > 0;
}
void Personaje::imprimir() const {
    cout << "Nombre: " << getNombre() << endl;
    cout << "Nivel: " << getNivel() << endl;
    cout << "Salud: " << getSalud() << "/" << vida << endl;
    cout << "Ataque: " << getAtaque() << endl;
    cout << "Defensa: " << getDefensa() << endl;
    cout << "Porcentaje de crítico: " << getCritico() << endl;
    cout << "Experiencia: " << getExperiencia() << endl;
    cout << "Porcentaje de salud: ";
    imprimeBarra();
    cout << "Estado actual: " << (estaVivo() ? "Vivo" : "Muerto") << endl;
}*/
