#pragma once
#include "Personaje.hpp"

class Elfo : public Personaje{ 
    private:
        int disparos;
        int precision;
    public:
        Elfo();
        Elfo(std::string nombre, float critico, int salud, int ataque, int defensa, int vida, int nivel, int experiencia, int disparos, int precision);

        int getPrecision()const;
        void setPrecision(int p);

        int getDisparos()const;
        void setDisparos(int d);

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