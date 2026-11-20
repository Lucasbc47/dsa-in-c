#include <stdio.h>

int main()
{
    // (1, 3, 5, 7, 9)
    for (int i = 1; i <= 9; i += 2)
    {
        // I, J vai de 7 até 5
        for (int j = 7; j >= 5; j--)
        {
            printf("I=%d J=%d\n", i, j);
        }
    }

    return 0;
}
