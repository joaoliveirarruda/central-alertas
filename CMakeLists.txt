cmake_minimum_required(VERSION 3.16)
project(central-alertas CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra)

option(ENABLE_SANITIZERS "Compila com AddressSanitizer e UndefinedBehaviorSanitizer" OFF)
if(ENABLE_SANITIZERS)
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()

add_executable(central-alertas
    main.cpp
    alerta.cpp
    central.cpp
    alertas/alerta_critico.cpp
    alertas/alerta_aviso.cpp
    alertas/alerta_info.cpp
    alertas/alerta_debug.cpp
)

target_include_directories(central-alertas PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
