// Importing the libraries
#include <stdio.h>
#include <ctype.h>

int main() {
    // input -> The integer number user enters 
    // count-> Initialy equal to 1. Using for word count
    // ch-> To store character from file
    // word-> Buffer to store each word extracted from the file
    // index-> Index for the current position in the `word` buffer
    // wpl -> words per line
    int input, count = 1, ch; 
    char word[1024]; 
    int index = 0; 
    int wpl=0;

    //Getting input from user
    printf("Please enter an integer number: ");
    scanf("%d", &input);
    //input--; // Convert to zero-based index for easier array manipulation


    // Reading .txt file
    char *filename= "text.txt";
    FILE *file = fopen("text.txt", "r");
    // Checking for file existance
    if (!file) {
        printf("Error: %s file doesn't exist",filename);
        return 1;
    }




    while ((ch = fgetc(file)) != EOF) { // Read character by character up to the last line
        if (isspace(ch) || ispunct(ch)) { // Check for separators or punctuation
            if (index > 0) { 
                word[index] = '\0'; // Null terminate the word
                if (count == input) { 
                    printf("%s\n", word);
                }
                count++;
                index = 0; // Reset index for the next word
            }
            if (ch == '.') { // New line, reset word count
                if(count<=input){
                    printf("fewer words that asked.\n");
                }
                count = 0;
            }
        } else { // It's a part of a word
            word[index++] = (char)ch; // Store the character
        }
    }

    // Last word processing if it doesn't end with a space or punctuation
    if (index > 0 && count == input) {
        word[index] = '\0'; // Null terminate the last word
        printf("%s\n", word);
    }

    fclose(file);
    return 0;
}
