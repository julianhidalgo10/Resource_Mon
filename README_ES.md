# Resource_Mon

**Taller de Programación de Sistemas Linux Embebidos – 2025-1S**  
**Universidad Nacional de Colombia**
**Docente:** Juan Bernardo Gómez Mendoza  

## Integrantes del equipo

- Julián Felipe Gutierrez Ramirez – CC 1193577237
- Julián Alberto Hidalgo – CC 1010075559
- David Santiago Pérez – CC 1081393239
- Felipe Idarraga Quintero – CC 1002632670

---

## Descripción general del proyecto

**`resource_mon`** Es una herramienta de monitoreo de recursos del sistema en tiempo real desarrollada en lenguaje C para sistemas operativos GNU/Linux. Ejecutada desde la línea de comandos (CLI), permite visualizar de forma clara y constante la información clave de la CPU y la memoria del sistema.

### Funcionalidades principales

- Información detallada de la CPU:
  - Nombre y fabricante
  - Número de núcleos físicos y hilos totales
  - Porcentaje de uso de cada hilo en tiempo real
- Información de memoria:
  - Memoria física total (MB)
  - Memoria de intercambio (swap) total (MB)
  - Porcentaje de uso de memoria física y de swap
- Actualización de datos cada segundo
- Interfaz persistente en pantalla (sin scroll)
- Finalización del programa con la tecla `q`, combinación `Ctrl + C` o cierre de terminal

---

## Estructura del proyecto

```plaintext
Resource_Mon/
├── bin/                  # Ejecutables generados por Makefile
├── obj/                  # Archivos objeto .o
├── src/                  # Código fuente principal
│   ├── cpuinfo_manip.c/h
│   ├── meminfo_manip.c/h
│   ├── tui.c/h
│   └── resource_mon.c
├── test/                 # Archivos de prueba para cada módulo
│   ├── cpuinfo_test.c
│   ├── meminfo_test.c
│   └── tui_test.c
├── Makefile              # Compilación principal del proyecto
├── README.md             # El presente archivo
```

## Requerimientos técnicos
- Sistema operativo GNU/Linux
- Compilador gcc
- Herramienta make

### Archivos fuente y sus roles

- cpuinfo_manip.*: Obtención de información de CPU desde /proc/cpuinfo y uso por hilo desde /proc/stat.

- meminfo_manip.*: Lectura de uso de memoria desde /proc/meminfo.

- tui.*: Interfaz tipo TUI (Text-based User Interface) para mostrar datos en pantalla.

- resource_mon.c: Ciclo principal de ejecución del programa, integra todas las funcionalidades anteriores.

## Pruebas (tests)
Los archivos de prueba validan el correcto funcionamiento de cada módulo individual:

- **cpuinfo_test:** Prueba las funciones de obtención y cálculo de uso de CPU.

- **meminfo_test:** Verifica el parsing de la información de memoria.

- **tui_test:** Prueba las funciones relacionadas con la visualización en pantalla.

- Los tests están ubicados en la carpeta test/.

## Uso de Makefile

### Comandos principales desde la raíz del proyecto

```
make              # Construye resource_mon y los tests (equivalente a make all)
make resource_mon # Compila solamente el programa principal
make tests        # Compila solo los ejecutables de prueba
make clean        # Elimina los archivos objeto y ejecutables
```

### Comandos desde subdirectorios

Desde src/:

```
- make: Compila los archivos fuente a .o
- make clean: Elimina los .o
```

## Cómo ejecutar el programa
./bin/resource_mon

```
- La pantalla se actualizará cada segundo.
- Presione la tecla q para salir del programa.
```