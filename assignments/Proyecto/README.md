# Ejercicio - Hello World

Este proyecto tiene la estructura básica para cualquier proyecto C++. 

La carpeta contiene el código fuente y el archivo de construcción ```make```.

La carpeta `build` contiene el codigo binario generado por el archivo de construcción ```make```.

Consulta el archivo assignments/README.md para instrucciones sobre la compilación y ejecución del proyecto.

## Diagrama UML

```mermaid
classDiagram
        Personaje <|--Mago
        Personaje <|--Elfo
        Personaje <|--Guerrero
            class Personaje{
                - vida: int
                - salud: int
                - ataque: int
                - nivel: int
                - nombre: string
                - defensa: int
                # critico: float

                +Personaje()
                +Personaje(int,int,int,int,int,nombre:string,float)
                + getVida() int
                + setVida(int) void
                + getSalud() int
                + setSalud(int) void
                + getAtaque() int
                + setAtaque(int) void
                + getNivel() void
                + setNivel(int) void
                + getNombre() void
                + setNombre(string) void
                + getDefensa() void
                + setDefensa(int) void
                + getCritico() float
                + setCritico(float) void
                + porcentajeSalud() int
                + imprimeBarra() void
                + recibeAtaque(int) void
                + atacar(Personaje &) void
                + imprimir() void
            }
            
            class Mago{
                - mana: int
                - elemento: string
                - hechizos: int

                + Mago()
                + Mago(,int,string,int,int,int,int,int,int,nombre:string,float)
                + getMana() int
                + setMana(int) void
                + getHechizos() int
                + setHechizos(int) void
                + getElemento() string
                + setElemento(string) void
                + activarCritico() bool
                + imprimir() void
            }

            class Elfo{
                - precision: float
                - velocidad: int
                - disparos: int

                + Elfo()
                + Elfo(float,int,int,int,int,int,int,int,nombre:string,float)
                + getPrecision() float
                + setPrecision(float) void
                + getVelocidad() int
                + setVelocidad(int) void
                + getDisparos() int
                + setDisparos(float) void
                + activarCritico() bool
                + imprimir() void
            }

            class Guerrero{
                - fuerza: int
                - ira: int
                - armadura: int

                + Guerrero()
                + Guerrero(int,int,int,int,int,int,int,int,nombre:string,float)
                + getFuerza() int
                + setFuerza(int) void
                + getIra() int
                + setIra(int) void
                + getArmadura() int
                + setArmadura(int) void
                + defensaExtra() bool
                + activarIra() bool
                + activarCritico() bool
                + imprimir() void
            }
``` 