#include "include/list.h"

int main( int arg_count, char *args[] ){
    cout << "Hello world!" << endl;
    if ( arg_count > 1 ){
        List simpleList;
        simpleList.name = string(args[1]);
        simpleList.print_menu();
    } else {
        cout << "No username supplied. Exiting..." << endl;
    }
    return 0;
}

