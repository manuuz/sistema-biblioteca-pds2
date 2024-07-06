#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <vector>
#include "livro.hpp"
#include "usuario.hpp"

class Funcionario {
private:
    int id;
    std::string nome;
    std::vector<Livro*> livros;

public:
  Funcionario(int id, std::string nome);
  void cadastrarLivro(int id, std::string titulo, std::string autor);
  void realizarEmprestimo(Usuario* usuario, int idLivro);
  void gerenciarMultas(const std::vector<Usuario*>& usuarios);
};

#endif // FUNCIONARIO_HPP
