#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("chcp 65001");

    typedef struct {
        char name[20], surname[20];
        short day_birth;
    } humen;
    FILE *f;
    f = fopen("people.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия файла для чтения");
        return -1;
    }

    humen start_list[4];
    humen end_list[4];

    short n = 0;
    while (!feof(f)) {
        fscanf(f, "%s%s%hd", start_list[n].surname, start_list[n].name, &start_list[n].day_birth);
        printf("%s %s %hd\n", start_list[n].surname, start_list[n].name, start_list[n].day_birth);
        n++;
    }
    for (short i = 0; i < 4; i++) {
        end_list[i] = start_list[i];
        for (short j = 0; j < 4; j++) {
            if (end_list[i].day_birth > start_list[j].day_birth) end_list[i] = start_list[j];
        }
        printf("%s\n", end_list[i].surname);
    }

    return 0;
}
