#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Guerrero.hpp"
#include "Mago.hpp"
#include "Elfo.hpp"
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    srand(static_cast<unsigned>(time(0))); 

    vector<Personaje*>personajes;
    personajes.push_back(new Guerrero(15,40,10,100,100,20,5,10,"Ares",0.2));
    personajes.push_back(new Mago(80,"Fuego",3,90,90,15,4,8,"Merlin",0.25));
    personajes.push_back(new Elfo(85,85,18,4,6,"Legolas",0.3f,0.75f,12,6));

    cout << "=== PERSONAJES ===" << endl;
    for (Personaje*p : personajes){
        cout << *p << endl;
    }

     cout << "====== COMBATE ======" << endl;
    personajes[0]->atacar(*personajes[1]);
    cout << "Después del ataque a " << personajes[1]->getNombre() << ":" << endl;
    cout << *personajes[1] << endl;

    personajes[0]->atacar(*personajes[2]);
    cout << "Después del ataque a " << personajes[2]->getNombre() << ":" << endl;
    cout << *personajes[2] << endl;

    for (Personaje* p : personajes) delete p;
    return 0;
}

    /*
    Guerrero g1(15, 40, 10, 100, 100, 20, 5, 10, "Ares", 0.2);
    Mago m1(80, "Fuego", 3, 90, 90, 15, 4, 8, "Merlin", 0.25);
    Elfo e1(0.75, 12, 85, 85, 18, 4, 6, "Legolas", 0.3, 6);

    // Imprimir info inicial
    cout << "GUERRERO:" << endl;
    g1.imprimir();
    cout << endl;

    cout << "MAGO:" << endl;
    m1.imprimir();
    cout << endl;

    cout << "ELFO:" << endl;
    e1.imprimir();
    cout << endl;

    // Simulación de ataques
    cout << "====== COMBATE ======" << endl;

    g1.atacar(m1);  // Guerrero ataca a Mago
    cout << endl;

    m1.atacar(e1);  // Mago ataca a Elfo
    cout << endl;

    e1.atacar(g1);  // Elfo ataca a Guerrero
    cout << endl;

    // Comprobar ira del Guerrero
    if (g1.activarIra()) {
        cout << g1.getNombre() << " está furioso y listo para un ataque devastador!" << endl;
    }

    // Comprobar si defensa extra del Guerrero se activa
    if (g1.defensaExtra()) {
        cout << g1.getNombre() << " activó su defensa extra!" << endl;
    }
*/
