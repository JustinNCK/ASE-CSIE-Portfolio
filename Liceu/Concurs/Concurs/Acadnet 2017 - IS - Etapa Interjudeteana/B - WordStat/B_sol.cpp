/*
    Acadnet 2017 - Etapa Interjudeteana
    Problema B - WordStat
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>

#define SPACE ' '
#define VOWELS "AEIOU"

using namespace std;


bool myPairOperator (pair<char,int> a, pair<char,int> b)
{
    if(b.second > a.second)
    {
        return false;
    }
    else if (b.second == a.second)
    {
        return (a.first > b.first);
    }
    else
        return true;
}


int isLetter(char letter)
{
    if ((65 <= letter && letter <= 90) ||
        (97 <= letter && letter <= 122))
        return 1;
    return 0;
}

int isVowel(char letter)
{
    int it;
    for(it = 0; it < strlen(VOWELS); it++)
    {
        if(VOWELS[it] == letter)
            return 1;
    }
    return 0;
}
int main (int argc, char **argv)
{
    int returnValue = 0;
    FILE *datafp = NULL;
    unsigned int lettersNumber = 0;
    unsigned int vowelsNumber = 0;
    unsigned int consonantNumber = 0;
    char buffer[25];
    int appearances[256];
    char cit = 0;
    unsigned int it = 0;
    vector < pair <char, int> > myVowels;
    vector < pair <char, int> > myConsonants;


    do
    {
        datafp = fopen("input.txt", "r");
        if (datafp == NULL)
        {
            returnValue = 1;
            break;
        }

        fscanf(datafp, "%ud", &lettersNumber);
        fscanf(datafp, "%ud", &vowelsNumber);
        fscanf(datafp, "%ud", &consonantNumber);

        for (it = 0; it < 256; it++)
        {
            appearances[it] = 0;
        }

        while ( !feof( datafp ) )
        {
            if (fgets(buffer, 25, datafp) == NULL) 
            {
                if (feof( datafp ))
                    break;
                returnValue = 1;
                break;
            }
            if ( (strlen(buffer) - 1) == lettersNumber )
            {
                for (cit = 0; cit < strlen(buffer); cit++)
                {
                    if (buffer[cit] >= 95)
                        appearances[buffer[cit] - SPACE]++;
                    else
                        appearances[buffer[cit]]++;
                }
            }
        }
        if (returnValue != 0)
            break;

        for (cit = 0; cit < 127; cit++)
        {
            if (isLetter(cit) == 1)
            {
                if (cit >= 95)
                    continue;
                if (isVowel(cit) == 1)
                {
                   myVowels.push_back(make_pair(cit,appearances[cit]));
                }
                else
                {
                   myConsonants.push_back(make_pair(cit,appearances[cit]));
                }
            }
        }


        sort (myVowels.begin(), myVowels.end(), myPairOperator);
        sort (myConsonants.begin(), myConsonants.end(), myPairOperator);

        for (cit = 0; cit < vowelsNumber - 1; cit++)
        {
            cout << myVowels[cit].first << " ";
        }
        cout <<  myVowels[cit].first << endl;
        for (cit = 0; cit < consonantNumber - 1; cit++)
        {
            cout << myConsonants[cit].first << " ";
        }
        cout << myConsonants[cit].first << endl;
        
    } while (0);

    if (datafp != NULL)
        fclose(datafp);
    return returnValue;
}