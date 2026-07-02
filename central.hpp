#pragma once

#include <memory>
#include <vector>

#include "alerta.hpp"

// Gerencia os alertas via polimorfismo dinâmico.
// Regra do zero: o vector<unique_ptr> torna a central move-only automaticamente.
class central {
    std::vector<std::unique_ptr<alerta>> alertas_;

public:
    void registrar(std::unique_ptr<alerta> a);  // recebe por valor (move)
    void exibir_todos() const;                   // itera e chama a->exibir()
    [[nodiscard]] int total() const noexcept;    // retorna alertas_.size()
};
