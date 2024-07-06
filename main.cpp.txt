#include "livro.hpp"
#include "usuario.hpp"
#include "funcionario.hpp"
#include "biblioteca.hpp"
#include <iostream>
#include <ctime> 


int main() {
    Livro livro1(1, "Dom Casmurro", "Machado de Assis");
    Livro livro2(2, "Harry Potter e a Pedra Filosofal", "J.K. Rowling");
    Livro livro3(3, "O Senhor dos Anéis", "J.R.R. Tolkien");

    Usuario usuario1(1, "Elisa");
    Usuario usuario2(2, "Maria");

    Funcionario funcionario(1, "Malu");

    Biblioteca biblioteca;
    biblioteca.adicionarLivro(&livro1);
    biblioteca.adicionarLivro(&livro2);
    biblioteca.adicionarLivro(&livro3);
    biblioteca.adicionarUsuario(&usuario1);
    biblioteca.adicionarUsuario(&usuario2);
    biblioteca.adicionarFuncionario(&funcionario);

    std::cout << "Estoque inicial da Biblioteca:\n";
    biblioteca.exibirEstoque();

    funcionario.realizarEmprestimo(&usuario1, 1);

    std::cout << "Estoque da Biblioteca após empréstimo:\n";
    biblioteca.exibirEstoque();

    usuario1.devolverLivro(&livro1);

    std::cout << "Estoque da Biblioteca após devolução:\n";
    biblioteca.exibirEstoque();

    funcionario.realizarEmprestimo(&usuario2, 2); 
    usuario2.adicionarMulta(10.0);

    std::cout << "Estoque da Biblioteca após segundo empréstimo e multa:\n";
    biblioteca.exibirEstoque();

    std::vector<Usuario*> usuarios = biblioteca.getUsuarios();
    funcionario.gerenciarMultas(usuarios);

    return 0;
}
