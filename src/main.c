#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
enum Choices { Rock, Paper, Scissors };
void convert_to_lowercase(char *str) {
    
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}
void clear_input_buffer() {
    int c;
    // Read characters one by one until a newline or EOF is encountered
    while ((c = getchar()) != '\n' && c != EOF) {
        // Discard the character; the loop condition handles the reading
        continue; 
    }
}
const char* choice_to_string(enum Choices choice) {
    switch (choice) {
        case Rock: return "rock";
        case Paper: return "paper";
        case Scissors: return "scissors";
        default: return "Unknown Choice";
    }
}


int valid_choice(const char* choice) {
    if (choice == NULL) return 0;
    // Check for word choices
    if (strcmp(choice, "rock") == 0 || strcmp(choice, "paper") == 0 || strcmp(choice, "scissors") == 0) {
        return 1;
    }
    // Check for numeric choices: "0", "1", "2"
    if (strlen(choice) == 1 && (choice[0] == '0' || choice[0] == '1' || choice[0] == '2')) {
        return 1;
    }
    
    return 0;
}
int computer_choice() {
    return rand() % 3; // Random choice between 0 (Rock), 1 (Paper), 2 (Scissors)
}

int validate_win(const char* user_choice, const char* comp_pick){
    if (strcmp(comp_pick, user_choice) == 0){
        // Return 2 for Tie
        return 2; 

    } else if (
        (strcmp(user_choice, "rock") == 0 && strcmp(comp_pick, "scissors") == 0) || 
        (strcmp(user_choice, "scissors") == 0 && strcmp(comp_pick, "paper") == 0) || 
        (strcmp(user_choice, "paper") == 0 && strcmp(comp_pick, "rock") == 0)
    ) {
        // Return 0 for Win
        return 0; 
    // All other cases are a Loss (Computer wins)
    } else {
        // Return 1 for Loss
        return 1;
    }
}
int main(){
    // Initialize the random number generator
    srand(time(NULL));
    char user_choice[32];
    printf("Valid choices are: Rock, Paper, Scissors. As well as 0,1,2\n");   
    printf("Enter your choice: ");
    // Waits for valid input from user.
    while (1) {
        if (scanf("%31s", user_choice) == 1){
            clear_input_buffer();
            convert_to_lowercase(user_choice);
            
            if (!valid_choice(user_choice)) {
                printf("Invalid choice. Please enter Rock, Paper, or Scissors: ");
        }   else {
                if (strlen(user_choice) == 1) {
                    if (user_choice[0] == '0') {
                        strcpy(user_choice, "rock");
                }   else if (user_choice[0] == '1') {
                        strcpy(user_choice, "paper");
                }   else if (user_choice[0] == '2') {
                        strcpy(user_choice, "scissors");
                }}
                printf("You chose: %s\n", user_choice);
                break;
        }}
        else {
            clear_input_buffer();
            printf("Must enter valid input");
        }}

    // If user entered a numeric choice ("0","1","2"), convert it to the
    // corresponding word so later string comparisons work uniformly.
    
    int computers_index = computer_choice();
    enum Choices comp_pick = (enum Choices) computers_index;
    const char* string_pick = choice_to_string(comp_pick);
    printf("Computer's choice: %s\n", string_pick);
    int outcome = validate_win(user_choice, string_pick);
    if (outcome == 0){
        printf("%s beats %s\n", user_choice, string_pick);
        printf("Congratulations! You Won!");
    } else if (outcome == 1){
        printf("%s beats %s\n", string_pick, user_choice);
        printf("Try again next time. You lost.");

    } else {
        printf("Both players chose %s\n", user_choice);
        printf("The game is a draw");
    }
    

    return 0;
}