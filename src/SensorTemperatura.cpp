#include "MedidorTermico.h"
#include <iostream>
#include <cstdlib> // Para atof

MedidorTermico::MedidorTermico(const char* n) : DispositivoBase(n) {}

// El destructor de 'registros' (HistoricoDatos<float>) se llamará automáticamente
MedidorTermico::~MedidorTermico() {
    std::cout << "    [Log] Lista interna de " << id << " liberada por su destructor." << std::endl;
}

void MedidorTermico::registrarValor(const char* valor) {
    float val = static_cast<float>(atof(valor)); // Convertir string a float
    registros.anexarDato(val); // Antes 'insertarAlFinal'
    std::cout << "[Log] Insertando Elemento<float> " << val << " en " << id << "." << std::endl;
}

void MedidorTermico::analizarDatos() {
    std::cout << "-> Procesando Dispositivo " << id << " (Termico)..." << std::endl;
    if (registros.estaVacio()) { // Antes 'estaVacia'
        std::cout << "   [Medidor Termico] No hay datos para procesar." << std::endl;
        return;
    }
    
    // Lógica: "eliminar el valor más bajo"
    float minVal = registros.extraerMinimo(); // Antes 'encontrarYQuitarMinimo'
    std::cout << "   [Medidor Termico] Valor más bajo (" << minVal << ") eliminado." << std::endl;
    
    // Lógica: "calcular promedio restante"
    double prom = registros.obtenerMedia(); // Antes 'calcularPromedio'
    std::cout << "   [Medidor Termico] Media restante sobre " << registros.obtenerConteo() // Antes 'getTamano'
              << " datos: " << prom << "." << std::endl;
}

void MedidorTermico::mostrarEstado() const {
    std::cout << "--- Info Dispositivo [" << id << "] (Termico, float) ---" << std::endl;
    registros.imprimir();
}
