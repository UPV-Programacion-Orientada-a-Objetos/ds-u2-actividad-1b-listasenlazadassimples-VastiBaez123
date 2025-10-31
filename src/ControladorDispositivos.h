#ifndef CONTROLADOR_DISPOSITIVOS_H
#define CONTROLADOR_DISPOSITIVOS_H

#include "DispositivoBase.h" // Almacena punteros a este tipo

/**
 * @class ControladorDispositivos
 * @brief Implementa la lista enlazada principal NO genérica
 * para almacenar punteros polimórficos a DispositivoBase*.
 */
class ControladorDispositivos {
private:
    /**
     * @struct NodoControl
     * @brief Nodo para la lista de control. Almacena el puntero.
     */
    struct NodoControl { // Antes 'NodoGestion'
        DispositivoBase* dispositivo; // Antes 'sensor'
        NodoControl* proximo; // Antes 'siguiente'

        NodoControl(DispositivoBase* d) : dispositivo(d), proximo(nullptr) {}
    };

    NodoControl* inicio; // Antes 'cabeza'

public:
    ControladorDispositivos();
    /**
     * @brief Destructor de la lista de control.
     * ¡CRÍTICO! Debe iterar y hacer 'delete' de cada puntero DispositivoBase*
     * para invocar la cadena de destructores virtuales.
     */
    ~ControladorDispositivos();

    // Prohibir copia
    ControladorDispositivos(const ControladorDispositivos&) = delete;
    ControladorDispositivos& operator=(const ControladorDispositivos&) = delete;

    /**
     * @brief Agrega un nuevo dispositivo (ya creado con 'new') a la lista.
     */
    void conectarDispositivo(DispositivoBase* nuevoDispositivo); // Antes 'agregarSensor'

    /**
     * @brief Busca un dispositivo por su ID.
     */
    DispositivoBase* encontrarDispositivo(const char* id); // Antes 'buscarSensor'

    /**
     * @brief Itera sobre todos y llama a su método polimórfico.
     */
    void analizarTodos(); // Antes 'procesarTodos'
    
    /**
     * @brief Imprime la información de todos.
     */
    void mostrarTodos() const; // Antes 'imprimirTodos'
};

#endif // CONTROLADOR_DISPOSITIVOS_H
