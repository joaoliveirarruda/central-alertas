#pragma once

#include <string>

#include "../alerta.hpp"

// Severidade sempre 3. Marcada como final: não pode ser estendida.
class alerta_critico final : public alerta {
    std::string mensagem_;

public:
    alerta_critico(std::string origem, std::string mensagem);

    [[nodiscard]] std::string tipo() const override;
    [[nodiscard]] std::string formatar() const override;
};
