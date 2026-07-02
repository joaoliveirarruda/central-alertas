#include "alerta.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>

alerta::alerta(std::string origem, int severidade)
    : origem_(std::move(origem)), severidade_(severidade) {
    if (severidade_ < 1 || severidade_ > 3) {
        throw std::invalid_argument(
            "severidade deve estar no intervalo [1, 3]");
    }
}

void alerta::exibir() const {
    std::cout << "[" << tipo()        // chama o virtual tipo()
              << "] " << origem_ << ": "
              << formatar()           // chama o virtual formatar()
              << "\n";
}

std::string alerta::origem() const { return origem_; }

int alerta::severidade() const noexcept { return severidade_; }
