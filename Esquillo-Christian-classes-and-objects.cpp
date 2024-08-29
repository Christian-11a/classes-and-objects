#include <iostream>
#include <iomanip>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book() : title(""), author(""), year(0) {}
    Book(string t, string a, int y) : title(t), author(a), year(y) {}
    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getYear() { return year; }
};

class Library {
private:
    Book books[50];
    int numBooks;

public:
    Library() : numBooks(0) {}

    void addBook(Book book) {
        if (numBooks < 50) {
            books[numBooks] = book;
            numBooks++;
        } else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }
void displayBooks() {
        if (numBooks == 0) {
            cout << "\nNo books in the library.\n" << endl;
            return;
        }

        // Header row with setw to align columns
        cout << left << setw(20) << "Title" 
             << setw(20) << "Author" 
             << setw(6) << "Year" << endl;
        cout << "--------------------------------------------\n";

        // Print each book's details in a row with setw for alignment
        for (int i = 0; i < numBooks; i++) {
            cout << left << setw(20) << books[i].getTitle()
                 << setw(20) << books[i].getAuthor()
                 << setw(6) << books[i].getYear() << endl;
        }
    }

    void searchBookByTitle(string title) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].getTitle() == title) {
                // Book found
                cout << "\nBook found!\n";
                cout << left << setw(20) << "Title" 
                     << setw(20) << "Author" 
                     << setw(6) << "Year" << endl;
                cout << "--------------------------------------------\n";
                cout << left << setw(20) << books[i].getTitle()
                     << setw(20) << books[i].getAuthor()
                     << setw(6) << books[i].getYear() << endl;
                cout << "--------------------------------------------\n" << endl;
                return;
            }
        }
        cout << "\nBook not found.\n" << endl;
    }
};
int main() {
    Library library;
    int choice;

    while (true) {
        system("cls");  // Clears the console
        cout << "=======================" << endl;
        cout << "  Library Management   " << endl;
        cout << "=======================" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book by Title" << endl;
        cout << "4. Exit" << endl;
        cout << "=======================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");  // Clears the console after each choice

        switch (choice) {
            case 1: {
                string title, author;
                int year;
                cout << "\nEnter book title: ";
                cin.ignore();  // Clear the newline character from the input buffer
                getline(cin, title);
                cout << "Enter author's name: ";
                getline(cin, author);
                cout << "Enter publication year: ";
                cin >> year;
                Book book(title, author, year);
                library.addBook(book);
                cout << "\nBook added successfully!\n" << endl;
                break;
            }
            case 2: {
                library.displayBooks();
                break;
            }
            case 3: {
                string title;
                cout << "\nEnter book title to search: ";
                cin.ignore();  // Clear the newline character from the input buffer
                getline(cin, title);
                library.searchBookByTitle(title);
                break;
            }
            case 4: {
                cout << "\nExiting the program...\n" << endl;
                return 0;
            }
            default: {
                cout << "\nInvalid choice. Please try again!\n" << endl;
            }
        }

        cout << "Press Enter to continue..." << endl;
        cin.ignore();  // Wait for user to press Enter
        cin.get();
    }

    return 0;
}