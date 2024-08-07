
# Sistema de Biblioteca Avançado

## Descrição
O Sistema de Biblioteca Avançado é um software projetado para gerenciar bibliotecas, incorporando funcionalidades como notificação de devolução atrasada, gerenciamento de multas e controle de estoque de livros. Este sistema visa aprimorar a eficiência e a organização dos processos de empréstimo e devolução de livros, bem como melhorar a comunicação com os usuários da biblioteca.

## Modelagem

### Diagrama de Classes
<img width="2848" alt="Untitled (3)" src="https://github.com/manuuz/sistema-biblioteca-pds2/assets/52366222/b3a0d1f7-1114-4b4c-a83c-a4aba5073fb4">

[Cartões CRC e Divisão de Tarefas](https://docs.google.com/document/d/1GOgi_fkTgy_AZBuBnDpczVqwoWMXSgU3ZNwdjlJeYJU/edit?usp=sharing)

### Classes, Atributos e Métodos

#### Classe: Livro
**Atributos:**
- `int id`: Identificador único do livro.
- `string titulo`: Título do livro.
- `string autor`: Autor do livro.
- `bool disponibilidade`: Indicador de disponibilidade do livro.

**Métodos:**
- `Livro(int id, string titulo, string autor)`: Construtor da classe Livro.

#### Classe: Biblioteca
**Atributos:**
- `vector<Livro> livros`: Lista de livros na biblioteca.
- `vector<Usuario> usuarios`: Lista de usuários registrados na biblioteca.
- `vector<Funcionario> funcionarios`: Lista de funcionários da biblioteca.

**Métodos:**
- `void adicionarUsuario(Usuario usuario)`: Adiciona um novo usuário à biblioteca.
- `void devolverLivro(int livroID, int usuarioID)`: Devolve um livro emprestado por um usuário.
- `void exibirEstoque()`: Exibe o estoque de livros da biblioteca.

#### Classe: Usuario
**Atributos:**
- `int id`: Identificador único do usuário.
- `string nome`: Nome do usuário.
- `vector<Livro> livrosEmprestados`: Mapa de livros emprestados pelo usuário com a data de empréstimo.
- `double multa`: Total de multas acumuladas pelo usuário.

**Métodos:**
- `Usuario(int id, string nome)`: Construtor da classe Usuario.
- `void emprestarLivro(int livroID)`: Solicita o empréstimo de um livro.
- `void devolverLivro(int livroID)`: Devolve um livro emprestado.
- `void pagarMulta(double valor)`: Paga uma multa acumulada.

#### Classe: Funcionario
**Atributos:**
- `int id`: Identificador único do funcionário.
- `string nome`: Nome do funcionário.

**Métodos:**
- `Funcionario(int id, string nome)`: Construtor da classe Funcionario.
- `void cadastrarLivro(Livro livro)`: Adiciona um novo livro à biblioteca.
- `void realizaEmprestimo(int livroID, int usuarioID)`: Empresta um livro para um usuário.
- `void gerenciarMulta(const std::vector<Usuario*>& usuarios)`: Calcula e registra a multa de um usuário com base nos dias de atraso.

## User Stories

### Gerenciamento de Multas
- **Como funcionário, quero calcular e registrar o valor total da multa por dia de atraso em relação à data de devolução de um livro.**

### Controle de Estoque
- **Como funcionário quero cadastrar novos livros no acervo.**
- **Como funcionário, quero realizar os empréstimos pelo sistema e atualizar a disponibilidade dos livros no acervo.**
- **Como funcionário, quero gerenciar os usuários que estão com devoluções atrasadas e suas respectivas multas.**

## Instalação e Uso

### Requisitos
- Compilador C++ (GCC, Clang, etc.)
- CMake (opcional, mas recomendado para facilitar a compilação)
- Biblioteca padrão C++ (STL)

### Compilação
1. Clone o repositório:
   ```sh
   git clone https://github.com/seuusuario/sistemabiblioteca.git
   cd sistemabiblioteca
   ```

2. Compile o código:
   ```sh
   g++ -o biblioteca main.cpp Usuario.cpp Livro.cpp Funcionario.cpp
   ```

3. Execute o programa:
   ```sh
   ./biblioteca
   ```

### Uso
O programa aceita comandos via linha de comando para gerenciar o acervo de livros, os usuários e os funcionários. Abaixo estão os comandos suportados:

- `adicionarLivro <id> <titulo> <autor>`: Adicionar um novo livro à biblioteca.
- `adicionarUsuario <id> <nome>`: Adicionar um novo usuário à biblioteca.
- `emprestarLivro <livroID> <usuarioID>`: Emprestar um livro para um usuário.
- `devolverLivro <livroID> <usuarioID>`: Devolver um livro emprestado por um usuário.
- `exibirEstoque`: Exibir o estoque de livros da biblioteca.