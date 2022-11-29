#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include "var.h"
#include "out.h"
using namespace std;
using namespace nsOut;
using namespace nsVar;
void nsOut::show_base(Base* p, int size, char* fname)
{
    cout << endl << "\nfile \"" << fname << "\":\n";
    ifstream f(fname, ios::binary);
    int x;
    while (f.read((char*)&x, sizeof(x)))
        cout << x << endl;
    cout << endl;
}
