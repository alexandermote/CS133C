#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool *validate_word(char *word)
{
    int length = strlen(word);
    char fixed_word[length];
    for (int i = 0; i < length; i++)
    {
        bool low_bad = word[i] < 'A';
        bool mid_bad = (word[i] > 'Z' && word[i] < 'a');
        bool high_bad = word[i] > 'z';
        if (low_bad || mid_bad || high_bad)
        {
            printf("You entered an invalid word. Please only use letters.\n");
            return true;
        }
    }
    //do stuff fix word
    return false;
}

char get_word(char *secret, int max_length)
{
    printf("Please enter the word you want to play with (100 characters or less): ");
    fgets(secret, max_length, stdin);
    secret[strlen(secret) - 1] = '\0';
    return *secret;
}
int main()
{
    char play_again = 'y';
    while (play_again == 'y') // runs until the user decides to stop playing
    {
        int max_length = 100;
        char secret_word[max_length];

        bool bad_word = true;

        while (bad_word)
        {
            *secret_word = get_word(secret_word, max_length);
            bad_word = validate_word(secret_word);
        }

        int guesses = 5; // number of wrong guesses before game ends

        int secret_length = strlen(secret_word);
        char guessed_word[secret_length];
        for (int i = 0; i < secret_length; i++)
        {
            guessed_word[i] = '_'; // sets guessed word to all blanks
        }

        guessed_word[secret_length] = '\0';

        printf("%s, %s\n", secret_word, guessed_word);
        int bingo = 0;
        char guess = '?';

        while (guesses > 0 && strcmp(secret_word, guessed_word) != 0)
        {
            bingo = 0;

            for (int i = 0; i < strlen(guessed_word); i++)
            {
                printf("%c ", guessed_word[i]);
            }

            printf("\nYou have %d guesses remaining.\nEnter a letter: ", guesses);
            scanf("%c", &guess);
            while (getchar() != '\n')
                ;

            for (int i = 0; i < strlen(guessed_word); i++)
            {
                if (guess == guessed_word[i])
                {
                    printf("You already guessed this letter.\n");
                    bingo = 1;
                    break;
                }
                if (guess == secret_word[i])
                {
                    guessed_word[i] = secret_word[i];
                    bingo = 1;
                }
            }

            if (bingo == 0)
            {
                printf("Incorrect guess!\n");
                guesses--;
            }
        }
        if (guesses == 0)
        {
            printf("You are out of guesses! The correct word was %s. You guessed %s.", secret_word, guessed_word);
        }
        else
        {
            printf("You win! You had %d guesses remaining.", guesses);
        }

        printf("\nPlay again? (y/n): ");
        scanf("%c", &play_again);
        while (getchar() != '\n')
            ;
    }
}