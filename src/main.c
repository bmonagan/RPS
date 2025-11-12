#include <stdio.h>
#include <stdlib.h>
enum Choices { Rock, Paper, Scissors };


int valid_choice(const char* choice) {
    if (choice == NULL) return 0;

    if (strcmp(choice, "Rock") == 0 || strcmp(choice, "Paper") == 0 || strcmp(choice, "Scissors") == 0) {
        return 1;
    }
    // Accept numeric choices as strings: "0", "1", "2"
    if (strlen(choice) == 1 && (choice[0] == '0' || choice[0] == '1' || choice[0] == '2')) {
        return 1;
    }

    return 0;
}
int computer_choice() {
    return rand() % 3; // Random choice between 0 (Rock), 1 (Paper), 2 (Scissors)
}
int main(){
    char* user_choice[10];    
    printf("Enter your choice: ");
    // Waits for valid input from user.
    while (1) {
        scanf("%*s", user_choice);
        if (!valid_choice(*user_choice)) {
            printf("Invalid choice. Please enter Rock, Paper, or Scissors: ");
        } else {
            printf("You chose: %s\n", *user_choice);
            break;
        }
    }
    int computers_pick = computer_choice();

    return 0;

}