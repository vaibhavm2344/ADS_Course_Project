# Phone Book Directory using Trie Data Structure

This C program implements a phone book directory using a Trie data structure to efficiently store and search for contact information. The program allows you to add contacts with names and associated email addresses, search for contacts by prefix, save the contact information to a file, and exit the program. The contacts are stored in a file named "Contacts_db."

## Features

- **Add a Contact**: You can add a new contact to the phone book directory. Each contact can have a name and an associated email address.

- **Search for a Contact by Prefix**: You can search for contacts by providing a prefix of the name. The program will display all matching contacts based on the provided prefix.

- **Save Contacts to a File**: You can save all the contacts to a file named "Contacts_db" for later retrieval.

- **Quit**: Allows you to exit the program.

## Usage

1. Compile the program using a C compiler (e.g., GCC):

   ```bash
   gcc phone_book.c -o phone_book
   ```

2. Run the program:

   ```bash
   ./phone_book
   ```

3. Follow the on-screen menu to perform various operations.

## Menu Options

1. **Add a Contact**: This option allows you to add a new contact to the phone book. You will be prompted to enter the name and email address of the contact.

2. **Search for a Contact by Prefix**: You can search for contacts by providing a prefix of the name. The program will display all matching contacts based on the provided prefix.

3. **Save Contacts to a File**: This option will save all the contacts to a file named "Contacts_db." The file will be created or overwritten with the updated contact information.

4. **Quit**: Allows you to exit the program.

## File Storage

The program uses a Trie data structure to efficiently store and search for contact information. The contacts are stored in memory while the program is running. To persist the contacts, use the "Save Contacts to a File" option, which will write the contact information to the "Contacts_db" file. The file is stored in the same directory as the program.

## Example Usage

```plaintext
Phone Book Directory - Trie Data Structure

1. Add a Contact
2. Search for a Contact by Prefix
3. Save Contacts to a File
4. Quit

Select an option: 1

Enter the name: John Smith
Enter the email address: john.smith@example.com
Contact added successfully!

Select an option: 2

Enter the prefix to search for: Jo
Matching Contacts:
1. Name: John Smith
   Email: john.smith@example.com

Select an option: 3

Contacts saved to "Contacts_db" file.

Select an option: 4

Exiting the program. Goodbye!
```

**Note**: This README provides an overview of the phone book directory program using a Trie data structure. Please refer to the source code (phone_book.c) for the complete implementation.
