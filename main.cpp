#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "livro.hpp"
#include "usuario.hpp"
#include "funcionario.hpp"
#include "biblioteca.hpp"

void menuUsuario(Biblioteca &biblioteca, Usuario* usuario);
void menuFuncionario(Biblioteca &biblioteca, Funcionario* funcionario);

int main() {
    Biblioteca biblioteca;

    Livro livro1(1, "Harry Potter e Pedra Filosofal", "J. K. Rowling");
    Livro livro2(2, "As Veias Abertas da América Latina", "Eduardo Galeano");
    biblioteca.adicionarLivro(&livro1);
    biblioteca.adicionarLivro(&livro2);

    Usuario usuario1(1, "Maisa");
    Usuario usuario2(2, "Helena");
    biblioteca.adicionarUsuario(&usuario1);
    biblioteca.adicionarUsuario(&usuario2);

    Funcionario funcionario1(1, "Maria Joaquina");
    Funcionario funcionario2(2, "Cirilo");
    biblioteca.adicionarFuncionario(&funcionario1);
    biblioteca.adicionarFuncionario(&funcionario2);

    int opcaoInicial;

    while (true) {
        std::cout << "Menu Inicial\n";
        std::cout << "1. Funcionario\n";
        std::cout << "2. Usuario\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcaoInicial;

        if (opcaoInicial == 1) {
            int idFuncionario;
            std::cout << "Digite o ID do funcionario: ";
            std::cin >> idFuncionario;

            Funcionario* funcionario = nullptr;
            for (Funcionario* f : biblioteca.getFuncionarios()) {
                if (f->getId() == idFuncionario) {
                    funcionario = f;
                    break;
                }
            }

            if (funcionario) {
                menuFuncionario(biblioteca, funcionario);
            } else {
                std::cout << "Funcionario nao encontrado.\n";
            }
        } else if (opcaoInicial == 2) {
            int idUsuario;
            std::cout << "Digite o ID do usuario: ";
            std::cin >> idUsuario;

            Usuario* usuario = nullptr;
            for (Usuario* u : biblioteca.getUsuarios()) {
                if (u->getId() == idUsuario) {
                    usuario = u;
                    break;
                }
            }

            if (usuario) {
                menuUsuario(biblioteca, usuario);
            } else {
                std::cout << "Usuario nao encontrado.\n";
            }
        } else if (opcaoInicial == 3) {
            break;
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }

    return 0;
}

void menuUsuario(Biblioteca &biblioteca, Usuario* usuario) {
    int opcaoUsuario;

    while (true) {
        std::cout << "\nMenu Usuario\n";
        std::cout << "1. Emprestar livro\n";
        std::cout << "2. Devolver livro\n";
        std::cout << "3. Ver livros emprestados\n";
        std::cout << "4. Voltar ao menu inicial\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcaoUsuario;

        if (opcaoUsuario == 1) {
            biblioteca.exibirEstoque();
            int idLivro;
            std::cout << "Digite o ID do livro para emprestar: ";
            std::cin >> idLivro;
            biblioteca.emprestarLivro(idLivro, usuario->getId());
            std::cout << "Emprestimo feito com sucesso!";
        } else if (opcaoUsuario == 2) {
            biblioteca.exibirEstoque();
            int idLivro;
            std::cout << "Digite o ID do livro para devolver: ";
            std::cin >> idLivro;
            biblioteca.devolverLivro(idLivro, usuario->getId());
            std::cout << "Seu livro foi devolvido certinho!";
        } else if (opcaoUsuario == 3) {
            std::vector<Livro*> livrosEmprestados = usuario->getLivrosEmprestados();
            for (Livro* livro : livrosEmprestados) {
                std::cout << "ID: " << livro->getID() << ", Titulo: " << livro->getTitulo() << std::endl;
            }
        } else if (opcaoUsuario == 4) {
            break;
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}

void menuFuncionario(Biblioteca &biblioteca, Funcionario* funcionario) {
    int opcaoFuncionario;

    while (true) {
        std::cout << "\nMenu Funcionario\n";
        std::cout << "1. Adicionar livro\n";
        std::cout << "2. Adicionar usuario\n";
        std::cout << "3. Exibir estoque\n";
        std::cout << "4. Gerenciar multas\n";
        std::cout << "5. Voltar ao menu inicial\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcaoFuncionario;

        if (opcaoFuncionario == 1) {
            biblioteca.exibirEstoque();
            int idLivro;
            std::string titulo, autor;
            std::cout << "Digite o ID do livro: ";
            std::cin >> idLivro;
            std::cin.ignore();
            std::cout << "Digite o titulo do livro: ";
            std::getline(std::cin, titulo);
            std::cout << "Digite o autor do livro: ";
            std::getline(std::cin, autor);

            try {
                Livro* livro = new Livro(idLivro, titulo, autor);
                biblioteca.adicionarLivro(livro);
                std::cout << "Livro adicionado com sucesso." << std::endl;
            } catch (const std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
            }
        } else if (opcaoFuncionario == 2) {
            int idUsuario;
            std::string nome;
            std::cout << "Digite o ID do usuario: ";
            std::cin >> idUsuario;
            std::cin.ignore();
            std::cout << "Digite o nome do usuario: ";
            std::getline(std::cin, nome);

            Usuario* usuario = new Usuario(idUsuario, nome);
            biblioteca.adicionarUsuario(usuario);
            std::cout << "Usuario adicionado com sucesso." << std::endl;
        } else if (opcaoFuncionario == 3) {
            biblioteca.exibirEstoque();
        } else if (opcaoFuncionario == 4) {
            funcionario->gerenciarMultas(biblioteca.getUsuarios());
        } else if (opcaoFuncionario == 5) {
            break;
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}