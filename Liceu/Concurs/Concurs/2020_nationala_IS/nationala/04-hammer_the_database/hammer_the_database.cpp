/*
AcadNet 2020
Author: Alexandru Razvan Caciulescu
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LINES           1024
#define LINE_LENGTH     20

using namespace std;

char db[LINES][LINE_LENGTH];

int restricted;
bool looged_in = false;
const char* secret = "very_hidden_hammer_secret_which_should_not_be_seen";

const char alphanum[] = "abcdefghijklmnopqrstuvwxyz0123456789";

#define FLUSH_STDIN(x) {if(x[strlen(x)-1]!='\n'){do fgets(Junk,16,stdin);while(Junk[strlen(Junk)-1]!='\n');}else x[strlen(x)-1]='\0';}
char Junk[16];

void assign_password()
{
    int line = 741;
    for (int i = 0; i < LINE_LENGTH; i++) {
        db[line][i] = alphanum[rand() % strlen(alphanum)];
    }
    restricted = line;
}

void write_line(int line, const char* word, int word_length)
{
    if (line == restricted)
    {
        cerr << "Warning: Attempted to write on a restricted line. Choose another line." << endl;
    }
    else if (line >= 0 && line < LINES)
    {
        memset((*(db+line-1)+LINE_LENGTH), 0, LINE_LENGTH);
        memcpy((*(db+line-1)+LINE_LENGTH), word, word_length);

        // if (line == restricted - 1 || line == restricted + 1)
        if (line > 0 && line < LINES - 1)
        {
            for (int i = 0; i < LINE_LENGTH; i++) {
                // if (db[restricted - 1][i] != '\0' && db[restricted + 1][i] != '\0' && db[restricted - 1][i] == db[restricted + 1][i] && rand() % 2 == 0)
                if (line - 2 >= 0 && db[line - 2][i] == db[line][i] && rand() % 2 == 0)
                    db[line - 1][i] = db[line][i];
                if (line + 2 <= LINES - 1 && db[line + 2][i] == db[line][i] && rand() % 2 == 0)
                    db[line + 1][i] = db[line][i];
                // if (db[line - 1][i] == db[line + 1][i] && rand() % 2 == 0)
                // {
                //     db[restricted][i] = db[line][i];
                // }
            }
        }
    }
    else
    {
        cerr << "Error: Attempted to write a line outside the bounds of the DB! Terminating program..." << endl;
        exit(1);
    }
}

void read_line(int line)
{
    if (line == restricted)
    {
        cerr << "Warning: Attempted to read on a restricted line. Choose another line." << endl;
        return;
    }
    for (int j = 0; j < LINE_LENGTH; j++)
    {
        cout << db[line][j] << ".";
    }
    cout << endl;
}

void login(char* input)
{
    if (strncmp(input, db[restricted], LINE_LENGTH) == 0)
    {
        cout << "Login successful!" << endl;
        looged_in = true;
    }
    else
    {
        int diff = 0;
        for (int i = 0; i < LINE_LENGTH; i++) {
            if (db[restricted][i] != input[i]) diff++;
        }
        cerr << "Failed to log in, password incorrect! " << diff << " missmatched characters detected" << endl;
    }

}

void print_db()
{
    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < LINE_LENGTH; j++)
        {
            if (i == restricted)
                cout << "#" << ".";
            else
                cout << db[i][j] << ".";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    char command;
    char input[LINE_LENGTH + 1];
    int line;

    srand(time(0));
    assign_password();

    cout << "Welcome to Hammer the Database!" << endl;
    print_db();

    memset(input, 0, LINE_LENGTH + 1);
    cout << "Enter your command:" << endl;
    while (fgets(input, LINE_LENGTH + 1, stdin))
    {
        switch (input[0])
        {
            case 'R':
                if (!fgets(input, LINE_LENGTH + 1, stdin)) goto input_error;
                line = atoi(input);
                read_line(line);
                break;
            case 'W':
                fgets(input, LINE_LENGTH + 1, stdin);
                line = atoi(input);
                fgets(input, LINE_LENGTH + 1, stdin);
                write_line(line, input, strlen(input));
                break;
            case 'L':
                if (!fgets(input, LINE_LENGTH + 1, stdin)) goto input_error;
                login(input);
                break;
            case 'S':
                if (!looged_in) goto input_error;
                cout << "Secret revealed: " << secret << endl;
                break;
            case 'P':
                print_db();
                break;
            case 'Q':
                exit(0);
            default:
                goto input_error;
                break;
        }
        FLUSH_STDIN(input);
    }

input_error:
    cerr << "Error: command not recognized or insufficient rights, terminating program..." << endl;
    exit(1);
}
