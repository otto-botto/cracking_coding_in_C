#include <stdio.h>
#include "2.1_removeDup.h"


int main() {
    Node* node = makeNode(6);
    unsigned int ptrAddress = (unsigned int)node;
    int index = ptrAddress % 100;
    printf("%d \n", ptrAddress);
    printf("%d \n", index);



    return 0;
}