#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts;
    int play_again = 1;
    int max_range = 100;

    srand(time(NULL));  // Seed random number generator once

    printf("=== GuessGame 1.0 - Built from source on Ubuntu 24.04! ===\n");
    printf("A tiny terminal game created just for this lecture 🎮\n\n");

    while (play_again) {
        number = rand() % max_range + 1;
        guess = 0;
        attempts = 0;

        printf("I picked a secret number between 1 and %d.\n", max_range);
        printf("Can you guess it?\n\n");

        while (guess != number) {
            printf("Enter your guess: ");
            if (scanf("%d", &guess) != 1) {
                printf("Invalid input! Please enter a number.\n");
                while (getchar() != '\n'); // clear input buffer
                continue;
            }

            attempts++;

            if (guess < number) {
                printf("Too low! Try higher.\n");
            } else if (guess > number) {
                printf("Too high! Try lower.\n");
            } else {
                printf("🎉 Correct! You guessed it in %d attempts!\n\n", attempts);
            }
        }

        printf("Play again? (1 = Yes, 0 = No): ");
        if (scanf("%d", &play_again) != 1) {
            play_again = 0;
        }
    }

    printf("Thanks for playing GuessGame! Goodbye 👋\n");
    return 0;
}
