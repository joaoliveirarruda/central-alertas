#pragma once

#include <string>

// Interface pura: apenas contrato, sem estado.
class formatavel {
public:
    [[nodiscard]] virtual std::string formatar() const = 0;
    virtual ~formatavel() = default;
};

// Classe abstrata: tem estado e implementa o Template Method exibir().
// formatar() permanece puro (herdado de formatavel), mantendo alerta abstrata.
class alerta : public formatavel {
    std::string origem_;
    int severidade_;

public:
    // Lança std::invalid_argument se severidade estiver fora de [1, 3].
    alerta(std::string origem, int severidade);

    // Template Method: NÃO-virtual. Despacha para tipo() e formatar().
    void exibir() const;

    [[nodiscard]] virtual std::string tipo() const = 0;

    [[nodiscard]] std::string origem() const;
    [[nodiscard]] int severidade() const noexcept;

    ~alerta() override = default;
};
