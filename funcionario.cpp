#include "funcionario.hpp"
#include <iostream>
#include <time.h>

Funcionario::Funcionario(int id, std::string nome) {}

void Funcionario::cadastrarLivro(int id, std::string titulo, std::string autor){
  livros.push_back(new Livro(id, titulo, autor));
  std::cout << "Livro cadastrado com sucesso!" << std::endl;
}

int Funcionario::getId() {
    return id;
}

void Funcionario::realizarEmprestimo(Usuario* usuario, int idLivro) {
    for (Livro* livro : livros) {
        if (livro->getID() == idLivro && livro->isDisponivel()){
            livro->setDisponivel(false);
            usuario->emprestarLivro(livro);

            time_t dataEmprestimo = time(NULL);
            struct tm* data = localtime(&dataEmprestimo);
            data->tm_mday += 7;
            time_t dataDevolucao = mktime(data);

            std::cout << "O emprestimo foi registrado!" << std::endl;
            std::cout << "Data de emprestimo: " << asctime(localtime(&dataEmprestimo)) << std::endl;
            std::cout << "Data de devolucao: " << asctime(localtime(&dataDevolucao)) << std::endl;
        }else if(livro == nullptr){
            std::cout << "Livro nao encontrado." << std::endl;
        }else{
            std::cout << "Livro esta indisponivel para emprestimo." << std::endl;
        }
    }
}

void Funcionario::gerenciarMultas(const std::vector<Usuario*>& usuarios) {
    time_t agora = time(NULL);
    for (const auto& usuario : usuarios) {
        for (const auto& livro : usuario->getLivrosEmprestados()) {
            struct tm* dataDevolucao = localtime(&agora);
            dataDevolucao->tm_mday -= 7;
            time_t devolucaoPrevista = mktime(dataDevolucao);

            if (agora > devolucaoPrevista) {
                int diasAtraso = difftime(agora, devolucaoPrevista) / (60 * 60 * 24);
                double multa = diasAtraso * 1.0;
                std::cout << "Usuario: " << usuario->getNome()
                          << ", Livro: " << livro->getTitulo()
                          << ", Devolucao prevista: " << asctime(dataDevolucao)
                          << ", Multa: R$" << multa << std::endl;
            }
        }
    }
}