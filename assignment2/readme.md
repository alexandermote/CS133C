# Design
This assignment had us create a number-guessing program that could be played by two players. The program was to be designed as follows:

Player 1 enters a secret number between two values
until Player 2 guesses correctly:
    Player 2 enters a guess
    If the guess is too low:
        let them know so
        change the minimum value to the guess
    If the guess is too high:
        let them know so
        change the maximum value to the guess
    If the player is out of guesses:
        end the game
        tell them what the number was
        tell them their closest guess
    If the guess is correct:
        end the game
        tell them they won!
give the player the option to play again

The final line of this pseudocode design means that the entire program must live inside of a while loop that runs until the player enters "no" instead of "yes". The guess-and-check code runs inside of another while loop that runs until the player either guesses correctly or runs out of guesses.

# Testing
Overall, this program was simple enough to write and test. However, there were two major pieces that caused trouble over time. The first was the scanf function, and how to assign the value collected by this function to a variable. This was solved through trial and error, as well as by looking up information about the scanf function online.
The second issue was the "closest guess" portion of the code, which in its original state would always give the most recent guess as the closest guess. This was eventually attributed to the code incorrectly comparing the difference between the guess and the correct answer to the value of the previous closest answer, rather than another difference. This issue was noticed after speaking to the teacher, fixed, and ran correctly.

# Reflection
This project allowed me to learn a lot more about how C programs work, including how it handles variables and reading user input. This was invaluable as a tool for future programming, and I expect to use a great deal of the syntax and semantics that I learned from this assignment on future work in this class and in C projects down the road. Online resources and one-on-one teacher conversation allowed me to fix the issues that were not readily apparent.