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


int main(void) {
    char string1[] = "ottoman";
    char string2[] = "toto";
    bool result = permutation(string1, string2);
    printf("%s\n", result ? "true" : "false");
    //printf("%lu", sizeof(int));
    return 0;
}