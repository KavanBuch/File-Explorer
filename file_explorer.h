#include <string>
using namespace std;
// Forward declaration...
class recycleBin;

struct node
{
    string file_name;
    string file_extension;
    node *next;
};

class file_explorer
{
protected:
    // First and last node if list
    node *head, *tail;

public:
    file_explorer();
    //Constructor to intialise head and tail
    void create_file(string, string);
    //Append a new node(file) at the end
    void remove_file(string);
    //Delete a node(file)
    void print_files();
    //Print the list of files

    void sort_ascending_order();
    void sort_descending_order();
    //Sort according to alphabetical order

    int check_file_name(string);
    //To check whether a file is already created or not.If so, then user should not be allowed to make the file with same name.
    string if_present(string);
    //If a file is present then return its extension.

    void clear_list(recycleBin &);
    // clear all the files of a directory and puch them into recycleBin
};
