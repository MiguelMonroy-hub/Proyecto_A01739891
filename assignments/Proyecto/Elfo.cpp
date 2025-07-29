#include "Elfo.hpp"
#include <iostream>
using namespace std;

Elfo::Elfo() : Personaje(), disparos(0), precision(0){}

Elfo::Elfo(string nombre, float critico, int salud, int ataque, int defensa, int vida, int nivel, int experiencia, int disparos, int precision)
    : Personaje(nombre, critico, salud, ataque, defensa, vida, nivel, experiencia), disparos(disparos), precision(precision) {}

int Elfo:: getPrecision()const{return precision;}
void Elfo::setPrecision(int p){precision = p;}

int Elfo:: getDisparos()const{return disparos;}
void Elfo::setDisparos(int d){disparos = d;}

int Elfo::porcentajeSalud() const {
    return (vida > 0) ? static_cast<int>((100 * salud) / vida) : 0;
}

void Elfo::imprimeBarra() const {
    int porcentaje = porcentajeSalud();
    int llenos = (porcentaje * 20) / 100;
    for (int i = 0; i < llenos; ++i) cout << '%';
    for (int i = llenos; i < 20; ++i) cout << '.';
    cout << " (" << porcentaje << "%)\n";
}

void Elfo::calcularAtributos() {
    float porcentajeSaludActual = static_cast<float>(salud) / vida;
    vida = 100 + (nivel - 1) * 100;
    ataque = 75 * nivel;
    defensa = 50 * nivel;
    salud = static_cast<int>(vida * porcentajeSaludActual);
}

bool Elfo::activarCritico(){
    float probabilidadTotal = critico + (precision / 100.0f);
    if(probabilidadTotal > 1.0f)probabilidadTotal = 1.0f;
    float oportunidad = static_cast<float>(rand()) / RAND_MAX;
    return oportunidad <= probabilidadTotal;
    /*float oportunidad = static_cast<float>(rand()) / RAND_MAX;
    return oportunidad <= critico;*/
}


/*
void Elfo::recibeAtaque(int ptosAtaque) { 
    int danio = ptosAtaque - defensa;
    if (danio < 0) danio = 0;
    salud -= danio;
    if (salud < 0) salud = 0;
}
    */
int Elfo::recibeAtaque(int ptosAtaque) {
    int danio = ptosAtaque - defensa;
    if (danio < 0) danio = 0;
    salud -= danio;
    if (salud < 0) salud = 0;
    return danio;
}

void Elfo::atacar(Personaje& objetivo) {
    if (objetivo.getSalud() <= 0) {
        std::cout << objetivo.getNombre() << " ya está derrotado. No puedes atacarlo." << std::endl;
        return;
    }

    int damage = ataque;

    if (activarCritico()) {
        damage = static_cast<int>(ataque * 1.5);
        std::cout << "Se realizó un ataque crítico." << std::endl;
    }

    bool estabaVivo = objetivo.getSalud() > 0;

    int danoReal = objetivo.recibeAtaque(damage);

    std::cout << nombre << " ataca a " << objetivo.getNombre() << " con " << damage << " puntos de ataque." << std::endl;
    std::cout << objetivo.getNombre() << " recibe " << danoReal << " puntos de daño." << std::endl;

    obtenerExperiencia(25);

    if (estabaVivo && objetivo.getSalud() <= 0) {
        std::cout << objetivo.getNombre() << " ha sido derrotado." << std::endl;
        obtenerExperiencia(75);
    }
}

/*
void Elfo::atacar(Personaje& objetivo) {
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
*/
void Elfo::obtenerExperiencia(int exp) {
    experiencia += exp;
    subirNivel();
}

void Elfo::subirNivel() {
    while (experiencia >= 100) {
        nivel++;
        experiencia -= 100;
        calcularAtributos();
        cout << nombre << " subió de nivel (" << nivel << ")" << endl;
    }
}

bool Elfo::estaVivo()const{
    return salud > 0;
}
void Elfo::imprimir() const {
    cout << "Nombre: " << getNombre() << endl;
    cout << "Nivel: " << getNivel() << endl;
    cout << "Salud: " << getSalud() << "/" << vida << endl;
    cout << "Ataque: " << getAtaque() << endl;
    cout << "Defensa: " << getDefensa() << endl;
    cout << "Porcentaje de crítico: " << getCritico() << endl;
    cout << "Experiencia: " << getExperiencia() << endl;
    cout << "Disparos: " << disparos << endl;
    cout << "Precisión: " << precision << endl;
    cout << "Porcentaje de salud: ";
    imprimeBarra();
    cout << "Estado actual: " << (estaVivo() ? "Vivo" : "Muerto") << endl;
}