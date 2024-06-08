
# Sistema de Biblioteca Avançado

## Descrição
O Sistema de Biblioteca Avançado é um software projetado para gerenciar bibliotecas, incorporando funcionalidades como notificação de devolução atrasada, gerenciamento de multas e controle de estoque de livros. Este sistema visa aprimorar a eficiência e a organização dos processos de empréstimo e devolução de livros, bem como melhorar a comunicação com os usuários da biblioteca.

## Modelagem

### Diagrama de Classes
![Diagrama de Classes](file-JELAhhB8U2YsuVmxSUYPgdgU)

### Classes, Atributos e Métodos

#### Classe: Livro
**Atributos:**
- `int id`: Identificador único do livro.
- `string titulo`: Título do livro.
- `string autor`: Autor do livro.
- `bool disponivel`: Indicador de disponibilidade do livro.

**Métodos:**
- `Livro(int id, string titulo, string autor)`: Construtor da classe Livro.

#### Classe: Biblioteca
**Atributos:**
- `vector<Livro> livros`: Lista de livros na biblioteca.
- `vector<Usuario> usuarios`: Lista de usuários registrados na biblioteca.
- `vector<Funcionario> funcionarios`: Lista de funcionários da biblioteca.

**Métodos:**
- `void adicionarLivro(Livro livro)`: Adiciona um novo livro à biblioteca.
- `void adicionarUsuario(Usuario usuario)`: Adiciona um novo usuário à biblioteca.
- `void emprestarLivro(int livroID, int usuarioID)`: Empresta um livro para um usuário.
- `void devolverLivro(int livroID, int usuarioID)`: Devolve um livro emprestado por um usuário.
- `void exibirEstoque()`: Exibe o estoque de livros da biblioteca.

#### Classe: Usuario
**Atributos:**
- `int id`: Identificador único do usuário.
- `string nome`: Nome do usuário.
- `unordered_map<int, time_t> livrosEmprestados`: Mapa de livros emprestados pelo usuário com a data de empréstimo.
- `double totalMulta`: Total de multas acumuladas pelo usuário.

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
- `void notificarDevolucaoAtrasada(Usuario &usuario, int livroID, int diasAtraso)`: Notifica o usuário sobre a devolução atrasada de um livro.
- `void gerenciarMulta(Usuario &usuario, int diasAtraso)`: Calcula e registra a multa de um usuário com base nos dias de atraso.

## User Stories

### Notificação de Devolução Atrasada
- **Como funcionário da biblioteca, quero registrar a data do empréstimo e a data de devolução de um livro e ser notificado pelo sistema quando a devolução estiver atrasada.**
- **Como cliente, quero receber uma notificação (por email ou mensagem) quando a data de devolução de um livro estiver próxima e atrasada.**

### Gerenciamento de Multas
- **Como funcionário, quero calcular e registrar o valor total da multa por dia de atraso em relação à data de devolução de um livro.**
- **Como cliente, quero consultar o valor da multa de um livro atrasado.**
- **Como cliente, quero realizar o pagamento da multa de um livro atrasado.**

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
   g++ -o biblioteca main.cpp CadastroUsuario.cpp Playlist.cpp Filme.cpp
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

## Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests para adicionar novas funcionalidades, corrigir bugs ou melhorar a documentação.

## Licença
Este projeto é licenciado sob a licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.
