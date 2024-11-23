#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_INPUT_LENGTH 200

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if a keyword exists in the user's input
int contains_word(const char *input, const char *keyword) {
    return strstr(input, keyword) != NULL;
}

int main() {
    srand(time(0));

    // Predefined chatbot responses
    const char *inputs[][6] = {
        {"hi", "hello", "hey", "hi there", "hello there"},
        {"who made you","who", "who created you", "who is your creator", "who are you"},
        {"bye", "goodbye", "exit"},
        {"college","charusat","cspit"},
        {"?"}
    };
    const char *outputs[][6] = {
        {"Hello! How can I help you today?", "Hi there! Need any assistance?", "Greetings! How can I assist you?", "Hello! What can I do for you?"},
        {"I am a simple chatbot and my genius creators are Ansh, Deep, and Hitarth.", "I was created by Ansh, Deep, and Hitarth.", "My genius developers are Ansh, Deep, and Hitarth."},
        {"Goodbye! Have a nice day!", "Take care! See you soon!", "Bye! Looking forward to chatting again!"},
        {"looks like you are talking about charusat. my creators are currently doing b.tech in cspit college if my response didn't match then sorry,I'm trying","oh seems like you are referring to cspit of charusat.by the way let me tell you my creators study there","hmm,charusat is a great university ,afterall my creators are studying there"},
        {"looks like you are trying to ask something"}
    };
    int input_counts[] = {5, 5, 3, 3,1}; // Number of keywords in each category
    int output_counts[] = {4, 3, 3, 3,1}; // Number of responses in each category

    char user_input[MAX_INPUT_LENGTH];
    printf("chatbot: Ask me something.\n");

    while (1) {
        printf("user: ");
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = 0; // Remove newline

        // Convert input to lowercase
        to_lowercase(user_input);

        int found = 0;
        for (int i = 0; i < 5; i++) { // Iterate over all categories
            for (int j = 0; j < input_counts[i]; j++) {
                if (contains_word(user_input, inputs[i][j])) { // Check if input contains any keyword
                    int random_index = rand() % output_counts[i];
                    printf("chatbot: %s\n", outputs[i][random_index]);
                    found = 1;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) {
            printf("chatbot: I am unable to help with that...\n");
        }

        if (contains_word(user_input, "bye")) { // Exit condition
            printf("chatbot: Okay, bye!\n");
            break;
        }
    }

    return 0;
}
