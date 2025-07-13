#pragma once
#include <iostream>
#include <string>
#include "Personaje.hpp"

class Mago : public Personaje{
    private:
    int mana;
    std::string elemento;
    int hechizos;
    public:
    Mago();
    Mago(int mana,std::string elemento,int hechizos,int vida, int salud, int ataque, int nivel, int defensa, std::string nombre,float critico);
    int getMana();
    void setMana(int m);
    int getHechizos();
    void setHechizos(int h);
    std::string getElemento();
    void setElemento(std::string el);
    bool activarCritico()const;
    void imprimir()const override;
};