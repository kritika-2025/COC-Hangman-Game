#include <stdio.h>
#include <string.h>

int main() {
    // 1. Secret word which is already feeded by us.
    char secret_word[] = "DEBUGGERS";
    int word_length = strlen(secret_word);

    // 2. Another array to store players letter.
    char display_word[word_length + 1]; // +1 for null terminator
    for (int i = 0; i < word_length; i++) {
        display_word[i] = '_';
    }
    display_word[word_length] = '\0';

    int lives = 6; // Number of wrong guesses allowed
    int won = 0;

    // 3. Game fundamental
    while (lives > 0 && !won) {
        printf("\nWord: %s\n", display_word);
        printf("Lives left: %d\n", lives);
        printf("Guess a letter: ");

        char guess;
        scanf(" %c", &guess); // Space before %c to skip whitespace

        int match_found = 0;

        // 4. To check guess against secret word by player.
        for (int i = 0; i < word_length; i++) {
            if (secret_word[i] == guess && display_word[i] == '_') {
                display_word[i] = guess;
                match_found = 1;
            }
        }
        // When the guess is wrong
        if (!match_found) {
            lives--;
            printf("Wrong guess!\n");
        }

        // Check win condition
        if (strcmp(secret_word, display_word) == 0) {
            won = 1;
        }
    }

    // 5. Win or Loss decision is made 
    if (won) {
        printf("%s\n", secret_word);
        printf("Congratulations! You won!\n");
    } else {
        printf("You lost! The word was: %s\n", secret_word);
    }
    return 0;
}