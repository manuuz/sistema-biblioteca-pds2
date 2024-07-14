#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>
#include "livro.hpp"

class Usuario {
private:
    int id;
    std::string nome;
    std::vector<Livro*> livrosEmprestados;
    double multas;

public:
    Usuario(int id, std::string nome);
    int getId();
    std::string getNome();
    double getMultas();
    void adicionarMulta(double valor);
    void removerMulta(double valor);
    void emprestarLivro(Livro* livro);
    void devolverLivro(Livro* livro);
    std::vector<Livro*> getLivrosEmprestados();
};

#endif // USUARIO_HPP
