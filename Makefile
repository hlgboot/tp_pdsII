# --- Variáveis de Compilação ---
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Iinclude -MMD -MP

# --- Variáveis de Diretório ---
SRCDIR = src
BUILDDIR = build
BINDIR = bin

# O executável final irá para a pasta 'bin/'
TARGET = $(BINDIR)/main

# --- Descoberta Automática de Arquivos ---

# Encontra TODOS os arquivos terminados em .cpp dentro da pasta src/
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Cria a lista de arquivos objeto (.o) correspondentes na pasta 'build/'
# Ex: Converte 'src/main.cpp' para 'build/main.o'
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# Lista de arquivos de dependência (.d) gerados pela flag -MMD
DEPS = $(OBJECTS:.o=.d)

# --- Regras Principais ---

# Alvo padrão: o que será executado ao rodar 'make'
# Primeiro cria os diretórios, depois o executável
all: $(BINDIR) $(BUILDDIR) $(TARGET)

# Regra para criar o executável final (Linkagem)
# Depende de todos os arquivos objeto
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Regras para criar os diretórios, se não existirem
$(BINDIR):
	@mkdir -p $(BINDIR)
$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

# --- Regra de Compilação ---
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Regra de Execução (Requisito E8a) ---
run: all
	./$(TARGET)

# --- Regra de Limpeza ---
clean:
	# Remove o executável, os objetos e os arquivos de dependência
	rm -f $(TARGET) $(OBJECTS) $(DEPS)
	
	# Tenta remover os diretórios (só funciona se estiverem vazios)
	@rmdir $(BINDIR) 2>/dev/null || true
	@rmdir $(BUILDDIR) 2>/dev/null || true

# --- Regra de geracao do Doxygen ---
docs:
	@mkdir -p docs/doxygen
	doxygen Doxyfile

# Evita que 'make' se confunda com arquivos chamados 'all' 'clean' 'run' 'docs' 
.PHONY: all clean docs run

# Inclui os arquivos de dependência (.d) gerados automaticamente
# Isso garante que um .cpp será recompilado se um .h que ele usa for modificado
-include $(DEPS)
