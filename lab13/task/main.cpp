#include <iostream>
#include <string.h>
#include "database.h"
#include "file.h"
#include "index.h"
using namespace std;

int main() {
    students *studs = new students[1];
    size_t n = 0;
    import_file("file.txt", studs, n);
    strcpy(currentIndexFileName, "group_index.txt");
    int mrot = 400;
    cout << "Welcome to students database.\n";
    short mode = 0;
    while (mode != 6) {
        cout << "Choose mode:\n";
        cout << "1 - add a record.   2 - list records.                     3 - sort by.\n";
        cout << "4 - delete by.      5 - list records with small income.   6 - exit.\n> ";
        cin >> mode;
        switch (mode) {
            case 1:
                add_record(studs, n, "file.txt");
                break;
            case 2:
                list(studs, n);
                break;
            case 3:
                sort_by(studs, n);
                rewrite_file("file.txt", studs, n);
                break;
            case 4:
                delete_by(studs, n);
                rewrite_file("file.txt", studs, n);
                break;
            case 5:
                list_by_income(studs, n, mrot);
            case 6:
                cout << "Exit\n";
                break;
            default:
                cout << "Unknown.\n";
                break;
        }
    }
    delete[] studs;
    return 0;
}



