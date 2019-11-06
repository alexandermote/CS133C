# include <stdio.h>
# include <string.h>

int game_win(char board[][3][3])
{
    //row win check
    for (int row = 0; row < 3; row++)
    {
        if (board[row][0][0] == board[row][1][0] && board[row][1][0] == board[row][2][0])
        {
            if (board[row][0][0] != 'X' && board[row][0][0] != 'O')
            {
                continue; // passes by starting values (a, b, or c)
            }
            else
            {
                return 1;
            }
        }
    }

    // column win check
    for (int col = 0; col < 3; col++)
    {
        if (board[0][col][0] == board[1][col][0] && board[1][col][0] == board[2][col][0])
        {
            return 1;
        }
    }

    // diag win checks
    if (board[0][0][0] == board[1][1][0] && board[1][1][0] == board[2][2][0])
    {
        return 1;
    }

    if (board[2][0][0] == board[1][1][0] && board[1][1][0] == board[0][2][0])
    {
        return 1;
    }

    // tie game check
    int cats_game = 1;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col][0] != 'X' && board[row][col][0] != 'O')
            {
                cats_game = 0;
            }
        }
    }
    if (cats_game == 1)
    {
        return 2;
    }
}

void print_board(char board[][3][3])
{

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("%s", board[row][col]);

            if ((col+1)%3 != 0)
            {
                printf("|"); // print lines between each column
            }
        }
        if ((row+1)%3 != 0)
        {
            printf("\n--------\n"); // print lines between each row
        }
    }
}

int main()
{
    char play_again = 'y';
    while (play_again == 'y')
    {
        char ttt_board[4][3][3] = {
            {"a0", "a1", "a2"},
            {"b0", "b1", "b2"},
            {"c0", "c1", "c2"},
            {"\0"}
        };
        char *player_piece = "X ";
        char play_row = 'd';
        int play_col = 4;

        while (play_again == 'y') // Runs until broken by game end condition
        {
            print_board(ttt_board);

            printf("\nPlayer %s: Choose a position to play in: ", player_piece);
            scanf("%c%d", &play_row, &play_col);
            play_row = play_row - 'a'; // convert character into row position (0,1,2)
            while (getchar() != '\n')
                ;
            strcpy(ttt_board[play_row][play_col], player_piece); // change string value to player piece

            if (game_win(ttt_board) == 1)
            {
                printf("\n");
                print_board(ttt_board);
                printf("\nPlayer %swins!", player_piece);
                break;
            }

            if (game_win(ttt_board) == 2)
            {
                printf("\n");
                print_board(ttt_board);
                printf("\nCat's game! Nobody wins.");
                break;
            }

            printf("\n");
            // Change players between "turns"
            if (strcmp(player_piece, "X ") == 0)
            {
                player_piece = "O ";
            }
            else
            {
                if (strcmp(player_piece, "O ") == 0)
                {
                    player_piece = "X ";
                }
            }
        }
    
        printf("\nPlay again? (y/n): ");
        scanf("%c", &play_again);
        while (getchar() != '\n')
            ;
    }
}