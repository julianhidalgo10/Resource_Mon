# Compilador
CC := gcc
CFLAGS := -Wall -Isrc -Itest/src

# Directorios
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

TEST_SRC_DIR := test/src
TEST_BIN_DIR := test/bin

# Archivos fuente principales
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Archivos fuente de prueba
TEST_SRC_FILES := $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_OBJ_FILES := $(patsubst $(TEST_SRC_DIR)/%.c, $(OBJ_DIR)/%.test.o, $(TEST_SRC_FILES))

# Ejecutable principal
TARGET := $(BIN_DIR)/resource_mon

# Ejecutables de prueba
TEST_EXEC := $(TEST_BIN_DIR)/cpuinfo_test \
             $(TEST_BIN_DIR)/meminfo_test \
             $(TEST_BIN_DIR)/tui_test

.PHONY: all tests clean

all: $(TARGET)

# Compilar el programa principal
$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $^

# Regla general para compilar archivos fuente a objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla general para compilar tests
$(OBJ_DIR)/%.test.o: $(TEST_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar los ejecutables de prueba
tests: $(TEST_OBJ_FILES)
	$(CC) -o $(TEST_BIN_DIR)/cpuinfo_test $(OBJ_DIR)/cpuinfo_manip.o $(OBJ_DIR)/cpuinfo_test.test.o
	$(CC) -o $(TEST_BIN_DIR)/meminfo_test $(OBJ_DIR)/meminfo_manip.o $(OBJ_DIR)/meminfo_test.test.o
	$(CC) -o $(TEST_BIN_DIR)/tui_test $(OBJ_DIR)/tui.o $(OBJ_DIR)/tui_test.test.o

clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.test.o $(BIN_DIR)/* $(TEST_BIN_DIR)/*