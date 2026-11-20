# Representação Encadeada (Ponteiros)

## Conceito

Uma **árvore binária** na representação encadeada é um conjunto de estruturas que satisfaz:

1. Os registros são chamados **nós** ou **células**
2. Cada nó possui:
   - **Informações** que devem ser armazenadas
   - **Endereços** ou **referências de memória** para seus nós sucessores

---

## Estrutura do Nó

Cada nó tem **três campos**:

1. **Informação**: um número inteiro (ou qualquer tipo de dado)
2. **Referência (ponteiro)** para o filho da esquerda
3. **Referência (ponteiro)** para o filho da direita

### Em C:

```c
typedef struct Node {
    int info;              // Campo 1: informação
    struct Node* left;     // Campo 2: ponteiro para filho esquerdo
    struct Node* right;    // Campo 3: ponteiro para filho direito
} Node;
```

---

## Visualização de Memória

### Árvore Lógica:

```
        50
       /  \
      30   70
```

### Memória Física:

```
Endereço: 0x1000
┌──────────────────┐
│  info = 50       │ ← Nó raiz
│  left = 0x2000   │ ─┐
│  right = 0x3000  │ ─┼─┐
└──────────────────┘  │ │
                      │ │
Endereço: 0x2000 ←────┘ │
┌──────────────────┐    │
│  info = 30       │    │
│  left = NULL     │    │
│  right = NULL    │    │
└──────────────────┘    │
                        │
Endereço: 0x3000 ←──────┘
┌──────────────────┐
│  info = 70       │
│  left = NULL     │
│  right = NULL    │
└──────────────────┘
```

---

## Criação de Nós

### Função para criar um nó:

```c
Node* criar_no(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));  // Aloca memória
    novo->info = valor;                        // Define o valor
    novo->left = NULL;                         // Inicializa esquerda
    novo->right = NULL;                        // Inicializa direita
    return novo;                               // Retorna ponteiro
}
```

### Uso:

```c
Node* raiz = criar_no(50);
raiz->left = criar_no(30);
raiz->right = criar_no(70);
```

**Resultado:**

```
        50
       /  \
      30   70
```

---

## Navegação na Árvore

### Acessando informações:

```c
// Valor da raiz
printf("%d\n", raiz->info);  // 50

// Valor do filho esquerdo
printf("%d\n", raiz->left->info);  // 30

// Valor do filho direito
printf("%d\n", raiz->right->info);  // 70
```

### Verificando se um nó é folha:

```c
int eh_folha(Node* no) {
    return (no != NULL && no->left == NULL && no->right == NULL);
}
```

### Verificando se existe filho:

```c
if (raiz->left != NULL) {
    printf("Tem filho esquerdo: %d\n", raiz->left->info);
}

if (raiz->right != NULL) {
    printf("Tem filho direito: %d\n", raiz->right->info);
}
```

---

## Exemplo Completo: Construindo uma Árvore

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* left;
    struct Node* right;
} Node;

Node* criar_no(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->info = valor;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

int main() {
    // Construindo a árvore manualmente
    //        50
    //       /  \
    //      30   70
    //     / \
    //    20  40

    Node* raiz = criar_no(50);
    raiz->left = criar_no(30);
    raiz->right = criar_no(70);
    raiz->left->left = criar_no(20);
    raiz->left->right = criar_no(40);

    // Navegando
    printf("Raiz: %d\n", raiz->info);
    printf("Filho esquerdo da raiz: %d\n", raiz->left->info);
    printf("Filho direito da raiz: %d\n", raiz->right->info);
    printf("Neto esquerdo-esquerdo: %d\n", raiz->left->left->info);
    printf("Neto esquerdo-direito: %d\n", raiz->left->right->info);

    // Verificações
    if (raiz->left->left->left == NULL) {
        printf("\nO no 20 nao tem filho esquerdo (eh folha)\n");
    }

    return 0;
}
```

**Saída:**

```
Raiz: 50
Filho esquerdo da raiz: 30
Filho direito da raiz: 70
Neto esquerdo-esquerdo: 20
Neto esquerdo-direito: 40

O no 20 nao tem filho esquerdo (eh folha)
```

---

## Liberação de Memória

**IMPORTANTE:** Como usamos `malloc`, precisamos liberar a memória!

```c
void liberar_arvore(Node* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->left);   // Libera subárvore esquerda
        liberar_arvore(raiz->right);  // Libera subárvore direita
        free(raiz);                   // Libera o nó atual
    }
}
```

**Uso:**

```c
liberar_arvore(raiz);
raiz = NULL;  // Boa prática
```

---

## Vantagens da Representação Encadeada

✅ **Flexibilidade total**

- Pode representar qualquer formato de árvore
- Não desperdiça espaço com "buracos"

✅ **Memória dinâmica**

- Usa apenas o necessário
- Pode crescer/diminuir durante execução

✅ **Navegação natural**

- Acesso direto aos filhos via ponteiros
- Implementação intuitiva de recursão

---

## Desvantagens

❌ **Sem acesso direto ao pai**

- Precisa armazenar ponteiro extra ou percorrer árvore

❌ **Fragmentação de memória**

- Nós podem estar espalhados na memória
- Cache-unfriendly comparado a array

❌ **Overhead de ponteiros**

- Cada nó precisa armazenar 2 ponteiros
- Em sistemas 64-bit: 16 bytes extras por nó

---

## Comparação: Encadeada vs Array

| Aspecto           | Encadeada                   | Array                |
| ----------------- | --------------------------- | -------------------- |
| Flexibilidade     | Alta (qualquer formato)     | Baixa (só completas) |
| Memória           | Só o necessário + ponteiros | Pode ter "buracos"   |
| Acesso aos filhos | O(1) via ponteiros          | O(1) via fórmula     |
| Acesso ao pai     | Precisa de ponteiro extra   | O(1) via fórmula     |
| Implementação     | Mais complexa               | Mais simples         |
| Uso comum         | BST, árvores gerais         | Heap, Priority Queue |

---

## Quando Usar?

### ✅ Use Representação Encadeada para:

- **Binary Search Trees (BST)**
- **Árvores desbalanceadas**
- **Árvores AVL, Red-Black Trees**
- **Árvores B, B+**
- Quando não sabe o tamanho final
- Quando precisa de flexibilidade

### ❌ Prefira Array para:

- **Binary Heap (min/max heap)**
- **Complete Binary Trees**
- **Priority Queues**
- Quando a árvore é sempre completa
- Quando precisa de cache performance

---

## Resumo

A **representação encadeada** é a forma mais comum e flexível de implementar árvores binárias:

- Cada nó é uma struct com 3 campos: `info`, `left`, `right`
- Usa `malloc` para alocar memória dinamicamente
- Usa ponteiros (`NULL`) para indicar ausência de filhos
- Requer `free` para liberar memória
- Ideal para BST e árvores com estrutura variável
