#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>

class Livro{
private:
    int id;
    std::string titulo;
    std::string autor;
    bool disponibilidade;

public:
    Livro(int id, std::string titulo, std::string autor);

    int getID() const;
    void setID(int id);

    std::string getTitulo() const;
    void setTitulo(const std::string &titulo);

    std::string getAutor() const;
    void setAutor(const std::string &autor);

    bool isDisponivel() const;
    void setDisponivel(bool disponibilidade);
};
#endif //LIVRO_HPP