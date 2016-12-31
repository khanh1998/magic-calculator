#include <stdio.h>

void saveValue(char value[]) {
    FILE *f = fopen("data.mcal", "w");
    if (f != NULL) {
        fprintf(f, "%s", value);
    } else printf("404 File Not Found :(\n");
    fclose (f);
    printf("Saved!\n");
}

void loadValue() {
    FILE *f = fopen("data.mcal", "w");
    if (f != NULL) {
        for (int i = 0; i <= 9; i++) {
            fscanf(f, "%s\n", var[i])
        };
    } else printf("404 File Not Found :(\n");
    fclose (f);
}

void resetValue() {
    FILE *f = fopen("data.mcal", "w");
    if (f != NULL) {
        fprintf(f, "10");
        cash = 10;
    } else printf("404 File Not Found :(");
    fclose (f);
    printf("Done!\n");
}

int main(void) {
    char value[100], ch;
    scanf("Value: %s", value);
    loadValue();
    scanf("Variable: %c", ch);
}
