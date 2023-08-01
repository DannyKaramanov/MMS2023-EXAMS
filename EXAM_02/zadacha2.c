#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdint.h>

#define COUNT 10

typedef struct Car{
    char model[20];
    uint8_t maxspeed;
    double price;

}Car;
char *alphabet="abcdefghijklmnopqrstuvwxyz";

int generate(int min, int max){
    return (rand()%(max -min+1)+min);
}
void randomName(int lenght, char n[]){
    int i;
    for(i=0; i<lenght; i++){
        int k = generate(1, 26);
        n[i] = alphabet[k-1];
    }
    n[0] = toupper(n[0]);
    n[i] = '\0';
}
// void ModelASC( const char * a, const char * b){
//     char *temp;
//     int i,str;
//     int a = strlen(a);
//     int *b= strlen(b);
//     for(int i = 0; i<n-1; i++){
//         for(int j=i+1;j<n;j++){
//             if(strcmp(&b[str],&a[str])>0){
//                 *temp = b[str];
//                 b[str] = a[str];

//             }
//         }
//     }

// }

int maxspeedASC(const void * a, const void * b){
        return (((Car*)a) -> maxspeed - ((Car*)b) -> maxspeed);
        }
int maxspeedDESC(const void * a, const void * b){
        return (((Car*)b) -> maxspeed - ((Car*)a) -> maxspeed);
    }
int pricesASC(const void * a, const void * b){
        return (((Car*)a) -> price - ((Car*)b) -> price)*10;
    }
int pricesDESC(const void * a, const void * b){
        return (((Car*)b) -> price - ((Car*)a) -> price)*10;
    }

int (*getComparator(int n))(const void* a, const void* b){
    switch (n) {
        case 1:
        
        case 2:
        //return ;
    case 3:
        return maxspeedASC;
        break;
    case 4:
        return maxspeedDESC;
        break;
    case 5:
        return pricesASC;
        break;
    case 6:
        return pricesDESC;
        break;
    default:
    return NULL;

    }
}
void print_arr(Car arr[], size_t n){
    for(size_t i = 0; i < n; i++){
        printf("%s \t %d \t %.2lf \n", arr[i].model,arr[i].maxspeed,arr[i].price);
    }
    printf("\n");
}

int main(){
    Car *arr = malloc( COUNT*sizeof(Car));
     for(size_t i =0; i < COUNT; i++){
        int names = generate(4,10);
        randomName(names,arr[i].model);
        arr[i].maxspeed = generate(100,300);
        arr[i].price = generate((double)1000.00, (double)100000.00);
    }
    print_arr(arr, COUNT);

    int sortN;
    printf("Enter number from 1 to 6: ");
    scanf("%d", &sortN);
    printf("Sorted: \n");
    qsort(arr, COUNT, sizeof(Car), getComparator(sortN));
    print_arr(arr, COUNT);
    

    
}