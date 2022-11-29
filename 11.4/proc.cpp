#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include "var.h"
#include "proc.h"
using namespace std;
using namespace nsProc;
using namespace nsVar;
bool nsProc::remove_line(const char* fname, size_t index)
{
    std::vector<std::string> vec;
    std::ifstream file(fname);
    if (file.is_open())
    {
        std::string str;
        while (std::getline(file, str))
            vec.push_back(str);
        file.close();
        if (vec.size() < index)
            return false;
        vec.erase(vec.begin() + index);
        std::ofstream outfile(fname);
        if (outfile.is_open())
        {
            std::copy(vec.begin(), vec.end(),
                std::ostream_iterator<std::string>(outfile, "\n"));
            outfile.close();
            return true;
        }
        return false;
    }
    return false;
}

void nsProc::delete_base(Base* p, int size)
{
    for (int i = 0; i != size; i++)
    {
        {
            cout << "Deleting base...\n";
            for (int i = 0; i != this->persons; i++)
            {
                delete[] name[i];
            }
            delete[] name;

            cout << "Delete status: Ok\n";
        }
    }
}

void nsProc::search_room(Base* p, int size, char* fname)
{
    for (int i = 0; i != size; i++)
    {
        int r;
        cout << "Room: ";
        cin >> r;
        if (p[i].room == r);
        fstream f(fname, ios::binary);
        f.read((char*)&baza, sizeof(Base));
        cout << baza.number << endl;
        cout << baza.name << endl;
    }
}

void nsProc::search_name(Base* p, int size, char* fname)
{
    for (int i = 0; i != size; i++)
    {
        char n[20];
        cin >> n;
        for (int i = 0; i != p[i].persons; i++)
        {
            if (!strcmp(p[i].name[i], n));
            fstream f(fname, ios::binary);
            f.read((char*)&baza, sizeof(Base));
            cout << baza.number << endl;
        }
    }

}

void nsProc::search_number(Base* p, int size, char* fname)
{
    for (int i = 0; i != size; i++)
    {
        int n;
        cout << "Tel: ";
        cin >> n;
        if (number == n)
        {
            cout << "Room: " << room << endl;
            cout << "Staff: " << endl;
            for (int i = 0; i != persons; i++)
            {
                fstream f(fname, ios::binary);
                f.read((char*)&baza, sizeof(Base));
                cout << baza.number << endl;
            }
        }
    }
}
