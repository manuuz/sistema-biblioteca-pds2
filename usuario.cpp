#include "usuario.hpp"
#include <algorithm>

Usuario::Usuario(int id, std::string nome) : id(id), nome(nome), multas(0.0) {}

int Usuario::getId() {
    return id;
}

std::string Usuario::getNome() {
    return nome;
}

double Usuario::getMultas() {
    return multas;
}

void Usuario::adicionarMulta(double valor) {
    multas += valor;
}

void Usuario::removerMulta(double valor) {
    if (valor <= multas) {
        multas -= valor;
    }
}

void Usuario::emprestarLivro(Livro* livro) {
    if (livro->isDisponivel()) {
        livrosEmprestados.push_back(livro);
        livro->setDisponivel(false);
    }
}

void Usuario::devolverLivro(Livro* livro) {
    auto it = std::find(livrosEmprestados.begin(), livrosEmprestados.end(), livro);
    if (it != livrosEmprestados.end()) {
        livrosEmprestados.erase(it);
        livro->setDisponivel(true);
    }
}

std::vector<Livro*> Usuario::getLivrosEmprestados() {
    return livrosEmprestados;
}
