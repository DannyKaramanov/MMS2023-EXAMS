#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[]) {
    float sum = 0;
 
    int i;
    for (i = 1; i < argc; i++) {
        if (strchr(argv[i], '.') != NULL) {
            float fl = strtof(argv[i], NULL);
            sum += fl;
        } else if (strstr(argv[i], "0x") != NULL || strstr(argv[i], "0X") != NULL) {
            unsigned int hex = 0;
            sscanf(argv[i], "%x", &hex);
            sum += hex;
        } else {
            int num = atoi(argv[i]);
            sum += num;
        }
    }
 
    printf("Sum is %.2f\n", sum);
    return 0;
}