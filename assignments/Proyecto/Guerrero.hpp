#pragma once
#include "Personaje.hpp"
#include <iostream>
#include <string>

class Guerrero : public Personaje{
    private:
        int aura; //Servira para revivirlo
        int ira; // Puede aumentar el porcentaje de critico
        int armadura; //Aumenta la defensa
    public:
        Guerrero();
        Guerrero(std::string nombre, float critico,int salud, int ataque, int defensa, int vida, int nivel, int experiencia, int aura, int ira, int armadura);

        int getAura()const;
        void setAura(int a);

        int getIra()const;
        void setIra(int i);

        int getArmadura()const;
        void setArmadura(int a);

        void debilitarPorMagia(int mana);

        void puedeRevivir();

        void defensaExtra();

        bool activarIra()const;

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