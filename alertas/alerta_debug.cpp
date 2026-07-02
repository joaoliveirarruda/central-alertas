#include "alerta_debug.hpp"

#include <utility>

alerta_debug::alerta_debug(std::string origem, std::string mensagem,
                           std::string contexto)
    : alerta_info(std::move(origem), std::move(mensagem)),
      contexto_(std::move(contexto)) {}

std::string alerta_debug::formatar() const {
    // mensagem_ é privado em alerta_info; reaproveita a formatação da base
    // por nome qualificado e apende o contexto técnico.
    return alerta_info::formatar() + " [debug: " + contexto_ + "]";
}
