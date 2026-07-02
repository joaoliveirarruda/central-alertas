#pragma once

#include <string>

// Interface pura: apenas contrato, sem estado.
class formatavel {
public:
    [[nodiscard]] virtual std::string formatar() const = 0;
    virtual ~formatavel() = default;

protected:
    // Regra dos cinco explícita (C++ Core Guidelines C.67): copy/move
    // protegidos evitam object slicing pela base polimórfica, mas permitem
    // que as classes derivadas os defaultem normalmente.
    formatavel() = default;
    formatavel(const formatavel&) = default;
    formatavel& operator=(const formatavel&) = default;
    formatavel(formatavel&&) = default;
    formatavel& operator=(formatavel&&) = default;
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

protected:
    // Regra dos cinco explícita: copy/move protegidos impedem slicing por
    // alerta&, preservando a semântica de valor apenas para as derivadas.
    alerta(const alerta&) = default;
    alerta& operator=(const alerta&) = default;
    alerta(alerta&&) = default;
    alerta& operator=(alerta&&) = default;
};
