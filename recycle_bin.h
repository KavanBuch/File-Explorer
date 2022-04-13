#include <string>

class recycleBin
{
protected:
    int top;
    int size;
    string *arr_file_name;
    string *arr_file_extension;

public:
    recycleBin(int);
    // Constructor to create a empty stack.
    void push(string, string);
    //Push file_name as well as extension.
    void show();
    //Desplay them.
};
