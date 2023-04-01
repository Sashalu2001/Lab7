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

    for (short i = 0; i < 4; i++) fscanf(f, "%s%s%hd", start_list[i].surname, start_list[i].name, &start_list[i].day_birth);
    fclose(f);

    printf("= = = = = = = = = = = = = = = =\n");
    for (short i = 0; i < 4; i++) {
        end_list[i] = start_list[i];
        for (short j = 0; j < i; j++) {
            if (end_list[j].day_birth < end_list[j+1].day_birth) {
                humen temp = end_list[j];
                end_list[j] = end_list[j+1];
                end_list[j+1] = temp;
            };
        }
    }

    for (short i = 3; i >= 0; i--) printf("%s %s %hd\n", end_list[i].surname, end_list[i].name, end_list[i].day_birth);

    return 0;
}
