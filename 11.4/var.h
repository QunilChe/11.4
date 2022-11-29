#pragma once
using namespace std;
namespace nsVar
{
    extern  struct Base
    {

        int number;
        int room;
        int persons;
        char** name;
    public:
        Base() { number = room = persons = 0; }
        void delete_base();
        void search_number(char* fname);
    };
    extern int size;
    extern int x = 20;
    extern  Base* base;
         extern Base* base = new Base[size];
         extern  char fname[100]; // ім'я першого файлу

}