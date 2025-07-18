// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.
#pragma once
#include <string>
#include <iostream>

class Personaje{
    protected:
        int vida,salud,ataque,nivel,defensa;
        std::string nombre;
        float critico;
    public:
        Personaje();
        Personaje(int vida, int salud, int ataque, int nivel, int defensa, std::string nombre,float critico);
        int getVida()const;
        void setVida(int v);

        int getSalud()const;
        void setSalud(int s);

        int getAtaque()const;
        void setAtaque(int a);

        int getNivel()const;
        void setNivel(int n);

        int getDefensa()const;
        void setDefensa(int d);

        std::string getNombre()const;
        void setNombre(const std::string& nom);

        float getCritico()const;
        void setCritico(float c);

        int porcentajeSalud()const;

        void imprimeBarra()const;

        virtual void recibeAtaque(int ptosAtaque) = 0;
        virtual void atacar(Personaje& objetivo) = 0;
        virtual bool activarCritico() = 0;
        virtual void imprimir()const = 0;
        virtual bool estaVivo()const = 0;

        friend std::ostream& operator<<(std::ostream& os, const Personaje& p);
};  