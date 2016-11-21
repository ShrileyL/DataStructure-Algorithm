/**************************************************
 * Effective C++ 
 * 
 * #3 use const member function
 * 
 *
 * 2016/11/21 Shirley test
 *************************************************/

#include <iostream>

using namespace std;

class TextBlock
{
public:
    // TextBlock();
    // ~TextBlock();
    TextBlock(std::string str){text = str;}
    const char& operator[](std::size_t position) const
    {return text[position];};
    char& operator[](std::size_t position)
    {return text[position];};
private:
    std::string text;
};

class CTextBlock
{
public:
    CTextBlock(char p){pText = &p;}
    char& operator[](std::size_t position) const
    {return pText[position];}
    void print(std::size_t position){std::cout << pText[position];}
    
    
private:
    char *pText;
};

int main(int argc, char const *argv[])
{
    TextBlock tb("Hello");
    
    std::cout << tb[0];//output:"H"
    
    const TextBlock ctb("World");
    
    std::cout << ctb[0];//output:"W"
    
    tb[0] = 'x';
    
    //ctb[0] = 'x'; //error! writing a const TextBlock
    
    CTextBlock cctb('H');
    char *pc = &cctb[0];
    //try to modify value in "cctb"
    *pc = 'J';//make argument to "cctb" through const operator[]!
    std::cout << *pc << endl;//output:"J".value changed!
//    cctb.print();
    
    return 0;
}