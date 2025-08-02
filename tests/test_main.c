#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../src/main.h"

// Simple test framework macros
#define TEST_ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            printf("FAIL: %s\n", message); \
            return 1; \
        } else { \
            printf("PASS: %s\n", message); \
        } \
    } while(0)

// Test function for get_greeting()
int test_get_greeting(void) {
    printf("\n--- Testing get_greeting() ---\n");

    const char* greeting = get_greeting();

    TEST_ASSERT(greeting != NULL, "get_greeting() should not return NULL");
    TEST_ASSERT(strcmp(greeting, "Hello World") == 0, "get_greeting() should return 'Hello World'");

    return 0;
}

// Test function for is_valid_greeting()
int test_is_valid_greeting(void) {
    printf("\n--- Testing is_valid_greeting() ---\n");

    // Test with valid greeting
    TEST_ASSERT(is_valid_greeting("Hello World") == 1,
                "is_valid_greeting() should return 1 for valid greeting");

    // Test with empty string
    TEST_ASSERT(is_valid_greeting("") == 0,
                "is_valid_greeting() should return 0 for empty string");

    // Test with NULL
    TEST_ASSERT(is_valid_greeting(NULL) == 0,
                "is_valid_greeting() should return 0 for NULL");

    // Test with another valid string
    TEST_ASSERT(is_valid_greeting("Test") == 1,
                "is_valid_greeting() should return 1 for any non-empty string");

    return 0;
}

// Main test runner
int main(void) {
    printf("Running unit tests for main.c\n");
    printf("==============================\n");

    int result = 0;

    // Run all tests
    result |= test_get_greeting();
    result |= test_is_valid_greeting();

    printf("\n==============================\n");
    if (result == 0) {
        printf("All tests PASSED!\n");
    } else {
        printf("Some tests FAILED!\n");
    }

    return result;
}
