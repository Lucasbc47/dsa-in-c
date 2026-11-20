# Triângulo de Pascal e Árvores Binárias

## Triângulo de Pascal Completo

```
                        1                          linha 0
                      1   1                        linha 1
                    1   2   1                      linha 2
                  1   3   3   1                    linha 3
                1   4   6   4   1                  linha 4
              1   5  10  10   5   1                linha 5
            1   6  15  20  15   6   1              linha 6
          1   7  21  35  35  21   7   1            linha 7
```

**Propriedade:** Cada número é a soma dos dois números acima dele.
- Fórmula: `C(n, k) = C(n-1, k-1) + C(n-1, k)`

---

## Números de Catalan

Os **Números de Catalan** aparecem no Triângulo de Pascal e contam estruturas combinatórias, incluindo árvores binárias!

### Fórmula:
```
C_n = C(2n, n) / (n+1)

Onde C(2n, n) é o coeficiente binomial
```

### Calculando C_n:

```
C_0 = 1
C_1 = 1
C_2 = C(4,2) / 3 = 6/3 = 2
C_3 = C(6,3) / 4 = 20/4 = 5
C_4 = C(8,4) / 5 = 70/5 = 14
C_5 = C(10,5) / 6 = 252/6 = 42
```

### Onde encontrar no Triângulo de Pascal:

```
         1
       1   1
     1   2   1
   1   3   3   1
 1   4   6   4   1          ← C(4,2) = 6
1  5  10  10   5   1
1 6  15  20  15  6  1        ← C(6,3) = 20
```

**C_3 = 20 / 4 = 5** (5 árvores binárias com 3 nós)

---

## Exemplos de Árvores Binárias

### n = 1 (C_1 = 1 árvore)
```
  1
```

### n = 2 (C_2 = 2 árvores)
```
  1        2
   \      /
    2    1
```

### n = 3 (C_3 = 5 árvores)
```
    1          1          2          3          3
     \          \        / \        /          /
      2          3      1   3      1          2
       \        /                   \        /
        3      2                     2      1
```

### n = 4 (C_4 = 14 árvores - algumas)
```
    1          1          1          2          2
     \          \          \        / \        / \
      2          2          3      1   3      1   4
       \          \        /            \        /
        3          4      2              4      3
         \        /        \
          4      3          4

    3          3          4
   / \        / \        /
  1   4      2   4      1
   \        /          / \
    2      1          2   3
```

**E assim por diante...**

---

## Aplicações Práticas

### 1. **Contagem de BSTs possíveis**
Com valores [1, 2, 3], quantas BSTs diferentes podemos criar?
**Resposta:** C_3 = 5

### 2. **Análise de Ordenação**
Se inserirmos [1, 2, 3] nesta ordem:
```
  1
   \
    2
     \
      3
```
Árvore degenerada (lista) → O(n)

Se inserirmos [2, 1, 3]:
```
    2
   / \
  1   3
```
Árvore balanceada → O(log n)

### 3. **Outras estruturas que usam Catalan**
- Caminhos em grade (sem passar acima da diagonal)
- Expressões com parênteses válidas
- Formas de dividir polígonos em triângulos
- Formas de calcular produtos matriciais

---

## Exercício Prático

**Questão:** Quantas BSTs diferentes podem ser formadas com 5 nós distintos?

**Solução:**
```
C_5 = C(10, 5) / 6
C(10, 5) = 10!/(5!×5!) = 252
C_5 = 252 / 6 = 42
```

**Resposta:** 42 árvores binárias diferentes!

---

## Resumo

| n | C_n | Árvores possíveis |
|---|-----|-------------------|
| 0 | 1   | 1 (vazia)         |
| 1 | 1   | 1                 |
| 2 | 2   | 2                 |
| 3 | 5   | 5                 |
| 4 | 14  | 14                |
| 5 | 42  | 42                |
| 6 | 132 | 132               |

**Importante:** Isso mostra que a ordem de inserção importa MUITO na estrutura final de uma BST!
