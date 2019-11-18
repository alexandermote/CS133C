# Design

    // define the player's ships using a Struct
    // while the users want to keep playing:
        // ask a user how big they want the board to be
        // build a board using the given sizes
        // allow both players to place their ships onto the board:
            // take initial and final positions as input for each ship
            // check to make sure these positions make sense (probably its own function)
        // each turn:
            // require input to begin the turn (keeps information secret)
            // print the current player's board
            // take a space on the board as input
            // check if that space is a hit:
                // if they've already tried this space, tell them and let them go again
                // if the space is a hit, tell them and let them go again
                    // if the player has destroyed a ship, let them know
                    // if the player has destroyed all ships, break the turn loop
                // if the space is a miss, tell them
            // pass turn to the other player
        // print the winner!
        // save the final board states to a file that the players can view
        // ask the winner if they want to play again
            