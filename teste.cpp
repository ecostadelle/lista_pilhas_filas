#define CATCH_CONFIG_MAIN // define main() automaticamente
#include "catch.hpp"

#include "exercicios.hpp" // implementações do aluno

// =======================
// testes para exercício 0
// -----------------------

TEST_CASE("Ex0", "[aquecimento]")
{
    REQUIRE(teste() == 0);
}