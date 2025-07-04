#include "Personaje.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() 
{
  srand(time(0));
  
  Personaje guerrero(120,100,30,2,10,"Ogro");
  Personaje arquero(100,100,25,3,5,"Elfo");

  cout << "=====Estado inicial=====" << endl;
  guerrero.imprimir();
  arquero.imprimir();

  cout << "El ogro ataca primero" << endl;
  guerrero.atacar(arquero);

  cout << "Estado despues del ataque" << endl;
  guerrero.imprimir();
  arquero.imprimir();

  cout << "El elfo decide contratacar" << endl;
  arquero.atacar(guerrero);

  cout << "Vida actual del ogro y el elfo" << endl;
  guerrero.imprimir();
  arquero.imprimir();
  return 0;
}
