#pragma once

#include <string>

#include "alerta_info.hpp"

// Desafio: demonstra que alerta_info NÃO é final (mas alerta_critico é).
// Mantém tipo() == "INFO" (herdado) e apende um contexto técnico ao formatar().
class alerta_debug : public alerta_info {
    std::string contexto_;

public:
    alerta_debug(std::string origem, std::string mensagem, std::string contexto);

    [[nodiscard]] std::string formatar() const override;
};
