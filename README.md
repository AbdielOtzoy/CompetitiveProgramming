# 🏆 Competitive Programming Solutions

Este repositorio contiene mis soluciones a problemas de programación competitiva, principalmente de **Codeforces**.

## 📁 Estructura del Proyecto

Los problemas siguen la siguiente convención de nombres:
```
[ContestNum][Problem]_[ProblemName].cpp
```

**Ejemplo:** `274B_Tree.cpp`
- `274` = Número del contest
- `B` = Letra del problema  
- `Tree` = Nombre del problema

## 🛠️ Makefile

El Makefile automatiza el proceso de desarrollo con las siguientes características:

- **Compilación optimizada**: Usa `g++` con flags `-std=c++17 -Wall -Wextra -O2`
- **Ejecución simplificada**: `make archivo` (sin extensión) compila, ejecuta y elimina automáticamente
- **Limpieza automática**: Los ejecutables se eliminan después de cada ejecución
- `make clean` - Limpia cualquier ejecutable que pueda quedar

**Ejemplo de uso:** `make 274B_Tree` compila y ejecuta `274B_Tree.cpp`

## 📝 Plantilla Base

Cada solución utiliza una plantilla optimizada que incluye:

### Características principales:
- **Headers optimizados**: `#include <bits/stdc++.h>` para acceso completo a la STL
- **Debugging avanzado**: Macro `dbg()` para imprimir variables en modo LOCAL
- **Operadores personalizados**: Impresión automática de pairs y containers
- **Macros útiles**: 
  - `REP(i,a,b)` para bucles
  - `all(a)` para rangos completos
  - `sza(x)` para tamaño de containers
- **Tipos abreviados**: `ll` (long long), `ar` (array), `ld` (long double)
- **Constantes**: `MOD`, `INF`, `EPS` predefinidas
- **Fast I/O**: Optimización de entrada/salida

### Funcionamiento:
La función `solve()` contiene la lógica principal del problema, mientras que `main()` maneja la entrada y puede procesar múltiples casos de prueba según sea necesario.

---

*Happy coding! 💻*
