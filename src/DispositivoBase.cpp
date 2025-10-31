#include "DispositivoBase.h"
#include <cstring> // Para strncpy
#include <iostream>

DispositivoBase::DispositivoBase(const char* n) {
    // Copia segura de C-string
    strncpy(id, n, 49); // Antes 'nombre'
    id[49] = '\0'; // Asegurar terminación nula
}

// Aunque sea virtual y vacío, debe ser definido.
DispositivoBase::~DispositivoBase() {
    std::cout << "  [Destructor Dispositivo " << id << "] Limpiando..." << std::endl;
}

const char* DispositivoBase::obtenerID() const {
    return id; // Antes 'getNombre'
}
