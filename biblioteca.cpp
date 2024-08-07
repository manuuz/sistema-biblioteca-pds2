#include "biblioteca.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>


void Biblioteca::adicionarLivro(Livro* livro) {
    auto it = std::find_if(livros.begin(), livros.end(), [livro](Livro* l) {
        return l->getID() == livro->getID();
    });

    if (it != livros.end()) {
        throw std::runtime_error("ID de livro já existente na biblioteca.");
    }

    livros.push_back(livro);
}

void Biblioteca::adicionarUsuario(Usuario* usuario) {
    usuarios.push_back(usuario);
}

void Biblioteca::adicionarFuncionario(Funcionario* funcionario) {
    funcionarios.push_back(funcionario);
}

void Biblioteca::emprestarLivro(int livroID, int usuarioID) {
    auto livroIt = std::find_if(livros.begin(), livros.end(), [livroID](Livro* livro) {
        return livro->getID() == livroID && livro->isDisponivel();
    });

    if (livroIt != livros.end()) {
        auto usuarioIt = std::find_if(usuarios.begin(), usuarios.end(), [usuarioID](Usuario* usuario) {
            return usuario->getId() == usuarioID;
        });

        if (usuarioIt != usuarios.end()) {
            (*usuarioIt)->emprestarLivro(*livroIt);
        } else {
            std::cout << "Usuario nao encontrado." << std::endl;
        }
    } else {
        std::cout << "Livro nao disponivel." << std::endl;
    }
}

void Biblioteca::devolverLivro(int livroID, int usuarioID) {
    auto usuarioIt = std::find_if(usuarios.begin(), usuarios.end(), [usuarioID](Usuario* usuario) {
        return usuario->getId() == usuarioID;
    });

    if (usuarioIt != usuarios.end()) {
        auto livroIt = std::find_if(livros.begin(), livros.end(), [livroID](Livro* livro) {
            return livro->getID() == livroID;
        });

        if (livroIt != livros.end()) {
            (*usuarioIt)->devolverLivro(*livroIt);
        } else {
            std::cout << "Livro nao encontrado." << std::endl;
        }
    } else {
        std::cout << "Usuario nao encontrado." << std::endl;
    }
}

void Biblioteca::exibirEstoque() const {
    for (const auto& livro : livros) {
        std::cout << "ID: " << livro->getID() 
                  << ", Titulo: " << livro->getTitulo() 
                  << ", Autor: " << livro->getAutor() 
                  << ", Disponivel: " << (livro->isDisponivel() ? "Sim" : "Nao") 
                  << std::endl;
                  }
}

const std::vector<Usuario*>& Biblioteca::getUsuarios() const {
    return usuarios;
}

const std::vector<Funcionario*>& Biblioteca::getFuncionarios() const {
    return funcionarios;
}
