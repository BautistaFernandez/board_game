#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 30

// Points assigned to each letter of the alphabet.
int POINTS[] = {10, 1, 3, 5, 1, 4, 2, 1, 1, 9, 3, 1, 3, 1, 1, 3, 6, 1, 1, 7, 2, 4, 4, 8, 4, 10};

//               A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z

int compute_score(char word[]);

int main(void)
{
    char word1[MAX_LENGTH];
    char word2[MAX_LENGTH];
    
    // Get input words from both players.
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    // Calculate score from both words.
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner.
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }

    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }

    else
    {
        printf("Tie!\n");
    }
}

int compute_score(char word[])
{
    // Compute and return score for each word.
    int score = 0;

    // Compares chars from word with points based in alphabet order.
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 65];
        }

        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 97];
        }
    }

    return score;
}
