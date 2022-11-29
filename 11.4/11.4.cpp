#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

struct Base
{
    int number;
    int room;
    int persons;
    char** name;
public:
    void delete_base();
    void search_number(char* fname);
}baza;

bool remove_line(const char* fname, size_t index)
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
void Base::delete_base()
{
    cout << "Deleting base...\n";
    for (int i = 0; i != this->persons; i++)
    {
        delete[] name[i];
    }
    delete[] name;

    cout << "Delete status: Ok\n";
}
void Base::search_number(char* fname)
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

void set_base(Base* p, int size, char* fname)
{
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

void show_base(Base* p, int size, char* fname)
{
    cout << endl << "\nfile \"" << fname << "\":\n";
    ifstream f(fname, ios::binary);
    int x;
    while (f.read((char*)&x, sizeof(x)))
        cout << x << endl;
    cout << endl;
}

void delete_base(Base* p, int size)
{
    for (int i = 0; i != size; i++)
    {
        p[i].delete_base();
    }
}


void search_room(Base* p, int size, char* fname)
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

void search_name(Base* p, int size, char* fname)
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

void search_number(Base* p, int size, char* fname)
{
    for (int i = 0; i != size; i++)
        p[i].search_number(fname);
}


int main()
{
    SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
    SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
    int size;
    cout << "vvedit N: "; cin >> size;
    int x = 20;

    Base* base;
    base = new Base[size];
    char fname[100]; // ��'� ������� �����
    cout << "enter file name 1: "; cin >> fname;


    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "������� ��:" << endl << endl;
        cout << " [1] - �������� ����� � ���������" << endl;
        cout << " [2] - ���� ����� �� �����" << endl;
        cout << " [3] - �� ������� �������� ����� ��������� � ������ �����" << endl;
        cout << " [4] - �� ������� ��������� ����� ��������" << endl;
        cout << " [5] - �� �������� ��������� ���� �������� � ����� ���������" << endl;
        cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
        cout << "������ ��������: "; cin >> menuItem;
        cout << endl << endl << endl;
        switch (menuItem)
        {
        case 1:
            set_base(base, size, fname);
            break;
        case 2:
            show_base(base, size, fname);
            break;
        case 3:
            search_number(base, size, fname);
            break;
        case 4:
            search_room(base, size, fname);
            break;
        case 5:
            search_name(base, size, fname);
            break;
        case 0:
            break;
        default:
            cout << "�� ����� ��������� ��������! "
                "��� ������ ����� - ����� ��������� ������ ����" << endl;
        case 6:
            cout << remove_line(fname, 2);
            break;
        }
    } while (menuItem != 0);
    return 0;
}
