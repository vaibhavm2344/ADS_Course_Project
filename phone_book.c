#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isdigit

#define ALPHABET_SIZE 26

// Structure to represent a node in the trie
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    char* contact_number;
    char* email;
};

// Function to create a new TrieNode
struct TrieNode* createNode() {
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if (newNode) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->children[i] = NULL;
        }
        newNode->contact_number = NULL;
        newNode->email = NULL;
    }
    return newNode;
}

// Function to check if a string contains only digits and has a length of 10
int isValidMobileNumber(const char* number) {
    int len = strlen(number);
    if (len != 10) {
        return 0; // Not 10 digits
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(number[i])) {
            return 0; // Contains non-digit characters
        }
    }
    return 1; // Valid mobile number
}

// Function to insert a contact into the trie
void insertContact(struct TrieNode* root, const char* name, const char* contact_number, const char* email) {
    if (!isValidMobileNumber(contact_number)) {
        printf("Invalid mobile number. Please enter a 10-digit number.\n");
        return;
    }

    struct TrieNode* current = root;
    int len = strlen(name);

    for (int i = 0; i < len; i++) {
        int index = name[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }

    current->contact_number = strdup(contact_number);
    current->email = strdup(email);
}

// Function to display all contacts starting with a given prefix
void displayContactsStartingWithPrefix(struct TrieNode* node, const char* prefix);

// Function to search for a contact by name prefix
void searchContacts(struct TrieNode* root, const char* prefix) {
    struct TrieNode* current = root;
    int len = strlen(prefix);

    for (int i = 0; i < len; i++) {
        int index = prefix[i] - 'a';
        if (!current->children[index]) {
            printf("No contacts found with the given prefix.\n");
            return;
        }
        current = current->children[index];
    }

    displayContactsStartingWithPrefix(current, prefix);
}

// Recursive function to display contacts starting with a given prefix
void displayContactsStartingWithPrefix(struct TrieNode* node, const char* prefix) {
    if (node == NULL) {
        return;
    }

    if (node->contact_number != NULL) {
        printf("Name: %s, Mobile Number: %s, Email: %s\n", prefix, node->contact_number, node->email);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            char newPrefix[strlen(prefix) + 2];
            sprintf(newPrefix, "%s%c", prefix, 'a' + i);
            displayContactsStartingWithPrefix(node->children[i], newPrefix);
        }
    }
}

// Function to save contacts to a file
void saveContactsDFS(struct TrieNode* node, const char* currentName, FILE* file);

void saveContactsToFile(struct TrieNode* root, const char* filename) {
    FILE* file = fopen(filename, "ab+");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
   
    // Use a depth-first traversal to write contacts to the file
    saveContactsDFS(root, "", file);

    fclose(file);
}

// Recursive function to save contacts to a file
void saveContactsDFS(struct TrieNode* node, const char* currentName, FILE* file) {
    if (node == NULL) {
        return;
    }

    if (node->contact_number != NULL) {
        fprintf(file, "Name: %s, Mobile Number: %s, Email: %s\n", currentName, node->contact_number, node->email);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            char newPrefix[strlen(currentName) + 2];
            sprintf(newPrefix, "%s%c", currentName, 'a' + i);
            saveContactsDFS(node->children[i], newPrefix, file);
        }
    }
}

// Function to free the memory allocated for the trie nodes
void freeTrie(struct TrieNode* node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(node->children[i]);
    }
    free(node->contact_number);
    free(node->email);
    free(node);
}

int main() {
    struct TrieNode* root = createNode();
    int choice;
    char name[100], contact_number[20], email[50];

    while (1)   {
        printf("\nPhone Book Directory\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact by prefix\n");
        printf("3. Save contacts to a file\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Consume the newline character from the previous input
        getchar();

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter contact number: ");
                scanf("%s", contact_number);
                printf("Enter email: ");
                scanf("%s", email);
                insertContact(root, name, contact_number, email);

                getchar();
                fflush(stdin);
                break;
            case 2:
                printf("Enter prefix to search: ");
                scanf("%s", name);
                searchContacts(root, name);
                break;
            case 3:
                printf("Enter file name to save contacts: ");
                scanf("%s", name);
                saveContactsToFile(root, name);
                printf("Contacts saved to file successfully.\n");
                break;
            case 4:
                // Clean up memory before quitting
                freeTrie(root);
                printf("Thank you:) Please visit again!!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
