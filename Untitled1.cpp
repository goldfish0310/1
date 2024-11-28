#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to find the longest word in the input string
void find_longest_word(char *input_string) {
    char longest_word[MAX_LENGTH] = {0};
    char current_word[MAX_LENGTH] = {0};
    int longest_length = 0, current_length = 0;
    int i = 0, j = 0;

    while (input_string[i] != '\0') {
        if (isalpha(input_string[i])) {
            current_word[current_length++] = input_string[i];
        } else {
            if (current_length > longest_length) {
                longest_length = current_length;
                strcpy(longest_word, current_word);
            }
            current_length = 0;
            memset(current_word, 0, sizeof(current_word));
        }
        i++;
    }

    // Check again after the loop ends to ensure we capture the longest word
    if (current_length > longest_length) {
        strcpy(longest_word, current_word);
    }

    printf("Longest word: %s\n", longest_word);
}

// Function to count the number of words in the string
int count_words(char *input_string) {
    int count = 0;
    int in_word = 0;
    for (int i = 0; input_string[i] != '\0'; i++) {
        if (isalpha(input_string[i])) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    return count;
}

// Function to count the number of characters in the string (including spaces)
int count_characters(char *input_string) {
    return strlen(input_string);
}

int main() {
    char input_string[MAX_LENGTH];

    // Input string from the user
    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0';  // Remove newline character

    // Find the longest word
    find_longest_word(input_string);

    // Count the number of words in the string
    int num_words = count_words(input_string);
    printf("Number of words in the string: %d\n", num_words);

    // Count the number of characters in the string (including spaces)
    int num_characters = count_characters(input_string);
    printf("Number of characters in the string (including spaces): %d\n", num_characters);

    return 0;
}

