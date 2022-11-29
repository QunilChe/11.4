#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include "var.h"
#include "form.h"

using namespace std;
using namespace nsForm;
using namespace nsVar;
void nsForm::set_base(Base* p, int size, char* fname) {
    for (int i = 0; i != size; i++)
    {
        ; int x = 20;
        int N;

        cout << "Persons: ";
        cin >> p[i].persons;
        cin.clear();
        cin.sync();
        p[i].name = new char* [p[i].persons];

        for (int i = 0; i != p[i].persons; i++)
        {
            p[i].name[i] = new char[x];
        }

        for (int i = 0; i != p[i].persons; i++)
        {
            cin >> p[i].name[i];
        }

        cout << "Room: ";
        cin >> p[i].room;
        cout << "Number: ";
        cin >> p[i].number;
    }

    ofstream file(fname, ios::binary);
    vector<Base> s;
    for (int i = 0; i < s.size(); ++i)
        file << s[i].number << " " << s[i].room << " " << s[i].persons << " " << s[i].name << "\n";
    file.close();
}