#ifndef DISPOSITIVO_BASE_H
#define DISPOSITIVO_BASE_H

/**
 * @file DispositivoBase.h
 * @brief Clase Base Abstracta para todos los dispositivos.
 * Define la interfaz común polimórfica.
 */
class DispositivoBase {
protected:
    char id[50]; // Antes 'nombre'

public:
    /**
     * @brief Constructor.
     * @param n ID del dispositivo (se copiará).
     */
    DispositivoBase(const char* n);

    /**
     * @brief Destructor Virtual.
     * ¡CRÍTICO! Asegura que se llame al destructor de la clase derivada
     * correcta al hacer delete de un puntero DispositivoBase*.
     */
    virtual ~DispositivoBase();

    // --- Métodos Virtuales Puros (Interfaz) ---

    /**
     * @brief Procesa los datos almacenados (lógica específica).
     */
    virtual void analizarDatos() = 0; // Antes 'procesarLectura'

    /**
     * @brief Imprime la información y estado actual.
     */
    virtual void mostrarEstado() const = 0; // Antes 'imprimirInfo'

    /**
     * @brief Agrega un nuevo valor (como string) para ser parseado.
     * @param valor El valor en formato de cadena de texto.
     */
    virtual void registrarValor(const char* valor) = 0; // Antes 'agregarLectura'

    /**
     * @brief Obtiene el ID del dispositivo.
     * @return const char* al ID.
     */
    const char* obtenerID() const; // Antes 'getNombre'
};

#endif // DISPOSITIVO_BASE_H
