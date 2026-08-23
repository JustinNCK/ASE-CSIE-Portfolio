#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <regex>

using namespace std;

#define START_SYMBOL "A"

typedef enum {
    A,
    B,
    NONE
} nonterminal_t;

class Node {
    public:
        Node(void);
        Node(string &);
        ~Node(void);

        void expand_first(void);
        void expand_second(void);
    
        string content;
        Node *left_son, *right_son;
        nonterminal_t type;
};

Node *root = NULL;

Node::Node(void)
{
    this->content = string(START_SYMBOL);
    this->left_son = NULL;
    this->right_son = NULL;
    this->type = A;
}

Node::Node(string &s)
{
    this->content = s;
    this->left_son = NULL;
    this->right_son = NULL;

    if (strchr(s.c_str(), 'A'))
        this->type = A;
    else if (strchr(s.c_str(), 'B'))
        this->type = B;
    else
        this->type = NONE;
}

Node::~Node(void)
{
    delete this->left_son;
    delete this->right_son;
}

/*
    Functia regex_replace inlocuieste un subsir de caractere care se potriveste
    cu un anumit pattern cu un sir dat.
    Exemplu:
    1. regex_replace("Aa", regex("A"), "1A") -> "1Aa"
    2. regex_replace("AA", regex("A"), "1A") -> "1A1A"
*/
void Node::expand_first(void)
{
    if (this->left_son)
        return;

    string &str = this->content;
    string new_str;

    switch (this->type) {
        case A:
            // A -> 1A
            new_str = regex_replace(str, regex("A"), "1A");
            this->left_son = new Node(new_str);
            return;
        case B:
            // A -> B
            new_str = regex_replace(str, regex("B"), "B0");
            this->left_son = new Node(new_str);
            return;
        case NONE:
            return;
    }
}

/*
    Functia regex_replace inlocuieste un subsir de caractere care se potriveste
    cu un anumit pattern cu un sir dat.
    Exemplu:
    1. regex_replace("Aa", regex("A"), "1A") -> "1Aa"
    2. regex_replace("AA", regex("A"), "1A") -> "1A1A"
*/
void Node::expand_second(void)
{
    if (this->right_son)
        return;
    
    string &str = this->content;
    string new_str;

    switch (this->type) {
        case A:
            new_str = regex_replace(str, regex("A"), "B");
            this->right_son = new Node(new_str);
            return;
        case B:
            new_str = regex_replace(str, regex("B"), "");
            this->right_son = new Node(new_str);
            return;
        case NONE:
            return;
    }
}

void find_results(unsigned int number, vector<string> &results)
{
    queue<Node *> q;

    q.push(root);

    while (true) {
        auto &ptr = q.front();

        if (ptr->type == NONE) {
            results.push_back(ptr->content);
            q.pop();
            continue;
        }

        if (results.size() == number)
            return;
        
        if (ptr->left_son == NULL)
            ptr->expand_first();
        
        q.push(ptr->left_son);

        if (ptr->right_son == NULL)
            ptr->expand_second();
        
        q.push(ptr->right_son);

        q.pop();
    }
}

void print_results(vector<string> &results)
{
    cout << results.size() << " -> ";

    cout << "[";

    for (size_t i = 0; i < results.size(); ++i) {
        cout << "\"" << results[i] << "\"";
        if (i != results.size() - 1)
            cout << ", ";
    }

    cout << "]" << "\n";
}

int main(void)
{
    root = new Node();

    int number;
    vector<string> results;

    while (cin >> number) {
        if (number < 0)
            break;
        
        find_results(number, results);
        print_results(results);
        results.clear();
    }

    delete root;
    return 0;
}