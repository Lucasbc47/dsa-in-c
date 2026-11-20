# Binary Search Tree (BST) em C

Implementação simples de uma Binary Search Tree com exemplos práticos.

## Estrutura do Projeto

```
arvore-binaria/
├── src/
│   ├── bst.h        # Header com declarações
│   ├── bst.c        # Implementação das funções
│   └── main.c       # Exemplo de uso
├── out/             # Executável compilado
├── docs/
│   └── CONCEITOS_BST.md  # Teoria e conceitos
└── run.bat          # Script para compilar e executar
```

## Como Usar

1. **Compilar e executar:**
   ```
   run.bat
   ```

2. **Ou compilar manualmente:**
   ```
   gcc src/bst.c src/main.c -o out/bst.exe
   out\bst.exe
   ```

## Funções Disponíveis

| Função | Descrição |
|--------|-----------|
| `criar_no(int)` | Cria um novo nó |
| `inserir(Node*, int)` | Insere valor mantendo propriedade BST |
| `buscar(Node*, int)` | Busca um valor na árvore |
| `remover(Node*, int)` | Remove um valor da árvore |
| `in_order(Node*)` | Imprime em ordem crescente |
| `pre_order(Node*)` | Imprime pré-ordem |
| `post_order(Node*)` | Imprime pós-ordem |
| `altura(Node*)` | Retorna altura da árvore |
| `liberar_arvore(Node*)` | Libera memória |

## Exemplo Rápido

```c
Node* raiz = NULL;

raiz = inserir(raiz, 50);
raiz = inserir(raiz, 30);
raiz = inserir(raiz, 70);

in_order(raiz);  // Imprime: 30 50 70

liberar_arvore(raiz);
```

## Documentação

Veja `docs/CONCEITOS_BST.md` para entender a teoria completa sobre BST.
