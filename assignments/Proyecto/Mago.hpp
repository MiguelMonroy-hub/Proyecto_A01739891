#pragma once
#include "Personaje.hpp"
#include <iostream>

class Mago : public Personaje{
    private: 
        int mana;
        std::string elemento;
        int hechizo;
    public:
        Mago();
        virtual ~Mago();
        Mago(std::string nombre, float critico, int salud, int ataque, int defensa, int vida, int nivel, int experiencia, int mana, std::string elemento, int hechizo);

        int getMana()const;
        void setMana(int m);

        std::string getElemento()const;
        void setElemento(std::string e);

        int getHechizo()const;
        void setHechizo(int h);

        void generarMana();

        void puedeRevivir();
        
        int porcentajeSalud()const override;
        void imprimeBarra()const override;
        void calcularAtributos()override;
        bool activarCritico()override;
        int recibeAtaque(int ptosAtaque) override;
        void atacar(Personaje& objetivo) override;
        void obtenerExperiencia(int exp) override;
        void subirNivel()override;
        bool estaVivo()const override;
        void imprimir()const override;
};
