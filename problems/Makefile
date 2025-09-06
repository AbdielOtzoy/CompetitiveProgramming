# Makefile para compilar, ejecutar y eliminar archivos C++

# Compilador y flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# Regla genérica: compilar, ejecutar y eliminar con "make archivo"
%: %.cpp
	@echo "=== Compilando $< ==="
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo "=== Ejecutando $@ ==="
	./$@
	@echo "=== Eliminando $@ ==="
	@rm -f $@

# Regla para limpiar (en caso de quedar algo)
clean:
	@rm -f $(basename $(wildcard *.cpp))
	@echo "=== Ejecutables eliminados ==="
