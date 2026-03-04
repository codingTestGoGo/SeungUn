#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void* first, const void* second){ //compare 함수에서 인자로 가져오는 first와 second는 qsort의 첫번째 인자, 즉 arr배열 전체를 가리킨다.(2차 포인터 배열기준)
    if (strlen(*(char**)first) < strlen(*(char**)second)) {
        return -1;
    }
    else if (strlen(*(char**)first) > strlen(*(char**)second)) {
        return 1;
    }
    else {
        return strcmp(*(char**)first, *(char**)second);
    }
}



int main(void) {
    int n, i;
    char** arr;
    char input[51];

    scanf("%d", &n);
    arr = (char**)malloc(sizeof(char*) * n);

    for (i = 0; i < n; i++) {
        scanf("%s", input);
        arr[i] = (char*)malloc(sizeof(char) * 51);
        strcpy(arr[i], input);
    }
    qsort(arr, n, sizeof(*arr), compare); //const void* A는 char**, list와 동일한 타입을 갖고 있고,
                                         //여기서 참조를 한번 하면* (char**) = char* 로 비교할 문자열의 첫 char을 가르키는 포인터를 가르키게 됩니다.
    printf("%s\n", arr[0]);
    for (i = 1; i < n; i++) {
        if (strcmp(arr[i], arr[i - 1]) == 0) {
            continue;
        }
        else {
            printf("%s\n", arr[i]);
        }
    }
    for (i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}