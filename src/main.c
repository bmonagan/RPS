#include <stdio.h>
#include <stdlib.h>
enum Choices { Rock, Paper, Scissors };
int valid_choice(char* choice) {
    return (strcmp(choice, "Rock") == 0 || strcmp(choice, "Paper") == 0 || strcmp(choice, "Scissors") == 0);
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
    return 0;
}