#include <stdio.h>
#include "main.h"

int main(void) {
    const char* greeting = get_greeting();

    if (is_valid_greeting(greeting)) {
        printf("%s\n", greeting);
        return 0;
    } else {
        printf("Error: Invalid greeting\n");
        return 1;
    }
}
