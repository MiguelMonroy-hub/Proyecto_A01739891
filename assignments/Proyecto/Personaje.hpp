#pragma once
#include <string>
#include <iostream>
class Personaje{
    protected:
        std::string nombre;
        float critico;
        int salud,ataque,defensa,vida,nivel,experiencia;
    public:
        Personaje();
        virtual ~Personaje();
        Personaje(std::string nombre,float critico,int salud,int ataque,int defensa,int vida, int nivel,int experiencia);

        std::string getNombre()const;
        void setNombre(std::string nom);

        float getCritico()const;
        void setCritico(float c);

        int getSalud()const;
        void setSalud(int s);

        int getAtaque()const;
        void setAtaque(int a);

        int getDefensa()const;
        void setDefensa(int d);

        int getVida()const;
        void setVida(int v);

        int getNivel()const;
        void setNivel(int n);

        int getExperiencia()const;
        void setExperiencia(int exp);

        virtual int porcentajeSalud()const = 0;
        virtual void imprimeBarra()const = 0;
        virtual void calcularAtributos() = 0;
        virtual bool activarCritico()= 0;
        virtual int recibeAtaque(int ptosAtaque) = 0;
        virtual void atacar(Personaje& objetivo) = 0;
        virtual void obtenerExperiencia(int exp) = 0;
        virtual void subirNivel() = 0;
        virtual bool estaVivo()const = 0;
        virtual void imprimir()const = 0;

        friend std::ostream& operator<<(std::ostream& os, const Personaje& p);
};