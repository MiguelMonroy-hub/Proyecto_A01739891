// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.
#pragma once
#include <string>

class Personaje{
    private:
        int vida,salud,ataque,nivel,defensa;
        std::string nombre;
    public:
        Personaje();
        Personaje(int vida, int salud, int ataque, int nivel, int defensa, std::string nombre);
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

        int porcentajeSalud()const;

        void imprimeBarra()const;

        void recibeAtaque(int ptosAtaque);

        void atacar(Personaje& objetivo);

        void imprimir()const;

};  