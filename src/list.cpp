#include "include/list.h"

void List::print_menu(){
    int choice;
    cout << "***************\n";
    cout << "1 - Print list.\n";
    cout << "2 - Add to list.\n";
    cout << "3 - Delete from list.\n";
    cout << "4 - Save list.\n";
    cout << "5 - Exit programme.\n";

    cout << "Enter your choice: "; 
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
            save_list();
            break;
        case 5:
            return;
            break;
        default:
            cout << "Nothing to be done. Exiting...\n";
            break;
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
        cout << "*** Printing list ***\n";
        for (uint li = 0; li < list.size(); li++){
            cout << li << "*" << list[li] << "\n";
        }
        cout << "\n";
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

bool List::find_userList() {
    bool userFound = false;
    cout << "\n\n\n\n\n";
    cout << "*** Welcome " << name << " ***\n";

    for ( uint ui = 0; ui < mainList.size(); ui++ ){
        cout << mainList[ui][0] << '\n';
        if ( mainList[ui][0] == name ) {
            cout << "User has been found: " << mainList[ui][0] << '\n';
            list = mainList[ui];
            currentUserIndex = ui;
            userFound = true;
            break;
        }
    }

    if ( !userFound ) {
        list.push_back(name);
        mainList.push_back(list);
        currentUserIndex = (int)mainList.size()-1;
    }

    return userFound;
}

void List::save_list() {
    cout << "Saving the list...\n";
    mainList[currentUserIndex] = list;
    print_menu();
}