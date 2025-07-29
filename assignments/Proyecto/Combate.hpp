#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Personaje.hpp"
#include "Elfo.hpp"
#include "Guerrero.hpp"
#include "Mago.hpp"

class Combate {
private:
    std::vector<Personaje*> ejercito1;
    std::vector<Personaje*> ejercito2;

    void eliminarEjercitos();
    Personaje* crearPersonajeDatos(const std::string& tipo, const std::vector<std::string>& datos);
    void batallaEjercitos( Personaje* p1, Personaje *p2);

public:
    Combate();
    ~Combate();

    void cargarEjercito(const std::string& nombreArchivo, std::vector<Personaje*>& ejercito);
    void mostrarEjercito(const std::vector<Personaje*>& ejercito) const;
    void iniciarCombate();
};