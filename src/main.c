#include <stdio.h>
#include <stdlib.h>
enum Choices { Rock, Paper, Scissors };
int valid_choice(char* choice) {
    return (strcmp(choice, "Rock") == 0 || strcmp(choice, "Paper") == 0 || strcmp(choice, "Scissors") == 0);
}
int main(){
    char* user_choice[10];    
    printf("Enter your choice: ");
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