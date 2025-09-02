# Makefile para compilar y ejecutar archivos C++

# Compilador y flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# Regla genérica: compilar y ejecutar con "make archivo"
%: %.cpp
	@echo "=== Compilando $< ==="
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo "=== Ejecutando $@ ==="
	./$@

# Regla para limpiar todos los ejecutables
clean:
	@rm -f $(basename $(wildcard *.cpp))
	@echo "=== Ejecutables eliminados ==="
