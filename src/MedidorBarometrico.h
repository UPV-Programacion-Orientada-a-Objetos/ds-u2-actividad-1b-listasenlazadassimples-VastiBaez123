#ifndef MEDIDOR_BAROMETRICO_H
#define MEDIDOR_BAROMETRICO_H

#include "DispositivoBase.h"
#include "HistoricoDatos.h" // Antes 'ListaSensor.h'

/**
 * @class MedidorBarometrico
 * @brief Implementación concreta para un medidor de presión (int).
 */
class MedidorBarometrico : public DispositivoBase {
private:
    HistoricoDatos<int> registros; // Antes 'historial'

public:
    MedidorBarometrico(const char* n);
    virtual ~MedidorBarometrico();

    // Implementación de la interfaz virtual
    virtual void analizarDatos() override; // Antes 'procesarLectura'
    virtual void mostrarEstado() const override; // Antes 'imprimirInfo'
    virtual void registrarValor(const char* valor) override; // Antes 'agregarLectura'
};

#endif // MEDIDOR_BAROMETRICO_H
