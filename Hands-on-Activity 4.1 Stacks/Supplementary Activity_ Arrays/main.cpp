#include <iostream>
#include <cstring> // For strlen

const size_t maxCap = 100;
char stack[maxCap]; // Stack with max of 100 elements

int top = -1, top1 = -1;
char newData;
char stackCheck[maxCap]; // For checking the balance of the delimiters

void push();
void pop();
void Top();
bool isEmpty();
int showAll(int i);
void checkDelimiter(const char* str);

int main() {
    int choice;
    
    // Predefined string to check for delimiters
    std::cout << "Enter a string with delimiters to check: ";
    std::cin.getline(stackCheck, maxCap);

    while (true) {
        std::cout << "Stack Operations: " << std::endl;
        std::cout << "1. PUSH, 2. POP, 3. TOP, 4. isEMPTY, 5. Show the Stack, 6. Check the Balance of Delimiters, 7. Exit" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                Top();
                break;

            case 4:
                std::cout << (isEmpty() ? "Stack is empty." : "Stack is not empty.") << std::endl;
                break;

            case 5:
                showAll(maxCap);
                break;

            case 6:
                checkDelimiter(stackCheck);
                break;

            case 7:
                std::cout << "Exiting program." << std::endl;
                return 0;

            default:
                std::cout << "Invalid Choice." << std::endl;
                break;
        }
    }
    return 0;
}

bool isEmpty() {
    return top == -1;
}

void push() {
    // Check if full -> if yes, return error
    if (top == maxCap - 1) {
        std::cout << "Stack Overflow." << std::endl;
        return;
    }

    std::cout << "New Value (character): ";
    std::cin >> newData; // Input a character
    stack[++top] = newData; // Push the character onto the stack
}

void pop() {
    // Check if empty -> if yes, return error
    if (isEmpty()) {
        std::cout << "Stack Underflow." << std::endl;
        return;
    }

    // Display the top value
    std::cout << "Popping: " << stack[top] << std::endl;
    // Decrement top value from stack
    top--;
}

void Top() {
    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }

    std::cout << "The element on the top of the stack is " << stack[top] << std::endl;
}

int showAll(int i) {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return 0;
    }
    for (int y = 0; y <= top; y++) {
        std::cout << stack[y] << (y == top ? "" : ", ");
    }
    std::cout << std::endl;
    return 0;
}

void checkDelimiter(const char* str) 
{
    top1 = -1; // Reset top1 for this check
    int length = strlen(str);

    for (int i = 0; i < length; i++) 
    {
        char data = str[i];

        // a) If the character read is not a symbol to be balanced, ignore it.
        if (data != '(' && data != ')' && data != '{' && data != '}' && data != '[' && data != ']') 
        {
            continue; // Skip non-relevant characters
        }

        if (data == '(' || data == '{' || data == '[') 
        {
            // b) If the character is an opening symbol, push it onto the stack.
            stackCheck[++top1] = data;
        } else if (data == ')' || data == '}' || data == ']') 
        {
            // i) Report an error if the stack is empty.
            if (top1 == -1) 
            {
                std::cout << "Mismatched Delimiter! It is Unbalanced." << std::endl;
                return; // No opening delimiter to match with
            }
            char topChar = stackCheck[top1--]; // ii) Otherwise, pop the stack.

            // Check for matching pairs
            if ((data == ')' && topChar != '(') ||
                (data == '}' && topChar != '{') ||
                (data == ']' && topChar != '[')) 
            {
                std::cout << "Mismatched Delimiter! It is Unbalanced." << std::endl;
                return;
            }
        }
    }

    // 3. At the end of input, if the stack is not empty: report an error.
    if (top1 != -1) {
        std::cout << "Mismatched Delimiter! It is Unbalanced." << std::endl;
    } else {
        std::cout << "Delimiters are balanced!" << std::endl;
    }
}
