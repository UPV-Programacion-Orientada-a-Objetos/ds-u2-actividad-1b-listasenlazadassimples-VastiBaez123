#include <iostream>
#include <limits> // Para limpiar el buffer de entrada
#include "ControladorDispositivos.h" // Antes 'GestionSensores.h'
#include "MedidorTermico.h"         // Antes 'SensorTemperatura.h'
#include "MedidorBarometrico.h"     // Antes 'SensorPresion.h'

// Función auxiliar para leer líneas de forma segura sin std::string
void leerEntrada(char* buffer, int tam) { // Antes 'leerLinea'
    std::cin.getline(buffer, tam);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void mostrarMenu() {
    std::cout << "\n--- Sistema IoT de Monitoreo Polimórfico ---" << std::endl;
    std::cout << "1. Conectar Medidor (Tipo Termico - FLOAT)" << std::endl;
    std::cout << "2. Conectar Medidor (Tipo Barometrico - INT)" << std::endl;
    std::cout << "3. Registrar Valor" << std::endl;
    std::cout << "4. Ejecutar Analisis Polimorfico" << std::endl;
    std::cout << "5. Mostrar Estado de Dispositivos" << std::endl;
    std::cout << "6. Salir (Liberar Memoria)" << std::endl;
    std::cout << "Opcion: ";
}

int main() {
    ControladorDispositivos sistema; // Antes 'GestionSensores'
    bool salir = false;
    char opcion[10];
    char idDispositivo[50]; // Antes 'idSensor'
    char valorEntrada[20]; // Antes 'valorLectura'

    while (!salir) {
        mostrarMenu();
        leerEntrada(opcion, 10);
        int op = atoi(opcion);

        switch (op) {
            case 1: // Crear Medidor Termico
                std::cout << "ID para nuevo medidor Termico: ";
                leerEntrada(idDispositivo, 50);
                // Usamos 'new' para crear el objeto en el heap
                sistema.conectarDispositivo(new MedidorTermico(idDispositivo));
                break;
            
            case 2: // Crear Medidor Barometrico
                std::cout << "ID para nuevo medidor Barometrico: ";
                leerEntrada(idDispositivo, 50);
                sistema.conectarDispositivo(new MedidorBarometrico(idDispositivo));
                break;

            case 3: { // Registrar Valor
                std::cout << "ID del dispositivo para registrar: ";
                leerEntrada(idDispositivo, 50);
                DispositivoBase* dispositivo = sistema.encontrarDispositivo(idDispositivo);
                if (dispositivo != nullptr) {
                    std::cout << "Valor del dato: ";
                    leerEntrada(valorEntrada, 20);
                    dispositivo->registrarValor(valorEntrada); // Polimorfismo
                } else {
                    std::cout << "Error: Dispositivo con ID '" << idDispositivo << "' no encontrado." << std::endl;
                }
                break;
            }

            case 4: // Analisis Polimórfico
                sistema.analizarTodos();
                break;

            case 5: // Mostrar Estado
                sistema.mostrarTodos();
                break;

            case 6: // Salir
                salir = true;
                std::cout << "Cerrando sistema..." << std::endl;
                break;

            default:
                std::cout << "Opción no válida." << std::endl;
                break;
        }
    }

    // Al salir del main, la variable 'sistema' (ControladorDispositivos)
    // sale del scope, y su destructor (~ControladorDispositivos) es invocado.
    return 0;
}
