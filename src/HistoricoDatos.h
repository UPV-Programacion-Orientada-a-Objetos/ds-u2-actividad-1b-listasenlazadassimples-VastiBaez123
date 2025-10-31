#ifndef HISTORICO_DATOS_H
#define HISTORICO_DATOS_H

#include <iostream>
#include <cstddef> // Para nullptr
#include <limits>  // Para std::numeric_limits

/**
 * @file HistoricoDatos.h
 * @brief Implementación de una Lista Enlazada Simple Genérica (template).
 */
template <typename T>
class HistoricoDatos {
private:
    /**
     * @struct Elemento
     * @brief Estructura interna anidada para los nodos de la lista.
     */
    struct Elemento { // Antes 'Nodo'
        T valor; // Antes 'dato'
        Elemento* proximo; // Antes 'siguiente'

        Elemento(T v) : valor(v), proximo(nullptr) {}
    };

    Elemento* inicio; // Antes 'cabeza'
    int conteo; // Antes 'tamano'

    /**
     * @brief Función auxiliar para clonar otra lista (deep copy).
     */
    void clonar(const HistoricoDatos& otra) { // Antes 'copiar'
        inicio = nullptr;
        conteo = 0;
        Elemento* temp = otra.inicio;
        while (temp != nullptr) {
            anexarDato(temp->valor);
            temp = temp->proximo;
        }
    }

    /**
     * @brief Función auxiliar para vaciar (borrar) toda la lista.
     */
    void vaciar() { // Antes 'limpiar'
        Elemento* actual = inicio;
        while (actual != nullptr) {
            Elemento* aBorrar = actual;
            actual = actual->proximo;
            std::cout << "    [Log] Elemento<T> " << aBorrar->valor << " liberado." << std::endl;
            delete aBorrar;
        }
        inicio = nullptr;
        conteo = 0;
    }

public:
    HistoricoDatos() : inicio(nullptr), conteo(0) {}

    // --- Implementación de la Regla de los Tres ---

    ~HistoricoDatos() {
        vaciar();
    }

    HistoricoDatos(const HistoricoDatos& otra) {
        clonar(otra);
    }

    HistoricoDatos& operator=(const HistoricoDatos& otra) {
        if (this != &otra) { 
            vaciar(); 
            clonar(otra); 
        }
        return *this;
    }

    /**
     * @brief Inserta un nuevo dato al final de la lista.
     */
    void anexarDato(T dato) { // Antes 'insertarAlFinal'
        Elemento* nuevoElemento = new Elemento(dato);
        if (inicio == nullptr) {
            inicio = nuevoElemento;
        } else {
            Elemento* temp = inicio;
            while (temp->proximo != nullptr) {
                temp = temp->proximo;
            }
            temp->proximo = nuevoElemento;
        }
        conteo++;
    }

    void imprimir() const {
        Elemento* temp = inicio;
        while (temp != nullptr) {
            std::cout << temp->valor << " -> ";
            temp = temp->proximo;
        }
        std::cout << "nullptr" << std::endl;
    }

    int obtenerConteo() const { return conteo; } // Antes 'getTamano'
    bool estaVacio() const { return inicio == nullptr; } // Antes 'estaVacia'

    double obtenerMedia() const { // Antes 'calcularPromedio'
        if (estaVacio()) return 0.0;
        
        double suma = 0.0;
        Elemento* temp = inicio;
        while (temp != nullptr) {
            suma += static_cast<double>(temp->valor);
            temp = temp->proximo;
        }
        return suma / conteo;
    }

    T extraerMinimo() { // Antes 'encontrarYQuitarMinimo'
        if (estaVacio()) {
            return T(); 
        }

        T minVal = inicio->valor;
        Elemento* minNodoPrev = nullptr;
        Elemento* minNodo = inicio;

        Elemento* prev = nullptr;
        Elemento* actual = inicio;

        while (actual != nullptr) {
            if (actual->valor < minVal) {
                minVal = actual->valor;
                minNodoPrev = prev;
                minNodo = actual;
            }
            prev = actual;
            actual = actual->proximo;
        }

        if (minNodo == inicio) { 
            inicio = minNodo->proximo;
        } else { 
            minNodoPrev->proximo = minNodo->proximo;
        }

        std::cout << "    [Log] Elemento<T> " << minNodo->valor << " (min) eliminado." << std::endl;
        delete minNodo;
        conteo--;
        return minVal;
    }
};

#endif // HISTORICO_DATOS_H
