// cd '/mnt/c/Users/Khivus/CLionProjects/Lab 4 DB/cmake-build-debug' && '/mnt/c/Users/Khivus/CLionProjects/Lab 4 DB/cmake-build-debug/Lab_4_DB'; exitcode=$?; sleep 0.001; (exit $exitcode)
// From default directory:
// cd cmake-build-debug/; ./Lab_4_DB; exitcode=$?; sleep 0.001; (exit $exitcode)

#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

//static int callback(void* data, int argc, char** argv, char** azColName) {
//    int i;
//    fprintf(stderr, "%s: ", (const char*)data);
//    for (i = 0; i < argc; i++) {
//        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//    }
//    printf("\n");
//    return 0;
//}

class DBManager {
public:
    DBManager() { cout << "Constructing DBManager.\n"; };
    ~DBManager() { cout << "Destructing DBManager.\n"; };

    sqlite3* DB{};

    [[nodiscard]] sqlite3* get() const {
        return DB;
    }

    void open() {
        int exit;
        exit = sqlite3_open("MDB.db", &DB);
        if (exit)
            cerr << "Error open DB " << sqlite3_errmsg(DB) << endl;
        else
            cout << "Opened Database Successfully!" << endl;
    }

};

void menu_output() {
    cout << "=============================================\n"
            "Menu: \n"
            "[1] Insert info\n"
            "[2] Edit info\n"
            "[3] Delete info\n"
            "[4] Output info\n"
            "[5] About program\n"
            "[7] Exit\n"
            "=============================================\n\n";
}

int get_menu_point() {
    int point;
    cout << "> ";
    cin >> point;
    system("clear");
    //system("cls");
    menu_output();
    return point;
}

//void create_table_a(sqlite3* DB) {
//    string sql = "CREATE TABLE auditory ("
//                 " \"building_id\" INTEGER NOT NULL,"
//                 " \"num\" INTEGER NOT NULL,"
//                 " \"square\" INTEGER,"
//                 " \"purpose\" TEXT,"
//                 " \"university_unit\"\tTEXT,"
//                 " \"image\" TEXT,"
//                 " FOREIGN KEY(\"building_id\") REFERENCES \"buildings\"(\"id\")"
//                 ");";
//    int exit;
//    char* messageError;
//    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
//
//    if (exit != SQLITE_OK) {
//        std::cerr << "Error Create Table" << std::endl;
//        sqlite3_free(messageError);
//    }
//    else
//        std::cout << "Table created Successfully" << std::endl;
//}
//
//void create_table_b(sqlite3* DB) {
//    string sql = "CREATE TABLE \"buildings\" ("
//                 " \"id\" INTEGER NOT NULL,"
//                 " \"building\" INTEGER NOT NULL,"
//                 " PRIMARY KEY(\"id\" AUTOINCREMENT)"
//                 ");";
//    int exit;
//    char* messageError;
//    exit = sqlite3_exec(DB, sql.c_str(), nullptr, nullptr, &messageError);
//
//    if (exit != SQLITE_OK) {
//        std::cerr << "Error Create Table" << std::endl;
//        sqlite3_free(messageError);
//    }
//    else
//        std::cout << "Table created Successfully" << std::endl;
//}

int main() {
    bool in_menu = true;
    int menu_point;
    int exit;
    char* message_error;
    string info;
    string insert_into_sql;
    menu_output();
    DBManager DB;
    DB.open();

    do {
        menu_point = get_menu_point();
        switch (menu_point) {
            case 1: // insert
                cout << "Input into buildings...\n"
                        "Input building number: ";
                cin >> info;
                insert_into_sql = "INSERT INTO buildings (building) "
                                  "VALUES(" + info + ");";

                exit = sqlite3_exec(DB.get(), insert_into_sql.c_str(),nullptr, nullptr, &message_error);
                if (exit != SQLITE_OK) {
                    cerr << "Error: " << sqlite3_errmsg(DB.get()) << endl;
                    sqlite3_free(message_error);
                }
                else
                    cout << "Successfully inserted into buildings.\n";
                break;
            case 2: // change
                cout << "What you want to change? :>\n";
                break;
            case 3: // delete
                cout << "Select a record to delete:\n";
                break;
            case 4: // output
                cout << "Output from the 'MainDB_tnp.db':\n";
                break;
            case 7: // exit
                cout << "Exit the program\n";
                in_menu = false;
                break;
            default:
                cout << "Wrong input!\n";
                break;
        }
    } while (in_menu);

    sqlite3_close(DB.get());
    return 0;
}