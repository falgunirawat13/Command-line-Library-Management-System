#include <iostream>
#include <vector>
#include <string>

// Define a data structure for a book
struct Book {
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;

    // Constructor
    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), ISBN(i), available(true) {}
};

// Function to display the menu
void displayMenu() {
    std::cout << "Library Management System Menu" << std::endl;
    std::cout << "1. Add a Book" << std::endl;
    std::cout << "2. Remove a Book" << std::endl;
    std::cout << "3. Check Book Availability" << std::endl;
    std::cout << "4. Display Catalog" << std::endl;
    std::cout << "5. Quit" << std::endl;
}

// Function to add a book to the catalog with input validation
void addBook(std::vector<Book>& catalog) {
    std::string title, author, ISBN;
    std::cout << "Enter book title: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Enter ISBN ";
    std::cin >> ISBN;

    std::cout << "Enter author: ";
    std::cin.ignore();
    std::getline(std::cin, author);

    catalog.push_back(Book(title, author, ISBN));
    std::cout << "Book added to the catalog." << std::endl;
}

// Function to remove a book from the catalog
void removeBook(std::vector<Book>& catalog, const std::string& ISBN) {
    for (auto it = catalog.begin(); it != catalog.end(); ++it) {
        if (it->ISBN == ISBN) {
            catalog.erase(it);
            std::cout << "Book removed from the catalog." << std::endl;
            return;
        }
    }
    std::cout << "Book not found in the catalog." << std::endl;
}

// Function to check book availability
void checkAvailability(const std::vector<Book>& catalog, const std::string& ISBN) {
    for (const auto& book : catalog) {
        if (book.ISBN == ISBN) {
            std::cout << "Book Title: " << book.title << std::endl;
            std::cout << "Author: " << book.author << std::endl;
            if (book.available) {
                std::cout << "Availability: Available" << std::endl;
            } else {
                std::cout << "Availability: Not Available" << std::endl;
            }
            return;
        }
    }
    std::cout << "Book not found in the catalog." << std::endl;
}

// Function to display the catalog
void displayCatalog(const std::vector<Book>& catalog) {
    std::cout << "Library Catalog:" << std::endl;
    for (const auto& book : catalog) {
        std::cout << "Title: " << book.title << std::endl;
        std::cout << "Author: " << book.author << std::endl;
        std::cout << "ISBN: " << book.ISBN << std::endl;
        if (book.available) {
            std::cout << "Availability: Available" << std::endl;
        } else {
            std::cout << "Availability: Not Available" << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    }
}

int main() {
    std::vector<Book> catalog;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addBook(catalog);
                break;
            case 2: {
                std::string ISBN;
                std::cout << "Enter ISBN of the book to remove: ";
                std::cin >> ISBN;
                removeBook(catalog, ISBN);
                break;
            }
            case 3: {
                std::string ISBN;
                std::cout << "Enter ISBN of the book to check availability: ";
                std::cin >> ISBN;
                checkAvailability(catalog, ISBN);
                break;
            }
            case 4:
                displayCatalog(catalog);
                break;
            case 5:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

