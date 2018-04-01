
/// imports

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>
#include <windows.h>
#include <unistd.h>

using namespace std;

///Prototypes

void TimeDelay(); // for 3 seconds delay
void read (int &letters2); // for reading a file
int edit (int &letters4); // for editing and creating a file. This function only overwrites or creates new file, if the filename isn't present
void takeCommand(int& letters3); // this function takes these three commands, read, write and exit. It is just like our main(), and whole program is running here.
string ToUpperCase(string name); // converts string to uppercase
void suggestions(string word); // in the case of wrong commands entered, this function suggests the correct the command.
int countCharacters(string sentence,int &letters1);// count the total characters in a sentence/string
string game();

//Important notes:
    // you will find some functions that will be taking arguments such as letters1, letters2 etc. they are for counting the characters in the file read.
    // letters1, letters2, letters3, letters4 are all referring to the same thing, number of characters read.
    // the countCharacters function counts the spaces too
    // you must be thinking why my majority of the functions are taking letters[i] as input. The reason is, takeCommand is called in each function,
    // and for it to store and make changes to the characters read, the letters have to be transferred from one function to other.

int main ()
{
    int letters = 0;
    takeCommand(letters);
}

///defining functions

string game()
{
    string lst[] = {"B","R","T","A","G","A","V","R","E","T","0"};
}

int countCharacters(string sentence,int &letters1) //takes a string sentence, and counts the no. of characters present in it.
{                                                   // it uses a for loop that repeats the number of times the characters in a string, including the spaces
    for (int i = 0; i<sentence.size(); i++)
    {
        letters1 = letters1 +1; // letters1 is the number of characters
    }
}

void suggestions(string word) // this function uses the concept of neural systems.
{
    int matchRead = 0;
    int matchEdit = 0;
    int matchExit = 0;
    string readWord = "READ";
    string editWord = "EDIT";
    string exitWord = "EXIT";
    word = ToUpperCase(word);
    for(int i = 0; i < word.size(); i++)    // compares each word from the given command to 'read'. for counts the number of matches, and store it in match_read.
    {
        for (int j = 0; j < readWord.size(); j++)
        {
            if (word.at(i) == readWord.at(j))
            {
                matchRead = matchRead + 1;
            }
        }
    }
    for(int i = 0; i < word.size(); i++) // compares each word from the given command to 'edit'. for counts the number of matches, and store it in match_edit.
    {
        for (int j = 0; j < editWord.size(); j++)
        {
            if (word.at(i) == editWord.at(j))
            {
                matchEdit = matchEdit + 1;
            }
        }
    }
    for(int i = 0; i < word.size(); i++) // compares each word from the given command to 'exit'. for counts the number of matches, and store it in match_exit.
    {
        for (int j = 0; j < exitWord.size(); j++)
        {
            if (word.at(i) == exitWord.at(j))
            {
                matchExit = matchExit + 1;
            }
        }
    }
    //conditions
    //compares the three variables, and decides what to suggest base on the variable having the greatest value.
    if ((matchRead == 0) && ( matchExit == 0) && ( matchEdit == 0))
    {
        cout<<"Please enter a valid command"<<endl; // matches with none
    }

    else if ((matchRead >= matchEdit) && (matchRead >= matchExit))
    {
        cout<<"Did u mean read?"<<endl; // the command matched with read
    }
    else if ((matchEdit >= matchRead) && (matchEdit >= matchExit))
    {
        cout<<"Did u mean edit?"<<endl; // the command matched with edit
    }
    else if ((matchExit >= matchEdit) && (matchExit >= matchRead))
    {
        cout<<"Did u mean exit?"<<endl; // the command matched with exit
    }
}

