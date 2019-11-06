# Design

This assignment had us create two different games of tic-tac-toe; one with a one-dimensional array, and one with a two-dimensional array. Both projects had similar designs:

    // While the user wants to keep playing:
        // Build the initial board
        // Until someone wins:
            // Ask one of the players (X or O) where they want to play
            // Replace the value in the array with their player piece
            // Check if someone has won or if the game is a tie
                // Print the result and end the game if it's over
            // Switch to the other player and repeat
        // Ask the user(s) if they want to play again

# Testing

While this idea was simple enough in theory, it turned out to be fairly difficult in practice. In both cases, constructing the board turned out to be the most difficult part; in one dimension, separating everything in a way that made sense and looked good was tricky; and in two dimensions, just getting values to print properly wound up being harder than expected. The first problem was solved by using mod functions to keep our values straight while constructing the board; the second was only solved after talking to the instructor and realizing how C handles strings.

The win check functions were also surprisingly tricky. Both functions had to check the rows, columns, and diagonals of our board for equal values, and also had to know if the game was a tie, and therefore no longer "winnable". For the one-dimensional array, a method discussed in class was used for the win checks; for the two-dimensional array, the individual "coordinates" of the board could be called, making things a bit easier to visualize. The only added challenge in the 2D array was making sure the matching row values were either an X or an O, and not the initial values set at the start of the game. The tie checks wound up being similar in both cases, making sure that all squares contained either an X or an O and only returning a value if they did.

# Reflection

The hardest part of this assignment was definitely getting my head around the way C treats strings, including when to use single vs. double quotes, when and how to implement asterisks, and how to include strings in an array. I expect to use these concepts in the future, especially when dealing with some file input that contains a list of strings.