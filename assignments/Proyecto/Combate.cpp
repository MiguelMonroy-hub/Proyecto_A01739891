#include "Combate.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;

Combate::Combate() {
    srand(static_cast<unsigned int>(time(nullptr)));
}

Combate::~Combate() {
    eliminarEjercitos();
}

void Combate::eliminarEjercitos() {
    for (auto p : ejercito1) delete p;
    for (auto p : ejercito2) delete p;
    ejercito1.clear();
    ejercito2.clear();
}

void Combate::mostrarEjercito(const vector<Personaje*>& ejercito) const {
    for (auto p : ejercito) {
        cout << *p << endl;
    }
}

Personaje* Combate::crearPersonajeDatos(const string& tipo, const vector<string>& d) {
    try {
        if (tipo == "Elfo") {
            return new Elfo(d[0], stof(d[1]), stoi(d[2]), stoi(d[3]), stoi(d[4]),
                            stoi(d[5]), stoi(d[6]), stoi(d[7]), stoi(d[8]), stoi(d[9]));
        } else if (tipo == "Guerrero") {
            return new Guerrero(d[0], stof(d[1]), stoi(d[2]), stoi(d[3]), stoi(d[4]),
                                stoi(d[5]), stoi(d[6]), stoi(d[7]), stoi(d[8]), stoi(d[9]), stoi(d[10]));
        } else if (tipo == "Mago") {
            return new Mago(d[0], stof(d[1]), stoi(d[2]), stoi(d[3]), stoi(d[4]),
                            stoi(d[5]), stoi(d[6]), stoi(d[7]), stoi(d[8]), d[9], stoi(d[10]));
        }
    } catch (const exception& e) {
        cerr << "Error al crear personaje (" << tipo << "): " << e.what() << endl;
    }
    return nullptr;
}

void Combate::cargarEjercito(const string& nombreArchivo, vector<Personaje*>& ejercito) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tipo;
        getline(ss, tipo, ',');

        vector<string> datos;
        string campo;
        while (getline(ss, campo, ',')) {
            datos.push_back(campo);
        }

        Personaje* nuevo = crearPersonajeDatos(tipo, datos);
        if (nuevo) ejercito.push_back(nuevo);
    }
    archivo.close();
}

void Combate::batallaEjercitos(Personaje* p1, Personaje* p2) {
    std::cout << "\n Batalla entre " << p1->getNombre() << " y " << p2->getNombre() << "\n";

    int ronda = 1;
    while (p1->estaVivo() && p2->estaVivo()) {
        std::cout << "Turno " << ronda << std::endl;

        
        if (p1->estaVivo() && p2->estaVivo()) {
            p1->atacar(*p2);
        }

        
        if (p2->estaVivo() && p1->estaVivo()) {
            p2->atacar(*p1);
        }

        
        if (!p1->estaVivo() || !p2->estaVivo()) {
            break;
        }

        ronda++;
    }

    
    std::cout << "\nResultado de la batalla:\n";
    std::cout << *p1 << std::endl;
    std::cout << *p2 << std::endl;

    if (p1->estaVivo() && !p2->estaVivo()) {
        std::cout << p1->getNombre() << " ha ganado la batalla.\n";
    } else if (p2->estaVivo() && !p1->estaVivo()) {
        std::cout << p2->getNombre() << " ha ganado la batalla.\n";
    } else if (!p1->estaVivo() && !p2->estaVivo()) {
        std::cout << "Ambos combatientes han sido derrotados.\n";
    }

    std::cout << "=============================\n";
}



void Combate::iniciarCombate() {
    cargarEjercito("ejercito1.txt", ejercito1);
    cargarEjercito("ejercito2.txt", ejercito2);

    cout << "\n=== Ejército 1 ===\n";
    mostrarEjercito(ejercito1);

    cout << "\n=== Ejército 2 ===\n";
    mostrarEjercito(ejercito2);

    size_t ronda = 1;
    while (!ejercito1.empty() && !ejercito2.empty()) {
        cout << "\n========== Ronda " << ronda << " ==========\n";
        size_t minSize = min(ejercito1.size(), ejercito2.size());

        for (size_t i = 0; i < minSize; ++i) {
            batallaEjercitos(ejercito1[i], ejercito2[i]);
        }

        ejercito1.erase(remove_if(ejercito1.begin(), ejercito1.end(), [](Personaje* p) {
            return !p->estaVivo();
        }), ejercito1.end());

        ejercito2.erase(remove_if(ejercito2.begin(), ejercito2.end(), [](Personaje* p) {
            return !p->estaVivo();
        }), ejercito2.end());

        ronda++;
    }

    cout << "\n=== RESULTADO FINAL ===\n";
    if (!ejercito1.empty()) {
        cout << "Ejército 1 es el vencedor.\n";
        mostrarEjercito(ejercito1);
    } else if (!ejercito2.empty()) {
        cout << "Ejército 2 es el vencedor.\n";
        mostrarEjercito(ejercito2);
    } else {
        cout << "¡Empate! Todos han caído.\n";
    }
}



/*
#include "Combate.hpp"
#include <windows.h>
using namespace std;

Combate::Combate() {
    srand(static_cast<unsigned int>(time(nullptr)));
}

Combate::~Combate() {
    for (Personaje* p : personajes)
        delete p;
}

void Combate::agregarPersonaje(Personaje* p) {
    personajes.push_back(p);
}

void Combate::mostrarEstado() {
    cout << "\n=== ESTADO ACTUAL DE TODOS ===\n" << endl;
    for (Personaje* p : personajes) {
        cout << *p << endl;
    }
}

void Combate::iniciar() {
    cout << "\n=== INICIANDO COMBATE ENTRE TODOS ===\n" << endl;

    int ronda = 1;
    while (true) {
        cout << "\n>>> Ronda " << ronda << " <<<\n" << endl;

        // Contar cuántos vivos hay
        int vivos = 0;
        for (auto p : personajes)
            if (p->estaVivo()) vivos++;

        if (vivos <= 1) {
            cout << "\nEl combate ha terminado.\n";
            break;
        }

        for (size_t i = 0; i < personajes.size(); ++i) {
            Personaje* atacante = personajes[i];
            if (!atacante->estaVivo()) continue;

            // Buscar un objetivo vivo diferente
            size_t j = (i + 1) % personajes.size();
            while (j != i && !personajes[j]->estaVivo()) {
                j = (j + 1) % personajes.size();
            }

            if (j == i) continue; // Nadie más vivo

            Personaje* objetivo = personajes[j];

            atacante->atacar(*objetivo);

            cout << "\n--- Estado tras ataque ---" << endl;
            cout << *objetivo << endl;

            // Pausa para que se vea ronda por ronda
            Sleep(1000);
        }

        ronda++;
    }

    mostrarEstado();
}
*/