/*#pragma once
#include <iostream>
#include <string>
#include "Personaje.hpp"

class Elfo : public Personaje{
    private:
    float precision;
    int velocidad;
    int disparos;
    public:
    Elfo();
    Elfo(float precision,int velocidad,int vida, int salud, int ataque, int nivel, int defensa, std::string nombre,float critico,int disparos);
    float getPrecision();
    void setPrecision(float p);
    int getVelocidad();
    void setVelocidad(int v);
    int getDisparos();
    void setDisparos(int dis);
    void recibeAtaque(int ptosAtaque)override;
    void atacar(Personaje& objetivo)override;
    bool activarCritico()override;
    bool estaVivo()const override;
    void imprimir()const override;
};*/

#pragma once
#include <iostream>
#include <string>
#include "Personaje.hpp"

class Elfo : public Personaje {
private:
    float precision;
    int velocidad;
    int disparos;
public:
    Elfo();
    Elfo(int vida, int salud, int ataque, int nivel, int defensa, std::string nombre, float critico,
         float precision, int velocidad, int disparos);

    float getPrecision() const;
    void setPrecision(float p);

    int getVelocidad() const;
    void setVelocidad(int v);

    int getDisparos() const;
    void setDisparos(int d);

    
    void recibeAtaque(int ptosAtaque) override;
    void atacar(Personaje& objetivo) override;
    bool activarCritico() override;
    void imprimir() const override;
    bool estaVivo() const override;
};