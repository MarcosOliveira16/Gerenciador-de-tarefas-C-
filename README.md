# Gerenciador-de-tarefas-C-
Código feito em c++ utilizando conceitos de orientação a objetos como polimorfismo e herança.
Desenvolvido durante as disciplinas de "Linguagem de programação I" e "Laboratório de linguagem de programação I".


Claro! Vamos elaborar a documentação de forma mais detalhada, fornecendo informações sobre cada parte do código, sua funcionalidade, métodos, atributos e como eles se relacionam para formar o sistema de gerenciamento de tarefas.

# Documentação do Sistema de Gerenciamento de Tarefas

## Introdução

Este documento apresenta a documentação para um sistema de gerenciamento de tarefas desenvolvido em C++. O sistema permite a criação, visualização, edição, exclusão, salvamento e importação de tarefas de diferentes categorias, como Educação, Lazer, Esporte e Comemorativa.

## Estrutura do Projeto

O projeto está dividido em várias partes, cada uma responsável por uma funcionalidade específica do sistema. Abaixo estão listadas as principais partes do projeto:

1. **Tarefa.h e Tarefa.cpp**: Define a classe base `Tarefa`, que representa uma tarefa genérica.
2. **Educacao.h e Educacao.cpp**: Define a classe `Educacao`, que representa uma tarefa do tipo Educação.
3. **Lazer.h e Lazer.cpp**: Define a classe `Lazer`, que representa uma tarefa do tipo Lazer.
4. **Esporte.h e Esporte.cpp**: Define a classe `Esporte`, que representa uma tarefa do tipo Esporte.
5. **Comemorativa.h e Comemorativa.cpp**: Define a classe `Comemorativa`, que representa uma tarefa do tipo Comemorativa.
6. **Data.h e Data.cpp**: Define a classe `Data`, que representa uma data.
7. **Gerenciador.h e Gerenciador.cpp**: Define a classe `Gerenciador`, responsável por gerenciar todas as tarefas do sistema.
8. **SwitchException.h e SwitchException.cpp**: Define a classe `SwitchException`, responsável por lidar com exceções em comandos de switch.
9. **main.cpp**: Contém a função principal do programa.

## Detalhes de Implementação

### Classe `Tarefa`

A classe `Tarefa` serve como uma classe base para todos os tipos de tarefas no sistema. Ela armazena informações básicas como título, descrição, característica, tipo e data. Abaixo estão listados seus principais métodos e atributos:

#### Atributos:

- `titulo`: Título da tarefa.
- `descricao`: Descrição da tarefa.
- `caracteristica`: Característica da tarefa (ex: Educação, Lazer, etc.).
- `tipo`: Tipo da tarefa (ex: 1 para Educação, 2 para Lazer, etc.).
- `data`: Objeto da classe `Data` que representa a data da tarefa.

#### Métodos:

- `getTitulo()`: Retorna o título da tarefa.
- `getDescricao()`: Retorna a descrição da tarefa.
- `getCarac()`: Retorna a característica da tarefa.
- `getTipo()`: Retorna o tipo da tarefa.
- `getData()`: Retorna a data da tarefa.
- `setTitulo(string t)`: Define o título da tarefa.
- `setDescricao(string d)`: Define a descrição da tarefa.
- `setCarac(string c)`: Define a característica da tarefa.
- `setTipo(int t)`: Define o tipo da tarefa.
- `setData(Data d)`: Define a data da tarefa.
- `retornaTipo(int t)`: Retorna o nome da característica com base no tipo.

### Classes Específicas de Tarefas

As classes `Educacao`, `Lazer`, `Esporte` e `Comemorativa` herdam da classe `Tarefa` e adicionam informações específicas para cada tipo de tarefa. Por exemplo, a classe `Educacao` armazena informações como disciplina e professor, enquanto a classe `Lazer` armazena informações como local e tipo de pagamento.

### Classe `Gerenciador`

A classe `Gerenciador` é responsável por gerenciar todas as tarefas do sistema. Ela permite a criação, visualização, edição, exclusão, salvamento e importação de tarefas. Além disso, fornece métodos para realizar operações específicas, como apagar todas as tarefas de um determinado tipo ou salvar todas as tarefas em um arquivo.

### Manipulação de Exceções

A classe `SwitchException` é usada para lidar com exceções em comandos de switch. Por exemplo, quando o usuário seleciona uma opção inválida em um menu, uma exceção é lançada e tratada pela classe `SwitchException`, exibindo uma mensagem de erro apropriada.

## Conclusão

O sistema de gerenciamento de tarefas desenvolvido em C++ oferece uma maneira eficiente de criar, visualizar, editar, excluir, salvar e importar tarefas de diferentes categorias. Com uma estrutura bem organizada e métodos bem definidos, o sistema é fácil de entender, manter e estender. Ele pode ser usado para gerenciar tarefas pessoais, acadêmicas, esportivas e de lazer, proporcionando uma melhor organização e produtividade ao usuário.
