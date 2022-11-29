#pragma once
#include "var.h"
using namespace nsVar;
namespace nsProc
{
	bool remove_line(const char* fname, size_t index);
	void delete_base(Base* p, int size);
	void search_number(char* fname);
	void search_room(Base* p, int size, char* fname);
	void search_name(Base* p, int size, char* fname);
	void search_number(Base* p, int size, char* fname);
}