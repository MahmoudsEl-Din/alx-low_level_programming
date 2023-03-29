
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 13

int main(void)
{
    char password[PASSWORD_LENGTH + 1]; // Add 1 for null terminator
    int i;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random password
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int r = rand() % 62;
        if (r < 26) {
            password[i] = 'a' + r;
        } else if (r < 52) {
            password[i] = 'A' + r - 26;
        } else {
            password[i] = '0' + r - 52;
        }
    }
    password[PASSWORD_LENGTH] = '\0';

    // Print the password to stdout
    printf("%s", password);

    return 0;
}
