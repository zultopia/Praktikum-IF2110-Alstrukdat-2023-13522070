/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

# include "stack.h"
# include "wordmachine.h"
# include <stdio.h>

void readWord(Word *input) {
    int a;
    START();
    IgnoreBlanks();
    (*input).Length = 0;
    a = 0;
    while ((currentChar != MARK) && (a < NMax)) {
        (*input).TabWord[a] = currentChar;
        ADV();
        a++;}
    (*input).Length = a;
    (*input).TabWord[a] = '\0';
}

int main (){
    Word character;
    readWord(&character);
    Stack S;
    CreateEmpty(&S);

    int i;
    int in = 0;
    for(i = 0; i < character.Length ; i++){
        if(character.TabWord[0] == ')'){
            printf("-1\n");
            return 0;
        }
        if (character.TabWord[i] =='('){
            Push(&S, character.TabWord[i]);
        }
        else{
            Pop(&S, &character.TabWord[i]);
        }
        if (Top(S) + 1 > in){
            in = Top(S)+1;
        }
    }
    if(Top(S) != Nil){
        printf("-1\n");
        return 0;
    }
    printf("%d\n", in);
}