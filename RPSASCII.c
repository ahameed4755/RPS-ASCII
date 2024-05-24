#include <stdio.h>
#include <stdlib.h>

void printChoice(int choice) {
    switch (choice) {
        case 1:  // Rock
            printf("    _______\n");
            printf("---'   ____)\n");
            printf("      (_____)\n");
            printf("      (_____)\n");
            printf("      (____)\n");
            printf("---.__(___)\n");
            break;
        case 2:  // Paper
            printf("     _______\n");
            printf("---'    ____)____\n");
            printf("           ______)\n");
            printf("          _______)\n");
            printf("         _______)\n");
            printf("---.__________)\n");
            break;
        case 3:  // Scissors
            printf("    _______\n");
            printf("---'   ____)____\n");
            printf("          ______)\n");
            printf("       __________)\n");
            printf("      (____)\n");
            printf("---.__(___)\n");
            break;
        default:
            break;
    }
}

void determineWinner(int player1, int player2, int *score1, int *score2) {
    if (player1 == player2) {
        printf("It's a tie!\n");
    } else if ((player1 == 1 && player2 == 3) || 
               (player1 == 2 && player2 == 1) || 
               (player1 == 3 && player2 == 2)) {
        printf("Player 1 wins this round!\n");
        (*score1)++;
    } else {
        printf("Player 2 wins this round!\n");
        (*score2)++;
    }
}

int main() {
    int player1, player2;
    int score1 = 0, score2 = 0;
    char playAgain;

    do {
        printf("Player 1: Enter your choice (1 = Rock, 2 = Paper, 3 = Scissors): ");
        scanf("%d", &player1);
        printf("Player 1 chose:\n");
        printChoice(player1);

        printf("Player 2: Enter your choice (1 = Rock, 2 = Paper, 3 = Scissors): ");
        scanf("%d", &player2);
        printf("Player 2 chose:\n");
        printChoice(player2);

        determineWinner(player1, player2, &score1, &score2);
        
        printf("Scores: Player 1: %d, Player 2: %d\n", score1, score2);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Final Scores: Player 1: %d, Player 2: %d\n", score1, score2);
    if (score1 > score2) {
        printf("Player 1 wins the game!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins the game!\n");
    } else {
        printf("The game is a tie!\n");
    }

    return 0;
}

