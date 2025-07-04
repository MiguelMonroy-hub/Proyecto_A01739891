# Construcción - Comandos básicos

Los comandos siguientes funcionan en un entorno de programación Linux para la compilación y ejecución de cualquier `assignment`, deben ejecutarse dentro de la carpeta del proyecto.

### Compile+Run commands
```
make
```
### Compile command
```
make compile
```
### Run command
```
make run
```

### Clean command
```
make clean
```
### Debug command
```
make debug
```
Mini-tutorial : https://u.osu.edu/cstutorials/2018/09/28/how-to-debug-c-program-using-gdb-in-6-simple-steps/

## Diagrama UML

'''mermaid

classDiagram
    class Unidad{
        -vida:int
        -salud: int
        -ataque: int
        -nivel: int
        -nombre: string
        -defensa: int
        +Unidad()
        +Unidad(vida:int,salud:int,ataque:int,nivel:int,nombre:string)
        + getVida():int
        + setVida(vida:int): void
        + getSalud():int
        + setSalud(salud:int): void
        + getAtaque():int
        + setAtaque(ataque:int): void
        + getNivel(): void
        + setNivel(nivel:int): void
        + getNombre(): void
        + setNombre(nombre:string): void
        + getDefensa(): void
        + setDefensa(defensa:int): void
        + porcentajeSalud(): int
        + imprimeBarra(): void
        + recibeAtaque(int ptosAtaque): void
        + atacar(objetivo: Unidad&): void
        + imprimir(): void
    }
