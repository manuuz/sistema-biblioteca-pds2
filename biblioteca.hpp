#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <vector>
#include "livro.hpp"
#include "usuario.hpp"
#include "funcionario.hpp"

class Biblioteca {
private:
    std::vector<Livro*> livros;
    std::vector<Usuario*> usuarios;
    std::vector<Funcionario*> funcionarios;

public:
    void adicionarLivro(Livro* livro);
    void adicionarUsuario(Usuario* usuario);
    void adicionarFuncionario(Funcionario* funcionario);
    void emprestarLivro(int livroID, int usuarioID);
    void devolverLivro(int livroID, int usuarioID);
    void exibirEstoque() const;
    const std::vector<Usuario*>& getUsuarios() const;
    const std::vector<Funcionario*>& getFuncionarios() const;
};

#endif // BIBLIOTECA_HPP
