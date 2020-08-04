#include "include/list.h"

void List::print_menu(){
    int choice;
    cout << "***************\n";
    cout << "1 - Print list.\n";
    cout << "2 - Add to list.\n";
    cout << "3 - Delete from list.\n";
    cout << "4 - Exit programme.\n";

    cout << "Enter your choice: ";
    cout << "\n\n";
    cin >> choice;

    switch (choice){
        case 1:
            print_list();
            break;
        case 2:
            add_item();
            break;
        case 3:
            delete_item();
            break;
        case 4:
            cout << "Exiting...\n";
            exit(0);
            break;
        default:
            cout << "Nothing to be done. Exiting...\n";
    }
}

void List::add_item(){
    cout << "*** Add Item ***\n";
    cout << "Type in an item and press enter: ";

    string item;
    cin >> item;

    list.push_back(item);
    cout << "Successfully added an item to the list.\n\n\n";
    cin.clear();
    cout << "Returning to menu...\n";
    print_menu();
}

void List::delete_item() {
    if( !list.size() ){
        cout << "No item to delete. Returning to menu...\n";
        print_menu();
    } else {
        cout << "*** Delete Item ***\n";
        cout << "Select an item index number to delete: ";
        for(uint i=0; i < list.size(); i++){
            cout << i << ": " << list[i] << "\n";
        }
        uint itbd;
        cin >> itbd;
        list.erase( list.begin()+itbd );
        cout << "The new list looks like:\n";
        print_list();
    }
    print_menu();
}

void List::print_list(){
    cout << "*** Printing list ***\n";
    for (uint li = 0; li < list.size(); li++){
        cout << li << "*" << list[li] << "\n";
    }
    cout << "\n";
    print_menu();
}