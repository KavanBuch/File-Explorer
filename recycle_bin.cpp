#include <iostream>
#include <string>
using namespace std;
#include "recycle_bin.h"

// Forward Declaration
void SetColor(int);

recycleBin::recycleBin(int size)
{
    this->size = size;
    top = -1;
    arr_file_name = new string[this->size];
    arr_file_extension = new string[this->size];
}

void recycleBin::push(string f_name, string f_extension)
{
    // Check if stack is full or not
    if (top != size - 1)
    {
        top++;
        arr_file_name[top] = f_name;
        arr_file_extension[top] = f_extension;
    }
    else
    {
        SetColor(4);
        cout << "Recycle Bin is full.\n\n";
        SetColor(7);
    }
}

void recycleBin::show()
{
    if (top == -1)
    {
        SetColor(4);
        cout << "RecycleBin is empty!!!\n\n";
        SetColor(7);
    }

    else
    {
        SetColor(10);
        cout << "\nFile Name\t\t\tFile Type(Extension)\n"
             << "____________________________________________________\n\n";
        SetColor(7);
        for (int i = 0; i <= top; i++)
        {
            cout << arr_file_name[i] << "\t\t\t\t" << arr_file_extension[i] << "\n";
        }
        cout << endl;
    }
}
