#include <iostream>
#include <string>
// To change the background-colour as well as text colour:
#include <windows.h> //or #include <stdlib.h>
#include "inherited_folders.h"
#define MAX 10000000 //Assume size of recycleBin
using namespace std;

// Function to change the colour of the text:
void SetColor(int value)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

int main()
{
    //Make objects of class file_explorer and its inherited classes and of recycleBin...
    file_explorer fe;  //consider it as root directory
    file_explorer_desktop dt;
    file_explorer_documents dc;
    file_explorer_music m;
    file_explorer_pictures p;
    recycleBin r(MAX);

    SetColor(10);
    cout << "\n\n*************************************Welcome to the terminal****************************************\n\n";
    SetColor(7);
    cout << "type \'help\' to get all the commmands and \'exit[]\' to close the terminal...\n\n";

    string s;                            //Take input command from  user
    string new_file, new_file_extension; //To add a new file in a directory
    string remove_file;                  //To remove a file from directory
    string str;
    // To change the directory where user wants to go
    string working_directory = ":home\\rootdirectory";
    //To keep a track of location of user(default location is provided)
    string find_file; //File that user wants to search
    string cut_file = "", cut_file_extension;
    //File that user wants to cut (or copy too) and paste it to another location
    bool flag = true;

    while (1)
    {
        cout << working_directory << ": ";
        cin >> s;
        cout << endl;
        // guide to user of all the commands and their functions
        if (s == "help")
        {
            SetColor(10);
            cout << "\n\'lis\'    ------------>to print the list of all the files\n"
                 << "\n\'pwdr\'   ------------>to print the working directory\n"
                 << "\n\'mkfile\' ------------>to make a new file\n"
                 << "\n\'remfile\'------------>to remove a file\n"
                 << "\n\'sortac\' ------------>to sort in ascending order(A-Z)\n"
                 << "\n\'sortdc\' ------------>to sort in descending order(Z-A)\n"
                 << "\n\'cd\'     ------------>to change the current directory\n"
                 << "\n\'CD..\'   ------------>to be back at rootdirectory\n"
                 << "\n\'find\'   ------------>to find a file in directory\n"
                 << "\n\'clr\'    ------------>to clear all the custom files\n"
                 << "\n\'cut\'    ------------>to cut the file\n"
                 << "\n\'cpy\'    ------------>to copy the file\n"
                 << "\n\'paste\'  ------------->to paste the file\n\n";
            SetColor(7);
        }

        else if (s == "lis")
        {
            // print the files of working directory
            if (working_directory == ":home\\rootdirectory")
            {
                // Some default derectories
                cout << "Desktop\t\tDocuments\tMusic\t\tPictures\t\tRecycleBin\n\n";
                //Files created by user
                fe.print_files();
            }

            else if (working_directory == ":home\\rootdirectory\\Desktop")
            {
                // Some default derectories
                cout << "Google\t\tSpotify\t\tGmail\t\tMS Office\n\n";
                //Files created by user
                dt.print_files();
            }

            else if (working_directory == ":home\\rootdirectory\\Documents")
            {
                // Some default derectories
                cout << "VS Code\t\tMing-w64\t\tGoogle-Drive\t\tOne-Drive\n\n";
                //Files created by user
                dc.print_files();
            }

            else if (working_directory == ":home\\rootdirectory\\Music")
            {
                // Some default derectories
                cout << "My Music\t\tOffilne Songs\n\n";
                //Files created by user
                m.print_files();
            }

            else if (working_directory == ":home\\rootdirectory\\Pictures")
            {
                // Some default derectories
                cout << "Gallery\t\tVideos\t\tScreenshots\n\n";
                //Files created by user
                p.print_files();
            }
        }

        else if (s == "cd")
        {
            cout << "Desktop\t\tDocuments\tMusic\t\tPictures\t\tRecycleBin\n\n";
            cout << "Enter the directory: ";
            cin >> str;
            cout << endl;

            // Update the working directory as per user entered
            if (str == "Desktop")
            {
                working_directory = ":home\\rootdirectory\\Desktop";
            }

            else if (str == "Documents")
            {
                working_directory = ":home\\rootdirectory\\Documents";
            }

            else if (str == "Music")
            {
                working_directory = ":home\\rootdirectory\\Music";
            }

            else if (str == "Pictures")
            {
                working_directory = ":home\\rootdirectory\\Pictures";
            }

            // User cannot make changes in recycleBin but can see deleted files here.So if user navigate to that location just display all deleted files.
            else if (str == "RecycleBin")
            {
                r.show();
            }

            else
            {
                SetColor(4);
                cout << "No such files or directories exist!!\n\n";
                SetColor(7);
            }
        }
        //Back to default directory
        else if (s == "CD..")
        {
            working_directory = ":home\\rootdirectory";
        }

        else if (s == "mkfile")
        {
            cout << "Enter the name of the file: ";
            cin >> new_file;
            cout << "\nEnter the extension of the file: ";
            cin >> new_file_extension;
            cout << endl;

            //Make the file in the current working directory...

            if (working_directory == ":home\\rootdirectory")
            {
                fe.create_file(new_file, new_file_extension);
            }

            else if (working_directory == ":home\\rootdirectory\\Desktop")
            {
                dt.create_file(new_file, new_file_extension);
            }
            else if (working_directory == ":home\\rootdirectory\\Documents")
            {
                dc.create_file(new_file, new_file_extension);
            }
            else if (working_directory == ":home\\rootdirectory\\Music")
            {
                m.create_file(new_file, new_file_extension);
            }
            else if (working_directory == ":home\\rootdirectory\\Pictures")
            {
                p.create_file(new_file, new_file_extension);
            }
        }

        else if (s == "remfile")
        {
            cout << "Enter the name of the file to be removed: ";
            cin >> remove_file;
            cout << endl;

            // Remove file from the current working directory...
            if (working_directory == ":home\\rootdirectory")
            {
                if (fe.if_present(remove_file) != "")
                {
                    r.push(remove_file, fe.if_present(remove_file));
                }
                fe.remove_file(remove_file);
            }

            else if (working_directory == ":home\\rootdirectory\\Desktop")
            {
                if (dt.if_present(remove_file) != "")
                {
                    r.push(remove_file, dt.if_present(remove_file));
                }
                dt.remove_file(remove_file);
            }
            else if (working_directory == ":home\\rootdirectory\\Documents")
            {
                if (dc.if_present(remove_file) != "")
                {
                    r.push(remove_file, dc.if_present(remove_file));
                }
                dc.remove_file(remove_file);
            }
            else if (working_directory == ":home\\rootdirectory\\Music")
            {
                if (m.if_present(remove_file) != "")
                {
                    r.push(remove_file, m.if_present(remove_file));
                }
                m.remove_file(remove_file);
            }
            else if (working_directory == ":home\\rootdirectory\\Pictures")
            {
                if (p.if_present(remove_file) != "")
                {
                    r.push(remove_file, p.if_present(remove_file));
                }
                p.remove_file(remove_file);
            }
        }

        else if (s == "pwdr")
        {
            //Just show the current location
            cout << working_directory << endl
                 << endl;
        }

        else if (s == "exit[]")
        {
            //Terminate the program...
            cout << endl;
            goto ending;
        }

        else if (s == "sortac")
        {
            if (working_directory == ":home\\rootdirectory")
            {
                fe.sort_ascending_order();
            }

            else if (working_directory == ":home\\rootdirectory\\Desktop")
            {
                dt.sort_ascending_order();
            }
            else if (working_directory == ":home\\rootdirectory\\Documents")
            {
                dc.sort_ascending_order();
            }
            else if (working_directory == ":home\\rootdirectory\\Music")
            {
                m.sort_ascending_order();
            }
            else if (working_directory == ":home\\rootdirectory\\Pictures")
            {
                p.sort_ascending_order();
            }
        }

        else if (s == "sortdc")
        {
            if (working_directory == ":home\\rootdirectory")
            {
                fe.sort_descending_order();
            }

            else if (working_directory == ":home\\rootdirectory\\Desktop")
            {
                dt.sort_descending_order();
            }
            else if (working_directory == ":home\\rootdirectory\\Documents")
            {
                dc.sort_descending_order();
            }
            else if (working_directory == ":home\\rootdirectory\\Music")
            {
                m.sort_descending_order();
            }
            else if (working_directory == ":home\\rootdirectory\\Pictures")
            {
                p.sort_descending_order();
            }
        }

        else if (s == "find")
        {
            cout << "Enter the file name: ";
            cin >> find_file;

            if (working_directory == ":home\\rootdirectory")
            {
                //The function returns the extension of the file if found and if not, it returns the empty string.So if empty string is not returned then the file must be there.
                if (fe.if_present(find_file) != "")
                {
                    SetColor(10);
                    cout << "\nFile is present.\n\n";
                    SetColor(7);
                }
                else
                {
                    SetColor(4);
                    cout << "\nFile does not exist!!\n\n";
                    SetColor(7);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Desktop")
            {
                if (dt.if_present(find_file) != "")
                {
                    SetColor(10);
                    cout << "\nFile is present.\n\n";
                    SetColor(7);
                }
                else
                {
                    SetColor(4);
                    cout << "\nFile does not exist!!\n\n";
                    SetColor(7);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Documents")
            {
                if (dc.if_present(find_file) != "")
                {
                    SetColor(10);
                    cout << "\nFile is present.\n\n";
                    SetColor(7);
                }
                else
                {
                    SetColor(4);
                    cout << "\nFile does not exist!!\n\n";
                    SetColor(7);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Music")
            {
                if (m.if_present(find_file) != "")
                {
                    SetColor(10);
                    cout << "\nFile is present.\n\n";
                    SetColor(7);
                }
                else
                {
                    SetColor(4);
                    cout << "\nFile does not exist!!\n\n";
                    SetColor(7);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Pictures")
            {
                if (p.if_present(find_file) != "")
                {
                    SetColor(10);
                    cout << "\nFile is present.\n\n";
                    SetColor(7);
                }
                else
                {
                    SetColor(4);
                    cout << "\nFile does not exist!!\n\n";
                    SetColor(7);
                }
            }
        }

        else if (s == "clr")
        {
            //Clear alll the files made by user not default directories.
            if (working_directory == ":home\\rootdirectory")
            {
                fe.clear_list(r);
            }
            else if (working_directory == ":home\\rootdirectory\\Desktop")
            {
                dt.clear_list(r);
            }
            else if (working_directory == ":home\\rootdirectory\\Documents")
            {
                dc.clear_list(r);
            }
            else if (working_directory == ":home\\rootdirectory\\Music")
            {
                m.clear_list(r);
            }
            else if (working_directory == ":home\\rootdirectory\\Pictures")
            {
                p.clear_list(r);
            }
        }

        else if (s == "cut")
        {
            cout << "Enter the file name: ";
            cin >> cut_file;
            cout << endl;

            if (working_directory == ":home\\rootdirectory")
            {
                //The file that user wants to cut or copy must exist and if it does then this function will return the extension of it which we will be storing in a string so that to paste it in an another directory.
                if (fe.if_present(cut_file) != "")
                {
                    // So that we can  paste it in future
                    flag = true;
                    cut_file_extension = fe.if_present(cut_file);
                    fe.remove_file(cut_file);
                }

                else
                {
                    // So that we don't paste it in future
                    flag = false;
                    SetColor(4);
                    cout << "File does not exist!!\n\n";
                    SetColor(7);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Desktop")
            {
                if (dt.if_present(cut_file) != "")
                {
                    flag = true;
                    cut_file_extension = dt.if_present(cut_file);
                    dt.remove_file(cut_file);
                }
                else
                {
                    flag = false;
                    SetColor(4);
                    cout << "File does not exist!!\n\n";
                    SetColor(7);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Documents")
            {
                if (dc.if_present(cut_file) != "")
                {
                    flag = true;
                    cut_file_extension = dc.if_present(cut_file);
                    dc.remove_file(cut_file);
                }
                else
                {
                    flag = false;
                    SetColor(4);
                    cout << "File does not exist!!\n\n";
                    SetColor(7);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Music")
            {
                if (m.if_present(cut_file) != "")
                {
                    flag = true;
                    cut_file_extension = m.if_present(cut_file);
                    m.remove_file(cut_file);
                }
                else
                {
                    flag = false;
                    SetColor(4);
                    cout << "File does not exist!!\n\n";
                    SetColor(7);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Pictures")
            {
                if (p.if_present(cut_file) != "")
                {
                    flag = true;
                    cut_file_extension = p.if_present(cut_file);
                    p.remove_file(cut_file);
                }
                else
                {
                    flag = false;
                    SetColor(4);
                    cout << "File does not exist!!\n\n";
                    SetColor(7);
                }
            }
        }

        else if (s == "cpy")
        {
            //Same explanation as given in cut part...
            cout << "Enter the file name: ";
            cin >> cut_file;
            cout << endl;

            if (working_directory == ":home\\rootdirectory")
            {
                if (fe.if_present(cut_file) == "")
                {
                    flag = false;
                    SetColor(4);
                    cout << "File does not exist!!\n\n";
                    SetColor(7);
                }
                else
                {
                    flag = true;
                    cut_file_extension = fe.if_present(cut_file);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Desktop")
            {
                if (dt.if_present(cut_file) == "")
                {
                    flag = false;
                    SetColor(4);
                    cout << "File does not exist!!\n\n";
                    SetColor(7);
                }
                else
                {
                    flag = true;
                    cut_file_extension = dt.if_present(cut_file);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Documents")
            {
                if (dc.if_present(cut_file) == "")
                {
                    flag = false;
                    SetColor(4);
                    cout << "File does not exist!!\n\n";
                    SetColor(7);
                }
                else
                {
                    flag = true;
                    cut_file_extension = dc.if_present(cut_file);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Music")
            {
                if (m.if_present(cut_file) == "")
                {
                    flag = false;
                    SetColor(4);
                    cout << "File does not exist!!\n\n";
                    SetColor(7);
                }

                else
                {
                    flag = true;
                    cut_file_extension = m.if_present(cut_file);
                }
            }

            else if (working_directory == ":home\\rootdirectory\\Pictures")
            {
                if (p.if_present(cut_file) == "")
                {
                    flag = false;
                    SetColor(4);
                    cout << "File does not exist!!\n\n";
                    SetColor(7);
                }

                else
                {
                    flag = true;
                    cut_file_extension = p.if_present(cut_file);
                }
            }
        }

        else if (s == "paste")
        {
            //To perform paste operation, user must have performed operation of cut or copy before.

            if (cut_file == "")
            {
                SetColor(4);
                cout << "First cut or copy something!!\n\n";
                SetColor(7);
            }

            else
            {
                if (working_directory == ":home\\rootdirectory")
                {
                    if (flag)
                    {
                        fe.create_file(cut_file, cut_file_extension);
                    }
                }

                else if (working_directory == ":home\\rootdirectory\\Desktop")
                {
                    if (flag)
                    {
                        dt.create_file(cut_file, cut_file_extension);
                    }
                }

                else if (working_directory == ":home\\rootdirectory\\Documents")
                {
                    if (flag)
                    {
                        dc.create_file(cut_file, cut_file_extension);
                    }
                }

                else if (working_directory == ":home\\rootdirectory\\Music")
                {
                    if (flag)
                    {
                        m.create_file(cut_file, cut_file_extension);
                    }
                }

                else if (working_directory == ":home\\rootdirectory\\Pictures")
                {
                    if (flag)
                    {
                        p.create_file(cut_file, cut_file_extension);
                    }
                }
            }
        }

        else
        {
            SetColor(4);
            cout << "\nERROR!!! \'" << s << "\' not found as an internal or external command.\n\n";
            SetColor(7);
        }
    }
ending:
    return 0;
}
