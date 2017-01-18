//  Char in Cpp

//#1: use cin.get() to get whole characters
//Input: Hello my dear!
#include <iostream>
using namespace std;

int main()
{
    char buffer[80] = {'\0'};
    cout << "Enter the string: ";
    //std::cin >> buffer;
    cin.get(buffer, 79); // get up to 79 or newline
    cout << "Here's the buffer: " << buffer << endl;
    return 0;
}

// output:  Hello (use std::cin)
//          Input: Hello my dear! (use cin.get())

//#1: strcpy vs strncpy
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char String1[] = "No man is an island";
    char String2[80] = {'\0'};

    strcpy(String2,String1);

    cout << "String1: " << String1 << endl;
    cout << "String2: " << String2 << endl;
    return 0;
}

#include <iostream>
#include <string.h>

int main()
{
    const int MaxLength = 80;
    char String1[] = "No man is an island";
    char String2[MaxLength+1] = {'\0'};

    strncpy(String2, String1, MaxLength); // safer than strcpy

    std::cout << "String1: " << String1 << std::endl;
    std::cout << "String2: " << String2 << std::endl;

    return 0;
}