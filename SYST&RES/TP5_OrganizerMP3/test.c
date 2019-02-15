#include <stdio.h>
int main() {
    int nbr = 0;
    while (scanf("%d\n",&nbr)>0 && nbr<=99 && nbr!=42){
        printf("%d\n",nbr);
    }
    return 0;
}