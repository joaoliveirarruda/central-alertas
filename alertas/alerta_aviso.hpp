#pragma once

#include <string>

#include "../alerta.hpp"

// Severidade sempre 2.
class alerta_aviso : public alerta {
    std::string mensagem_;

public:
    alerta_aviso(std::string origem, std::string mensagem);

    [[nodiscard]] std::string tipo() const override;
    [[nodiscard]] std::string formatar() const override;
};
