#include <iostream>
#include <string>
#include "Personaje.hpp"

class Guerrero : public Personaje{
    private:
    int fuerza;
    int ira;
    int armadura;
    public:
    Guerrero();
    Guerrero(int fuerza, int ira, int armadura,int vida,int salud,int ataque, int nivel, int defensa, std::string nombre, float critico);
    int getFuerza();
    void setFuerza(int f);
    int getIra();
    void setIra(int i);
    int getArmadura();
    void setArmadura(int arm);
    void recibeAtaque(int ptosAtaque)override;
    void atacar(Personaje& objetivo)override;
    bool defensaExtra()const;
    bool activarIra()const;
    bool activarCritico()override;
    bool estaVivo()const override;
    void imprimir()const override;
};