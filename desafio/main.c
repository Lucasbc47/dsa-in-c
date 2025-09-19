#include "t_char_pilha.h"

int main() {

    char str[6];
    printf("Insira str:\n");
    scanf("%6s", str);
    
    // i < strlen(str) && !falha
    // for (int i=0; str[i] != '\0'; i++){
    for (int i=0; i < strlen(str); i++){        
    if (isalpha(str[i]) || (str[i] == '(') || (str[i] == ')'))  
        {
            if (str[i] == '('){
                printf("empilhar!\n");
                // tentar empilhar        
            }
            if (str[i] == ')'){
                // tentar desimpilhar        
                // falha = !(pop(&p, &car));
                printf("desempilhar!\n");
            }
            
        }
        printf("numero - ");
    }

}