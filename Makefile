# Archivo Makefile

# Variables de compilación
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Nombres de los archivos fuente y ejecutable
SOURCES = main.cpp boletin1.cpp
EXECUTABLE = a.out

# Regla para compilar todos los archivos y generar el ejecutable
all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@

# Regla para limpiar 
clean:
	rm -f $(EXECUTABLE)

# Regla para ejecutar el test
test: $(EXECUTABLE)
	./$(EXECUTABLE)
