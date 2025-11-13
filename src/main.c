#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
    char tmp[32];
    strncpy(tmp,choice,sizeof(tmp));
    tmp[sizeof(tmp) - 1] = '\0';
    convert_to_lowercase(tmp);
    

    if (strcmp(tmp, "rock") == 0 || strcmp(tmp, "paper") == 0 || strcmp(tmp, "scissors") == 0) {
        return 1;
    }
    // Accept numeric choices as strings: "0", "1", "2"
    if (strlen(tmp) == 1 && (tmp[0] == '0' || tmp[0] == '1' || tmp[0] == '2')) {
        return 1;
    }

    return 0;
}
int computer_choice() {
    return rand() % 3; // Random choice between 0 (Rock), 1 (Paper), 2 (Scissors)
}
int validate_win(char* user_choice, char* comp_pick){
    if (comp_pick == user_choice){
        return 2;
    } else if ((user_choice == "rock" && comp_pick == "scissors") || (user_choice == "scissors" && comp_pick == "paper") || (user_choice == "paper" && comp_pick == "rock")){
        return 0;
    } else {
        return 1;
    }
}
int main(){
    char user_choice[32];    
    printf("Enter your choice: ");
    // Waits for valid input from user.
    while (1) {
        if (scanf("%31s", user_choice) == 1){
            clear_input_buffer();
            if (!valid_choice(user_choice)) {
                printf("Invalid choice. Please enter Rock, Paper, or Scissors: ");
        }   else {
                printf("You chose: %s\n", user_choice);
                break;
        }}
        else {
            clear_input_buffer();
            printf("Must enter valid input");
        }}
    int computers_index = computer_choice();
    enum Choices comp_pick = (enum Choices) computers_index;
    const char* string_pick = choice_to_string(comp_pick);
    printf("Computer's choice: %s\n", string_pick);

    if (validate_win == 0){
        printf("%s beats %s\n", user_choice, string_pick);
        printf("Congratulations! You Won!");
    } else if (validate_win == 1){
        printf("%s beats %s\n", string_pick, user_choice);
        printf("Try again next time. You lost.");

    } else {
        printf("Both players chose %s\n", user_choice);
        printf("The game is a draw");
    }
    

    return 0;
}