# Representação Implícita - Árvore Binária em Array

## Conceito

Para **árvores binárias completas**, podemos usar um array em vez de ponteiros!

### Fórmulas de Navegação (array começa no índice 1)

```
Pai(i) = ⌊i/2⌋
Filho_esquerdo(i) = 2i
Filho_direito(i) = 2i + 1
```

---

## Exemplo Detalhado

### Árvore Completa:

```
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
        / \
       8   9
```

### Array Correspondente:

```
Índice:  0   1   2   3   4   5   6   7   8   9
Array:  [-,  1,  2,  3,  4,  5,  6,  7,  8,  9]
         ^   ^
         |   |
    (ignorado) raiz
```

---

## Navegação Passo a Passo

### Exemplo 1: Nó no índice 4 (valor = 4)

- **Pai:** ⌊4/2⌋ = 2 → array[2] = 2 ✓
- **Filho esquerdo:** 2×4 = 8 → array[8] = 8 ✓
- **Filho direito:** 2×4+1 = 9 → array[9] = 9 ✓

### Exemplo 2: Nó no índice 2 (valor = 2)

- **Pai:** ⌊2/2⌋ = 1 → array[1] = 1 ✓
- **Filho esquerdo:** 2×2 = 4 → array[4] = 4 ✓
- **Filho direito:** 2×2+1 = 5 → array[5] = 5 ✓

### Exemplo 3: Nó no índice 7 (valor = 7)

- **Pai:** ⌊7/2⌋ = 3 → array[3] = 3 ✓
- **Filho esquerdo:** 2×7 = 14 → 14 > 9 (não existe) ✗
- **Filho direito:** 2×7+1 = 15 → 15 > 9 (não existe) ✗
- **Conclusão:** Nó 7 é uma folha!

### Exemplo 4: Raiz no índice 1 (valor = 1)

- **Pai:** ⌊1/2⌋ = 0 → Não tem pai (é a raiz!) ✓
- **Filho esquerdo:** 2×1 = 2 → array[2] = 2 ✓
- **Filho direito:** 2×1+1 = 3 → array[3] = 3 ✓

---

## Implementação em C

```c
#include <stdio.h>
#define MAX 100

typedef struct {
    int info[MAX];
    int size;  // número de elementos
} ArrayTree;

// Inicializa árvore
void init(ArrayTree* tree) {
    tree->size = 0;
    // Índice 0 não é usado
    tree->info[0] = -1;
}

// Retorna índice do pai
int pai(int i) {
    if (i == 1) return -1;  // raiz não tem pai
    return i / 2;
}

// Retorna índice do filho esquerdo
int filho_esq(int i, int size) {
    int esq = 2 * i;
    return (esq <= size) ? esq : -1;
}

// Retorna índice do filho direito
int filho_dir(int i, int size) {
    int dir = 2 * i + 1;
    return (dir <= size) ? dir : -1;
}

// Verifica se é folha
int eh_folha(int i, int size) {
    return filho_esq(i, size) == -1 && filho_dir(i, size) == -1;
}

// Insere na próxima posição disponível
void inserir(ArrayTree* tree, int valor) {
    tree->size++;
    tree->info[tree->size] = valor;
}

// Imprime a árvore
void imprimir(ArrayTree* tree) {
    printf("Array: [");
    for (int i = 1; i <= tree->size; i++) {
        printf("%d", tree->info[i]);
        if (i < tree->size) printf(", ");
    }
    printf("]\n");
}

int main() {
    ArrayTree tree;
    init(&tree);

    // Inserindo valores
    printf("=== Árvore Binária em Array ===\n\n");
    for (int i = 1; i <= 9; i++) {
        inserir(&tree, i);
    }

    imprimir(&tree);

    printf("\nÁrvore:\n");
    printf("        1\n");
    printf("       / \\\n");
    printf("      2   3\n");
    printf("     / \\ / \\\n");
    printf("    4  5 6  7\n");
    printf("   / \\\n");
    printf("  8   9\n\n");

    // Testando navegação
    int no = 4;
    printf("Nó %d (índice %d):\n", tree.info[no], no);
    printf("  Pai: %d\n", tree.info[pai(no)]);

    int esq = filho_esq(no, tree.size);
    if (esq != -1)
        printf("  Filho esquerdo: %d\n", tree.info[esq]);

    int dir = filho_dir(no, tree.size);
    if (dir != -1)
        printf("  Filho direito: %d\n", tree.info[dir]);

    printf("\n");

    // Testando folhas
    printf("Folhas: ");
    for (int i = 1; i <= tree.size; i++) {
        if (eh_folha(i, tree.size)) {
            printf("%d ", tree.info[i]);
        }
    }
    printf("\n");

    return 0;
}
```

---

## Quando Usar?

### ✅ Bom para:

- **Heap** (min-heap, max-heap)
- **Árvores completas** ou **quase completas**
- **Priority Queue**
- Quando você precisa de acesso rápido ao pai

### ❌ Não ideal para:

- **BST genérica** (pode ter "buracos" no array)
- Árvores desbalanceadas
- Quando há muitas inserções/remoções

---

## Comparação: Array vs Ponteiros

| Aspecto       | Array                | Ponteiros           |
| ------------- | -------------------- | ------------------- |
| Acesso pai    | O(1) direto          | Precisa armazenar   |
| Acesso filhos | O(1) direto          | O(1) via ponteiros  |
| Memória       | Pode desperdiçar     | Só usa o necessário |
| Estrutura     | Só árvores completas | Qualquer formato    |
| Cache         | Melhor (contíguo)    | Pior (espalhado)    |

---

## Aplicação Real: Binary Heap

O **Heap** (usado em heapsort e priority queues) usa representação em array!

```
Max-Heap:        100
                /   \
               19    36
              /  \  /  \
             17  3 25  1

Array: [-, 100, 19, 36, 17, 3, 25, 1]

Propriedade: Pai sempre ≥ filhos
```

Para todo i: `array[i] >= array[2i]` e `array[i] >= array[2i+1]`
