#include <iostream>

#include <string>
using namespace std;
char* strrev1(char* str);
char* strrev2(char* str);
char* strrev3(char* str)

int main(int argc, char const *argv[])
{
	
	return 0;
}

char* strrev1(char* str)
{
	int len = strlen(str);
	char* temp = new char[len+1];
	strcpy(temp,str);
	for (int i = 0; i < len/2; ++i)
	{
		char c = temp[i];
		temp[i] = temp[len - i -1];
		temp[len - i -1] = c;
	}

	return temp;
}

char* strrev2(char* str)
{
    char* tmp = new char[strlen(str)+1];
    strcpy(tmp, str);
    char* ret = tmp;
    char* p = tmp + strlen(str) - 1;
    while(tmp < p)
    {
        swap (*tmp, *p);
        --p;
        ++tmp;
    }
    
    return ret;
}

//recursion
char* strrev3(char* str, int len)
{
	if (len <= 1)
	{
		return str;
	}

    char t = *str;
    *str = *(str + len -1);
    *(str + len - 1) = t;

    return (strrev3(str+1,len - 2)-1);
}

void loopMove(char *str, int n)
{
	char* temp = new[strlen(str) + 1];
	char *p = NULL, *q = str;
	if (;n > 0; n--)
	{
		*temp = *(str+strlen(str)-1);
		p = q;
		while(*p++)
			*temp++ = *p++;
		q = temp;

	}
}