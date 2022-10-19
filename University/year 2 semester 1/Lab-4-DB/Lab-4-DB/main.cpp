// DBM v0.1.0 2022 Kharin Aleksey
//
// cd '/mnt/c/Users/Khivus/CLionProjects/Lab 4 DB/cmake-build-debug' && '/mnt/c/Users/Khivus/CLionProjects/Lab 4 DB/cmake-build-debug/Lab_4_DB'; exitcode=$?; sleep 0.001; (exit $exitcode)
// From default directory:
// cd cmake-build-debug/; ./Lab_4_DB; exitcode=$?; sleep 0.001; (exit $exitcode)

#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for(i = 0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

class DBManager {
public:
    DBManager() { cout << "DBManager constructed.\n"; };
    ~DBManager() { cout << "DBManager destructed.\n"; };

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

    void insert(const string& info, int mode) const {
        char* message_error;
        string insert_info;

        if (mode == 1)
                insert_info = "INSERT INTO buildings (building) VALUES(" + info + ");";
        else if (mode == 2)
                insert_info = "INSERT INTO auditory (building_id, num, square, purpose, university_unit, image) VALUES(" + info + ");";

        int exit = sqlite3_exec(DB, insert_info.c_str(),nullptr, nullptr, &message_error);
        if (exit != SQLITE_OK) {
            cerr << "Sql insert error: " << sqlite3_errmsg(DB) << endl;
            sqlite3_free(message_error);
        }
        else
            cout << "Successfully inserted into database.\n";
    }

    void del(const string& id, int mode) const {
        char* message_error;
        string del_query;

        if (mode == 1)
            del_query = "DELETE FROM buildings WHERE ID = " + id + ";";
        else if (mode == 2)
            del_query = "DELETE FROM auditory WHERE ID = " + id + ";";

        int exit = sqlite3_exec(DB, del_query.c_str(), nullptr, nullptr, &message_error);
        if (exit != SQLITE_OK) {
            cerr << "Sql delete error: " << sqlite3_errmsg(DB) << endl;
            sqlite3_free(message_error);
        }
        else
            cout << "Record deleted Successfully!" << endl;
    }

    void dbout(int table) const {
        string sql;
        char* message_error;
        const char* data = "Callback function called";

        if (table == 1)
            sql = "SELECT * from buildings";
        else if (table == 2)
            sql = "SELECT * from auditory";
        int exit = sqlite3_exec(DB, sql.c_str(), callback, (void*)data, &message_error);

        if( exit != SQLITE_OK ) {
            cerr << "Sql error: " << sqlite3_errmsg(DB) << endl;
            sqlite3_free(message_error);
        } else {
            fprintf(stdout, "Outputted info successfully.\n");
        }
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
            "[6] Exit\n"
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

int main() {
    bool in_menu = true;
    int menu_point;
    string insert_into_sql;
    string info, id;
    int ans;
    menu_output();
    DBManager DB;
    DB.open();

    do {
        menu_point = get_menu_point();
        switch (menu_point) {
            case 1: // insert
                cout << "Input in [1]Buildings or [2]Auditories: ";
                cin >> ans;
                if (ans == 1) {
                    cout << "Input building_num(int): ";
                    cin >> info;
                }
                else if (ans == 2) {
                    string b_id, a_num, sqr, purpose, unit, img;
                    cout << "Input building num(int): ";
                    cin >> b_id;
                    cout << "Input auditory num(int): ";
                    cin >> a_num;
                    cout << "Input auditory square(int or NULL): ";
                    cin >> sqr;
                    cout << "Input auditory purpose(string or NULL): ";
                    cin >> purpose;
                    cout << "Input auditory university unit(string or NULL): ";
                    cin >> unit;
                    cout << "Input auditory image(link or NULL): ";
                    cin >> img;
                    info = b_id + ", " + a_num + ", " + sqr + ", '" + purpose + "', '" + unit + "', '" + img + "'";
                }
                else {
                    cout << "Wrong input!\n";
                    break;
                }
                DB.insert(info, ans);
                break;
            case 2: // change
                cout << "What you want to change? :>\n";
                break;
            case 3: // delete
                cout << "Delete from [1]Buildings or [2]Auditories: ";
                cin >> ans;
                if (ans != 1 && ans != 2)
                    cout << "Wrong input!\n";
                else {
                    cout << "Input id of the record to delete: ";
                    cin >> id;
                    DB.del(id, ans);
                }
                break;
            case 4: // output
                cout << "Output from 'MDB.db' [1]Buildings or [2]Auditories: ";
                cin >> ans;
                if (ans != 1 && ans != 2)
                    cout << "Wrong input!\n";
                else
                    DB.dbout(ans);
                break;
            case 5:
                cout << "DB manager v0.1.0 2022 Kharin Aleksey\n";
                break;
            case 6: // exit
                cout << "Exit the program.\n";
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