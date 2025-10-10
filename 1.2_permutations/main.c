#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* compare chars for qsort of a string */
int charcmp(const void* p1, const void* p2) {
    char a = *(const char*) p1;
    char b = *(const char*) p2;
    return a - b;
}


bool permutation(char* word1, char* word2) {
    size_t len1 = strlen(word1);
    size_t len2 = strlen(word2);

    if (len1 != len2) {
        return false;
    }

    // sort both strings
    qsort(word1, len1, sizeof(char), charcmp);
    qsort(word2, len2, sizeof(char), charcmp);

    for (int i = 0; i < len1; i++) {
        if (*word1 != *word2) {
            return false;
        }
        word1++;
        word2++;
    }
    return true;
}

bool permHashChar(char* word1, char* word2) {
    if (strlen(word1) != strlen(word2)) {
        return false;
    }else {
        // note: does not have O(n) to fill with 0's because on stack and optimized local variable
        char arr[26] = {0};
        while (*word1 != '\0') {
            int index = *word1 - 'a';
            arr[index]++;
            word1++;
        }
        while(*word2 != '\0') {
            int index2 = *word2 - 'a';
            arr[index2]--;
            if (arr[index2] < 0) {
                return false;
            }
            word2++;
        }
        return true;
    }
}

int main(void) {
    char string1[] = "otto";
    char string2[] = "toto";

    // first solution, sorting
    bool result = permutation(string1, string2);
    printf("%s\n", result ? "true" : "false");

    // second solution, hashmap of characters
    bool result2 = permHashChar(string1, string2);
    printf("%s\n", result2 ? "true" : "false");


    //printf("%lu", sizeof(int));
    return 0;
}