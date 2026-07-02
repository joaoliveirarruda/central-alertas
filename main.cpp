#include <iostream>
#include <memory>

#include "central.hpp"

#include "alertas/alerta_aviso.hpp"
#include "alertas/alerta_critico.hpp"
#include "alertas/alerta_debug.hpp"
#include "alertas/alerta_info.hpp"

int main() {
    central c;

    c.registrar(std::make_unique<alerta_critico>(
        "sensor1", "temperatura 95.3 graus"));
    c.registrar(std::make_unique<alerta_aviso>(
        "sensor2", "umidade 78.5 pct"));
    c.registrar(std::make_unique<alerta_info>(
        "sistema", "reinicio agendado"));

    std::cout << "Total: " << c.total() << " alertas\n\n";
    c.exibir_todos();

    // Desafio: alerta_info NÃO é final — alerta_debug o especializa e ainda
    // imprime "[INFO]", apenas apendendo o contexto técnico ao formatar().
    std::cout << "\n-- desafio: alerta_debug --\n";
    central extra;
    extra.registrar(std::make_unique<alerta_debug>(
        "kernel", "cache invalidado", "modulo=mm addr=0x1f40"));
    extra.exibir_todos();
}