void takeCommand(int &letters3) // just like a main(). I navigates between the different function, takes input and does everything(calling other functions)
{
    cout<<""<<endl;
    cout<<"Total characters read so far = "<< letters3<<endl;
    cout<<"                     ---------------------------------------------------------------"<<endl;
    cout<<"                     |                  Welcome to SimpleTextEditor                |"<<endl;
    cout<<"                     ---------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<< "Type 'edit' to edit a text file"<<endl;
   cout<< "Type 'read' to read a text file"<<endl;
   cout<< "Type 'exit' to exit program"<<endl;

    string command; //command can be read, write or exit
    do // asks for 1 input atleast
    {
        cout<< " "<<endl;
        cout<<"Enter your command: ";
        getline(cin,command); // takes the inmput and stores it in command
        command = ToUpperCase(command); // change the command to uppercase
        if ((command != "READ") && (command != "EDIT") && (command != "EXIT" )) // the program runs until a valid command is given.
        {
            if (command!= "") // if no command is given, is asks for a command again.
            {
                suggestions(command); // if an incorrect command is given, it gives suggestions for the write command
            }
        }
    }
    while ((command != "READ") && (command != "EDIT") && (command != "EXIT" )); // the program runs until a valid command is given.

    //conditions
    //sends the user to the right function, based on his/her command entered.
    if (command == "EDIT")
    {
        edit (letters3);
    }
    if (command == "READ")
    {
        read(letters3);
    }
    if (command == "EXIT")
    {
        exit(EXIT_SUCCESS); //closes the text editor
    }
}

void TimeDelay() // gives a 3 second pause
{
    cout<<""<<endl;
    cout<<"1";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(331); //time in milliseconds

    cout<<"2";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(331); //time in milliseconds

    cout<<"3";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(331); //time in milliseconds
}

string ToUpperCase(string name) //converts the whole string into uppercase.
{
    for(int i = 0; i < name.size(); i++) //uses a loop the number of times the characters in the string
    {
        name.at(i) = toupper(name.at(i)); //takes a character and replaces it with its uppercase by using touppper command.
    }
    return name; //returns uppercase
}

void read (int &letters2) // displays the contents of a file
{
    string erase_all;
    int line = 0; // number of lines in the document
    int line_num = 24; // number of lines to ask the permission at
    string permissionString; // asks whether the person wants to read more after 24 lines
    char filename[50]; // takes the file name
    ifstream readfile;
    string eachline = ""; // stores each line of the file
    cout << "Enter name of the file to read: "; //asks for file name
    cin.getline(filename, 50); // stores the filename
    readfile.open(filename); //open the file with that name
    if (readfile == 0)
    {
        cout<<""<<endl;
        cout<<"File doesn't exist"<<endl;
    }
    while(getline(readfile,eachline)) //runs the loop number of times the lines in the file
    {
        line = line + 1; //count no. of lines in the file
        cout<<line<<"> "<<eachline<<endl; //displays line number
        countCharacters(eachline, letters2); //counts character in each line
        if (line%line_num  == 0) // ask if the person wants to read more after line 24
        {
            cout<<" "<<endl;
            cout<<"Do you want to read more (type y to read)? ";
            getline(cin,permissionString); //takes yes if the person wants to see the file further
            permissionString = ToUpperCase(permissionString); // converts yes into uppercase
            if (permissionString != "Y")
            {
                break; // if the input is anything other than yes, it doest display more lines
            }
        }
    }
    readfile.close(); //closes file
    cout<<""<<endl;
    system("pause"); // says ,"Press any key to continue"
    TimeDelay(); //gives a 3 second pause
    system("cls"); // clears the screen
    takeCommand(letters2); // displays the main menu again
}

int edit (int &letters4) //edits/creates a new file
{
    int lineNoEdit = 1; // displays the line number
    string editLine; // takes each line
    char filenameEdit[50];
    ofstream editFile;
    cout << "Enter name of the file to edit: ";
    cin.getline(filenameEdit, 50);// takes filename
    editFile.open(filenameEdit); //open the file
    cout<<"Start typing, Enter / or CTRL + X to stop editing"<<endl;
    do //takes input until / or CTRL + X is entered.
    {
        cout<<lineNoEdit<<"> ";// displays line number
       getline(cin,editLine); // takes the contents in a line
       if ((editLine == "/" )|| (editLine == "")) //breaks the loop
       {
           break;//breaks the loop
       }
       editFile << (editLine)<<"\n";//adds the line to the file, and moves to the next line
       lineNoEdit = lineNoEdit +1; // line numbers
    }
    while ((editLine != "/") && (editLine != "" )); //takes input until / or CTRL + X is entered.
    editFile.close(); //closes the file
    system("pause"); // says ,"Press any key to continue"
    TimeDelay(); //gives a 3 second pause
    system("cls"); // clears the screen // 3 seconds pause
    takeCommand(letters4); //displays the main menu again
    return 0;
}

