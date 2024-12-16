#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500000


int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}


int remove_duplicates(int *array, int size) {
    if (size == 0) return 0;

    int uniqueCount = 1;
    for (int i = 1; i < size; i++) {
        if (array[i] != array[i - 1]) {
            array[uniqueCount++] = array[i];
        }
    }
    return uniqueCount;
}

int main() {
    for (int i = 0; i < 100; i++) {
        FILE *inputFile, *outputFile;
        int numbers[MAX_SIZE];
        int count = 0;


        inputFile = fopen("../src/numbers.txt", "r");
        if (inputFile == NULL) {
            printf("Error opening the file numbers.txt\n");
            return 1;
        }


        while (fscanf(inputFile, "%d", &numbers[count]) == 1) {
            count++;
            if (count > MAX_SIZE) {
                printf("There are too many numbers in the file\n");
                break;
            }
        }
        fclose(inputFile);

        qsort(numbers, count, sizeof(int), compare);

        int uniqueCount = remove_duplicates(numbers, count);

        outputFile = fopen("../src/output_dud.txt", "w");
        if (outputFile == NULL) {
            printf("Error opening the file output.txt\n");
            return 1;
        }

        for (int i = 0; i < uniqueCount; i++) {
            fprintf(outputFile, "%d\n", numbers[i]);
        }

        fclose(outputFile);
    }
    printf("Sort is finished and written in output_dud.txt\n");

    for (int i = 0; i < 100; i++) {
        FILE *inputFile, *outputFile;
        int numbers[MAX_SIZE];
        int count = 0;


        inputFile = fopen("../src/numbers.txt", "r");
        if (inputFile == NULL) {
            printf("Error opening the file numbers.txt\n");
            return 1;
        }


        while (fscanf(inputFile, "%d", &numbers[count]) == 1) {
            count++;
            if (count > MAX_SIZE) {
                printf("There are too many numbers in the file\n");
                break;
            }
        }
        fclose(inputFile);

        qsort(numbers, count, sizeof(int), compare);

        int uniqueCount = remove_duplicates(numbers, count);

        outputFile = fopen("../src/output_dud.txt", "w");
        if (outputFile == NULL) {
            printf("Error opening the file output.txt\n");
            return 1;
        }

        for (int i = 0; i < uniqueCount; i++) {
            fprintf(outputFile, "%d\n", numbers[i]);
        }

        fclose(outputFile);
    }
    printf("Sort is finished and written in output_dud.txt\n");

    return 0;
}
