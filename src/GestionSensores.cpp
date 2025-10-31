#include "ControladorDispositivos.h"
#include <iostream>
#include <cstring> // Para strcmp

ControladorDispositivos::ControladorDispositivos() : inicio(nullptr) {}

ControladorDispositivos::~ControladorDispositivos() {
    std::cout << "\n--- Liberación de Memoria en Cascada ---" << std::endl;
    NodoControl* actual = inicio;
    while (actual != nullptr) {
        NodoControl* aBorrar = actual;
        actual = actual->proximo;

        std::cout << "[Destructor Controlador] Liberando Nodo: " << aBorrar->dispositivo->obtenerID() << "." << std::endl;
        
        // ¡Aquí ocurre la magia!
        // Se invoca al destructor virtual
        delete aBorrar->dispositivo; 
        
        // Libera el nodo de la lista de control
        delete aBorrar; 
    }
    std::cout << "Sistema cerrado. Memoria limpia." << std::endl;
}

void ControladorDispositivos::conectarDispositivo(DispositivoBase* nuevoDispositivo) {
    NodoControl* nuevoNodo = new NodoControl(nuevoDispositivo);
    if (inicio == nullptr) {
        inicio = nuevoNodo;
    } else {
        NodoControl* temp = inicio;
        while (temp->proximo != nullptr) {
            temp = temp->proximo;
        }
        temp->proximo = nuevoNodo;
    }
    std::cout << "Dispositivo '" << nuevoDispositivo->obtenerID() << "' conectado al controlador." << std::endl;
}

DispositivoBase* ControladorDispositivos::encontrarDispositivo(const char* id) {
    NodoControl* temp = inicio;
    while (temp != nullptr) {
        if (strcmp(temp->dispositivo->obtenerID(), id) == 0) {
            return temp->dispositivo;
        }
        temp = temp->proximo;
    }
    return nullptr; // No encontrado
}

void ControladorDispositivos::analizarTodos() {
    std::cout << "\n--- Ejecutando Analisis Polimorfico ---" << std::endl;
    NodoControl* temp = inicio;
    if (temp == nullptr) {
        std::cout << "No hay dispositivos en el sistema." << std::endl;
        return;
    }
    while (temp != nullptr) {
        temp->dispositivo->analizarDatos(); // ¡Polimorfismo en acción!
        temp = temp->proximo;
    }
}

void ControladorDispositivos::mostrarTodos() const {
    std::cout << "\n--- Estado Actual de Dispositivos ---" << std::endl;
    NodoControl* temp = inicio;
     if (temp == nullptr) {
        std::cout << "No hay dispositivos en el sistema." << std::endl;
        return;
    }
    while (temp != nullptr) {
        temp->dispositivo->mostrarEstado();
        temp = temp->proximo;
    }
}
