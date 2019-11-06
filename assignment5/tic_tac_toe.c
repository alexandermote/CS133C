# include <stdio.h>
# include <string.h>

int game_win(char board[])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == board[i+3] && board[i+3] == board[i+6])
        {
            return 1;
        }

        if (board[3*i] == board[3*i+1] && board[3*i+1] == board[3*i+2])
        {
            return 1;
        }
    }

    if (board[0] == board[4] && board[4] == board[8])
    {
        return 1;
    }

    if (board[2] == board[4] && board[4] == board[6])
    {
        return 1;
    }

    int cats_game = 1;
    for (int i = 0; i < strlen(board); i++)
        {
        if (board[i] != 'X' && board[i] != 'O')
            {
                cats_game = 0;
            }
        }
    if (cats_game == 1)
    {
        return 2;
    }
}

int print_board(char board[])
{
    for (int i = 0; i < strlen(board); i++)
    {
        printf("%c", board[i]);
        if ((i+1)%3 != 0)
        {
            printf("|");
        }
        if (i == 8)
        {
            break;
        }
        if ((i+1)%3 == 0)
        {
            printf("\n------\n");
        }
    }
}

int main()
{
    char play_again = 'y';
    while (play_again == 'y')
    {
        char ttt_board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '\0'};
        char player_piece = 'X';
        int play_space = 9;

        while (play_again == 'y') // always true; runs until broken by game end condition
        {
            print_board(ttt_board);

            printf("\nPlayer %c: Choose a position to play in: ", player_piece);
            scanf("%d", &play_space);
            while (getchar() != '\n')
                ;
            ttt_board[play_space] = player_piece;

            if (game_win(ttt_board) == 1)
            {
                printf("\n");
                print_board(ttt_board);
                printf("\nPlayer %c wins!", player_piece);
                break;
            }

            if (game_win(ttt_board) == 2)
            {
                printf("\n");
                print_board(ttt_board);
                printf("\nCat's game! Nobody wins.");
                break;
            }

            // Change players between "turns"
            printf("\n");
            if (player_piece == 'X')
            {
                player_piece = 'O';
            }
            else
            {
                if (player_piece == 'O')
                {
                    player_piece = 'X';
                }
            }
        }
    
        printf("\nPlay again? (y/n): ");
        scanf("%c", &play_again);
        while (getchar() != '\n')
            ;
    }
}