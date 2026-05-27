# Makefile pentru Sistemul de Rezervari Cinema
# Folosire:
#   make          - compileaza aplicatia principala
#   make test     - compileaza si ruleaza testele unitare
#   make clean    - sterge fisierele compilate
#   make run      - compileaza si ruleaza aplicatia

# Compilatorul si optiunile
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Detectam sistemul de operare pentru portabilitate
ifeq ($(OS),Windows_NT)
    TARGET = cinema.exe
    TEST_TARGET = test_runner.exe
    RM = del /Q
    RUN_PREFIX =
else
    TARGET = cinema
    TEST_TARGET = test_runner
    RM = rm -f
    RUN_PREFIX = ./
endif

# Foldere
SRC_DIR = src
TEST_DIR = tests

# Fisierele sursa (toate .cpp din src, EXCEPT main.cpp pentru build modular)
SOURCES = $(SRC_DIR)/Film.cpp \
          $(SRC_DIR)/Sala.cpp \
          $(SRC_DIR)/Rezervare.cpp \
          $(SRC_DIR)/RezervareOnline.cpp \
          $(SRC_DIR)/Cinematograf.cpp

# Tinta principala
all: $(TARGET)

$(TARGET): $(SOURCES) $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(SOURCES) $(SRC_DIR)/main.cpp -o $(TARGET)
	@echo "Aplicatia a fost compilata cu succes!"

# Compilare si rulare teste
test: $(TEST_TARGET)
	@echo "Rulez testele unitare..."
	$(RUN_PREFIX)$(TEST_TARGET)

$(TEST_TARGET): $(SOURCES) $(TEST_DIR)/test_main.cpp
	$(CXX) $(CXXFLAGS) $(SOURCES) $(TEST_DIR)/test_main.cpp -o $(TEST_TARGET)

# Ruleaza aplicatia
run: $(TARGET)
	$(RUN_PREFIX)$(TARGET)

# Curatare fisiere compilate
clean:
	$(RM) $(TARGET) $(TEST_TARGET)

# Pseudo-tinte (nu sunt fisiere)
.PHONY: all test run clean