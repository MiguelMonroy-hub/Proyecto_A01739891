#include "Personaje.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Guerrero.hpp"
#include "Mago.hpp"
#include "Elfo.hpp"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0))); 


    Guerrero g1(15, 40, 10, 100, 100, 20, 5, 10, "Ares", 0.2);
    Mago m1(80, "Fuego", 3, 90, 90, 15, 4, 8, "Merlin", 0.25);
    Elfo e1(0.75, 12, 85, 85, 18, 4, 6, "Legolas", 0.3, 6);

    cout << "GUERRERO:" << endl;
    g1.imprimir();
    cout << endl;

    cout << "MAGO:" << endl;
    m1.imprimir();
    cout << endl;

    cout << "ELFO:" << endl;
    e1.imprimir();
    cout << endl;

    cout << "====== COMBATE ======" << endl;

    g1.atacar(m1);  
    cout << endl;

    m1.atacar(e1);  
    cout << endl;

    e1.atacar(g1);  
    cout << endl;
    
    if (g1.activarIra()) {
        cout << g1.getNombre() << " está furioso y listo para un ataque devastador!" << endl;
    }

    if (g1.defensaExtra()) {
        cout << g1.getNombre() << " activó su defensa extra!" << endl;
    }

    return 0;
}
