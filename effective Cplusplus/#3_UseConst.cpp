
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
	CTextBlock(char p){pText = *p;}
	char& operator[](std::size_t position) const
	{return pText[position];}
	void print(std::size_t position){std::cout << pText[position];}


private:
	char *pText;
};

int main(int argc, char const *argv[])
{
	TextBlock tb("Hello");

	std::cout << tb[0];

	const TextBlock ctb("World");

	std::cout << ctb[0];

	tb[0] = 'x';

	//ctb[0] = 'x'; //error! writing a const TextBlock

	CTextBlock cctb('H');
	char *pc = &cctb[0];

	*pc = 'J';
	cctb.print();

	return 0;
}