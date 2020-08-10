#include "include/list.h"
#include "include/database.h"

int main( int arg_count, char *args[] ){
    cout << "Hello world!" << endl;
    List simpleList;
    Database data;

    if ( arg_count > 1 ){
        simpleList.name = string(args[1]);
        simpleList.mainList = data.read();
        simpleList.find_userList();
        simpleList.print_menu();
        data.write(simpleList.mainList);
    } else {
        cout << "No username supplied. Exiting..." << endl;
    }

    return 0;
}

