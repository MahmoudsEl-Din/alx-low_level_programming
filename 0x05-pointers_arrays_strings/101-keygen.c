#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char* valid_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    const int password_length = 10;
    char password[password_length + 1];
    int i;

    srand(time(NULL));

    for (i = 0; i < password_length; i++) {
        int index = rand() % strlen(valid_chars);
        password[i] = valid_chars[index];
    }

    password[password_length] = '\0';

    printf("%s\n", password);

    return 0;
}
