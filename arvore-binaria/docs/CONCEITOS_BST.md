# Binary Search Tree (BST) - Conceitos

## O que é uma Árvore Binária?

Uma **árvore binária** é um conjunto de elementos que está vazio ou particionado em três subconjuntos:

- Um único elemento chamado **raiz**
- Duas árvores binárias chamadas **subárvore esquerda** e **subárvore direita**

**Importante:** Cada nó tem no máximo 2 filhos (esquerda e direita).

---

## O que é uma Binary Search Tree (BST)?

Uma **BST** é uma árvore binária com uma **propriedade especial**:

> Para cada nó X:
>
> - Todos os valores na **subárvore esquerda** são **menores** que X
> - Todos os valores na **subárvore direita** são **maiores** que X

### Exemplo Visual:

```
        50
       /  \
      30   70
     /  \    \
    20  40   80
```

- 30 < 50 (esquerda)
- 70 > 50 (direita)
- 20 < 30 < 40 (subárvore esquerda de 50)

---

## Conceitos Básicos

### Terminologia

- **Grau de um nó**: número de sub-árvores do nó
- **Grau da árvore**: máximo grau dos nós na árvore
- **Folha**: nó de grau zero (sem filhos)
- **Nível**: raiz está no nível 0, seus filhos no nível 1, etc.
- **Altura/Profundidade**: nível máximo da árvore
- **Caminho**: sequência de nós distintos v1, v2, ..., vk
- **Ancestrais**: todos os nós no caminho da raiz até o nó

### Níveis em uma Árvore Binária

O **nível** de um nó indica sua distância da raiz:

```
              1  ← nível 0 (raiz) → 2⁰ = 1 nó
             / \
            2   3  ← nível 1 → 2¹ = 2 nós
           / \ / \
          4  5 6  7  ← nível 2 → 2² = 4 nós
         / \
        8   9  ← alguns nós no nível 3 → 2³ = 8 nós possíveis
```

**Propriedades importantes:**

- Nível 0: raiz (1 nó)
- Nível 1: filhos da raiz (até 2 nós)
- Nível k: até **2^k** nós possíveis
- Número máximo de nós em uma árvore de altura h: **2^(h+1) - 1**

### Relação com o Triângulo de Pascal

O número de **árvores binárias distintas** com n nós está relacionado aos **Números de Catalan**, que aparecem no Triângulo de Pascal!

#### Triângulo de Pascal:

```
                1
              1   1
            1   2   1
          1   3   3   1
        1   4   6   4   1
      1   5  10  10   5   1
```

#### Números de Catalan (C_n):

Fórmula: **C_n = (2n)! / ((n+1)! × n!)**

Ou usando combinação: **C_n = C(2n, n) / (n+1)**

```
n = 0: 1 árvore
n = 1: 1 árvore    (apenas raiz)
n = 2: 2 árvores
n = 3: 5 árvores
n = 4: 14 árvores
n = 5: 42 árvores
```

#### Exemplo com n=3 nós (5 árvores diferentes):

```
    1        1        2        3        3
     \        \      / \      /        /
      2        3    1   3    1        2
       \      /              \       /
        3    2                2     1
```

**Por que isso importa?**

- Mostra quantas BSTs diferentes podemos formar com os mesmos valores
- Útil para análise de complexidade e balanceamento
- A ordem de inserção afeta a estrutura final da árvore!

---

## Representação de Árvores Binárias

### 1. Representação Encadeada (Ponteiros/Explícita)

Uma árvore binária é um conjunto de estruturas (chamadas **nós** ou **células**) que satisfaz:

- Cada nó possui informações que devem ser armazenadas
- Cada nó possui **endereços** ou **referências de memória** para seus nós sucessores (filho esquerdo e filho direito)

**Estrutura do Nó:** Três campos

1. A **informação**: um número inteiro (ou qualquer tipo de dado)
2. As **referências (ponteiros)** para os nós sucessores: filho esquerdo e filho direito

