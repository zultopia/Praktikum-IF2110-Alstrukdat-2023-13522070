/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

# include "stack.h"
# include <stdio.h>

int fibonacci(Stack *S, int i){
    printf("fibonacci(%d)\n",i);

    if (i == 0){
        return 0;
    }
    else if (i == 1){
        return 1;
    }
    else {
        return (fibonacci(S, i-1) + fibonacci(S, i-2));
    }
}

int main (){
    int N;
    Stack S;

    scanf("%d", &N);
    CreateEmpty(&S);

    int result = fibonacci(&S, N);
    printf("%d\n", result);
}