#include "livro.hpp"

Livro::Livro(int id, std::string titulo, std::string autor)
    : id(id), titulo(titulo), autor(autor), disponibilidade(true) {}

int Livro::getID() const {
    return id;
}

std::string Livro::getTitulo() const {
    return titulo;
}

std::string Livro::getAutor() const {
    return autor;
}

bool Livro::isDisponivel() const {
    return disponibilidade;
}

void Livro::setID(int id) {
    this->id = id;
}

void Livro::setTitulo(const std::string &titulo) {
    this->titulo = titulo;
}

void Livro::setAutor(const std::string &autor) {
    this->autor = autor;
}

void Livro::setDisponivel(bool disponibilidade) {
    this->disponibilidade = disponibilidade;
}