#include "Combate.hpp"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);  // UTF-8 en Windows

    Combate simulacion;
    simulacion.iniciarCombate();

    return 0;
}


/*
#include <windows.h>
#include "Combate.hpp"

int main() {
    SetConsoleOutputCP(65001);

    Combate combate;

    combate.agregarPersonaje(new Elfo("Legolas", 0.25f, 100, 70, 40, 100, 1, 0, 30, 80));
    combate.agregarPersonaje(new Guerrero("Arthas", 0.2f, 150, 80, 50, 200, 1, 0, 30, 90, 20)); // aura e ira altos para revivir
    combate.agregarPersonaje(new Mago("Merlin", 0.3f, 120, 90, 30, 150, 1, 0, 70, "Fuego", 3)); // mana alto para revivir

    combate.mostrarEstado();
    combate.iniciar();

    return 0;
}
*/
/* Si quieres ocupar este codigo, necesitas tener activo los archivos Combate.hpp y Combate.cpp*/

/*#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <vector>
#include "Elfo.hpp"
#include "Guerrero.hpp"
#include "Mago.hpp"
#include "Personaje.hpp"
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    srand(static_cast<unsigned int>(time(nullptr)));

    
    vector<Personaje*> personajes;
    personajes.push_back(new Elfo ("Legolas", 0.25f, 100, 70, 40, 100, 1, 0, 30, 80));
    personajes.push_back(new Guerrero ("Arthas", 0.2f, 150, 80, 50, 200, 1, 0, 30, 50, 20));
    personajes.push_back(new Mago ("Merlin", 0.3f, 120, 90, 30, 150, 1, 0, 50, "Fuego", 3));

    
    cout << "=== Estado inicial ===\n" << endl;
    for (Personaje* p : personajes){
        cout << *p << endl;
    }

    
    cout << "\n--- Ataques ---" << endl;
    personajes[0]->atacar(*personajes[1]); 
    cout << *personajes[1] << endl;

    personajes[0]->atacar(*personajes[2]); 
    cout << *personajes[2] << endl;

    
    cout << "\n--- Prueba de sobrecarga << ---" << endl;
    cout << *personajes[0] << endl;

    
    for (Personaje* p : personajes)
        delete p;

    return 0;
}*/
    /*
    legolas.imprimir();
    cout << "\n";
    arthas.imprimir();
    cout << "\n";
    merlin.imprimir();
    cout << "\n";

    
    cout << "=== Simulación de ataques ===\n";
    legolas.atacar(arthas);
    cout << "\n";
    arthas.atacar(merlin);
    cout << "\n";
    merlin.atacar(arthas);
    cout << "\n";

    
    cout << "=== Estado después de ataques ===\n";
    legolas.imprimir();
    cout << "\n";
    arthas.imprimir();
    cout << "\n";
    merlin.imprimir();
    cout << "\n";*/


/*#include "Personaje.hpp"
#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(65001);

    Personaje p1("Legolas",.2,100,50,30,100,2,0);
    Personaje p2("Aragon",.1,120,60,40,120,3,0);

    p1.calcularAtributos();
    p2.calcularAtributos(); 
    p1.imprimir();
    "\n";
    cout << "=============================" << endl;
    p2.imprimir();
    cout << "=============================" << endl;
    "\n";
    cout << "Legolas se prepara para atacar" << endl;
    p1.atacar(p2);
    cout << "Legolas ataco a " << p2.getNombre() << endl;
    "\n";
    cout << "Aragon se prepara para atacar" << endl;
    p2.atacar(p1);
    cout << "Aragon ataco a " << p1.getNombre() << endl;
    "\n";
    cout << "Estadisticas de los jugadores" << endl;
    p1.imprimir();
    p2.imprimir();
}*/