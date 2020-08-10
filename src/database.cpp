#include "include/database.h"

void Database::write( vector<vector<string>> mainList ) {
    ofstream db;
    db.open("db/lists.sl");

    if( db.is_open() ) {
        for ( uint ui = 0; ui < mainList.size(); ui++ ) {
            for ( uint li = 0; li < mainList[ui].size(); li++ ) {
                if ( !li ) {
                    db << "#" << mainList[ui][li] << '\n';   
                } else {
                    db << mainList[ui][li] << '\n';
                }
            }
            db << '%' << '\n';
        }
    } else {
        cout << "Cannot open file for writing.\n";
    }

    db.close();
}

vector<vector<string>> Database::read() {
    ifstream db;
    string line;

    vector<string> userList;

    db.open("db/lists.sl");

    if( db.is_open() ){
        while( getline(db, line, '\n' ) ){
            if( line.front() == '#' ){
                cout << "Found hastag: " << line << '\n';
                line.erase( line.begin() );
                userList.push_back(line);
            } else if( line.front() == '%' ) {
                cout << "Found percentage: " << line << '\n';
                mainList.push_back(userList);
                userList.clear(); 
            } else {
                cout << "Found item: " << line << '\n';
                userList.push_back(line);
            }
        }
    } else {
        cout << "Cannot open file for reading.\n";
    }

    db.close();
    return mainList;
}