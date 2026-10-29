
#include <stdio.h>

const char *higher(void) {
    return "higher";
}

const char *lower(void) {
    return "lower";
}

int main(void) {
    FILE *fptr;
    int secret;
    int guess;

    fptr = fopen("GUESS.txt", "r");

    if (fptr == NULL) {
        printf("Could not open words.txt\n");
        return 1;
    }

    if (fscanf(fptr, "%d", &secret) != 1) {
        printf("Could not read the secret number.\n");
        fclose(fptr);
        return 1;
    }

    fclose(fptr);

    printf("Guess a number: ");

    if (scanf("%d", &guess) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    while (guess != secret) {
        if (guess > secret) {
            printf("%s\n", lower());
        } else {
            printf("%s\n", higher());
        }

        printf("Try again: ");

        if (scanf("%d", &guess) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    printf("You got it!\n");
    return 0;
}
