# Sudoku em C

Jogo de Sudoku para terminal, desenvolvido em linguagem C como projeto da faculdade.

![Linguagem](https://img.shields.io/badge/linguagem-C-blue)
![Licença](https://img.shields.io/badge/licença-MIT-green)

## Sobre o projeto

Este projeto implementa o clássico jogo de Sudoku com interface em modo texto. O tabuleiro é uma grade 9x9 que deve ser preenchida com números de 1 a 9, sem repetir o mesmo número na mesma linha, coluna ou bloco 3x3.

O objetivo do trabalho foi praticar conceitos de programação em C, como:

- Matrizes e manipulação de vetores
- Funções e modularização
- Validação de entrada do usuário
- Estruturas de controle e laços de repetição

## Funcionalidades

- Tabuleiro 9x9 exibido no terminal
- Números iniciais fixos que não podem ser alterados
- Validação das jogadas (linha, coluna e bloco 3x3)
- Detecção de vitória quando o tabuleiro é preenchido corretamente
- Mensagens de erro para jogadas inválidas

> Ajuste esta lista para refletir o que o seu jogo realmente faz (níveis de dificuldade, dicas, salvar jogo, etc.).

## Pré-requisitos

- Compilador C, como o [GCC](https://gcc.gnu.org/)
  - **Windows:** instale o [MinGW](https://www.mingw-w64.org/) ou use o WSL
  - **Linux:** `sudo apt install build-essential`
  - **macOS:** `xcode-select --install`

## Como compilar

```bash
gcc sudoku.c -o sudoku
```

Se o projeto tiver vários arquivos:

```bash
gcc main.c tabuleiro.c validacao.c -o sudoku
```

## Como executar

**Linux / macOS:**

```bash
./sudoku
```

**Windows:**

```bash
sudoku.exe
```

## Como jogar

1. O tabuleiro será exibido no terminal, com as células vazias representadas por `0` ou `.`.
2. Digite a **linha**, a **coluna** e o **valor** que deseja inserir.
3. O jogo valida a jogada e avisa se ela for inválida.
4. Continue até preencher todas as células corretamente.

Exemplo de jogada:

```
Linha (1-9): 3
Coluna (1-9): 5
Valor (1-9): 7
```

### Regras do Sudoku

- Cada **linha** deve conter os números de 1 a 9 sem repetição.
- Cada **coluna** deve conter os números de 1 a 9 sem repetição.
- Cada **bloco 3x3** deve conter os números de 1 a 9 sem repetição.

## Estrutura do projeto

```
sudoku-c/
├── sudoku.c      # Código-fonte principal
├── README.md     # Documentação do projeto
└── .gitignore    # Arquivos ignorados pelo Git
```

> Atualize a estrutura conforme os arquivos do seu projeto.

## Tecnologias utilizadas

- Linguagem C (padrão C99)
- GCC

## Possíveis melhorias

- [ ] Níveis de dificuldade (fácil, médio, difícil)
- [ ] Geração aleatória de tabuleiros
- [ ] Sistema de dicas
- [ ] Resolução automática com backtracking
- [ ] Salvar e carregar partidas

## Autor

**Seu Nome**

- GitHub: [@seu-usuario](https://github.com/seu-usuario)
- E-mail: seu-email@exemplo.com

## Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.
