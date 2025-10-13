#include "one_way.h"

int hello(void) {
    return 4;
}

bool one_way(char* str1, char* str2) {
    assert(str1);
    assert(str2);
    int tracker = 0;
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char arr[26] = {0};
    while (*str1) {
        arr[*str1 - 'a']+=1;
        str1++;
    }

    while (*str2) {
        arr[*str2 - 'a']+=1;
        str2++;
    }

    for (int i = 0; i < 26; i++) {
        if (arr[i] == 1) {
            tracker++;
        }
    }

    if (tracker <= 1) {
        return true;
    }else if(tracker == 2){
        if (len1 == len2) {
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }

}