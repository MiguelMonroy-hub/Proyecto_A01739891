#include "Guerrero.hpp"
#include <iostream>
using namespace std;

Guerrero::Guerrero() : Personaje(), aura(0), ira(0), armadura(0){}

Guerrero::Guerrero(string nombre, float critico, int salud, int ataque, int defensa, int vida, int nivel, int experiencia, int aura, int ira, int armadura)
    : Personaje(nombre, critico, salud, ataque, defensa, vida, nivel, experiencia), aura(aura), ira(ira), armadura(armadura) {}

int Guerrero::getAura()const{return aura;}
void Guerrero::setAura(int a){aura = a;}

int Guerrero::getIra()const{return ira;}
void Guerrero::setIra(int i){ira = i;}

int Guerrero::getArmadura()const{return armadura;}
void Guerrero::setArmadura(int a){armadura = a;}

void Guerrero::debilitarPorMagia(int mana){
    if(mana >= 40){
        ataque /= 2;
        critico = 0.0f;
        salud -= 20;
        if(salud < 0) salud = 0;

        cout << nombre << " ha sido debilitado por magia:\n";
        cout << "- Ataque reducido a " << ataque << "\n";
        cout << "- Crítico desactivado\n";
        cout << "- Salud reducida a " << salud << "\n";
    }

}

void Guerrero::puedeRevivir(){
    if(salud == 0 && aura >=20){
        salud = vida / 2;
        aura -= 0;
        cout << nombre << " ha revivido " << "gracias a su aura" << endl;
    }
}

void Guerrero::defensaExtra(){
    defensa += armadura;
}

bool Guerrero::activarIra()const{
    float oportunidad = static_cast<float>(rand()) / RAND_MAX;
    return oportunidad <= (ira / 100.0f);
}

int Guerrero::porcentajeSalud()const{
    return (vida > 0) ? static_cast<int>((100 * salud) / vida) : 0;
}

void Guerrero::imprimeBarra()const{
    int porcentaje = porcentajeSalud();
    int llenos = (porcentaje * 20) / 100;
    for (int i = 0; i < llenos; ++i) cout << '%';
    for (int i = llenos; i < 20; ++i) cout << '.';
    cout << " (" << porcentaje << "%)\n";
}

void Guerrero::calcularAtributos(){
    float porcentajeSaludActual = static_cast<float>(salud) / vida;
    vida = 100 + (nivel - 1) * 100;
    ataque = 75 * nivel;
    defensa = 50 * nivel;
    salud = static_cast<int>(vida * porcentajeSaludActual);
}

bool Guerrero::activarCritico() {
    float probabilidad = critico;
    if (ira >= 100) {
        ira = 0;
        return true;
    }
    if (activarIra()) {
        probabilidad += 0.2f;
    }
    if (probabilidad > 1.0f) probabilidad = 1.0f;
    float oportunidad = static_cast<float>(rand()) / RAND_MAX;
    bool criticoActivado = (oportunidad <= probabilidad);
    if (criticoActivado) ira = 0;
    return criticoActivado;
}

int Guerrero::recibeAtaque(int ptosAtaque) {
    int danio = ptosAtaque - defensa;
    if (danio < 0) danio = 0;
    salud -= danio;
    if (salud < 0) salud = 0;
    return danio;
}

void Guerrero::atacar(Personaje& objetivo){
    if (objetivo.getSalud() <= 0) {
        cout << objetivo.getNombre() << " ya está derrotado. No puedes atacarlo." << endl;
        return;
    }

    int damage = ataque;

    if (activarCritico()) {
        damage = static_cast<int>(ataque * 1.5);
        cout << "Se realizó un ataque crítico." << endl;
        ira = 0;
    } else {
        ira += 10;
        if (ira > 100) ira = 100;
    }

    bool estabaVivo = objetivo.getSalud() > 0;

    int danoReal = objetivo.recibeAtaque(damage);

    cout << nombre << " ataca a " << objetivo.getNombre() << " con " << damage << " puntos de ataque." << endl;
    cout << objetivo.getNombre() << " recibe " << danoReal << " puntos de daño." << endl;

    obtenerExperiencia(25);

    if (estabaVivo && objetivo.getSalud() <= 0) {
        cout << objetivo.getNombre() << " ha sido derrotado." << endl;
        obtenerExperiencia(75);
    }
}


void Guerrero::obtenerExperiencia(int exp){
    experiencia += exp;
    subirNivel();
}
        
void Guerrero::subirNivel(){
    while (experiencia >= 100) {
        nivel++;
        experiencia -= 100;
        calcularAtributos();
        cout << nombre << " subió de nivel (" << nivel << ")" << endl;
    }
}

bool Guerrero::estaVivo()const{
    return salud > 0;
}
        
void Guerrero::imprimir()const{
    cout << "Nombre: " << getNombre() << endl;
    cout << "Nivel: " << getNivel() << endl;
    cout << "Salud: " << getSalud() << "/" << vida << endl;
    cout << "Ataque: " << getAtaque() << endl;
    cout << "Defensa: " << getDefensa() << endl;
    cout << "Porcentaje de crítico: " << getCritico() << endl;
    cout << "Experiencia: " << getExperiencia() << endl;
    cout << "Aura: " << aura << endl;
    cout << "Ira: " << ira << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Porcentaje de salud: ";
    imprimeBarra();
    cout << "Estado actual: " << (estaVivo() ? "Vivo" : "Muerto") << endl;
}