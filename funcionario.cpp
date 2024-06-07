#include "funcionario.hpp"
#include <iostream>
#include <time.h>

Funcionario::Funcionario(int id, std::string nome) {}

void Funcionario::cadastrarLivro(int id, std::string titulo, std::string autor){
  livros.push_back(new Livro(id, titulo, autor));
  std::cout << "Livro cadastrado com sucesso!" << std::endl;
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
