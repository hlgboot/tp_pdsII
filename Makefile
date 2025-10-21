# Makefile para o projeto TP_PDSII

# --- Variáveis de Compilação ---
CC=g++
# Adiciona -Iinclude para que o compilador encontre os headers nas subpastas
CFLAGS=-std=c++11 -Wall -Iinclude
TARGET=main
BUILD_DIR=build

# --- Listas de Arquivos ---

# Lista de todos os arquivos de cabeçalho
HDR_ALGORITHMS = include/algorithms/Aleatorio.hpp include/algorithms/Algoritmo.hpp \
                 include/algorithms/ForcaBruta.hpp include/algorithms/GulosoBeneficio.hpp \
                 include/algorithms/GulosoRazao.hpp
        
HDR_CORE = include/core/Ativo.hpp include/core/ResultadoInstancia.hpp \
           include/core/ResultadoUnitario.hpp

HDR_MANAGERS = include/managers/GeradorInstancias.hpp include/managers/MainController.hpp

HDR_UTILS = include/utils/Utils.hpp

# Todos os cabeçalhos juntos
HDR_ALL = $(HDR_ALGORITHMS) $(HDR_CORE) $(HDR_MANAGERS) $(HDR_UTILS)

# Lista de todos os arquivos objeto que serão criados
OBJECTS = $(BUILD_DIR)/main.o \
          $(BUILD_DIR)/Utils.o \
          $(BUILD_DIR)/Aleatorio.o \
          $(BUILD_DIR)/Algoritmo.o \
          $(BUILD_DIR)/ForcaBruta.o \
          $(BUILD_DIR)/GulosoBeneficio.o \
          $(BUILD_DIR)/GulosoRazao.o \
          $(BUILD_DIR)/Ativo.o \
          $(BUILD_DIR)/ResultadoInstancia.o \
          $(BUILD_DIR)/ResultadoUnitario.o \
          $(BUILD_DIR)/GeradorInstancias.o \
          $(BUILD_DIR)/MainController.o

# --- Regras Principais ---

# Alvo padrão: o que será executado ao rodar 'make'
all: $(BUILD_DIR) $(TARGET)

# Regra para criar o executável final (linkagem)
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Regra para criar o diretório de build, se não existir
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# --- Regras de Compilação (Arquivo .cpp -> .o) ---
# Cada regra compila um arquivo .cpp para um .o no diretório de build
# As dependências incluem o .cpp e os .h relevantes

$(BUILD_DIR)/main.o: src/main.cpp include/managers/MainController.hpp
	$(CC) $(CFLAGS) -c src/main.cpp -o $@

$(BUILD_DIR)/Utils.o: src/Utils.cpp include/utils/Utils.hpp
	$(CC) $(CFLAGS) -c src/Utils.cpp -o $@

# Algorithms
$(BUILD_DIR)/Aleatorio.o: src/Aleatorio.cpp include/algorithms/Aleatorio.hpp $(HDR_CORE)
	$(CC) $(CFLAGS) -c src/Aleatorio.cpp -o $@

$(BUILD_DIR)/Algoritmo.o: src/Algoritmo.cpp include/algorithms/Algoritmo.hpp $(HDR_CORE)
	$(CC) $(CFLAGS) -c src/Algoritmo.cpp -o $@

$(BUILD_DIR)/ForcaBruta.o: src/ForcaBruta.cpp include/algorithms/ForcaBruta.hpp $(HDR_CORE)
	$(CC) $(CFLAGS) -c src/ForcaBruta.cpp -o $@

$(BUILD_DIR)/GulosoBeneficio.o: src/GulosoBeneficio.cpp include/algorithms/GulosoBeneficio.hpp $(HDR_CORE)
	$(CC) $(CFLAGS) -c src/GulosoBeneficio.cpp -o $@

$(BUILD_DIR)/GulosoRazao.o: src/GulosoRazao.cpp include/algorithms/GulosoRazao.hpp $(HDR_CORE)
	$(CC) $(CFLAGS) -c src/GulosoRazao.cpp -o $@

# Core
$(BUILD_DIR)/Ativo.o: src/Ativo.cpp include/core/Ativo.hpp
	$(CC) $(CFLAGS) -c src/Ativo.cpp -o $@

$(BUILD_DIR)/ResultadoInstancia.o: src/ResultadoInstancia.cpp include/core/ResultadoInstancia.hpp
	$(CC) $(CFLAGS) -c src/ResultadoInstancia.cpp -o $@

$(BUILD_DIR)/ResultadoUnitario.o: src/ResultadoUnitario.cpp include/core/ResultadoUnitario.hpp
	$(CC) $(CFLAGS) -c src/ResultadoUnitario.cpp -o $@

# Managers
$(BUILD_DIR)/GeradorInstancias.o: src/GeradorInstancias.cpp include/managers/GeradorInstancias.hpp $(HDR_CORE) $(HDR_UTILS)
	$(CC) $(CFLAGS) -c src/GeradorInstancias.cpp -o $@

$(BUILD_DIR)/MainController.o: src/MainController.cpp include/managers/MainController.hpp $(HDR_ALL)
	$(CC) $(CFLAGS) -c src/MainController.cpp -o $@

# --- Regra de Limpeza ---
clean:
	rm -f $(TARGET) $(BUILD_DIR)/*.o
	@rmdir $(BUILD_DIR) 2>/dev/null || true

# Evita que 'make' se confunda com arquivos chamados 'all' ou 'clean'
.PHONY: all clean
