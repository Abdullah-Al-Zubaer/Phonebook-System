#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

class PhoneBook {
private:
    vector<Contact> contacts;

public:
    void addContact() {
        Contact c;
        cout << "Enter Name: ";
        getline(cin >> ws, c.name);
        cout << "Enter Phone Number: ";
        getline(cin, c.phone);
        cout << "Enter Email: ";
        getline(cin, c.email);
        contacts.push_back(c);
        cout << "Contact added successfully!\n";
    }

    void displayContacts() {
        if (contacts.empty()) {
            cout << "Phonebook is empty.\n";
            return;
        }

        cout << "\n--- Contact List ---\n";
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << "Contact " << i + 1 << ":\n";
            cout << "Name: " << contacts[i].name << "\n";
            cout << "Phone: " << contacts[i].phone << "\n";
            cout << "Email: " << contacts[i].email << "\n\n";
        }
    }

    void searchContact() {
        string searchName;
        cout << "Enter name to search: ";
        getline(cin >> ws, searchName);
        bool found = false;

        for (const auto& c : contacts) {
            if (c.name == searchName) {
                cout << "Name: " << c.name << "\n";
                cout << "Phone: " << c.phone << "\n";
                cout << "Email: " << c.email << "\n";
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Contact not found.\n";
    }

    void deleteContact() {
        string nameToDelete;
        cout << "Enter name to delete: ";
        getline(cin >> ws, nameToDelete);

        auto it = remove_if(contacts.begin(), contacts.end(), [&](Contact& c) {
            return c.name == nameToDelete;
        });

        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            cout << "Contact deleted successfully.\n";
        } else {
            cout << "Contact not found.\n";
        }
    }
};

int main() {
    PhoneBook pb;
    int choice;

    while (true) {
        cout << "\n--- PhoneBook Menu ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: pb.addContact(); break;
            case 2: pb.displayContacts(); break;
            case 3: pb.searchContact(); break;
            case 4: pb.deleteContact(); break;
            case 5: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
