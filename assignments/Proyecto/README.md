# Ejercicio - Hello World

Este proyecto tiene la estructura básica para cualquier proyecto C++. 

La carpeta contiene el código fuente y el archivo de construcción ```make```.

La carpeta `build` contiene el codigo binario generado por el archivo de construcción ```make```.

Consulta el archivo assignments/README.md para instrucciones sobre la compilación y ejecución del proyecto.

## Diagrama UML

```mermaid
classDiagram
    Personaje -- Combate
    Personaje <|-- Mago
    Personaje <|-- Elfo
    Personaje <|-- Guerrero

class Personaje {
    <<abstract>>
    - nombre: string
    - critico: float
    - salud: int
    - ataque: int
    - defensa: int
    - vida: int
    - nivel: int
    - experiencia: int

    + Personaje()
    + Personaje(string, float, int, int, int, int, int, int)

    + getNombre(): string
    + setNombre(string): void
    + getCritico(): float
    + setCritico(float): void
    + getSalud(): int
    + setSalud(int): void
    + getAtaque(): int
    + setAtaque(int): void
    + getDefensa(): int
    + setDefensa(int): void
    + getVida(): int
    + setVida(int): void
    + getNivel(): int
    + setNivel(int): void
    + getExperiencia(): int

    + porcentajeSalud(): int
    + imprimeBarra(): void
    + calcularAtributos(): void
    + activarCritico(): bool
    + recibeAtaque(int): int
    + atacar(Personaje&): void
    + obtenerExperiencia(int): void
    + subirNivel(): void
    + estaVivo(): bool
    + imprimir(): void

    + operator<<(ostream&, const Personaje&): friend
}

class Combate{
    - ejercito1 : vector~Personaje*~
    - ejercito2 : vector~Personaje*~
    - eliminarEjercitos() : void
    - crearPersonajeDatos(tipo : string, datos : vector~string~) : Personaje*
    - batallaEjercitos(p1 : Personaje*, p2 : Personaje*) : void
    + Combate()
    + ~Combate()
    + cargarEjercito(nombreArchivo : string, ejercito : vector~Personaje*&~) : void
    + mostrarEjercito(ejercito : vector~Personaje*~) const : void
    + iniciarCombate() : void
}

class Mago {
    - mana: int
    - elemento: string
    - hechizo: int

    + Mago()
    + Mago(string, float, int, int, int, int, int, int, int, string, int)

    + getMana(): int
    + setMana(int): void
    + getElemento(): string
    + setElemento(string): void
    + getHechizo(): int
    + setHechizo(int): void

    + generarMana(): void
    + puedeRevivir(): void
    + porcentajeSalud(): int
    + imprimeBarra(): void
    + calcularAtributos(): void
    + activarCritico(): bool
    + recibeAtaque(int): int
    + atacar(Personaje&): void
    + obtenerExperiencia(int): void
    + subirNivel(): void
    + estaVivo(): bool
    + imprimir(): void
}

class Elfo {
    - precision: int
    - disparos: int

    + Elfo()
    + Elfo(string, float, int, int, int, int, int, int, int, int)

    + getPrecision(): int
    + setPrecision(int): void
    + getDisparos(): int
    + setDisparos(int): void

    + porcentajeSalud(): int
    + imprimeBarra(): void
    + calcularAtributos(): void
    + activarCritico(): bool
    + recibeAtaque(int): int
    + atacar(Personaje&): void
    + obtenerExperiencia(int): void
    + subirNivel(): void
    + estaVivo(): bool
    + imprimir(): void
}

class Guerrero {
    - aura: int
    - ira: int
    - armadura: int

    + Guerrero()
    + Guerrero(string, float, int, int, int, int, int, int, int, int, int)

    + getAura(): int
    + setAura(int): void
    + getIra(): int
    + setIra(int): void
    + getArmadura(): int
    + setArmadura(int): void

    + debilitarPorMagia(int): void
    + puedeRevivir(): void
    + defensaExtra(): void
    + activarIra(): bool
    + porcentajeSalud(): int
    + imprimeBarra(): void
    + calcularAtributos(): void
    + activarCritico(): bool
    + recibeAtaque(int): int
    + atacar(Personaje&): void
    + obtenerExperiencia(int): void
    + subirNivel(): void
    + estaVivo(): bool
    + imprimir(): void
}
``` 