```c
typedef struct Node {
    int info;              // Informação
    struct Node* left;     // Ponteiro para filho esquerdo
    struct Node* right;    // Ponteiro para filho direito
} Node;
```

**Exemplo visual:**

```
    Node: 50
    ┌──────────┐
    │ info: 50 │
    │ left:  ──┼──┐
    │ right: ──┼─┐│
    └──────────┘ ││
                 ││
       ┌─────────┘│
       ↓          │
    Node: 30      │
    ┌──────────┐ │
    │ info: 30 │ │
    │ left: ─  │ │
    │ right: ─ │ │
    └──────────┘ │
                 │
       ┌─────────┘
       ↓
    Node: 70
    ┌──────────┐
    │ info: 70 │
    │ left: ─  │
    │ right: ─ │
    └──────────┘
```

**Características:**

- Flexível: pode representar qualquer tipo de árvore binária
- Memória dinâmica: usa apenas o espaço necessário
- Ponteiros podem ser NULL quando não há filho

### 2. Representação Implícita (Array)

Para **árvores binárias completas**, podemos usar um array de dimensão 1!

**Fórmulas importantes (array começa em índice 1):**

1. **Pai(i) = ⌊i/2⌋** - Se i ≠ 1, então ele é a raiz
2. **Filho_esq(i) = 2i** - Se 2i > n, não tem filho esquerdo
3. **Filho_dir(i) = 2i+1** - Se 2i+1 > n, não tem filho direito

#### Exemplo Visual:

```
Árvore:              1  ← índice 1 (raiz)
                    / \
                   2   3  ← índices 2 e 3
                  / \ / \
                 4  5 6  7  ← índices 4,5,6,7
                / \
               8   9  ← índices 8 e 9

Array: [-, 1, 2, 3, 4, 5, 6, 7, 8, 9]
       índice: 0  1  2  3  4  5  6  7  8  9
       (índice 0 não usado)
```

#### Verificando as fórmulas:

- Nó 4: pai = ⌊4/2⌋ = 2 ✓
- Nó 2: filho_esq = 2×2 = 4 ✓, filho_dir = 2×2+1 = 5 ✓
- Nó 3: filho_esq = 2×3 = 6 ✓, filho_dir = 2×3+1 = 7 ✓
- Nó 7: filho_esq = 2×7 = 14 (> 9, não existe) ✓

**Vantagens:**

- Acesso direto aos filhos e pai (O(1))
- Economia de memória (sem ponteiros)
- Cache-friendly (dados contíguos)

**Desvantagens:**

- Só funciona bem para árvores completas
- BST não é sempre completa → desperdício de espaço

---

## Operações Principais em BST

### 1. **Busca (Search)**

- Complexidade: **O(h)** onde h = altura
- Aproveita a propriedade da BST para decidir ir para esquerda ou direita

### 2. **Inserção (Insert)**

- Complexidade: **O(h)**
- Sempre insere como uma folha
- Mantém a propriedade da BST

### 3. **Remoção (Delete)**

- Complexidade: **O(h)**
- 3 casos:
  - Nó folha: remove direto
  - Nó com 1 filho: substitui pelo filho
  - Nó com 2 filhos: substitui pelo sucessor (menor da direita) ou predecessor (maior da esquerda)

### 4. **Travessias (Traversal)**

- **In-Order** (esquerda → raiz → direita): imprime em ordem crescente
- **Pre-Order** (raiz → esquerda → direita)
- **Post-Order** (esquerda → direita → raiz)

---

## Complexidade

| Operação | Melhor Caso | Pior Caso |
| -------- | ----------- | --------- |
| Busca    | O(log n)    | O(n)      |
| Inserção | O(log n)    | O(n)      |
| Remoção  | O(log n)    | O(n)      |

**Pior caso:** árvore degenerada (vira uma lista encadeada)
**Melhor caso:** árvore balanceada

---

## Vantagens da BST

1. Busca eficiente (melhor que lista, pior que hash table)
2. Inserção e remoção dinâmicas
3. Mantém dados ordenados
4. Travessia in-order retorna elementos ordenados
