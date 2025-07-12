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
    bool activarCritico();
    void imprimir()const override;
};