#ifndef MEDIDOR_TERMICO_H
#define MEDIDOR_TERMICO_H

#include "DispositivoBase.h"
#include "HistoricoDatos.h" // Antes 'ListaSensor.h'

/**
 * @class MedidorTermico
 * @brief Implementación concreta para un medidor térmico (float).
 */
class MedidorTermico : public DispositivoBase {
private:
    HistoricoDatos<float> registros; // Antes 'historial'

public:
    MedidorTermico(const char* n);
    virtual ~MedidorTermico();

    // Implementación de la interfaz virtual
    virtual void analizarDatos() override; // Antes 'procesarLectura'
    virtual void mostrarEstado() const override; // Antes 'imprimirInfo'
    virtual void registrarValor(const char* valor) override; // Antes 'agregarLectura'
};

#endif // MEDIDOR_TERMICO_H
