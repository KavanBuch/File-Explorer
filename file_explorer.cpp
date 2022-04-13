#include <iostream>
#include <string>
#include "file_explorer.h"
#include "recycle_bin.cpp"
using namespace std;

// Forward declaration...
void SetColor(int);
class recycleBin;

file_explorer::file_explorer()
{
    head = NULL;
    tail = NULL;
}

void file_explorer::create_file(string file_name, string file_extension)
{
    // First we have to check if there is already a file of same name or not.
    if (check_file_name(file_name))
    {
        node *temp = new node;
        temp->file_name = file_name;
        temp->file_extension = file_extension;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }

    else
    {
        SetColor(4);
        cout << "ERROR!!It seems there already exists a file with this name.\n\n";
        SetColor(7);
    }
}

void file_explorer::print_files()
{
    if (head != NULL)
    {
        node *p = new node;
        p = head;
        SetColor(10);
        cout << "\nFile Name\t\t\tFile Type(Extension)\n"
             << "____________________________________________________\n\n";
        SetColor(7);
        while (p != NULL)
        {
            cout << p->file_name << "\t\t\t\t"
                 << p->file_extension << "\n";
            p = p->next;
        }
    }
}

void file_explorer::remove_file(string f_name)
{
    // No files made by user
    if (head == NULL)
    {
        SetColor(4);
        cout << "No custom files exist.\n\n";
        SetColor(7);
    }

    // Deleting first node(file)
    else if (head->file_name == f_name)
    {
        node *p = new node;
        p = head;
        head = head->next;
        free(p);
        p = NULL;
    }

    else
    {
        node *p = new node;
        p = head;
        // Reach to the node before the node(file) to be deleted.
        while (p->next != NULL && p->next->file_name != f_name)
        {
            p = p->next;
        }

        // Traversed the whole list but did not find the file
        if (p->next == NULL)
        {
            SetColor(4);
            cout << "No such files or directories exist\n\n";
            SetColor(7);
        }

        //Deleting the last node(file)
        else if (p->next->file_name == f_name && p->next->next == NULL)
        {
            node *temp = new node;
            temp = p->next;
            p->next = NULL;
            delete temp;
            temp = NULL;
            //Tail is the last node in the list and is still pointing to an
            //invalid memory address which is freed and so it has to be shifted
            //towards last updated node in this case.
            tail = p;
        }

        else
        {
            // File found,Delete it...
            node *temp = new node;
            temp = p->next;
            p->next = temp->next;
            delete temp;
            temp = NULL;
        }
    }
}

void file_explorer::sort_ascending_order()
{
    node *p = new node;
    node *q = new node;
    // Bubble sort
    for (p = head; p->next != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->file_name > q->file_name)
            {
                string temp = p->file_name;
                p->file_name = q->file_name;
                q->file_name = temp;

                string temp2 = p->file_extension;
                p->file_extension = q->file_extension;
                q->file_extension = temp2;
            }
        }
    }
}

void file_explorer::sort_descending_order()
{
    node *p = new node;
    node *q = new node;
    for (p = head; p->next != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->file_name < q->file_name)
            {
                string temp = p->file_name;
                p->file_name = q->file_name;
                q->file_name = temp;

                string temp2 = p->file_extension;
                p->file_extension = q->file_extension;
                q->file_extension = temp2;
            }
        }
    }
}

int file_explorer::check_file_name(string f_name)
{
    node *p = head;
    while (p)
    {
        if (p->file_name == f_name)
        {
            return 0;
        }

        p = p->next;
    }
    return 1;
}

string file_explorer::if_present(string f_name)
{
    node *p = head;
    while (p)
    {
        if (p->file_name == f_name)
        {
            return p->file_extension;
        }

        p = p->next;
    }
    return "";
}

void file_explorer::clear_list(recycleBin &r)
{
    while (head)
    {
        // Delete first node every time and then update it.
        node *p = new node;
        p = head;
        // Push removed file to stack
        r.push(p->file_name, p->file_extension);
        head = head->next;
        delete p;
        p = NULL;
    }
    tail = NULL;
}
