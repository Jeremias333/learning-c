#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(){
    char input [4];
    // input[0] = '1';
    // input[1] = '2';
    // input[2] = '3';
    // // input[3] = '\0';
    // int value;
    // sscanf(input, "%d", &value);
    // printf("%d ", value);
    input[0] = 1+'0';
    printf("%c", input[0]);
    // char input[999];    
    // // while(scanf("%s", input) != EOF)
    // fgets(input, 999, stdin);

    // // printf("%s ", input[1]);

    // for (int i = 0; i < strlen(input); i++){
    //     printf("%c\n", input[i]);
    //     char temp_str = input[i];
    //     // printf("%d\n", strncmp(&input[i], "(", strlen("(")));
    //     if(strncmp(&input[i], "(", strlen("(")) == 0){
    //         printf("A raíz vai ser %d\n", input[i+1] - '0');
    //     }
    // }



    
    // char* input = "jeremias";
    // scanf("%s", &input);
    // fgets(input, sizeof(input), stdin);

    // printf("%d\n", strlen(input)-1);

    // printf("%s ", input[1]);

    // for (int i = 0; i < sizeof(input); i++)
    // {
    //     // int temp_len = (int) strlen(input);
    //     printf("%s ", &input);
    // }

    return 0;
}