#pragma once

#include <string>

#include "../alerta.hpp"

// Severidade sempre 1. NÃO é final: pode ser especializada (ver alerta_debug).
class alerta_info : public alerta {
    std::string mensagem_;

public:
    alerta_info(std::string origem, std::string mensagem);

    [[nodiscard]] std::string tipo() const override;
    [[nodiscard]] std::string formatar() const override;
};
