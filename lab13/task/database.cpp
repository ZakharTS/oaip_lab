#include "database.h"
#include "index.h"

extern char currentIndexFileName[32];

void add_record(students *&studs, size_t &n, const char *filename) {
    cout << "Add a record. Fields:\nSurname. Name. Patronymic. Group. Average mark. Income per family member.\n";
    char group[256];
    students current;
    cin >> current.surname >> current.name >> current.patronymic >> group >> current.avrMark >> current.income;
    if (!strcmp(group, "po-8") || !strcmp(group, "PO-8")) {
        current.grp = students::po8;
    } else if (!strcmp(group, "po-9") || !strcmp(group, "PO-9")) {
        current.grp = students::po9;
    } else if (!strcmp(group, "ii-21") || !strcmp(group, "II-21")) {
        current.grp = students::ii21;
    } else if (!strcmp(group, "ii-22") || !strcmp(group, "II-22")) {
        current.grp = students::ii22;
    } else {
        current.grp = students::unknown;
    }
    add_to_array(studs, n, current);
    FILE *f = fopen(filename, "ab");
    fwrite(&current, sizeof(students), 1, f);
    fclose(f);
    add_to_index(n - 1, current);
}

void add_to_array(students *&studs, size_t &n, students toAdd) {
    students *temp = new students[n + 1];
    for (size_t i = 0; i < n; i++) {
        temp[i] = studs[i];
    }
    delete[] studs;
    studs = temp;
    studs[n] = toAdd;
    n++;
}

void display_record(students cur) {
    cout << cur.surname << " " << cur.name << " " << cur.patronymic;
    switch (cur.grp) {
        case students::po8:
            cout << " PO-8 ";
            break;
        case students::po9:
            cout << " PO-9 ";
            break;
        case students::ii21:
            cout << " II-21 ";
            break;
        case students::ii22:
            cout << " II-22 ";
            break;
        default:
            cout << " Unknown group ";
            break;
    }
    cout << cur.avrMark << " " << cur.income << endl;
}

void list(students *studs, size_t n) {
    cout << "Students list. Fields:\nSurname. Name. Patronymic. Group. Average mark. Income per family member.\n";
    int ind[n], values[n];
    extern char currentIndexFileName[32];
    if (!strcmp(currentIndexFileName, "")) strcpy(currentIndexFileName, "group_index.txt");
    read_index_file(currentIndexFileName, ind, values, n);
    for (size_t i = 0; i < n; i++) {
        cout << i + 1 << ") ";
        display_record(studs[ind[i]]);
    }
}

void sort_by(students *studs, size_t n) {
    cout << "Sort by:\n";
    cout << "1 - group. 2 - income.\n> ";
    short mode;
    cin >> mode;
    switch (mode) {
        case 1:
            strcpy(currentIndexFileName, "group_index.txt");
            break;
        case 2:
            strcpy(currentIndexFileName, "income_index.txt");
            break;
        default:
            cout << "Unknown.\n";
            return;
    }
    int ind[n], values[n];
    read_index_file(currentIndexFileName, ind, values, n);
    for (size_t i = 1; i < n; i++) {
        for (size_t j = i; j > 0 && values[j - 1] > values[j]; j--) {
            swap(values[j], values[j - 1]);
            swap(ind[j], ind[j - 1]);
        }
    }
    rewrite_index_file(currentIndexFileName, ind, values, n);
}

void delete_by_id(students *&studs, size_t &n, size_t id) {
    n--;
    int ind[n], groups[n], incomes[n];
    for (size_t j = id; j < n; j++) {
        studs[j] = studs[j + 1];
    }
    for (size_t i = 0; i < n; i++) {
        ind[i] = i;
        groups[i] = studs[i].grp;
        incomes[i] = studs[i].income;
    }
    rewrite_index_file("group_index.txt", ind, groups, n);
    rewrite_index_file("income_index.txt", ind, incomes, n);
}

void delete_by(students *&studs, size_t &n) {
    cout << "Delete by:\n";
    cout << "1 - surname.   2 - group.   3 - mark.   4 - income.\n> ";
    short mode;
    cin >> mode;
    switch (mode) {
        case 1:
            cout << "Surname: ";
            char toDel[256];
            cin >> toDel;
            for (size_t i = 0; i < n; i++) {
                if (!strcmp(studs[i].surname, toDel)) {
                    delete_by_id(studs, n, i);
                }
            }
            break;
        case 2:
            cout << "Group: ";
            char group[256];
            cin >> group;
            short tempGrp;
            if (!strcmp(group, "po-8") || !strcmp(group, "PO-8")) {
                tempGrp = students::po8;
            } else if (!strcmp(group, "po-9") || !strcmp(group, "PO-9")) {
                tempGrp = students::po9;
            } else if (!strcmp(group, "ii-21") || !strcmp(group, "II-21")) {
                tempGrp = students::ii21;
            } else if (!strcmp(group, "ii-22") || !strcmp(group, "II-22")) {
                tempGrp = students::ii22;
            } else {
                tempGrp = students::unknown;
            }
            for (size_t i = 0; i < n; i++) {
                if (studs[i].grp == tempGrp) {
                    delete_by_id(studs, n, i);
                }
            }
            break;
        case 3:
            cout << "Average mark: ";
            double mark;
            cin >> mark;
            for (size_t i = 0; i < n; i++) {
                if (studs[i].avrMark == mark) {
                    delete_by_id(studs, n, i);
                }
            }
            break;
        case 4:
            cout << "Income: ";
            int income;
            cin >> income;
            for (size_t i = 0; i < n; i++) {
                if (studs[i].income == income) {
                    delete_by_id(studs, n, i);
                }
            }
            break;
        default:
            cout << "Unknown.\n";
            return;
            break;
    }
    students *temp = new students[n];
    for (size_t i = 0; i < n; i++) {
        temp[i] = studs[i];
    }
    delete[] studs;
    studs = temp;
}

void list_by_income(students *studs, size_t n, int mrot) {
    mrot *= 2;
    size_t j = 1;
    int ind[n], values[n];
    read_index_file("income_index.txt", ind, values, n);
    for (size_t i = 0; i < n; i++) {
        if (values[i] < mrot) {
            cout << j << ") ";
            display_record(studs[ind[i]]);
            j++;
        }
    }
}