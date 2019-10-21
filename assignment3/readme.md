# Design

This assignment asked us to create a design for a word-guessing game, akin to Hangman:

// while the user wants to keep playing:
    // create a word for the player to guess
        // take in a string typed by the gamemaster

    // define list of letters that haven't been guessed (currently all letters)
    // define number of wrong guesses player can make

    // create the "blank word" for the player to guess
        // count the letters of the word
        // turn each letter into a blank ("_")
    
    // while the player still has wrong guesses AND the word has not been guessed:
        // show the "blank word" with correct guesses filled in
            // if a letter is in the above list, leave it blank
            // otherwise, show it
        // let the player guess a letter
        // if the letter has already been guessed (not in the above list):
            // tell the player they dun goofed
            // let them guess again for free
        // if the letter has not been guessed:
            // take it off the above list
            // if it's in the word:
                // tell the player they guessed right
                // let them guess again for free
            // if it's not in the word:
                // tell the player they guessed wrong
                // take away one of their wrong guesses
    // if the player ran out of guesses:
        // tell them they lost
        // tell them what the word was
    // if the player guessed the word:
        // congratulate them
        // tell them how many wrong guesses they had left
    // ask the player if they want to play again