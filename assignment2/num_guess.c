#include <stdio.h>
#include <stdlib.h>

int main()
{
    char play_again = 'y';
    while (play_again == 'y')
    {
        int secret_num = 0;
        int min_num = 1;
        int max_num = 50;
        printf("\nEnter a secret number between %d and %d: ", min_num, max_num);
        scanf("%d", &secret_num);

        int guess = 51;
        int tries = 5;
        int closest = 51;

        while (secret_num != guess)
        {
            if (tries > 1)
            {
                printf("\nYou have %d tries remaining.\n", tries);
            }
            else
            {
                printf("\nYou have %d try remaining.\n", tries);
            }

            printf("Guess the secret number between %d and %d: ", min_num, max_num);
            scanf("%d", &guess);

            if (guess > secret_num)
            {
                tries--;
                printf("%d is too high.\n", guess);
                max_num = guess;
            }

            if (guess < secret_num)
            {
                tries--;
                printf("%d is too low.\n", guess);
                min_num = guess;
            }

            if (abs(guess - secret_num) < abs(closest - secret_num))
            {
                closest = guess;
            }
            if (tries == 0)
            {
                break;
            }
        }

        if (guess == secret_num)
        {
            printf("Congratulations! You've guessed the secret number!\n");
        }
        else
        {
            printf("You did not guess the secret number! It was %d.\nYour closest guess was %d.\n", secret_num, closest);
        }

        printf("Play again? y/n: ");
        scanf("%str", &play_again);
    }
}