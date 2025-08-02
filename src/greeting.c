#include <string.h>
#include "main.h"

// Function to get greeting message - this is what we'll test
const char* get_greeting(void) {
    return "Hello World";
}

// Function to check if greeting is valid
int is_valid_greeting(const char* greeting) {
    if (greeting == NULL) {
        return 0;
    }
    return strlen(greeting) > 0;
}
