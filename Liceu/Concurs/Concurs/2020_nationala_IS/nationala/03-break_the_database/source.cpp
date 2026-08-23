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
const char* secret = "very_hidden_secret_which_should_not_be_seen";

const char alphanum[] = "abcdefghijklmnopqrstuvwxyz0123456789";

void send_password_to_admin()
{
    // a blackmagic implementation that has been lost in the depths of time
}

void assign_password()
{
    int line = rand() % (LINE_LENGTH - 1) + 1;
    for (int i = 0; i < LINE_LENGTH; i++) {
        db[line][i] = alphanum[rand() % strlen(alphanum)];
    }
    restricted = line;

    send_password_to_admin();
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
        cerr << "Failed to log in, password incorrect!" << endl;
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
    char black_magic[69420];
    memset(black_magic, 0, 42069);

    char command;
    char input[LINE_LENGTH];
    int line;

    srand(time(0));
    assign_password();

    cout << "Welcome to Crack the Database!" << endl;
    print_db();

    memset(input, 0, LINE_LENGTH);
    cout << "Enter your command:" << endl;
    while (gets(input))
    {
        switch (input[0])
        {
            case 'R':
                if (!gets(input)) goto input_error;
                line = atoi(input);
                read_line(line);
                break;
            case 'W':
                if (!gets(input)) goto input_error;
                line = atoi(input);
                if (!gets(input)) goto input_error;
                write_line(line, input, strlen(input));
                break;
            case 'L':
                if (!gets(input)) goto input_error;
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
        memset(input, 0, LINE_LENGTH);
        memset(black_magic, 0, 42069);
    }

input_error:
    cerr << "Error: command not recognized or insufficient rights, terminating program..." << endl;
    exit(1);
}
