
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(SistemaSensores CXX)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

# Definir el ejecutable ysus rchivos fuente
add_executable(GestorSensores
    src/main.cpp
    src/SensorBase.cpp
    src/SensorTemperatura.cpp
    src/SensorPresion.cpp
    src/GestionSensores.cpp
)


find_package(Doxygen)

if(DOXYGEN_FOUND)

    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doc)

    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generando documentación con Doxygen..."
        VERBATIM
    )
else()
    message(WARNING "Doxygen no encontrado. El target 'doc' no estará disponible.")
endif()
