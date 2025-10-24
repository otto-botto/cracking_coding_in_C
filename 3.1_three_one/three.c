#include "three.h"

void initFixedStack(FixedStack* s){
    for (int i = 0; i < ARR_SIZE; i++) {
        s->values[i] = INT_MIN;
    }
    s->capacity = ARR_SIZE;
    int stackCapacity = s->capacity / 3;

    // stack 1 empty is -1
    s->stackCapacities[0] = -1;

    // stack 2 empty is 33 - 1 = 32
    s->stackCapacities[1] = stackCapacity -1;

    // stack 3 empty is 33 * 2 = 66 - 1 = 65
    s->stackCapacities[2] = (stackCapacity * 2 ) - 1;

}

/* A substack is full when its capacity is at 1/3 of the total array's capacity */
bool isFull(FixedStack* s, int stack_num) {
    int stackCapacity = s->capacity / 3;
    switch(stack_num){
        case 0:
            return s->stackCapacities[0] == (stackCapacity - 1);

        case 1:
            return s->stackCapacities[1] == ((stackCapacity * 2) - 1);
        case 2:
            return (s->stackCapacities[2] == (stackCapacity * 3) - 1);
        default: // invalid stack number
            return true;
    }

}

/* A substack is empty when its capacity is at 0 */
bool isEmpty(FixedStack* s, int stack_num) {
    int stackCapacity = s->capacity / 3;
    switch (stack_num) {
        case 0:
            return s->stackCapacities[0] == -1;
        case 1:
            return s->stackCapacities[1] == stackCapacity -1;
        case 2:
            return s->stackCapacities[2] == (stackCapacity * 2) - 1 ;
    }

}

void push(FixedStack* s, int stackNum, int value) {
    if (isFull(s, stackNum)) {
        fprintf(stderr, "Stack is full.\n");
        return;
    }
    s->stackCapacities[stackNum]++;
    s->values[s->stackCapacities[stackNum]] = value;
}

int pop(FixedStack* s, int stackNum) {
    if (isEmpty(s, stackNum)) {
        fprintf(stderr, "Stack is empty.\n");
        return INT_MIN;
    }
    int retValue = s->values[s->stackCapacities[stackNum]];
    s->values[s->stackCapacities[stackNum]] = INT_MIN;
    s->stackCapacities[stackNum]--;
    return retValue;
}

int peek(FixedStack* s, int stackNum) {
    if (isEmpty(s, stackNum)) {
        fprintf(stderr, "Stack is empty.\n");
        return INT_MIN;
    }
    int retValue = s->values[s->stackCapacities[stackNum]];
    return retValue;


}
