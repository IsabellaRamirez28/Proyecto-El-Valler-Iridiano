# Proyecto El Valle Iridiano
## 📘 Descripción del proyecto:
Valle Iridiano es un proyecto de simulación en C++ que representa un ecosistema dinámico donde criaturas con diversas habilidades interactúan en un mapa dividido en zonas específicas (pasto, desierto y agua). El objetivo principal del juego es observar cómo las criaturas se desplazan y ocupan el espacio de manera aleatoria, destacando las características particulares de cada tipo de criatura. A través de la interacción entre diferentes especies, se exploran dinámicas de supervivencia y ocupación de territorio.
## 🧑‍💻 Manual del usuario:
### Interfaz del juego
- **El juego se desarrolla en una cuadrícula de 10x10 donde las criaturas se mueven y interactúan, el mapa incluye:**
    - Zona de pasto: Representada por (.)
    - Zona de desierto: Representada por (_)
    - Zona de agua: Representada por (~)
- Las criaturas se representan mediante los caracteres A, B y C.

## Clases Principales
- Criatura: Clase base que define los atributos comunes a todas las criaturas (nombre, reino, energía, posición)
- Centella: Criatura con habilidades ofensivas
- Metamorfita: Criatura con capacidades defensivas
- Albo: Híbrido entre Centella y Metamorfita con capacidad de vuelo
- Raiz: Criatura que puede reproducirse.
- Mapa: El mapa se presenta en la consola, indicando los diferentes terrenos y las criaturas presentes.

## Diagramas UML

```mermaid
classDiagram
    class Criatura {
        - nombre: string
        - reino: string
        - energia: int
        - posicionX: int
        - posicionY: int
        + getNombre(): string
        + getEnergia(): int
        + getPosicion(): pair<int, int>
        + recibirAtaque()
        + moverse()
        + recibirEnergia()
        + mutar()
    }
    
    class Centella {
        - poderDeAtaque: int
        + getPoderDeAtaque(): int
        + recibirAtaque(danoo: int)
        + toJason(): json
    }
    
    class Metamorfita {
       - defensas: int
        + getDefensas(): int
        + recibirAtaque(dano: int)
        + toJson(): json
    }
    
    class albo {
       - poderVolador: int
        + getPoderVolador(): int
        + recibirAtaque(dano: int)
        + toJson(): json
    }
    
    class Raiz {
         - poderDeReproduccion: int
        + getPoderDeReproduccion(): int
        + recibirAtaque(dano: int)
        + toJson(): json
    }
 
    class Mapa {
        - int x
        - int y
        - vector<Criatura*> criaturas
        + Mapa(int x, int y)
        + int getX() const
        + int getY() const
        + void agregarCriatura(Criatura* criatura)
        + void eliminarCriatura(Criatura* criatura)
        + const vector<Criatura*>& getCriaturas() const
    }
    class Entorno{
        - string nombreEntorno
    - int filas
    - int columnas
    - int energia
    - vector<Criatura*> criaturas
    - vector<vector<Mapa>> mapa
    + Entorno(string nombre_entorno, int filas, int columnas)
    + string getNombreEntorno()
    + void mostrarmapa() const
    + void moverCriaturas()
    + pair<int, int> generarPosicionAleatoria()
    + void agregarCriaturaRaiz(string, string)
    + void agregarCriaturaCentella(string, string)
    + void agregarCriaturaMetamorfita(string, string)
    + void agregarCriaturaAlbo(string, string)
    + void guardarDatos(string)
    + void atacaCriatura(string, string, int)
    + void mostrarCriaturas()
}
Entorno --> "0..*" Criatura
Entorno --> "1" Mapa : contiene (matriz)
Mapa --> "0..*" Criatura
Albo --|> Criatura
Centella --|> Criatura
Raiz --|> Criatura
Metamorfita --|> Criatura
        
    
```
    
## 🗂️ Estructura del código fuente:
## 👥 Créditos y roles del equipo:
### - Intgrantes:
- Isabella Ramirez Echeverry
- Juan Manuel Ramirez Gonzales
### - Tareas:
- División de trabajo en el codigo:
    - Mapa: Juan Manuel Ramirez
    - Criaturas: Isabella Ramirez
- Division del README:
    - Descripcion del Proyecto: Isabella Ramirez
    - Manual del usuario: Juan Manuel Ramirez
    - Estructura del codigo fuente: Isabella Ramirez
    - Creditos y roles del equipo: Juan Manuel Ramirez
