#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    map<string, list<pair<string, string>>> Cbooks;
    map<string, list<pair<string, string>>> Cfavorite;

    while (1)
    {
        cout << "\n1-To add, edit and delete any contact";
        cout << "\n2-Adding, deleting and editing double sets of numbers for each contact";
        cout << "\n3-Delete and add contacts to favorites list";
        cout << "\n4-Changing the order of contacts in the list of favorites";
        cout << "\n5-Display all contacts in alphabetical order";
        cout << "\n6-Display all the numbers of a contact";
        cout << "\n7-Display the list of favorites in the saved order";
        cout << "\n8-Search among audience with the help of audience name";
        cout << "\n0-Exit";

        int choice;
        cout << "\n\nEnter the choice:";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\n1-add contact";
            cout << "\n2-edit contact";
            cout << "\n3-delete contact";

            int ch1;
            cout << "\n\nEnter the choice:";
            cin >> ch1;

            if (ch1 == 1)
            {
                string name, number, Type;
                cout << "\nEnter the name:";
                cin >> name;
                cout << "\nEnter the number:";
                cin >> number;
                cout << "\nEnter the Type:";
                cin >> Type;
                Cbooks[name].push_back(make_pair(Type, number));
                cout << "Contact added successfully!" << endl;
            }
            else if (ch1 == 2)
            {
                string name;
                cout << "\nEnter contact name to edit: ";
                cin >> name;
                auto it = Cbooks.find(name);
                if (it != Cbooks.end())
                {
                    string newType, newNumber;
                    cout << "Enter new contact type: ";
                    cin >> newType;
                    cout << "Enter new contact number: ";
                    cin >> newNumber;
                    it->second.clear();
                    it->second.push_back(make_pair(newType, newNumber));
                    cout << "Contact edited successfully!" << endl;
                }
                else
                {
                    cout << "Contact not found!" << endl;
                }
            }
            else if (ch1 == 3)
            {
                string name;
                cout << "\nEnter contact name to edit: ";
                cin >> name;
                auto it = Cbooks.find(name);
                if (it != Cbooks.end())
                {
                    Cbooks.erase(name);
                    cout << "\nContact deleted successfully!" << endl;
                }
                else
                {
                    cout << "\nContact not found!" << endl;
                }
            }
        }
        else if (choice == 2)
        {
            cout << "\n1-add double-set contact";
            cout << "\n2-edit double-set contact";
            cout << "\n3-delete double-set contact";

            int ch2;
            cout << "\n\nEnter the choice:";
            cin >> ch2;
            string name;
            cout << "\nEnter the name of the contact:";
            cin >> name;
            if (Cbooks.find(name) == Cbooks.end())
            {
                cout << "\nThere is no such a contact!" << endl;
            }
            else
            {
                if (ch2 == 1)
                {
                    string Type;
                    cout << "\nEnter the type:";
                    cin >> Type;
                    string number;
                    cout << "\nEnter the number:";
                    cin >> number;
                    Cbooks[name].push_back(make_pair(Type, number));
                }
                else if (ch2 == 2)
                {
                    cout << "\nWhat double-set do you want to change?" << endl;
                    int i = 1;
                    for (auto x : Cbooks[name])
                    {
                        cout << endl
                            << i << "(" << x.first << "," << x.second << ")" << endl;
                        i++;
                    }
                    int ch22;
                    cout << endl
                        << "Enter the choice:";
                    cin >> ch22;
                    string new_type, new_number;
                    cout << "\nEnter the new type:";
                    cin >> new_type;
                    cout << "\nEnter the new number:";
                    cin >> new_number;

                    auto it = Cbooks[name].begin();
                    advance(it, ch22 - 1);
                    *it = make_pair(new_type, new_number);
                    cout << "Double-set contact edited successfully!" << endl;
                }
                else if (ch2 == 3)
                {
                    cout << "\nWhat double-set do you want to delete?" << endl;
                    int i = 1;
                    for (auto x : Cbooks[name])
                    {
                        cout << endl
                            << i << "(" << x.first << "," << x.second << ")" << endl;
                        i++;
                    }
                    int ch23;
                    cout << "\nEnter the choice:";
                    cin >> ch23;
                    auto it = Cbooks[name].begin();
                    advance(it, ch23 - 1);
                    Cbooks[name].erase(it);
                    cout << "Double-set contact deleted successfully!" << endl;
                }
            }
        }
        else if (choice == 3)
        {
            cout << "\n1-add favorite contact";
            cout << "\n2-delete favorite contact";

            int ch3;
            cout << "\n\nEnter the choice:";
            cin >> ch3;

            if (ch3 == 1)
            {
                cout << "\nEnter the name of the contact:";
                string name;
                cin >> name;
                if (Cbooks.find(name) == Cbooks.end())
                {
                    cout << endl
                        << "There is no such a contact!" << endl;
                }
                else
                {
                    Cfavorite[name] = Cbooks[name];
                }
            }
            else if (ch3 == 2)
            {
                cout << "\nEnter the name of the contact you want to delete:";
                string name;
                cin >> name;
                if (Cfavorite.find(name) == Cfavorite.end())
                {
                    cout << endl
                        << "There is no such a contact in the favorite!" << endl;
                }
                else
                {
                    Cfavorite.erase(name);
                }
            }
        }
        else if (choice == 4)
        {

            cout << "\nFavorites contact List:\n";
            int i = 1;
            vector<string> name;
            for (const auto& contact : Cfavorite)
            {
                name.push_back(contact.first);
                cout << i++ << ". " << contact.first << endl;
            }

            cout << "Enter the positions of the contacts to swap (for example: 1 2): ";
            int choice1, choice2;
            cin >> choice1 >> choice2;

            swap(name[choice1 - 1], name[choice2 - 1]);

            map<string, list<pair<string, string>>> newFavorites;
            for (const auto& n : name)
            {
                newFavorites[n] = Cfavorite[n];
            }
            Cfavorite = newFavorites;

            cout << "Contacts swapped successfully!" << endl;
        }

        else if (choice == 5)
        {
            cout << "\nContacts:";
            vector<string> contact_name;
            for (auto x : Cbooks)
            {
                contact_name.push_back(x.first);
            }
            sort(contact_name.begin(), contact_name.end());
            for (auto name : contact_name)
            {
                cout << "\nName:" << name;
                list<pair<string, string>> contact = Cbooks.at(name);
                for (auto x : contact)
                {
                    cout << "     Type:" << x.first << "    Number:" << x.second;
                }
                cout << endl;
            }
        }
        else if (choice == 6)
        {
            cout << "\nEnter the name of the contact: ";
            string name;
            cin >> name;
            if (Cbooks.find(name) == Cbooks.end())
            {
                cout << "\nThere is no contact with this name!" << endl;
            }
            else
            {
                list<pair<string, string>> temp = Cbooks.find(name)->second;
                cout << "\nThe numbers of the " << name << " : ";
                for (auto x : temp)
                {
                    cout << x.second << ",";
                }
                cout << endl;
            }
        }
        else if (choice == 7)
        {
            cout << "\nContacts of favorite:";
            for (auto x : Cfavorite)
            {
                cout << endl
                    << "Name:" << x.first;
                for (auto y : x.second)
                {
                    cout << "  Type:" << y.first << "  Number:" << y.second;
                }
            }
            cout << endl;
        }
        else if (choice == 8)
        {
            cout << "\nEnter the subname of the contact: ";
            string subname;
            cin >> subname;
            bool found = false;
            for (auto x : Cbooks)
            {
                if (x.first.find(subname) != string::npos)
                {
                    found = true;
                    cout << endl
                        << x.first << endl;
                }
            }
            if (!found)
            {
                cout << "There is no contact with such a substring";
            }
        }
        else if (choice == 0)
        {
            exit(0);
        }
    }
}
