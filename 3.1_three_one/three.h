#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define ARR_SIZE 100

typedef struct FixedStack{
    int values[ARR_SIZE];
    int stackCapacities[3];
    int capacity;
}FixedStack;

void initFixedStack(FixedStack* s);
void push (FixedStack* s, int stackNum, int value);
int pop (FixedStack* s, int stackNum);
int peek (FixedStack* s, int stackNum);
bool isEmpty(FixedStack* s, int stackNum);





