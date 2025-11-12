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


int valid_choice(const char* choice) {
    char tmp[32];
    strcpy(tmp,choice);
    convert_to_lowercase(tmp);
    if (tmp == NULL) return 0;

    if (strcmp(tmp, "Rock") == 0 || strcmp(tmp, "Paper") == 0 || strcmp(tmp, "Scissors") == 0) {
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