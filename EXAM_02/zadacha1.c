#include <stdio.h>
#include <stdlib.h>
 
int main() {
     char *buffer;
    size_t bufsize = 0;
    size_t characters;
 
    //char specialSymbols[] = ['!','#','/','~','=','`','\'','\','>','.',',', '"'];
   // char alphabet[] = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'];
    char *alphabet="abcdefghijklmnopqrstuvwxyz";
 
 
    buffer = (char *)malloc(bufsize * sizeof(char));
    if ( buffer == NULL )
    {
        perror("Unable to allocate buffer\n");
        exit(1);
    }
 
    printf("Type something: ");
    characters = getline(&buffer, &bufsize, stdin);
 
    printf("%d characters were read.\n", (int)characters - 1);
    printf("You typed: '%s'\n", buffer);
 
    for(size_t i =0; i < (int)characters - 1; i++){
      if(i%2 == 0){
          // change the even numbers with alphabet symbol array
            buffer[i] = alphabet[(int)buffer[i]];
      } else {
          // change the odd numbers with speacial symbol array
         // buffer[i] = alphabet[(int)buffer[i]];
      }
    }
 
    printf("String is: '%s'\n", buffer);
 
}