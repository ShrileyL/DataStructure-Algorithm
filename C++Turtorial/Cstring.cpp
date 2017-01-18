#include <iostream>

#include <string>
using namespace std;

char *mystrcpy(char *dest,const char *str);

char *mystrcat(char *dest, const char *str);

int getStrLen(const char *str);

char* mydelete(char *str, char sub);
char* mydeleteBlock(char* str, int pos, int len);
char* myreplace(const char* str, const char* sub1, const char* sub2, char* out);
const char* mystrstr(const char* str,const char* sub);

int main()
{
//    char s1[]= "Hello";
//    char* s = "Hello";//the same thing with s[]
//    cout << *s1 <<endl;//cout char
//    cout<< s1 << endl;//"cout" string
//    cout << &s1 << endl;//"cout" address of char*
//    
//    cout << *s <<endl;//cout char
//    cout<< s << endl;//"cout" string
//    cout << &s << endl;//"cout" address of char*
    
//    char str1[] = "Kevin";
//    char str2[40] = "Shirley";
//    char str3[20] = " ";
//    cout << mystrcat(str2, str1)<< endl;
//    cout << mystrcpy(str3, str1)<< endl;
//    cout << strcpy(str3, str1)<< endl;//the same with mystrcpy
//    cout << getStrLen(str1)<<endl;
//    cout << getStrLen2(str1)<<endl;
//    cout << mydelete(str2, 'v')<<endl;

    
//    char str[10] = "abcdef";
//    char sub1[] ="cd";
//    char sub2[] = "45";
//    char out[100] = "";
//    cout << strstr(str, sub1)<<endl;
//    cout<<myreplace(str,sub1,sub2,out)<<endl;
    
//    char sstr[]="abcdefg";
//    char* sstr1=sstr;
//    cout<<mydeleteBlock(sstr,1,2)<<endl;
    
    char p[] = "12345";
    char q[] = "23";
    const char* r = mystrstr(p, q);
    cout << r;
    
    return 0;
}

char *mystrcpy(char *dest, const char *str)
{
    if ((dest== NULL)||(str == NULL)) 
    {
        return NULL;
    }//check for valid

    char* temp = dest;
    while ((*dest++ = *str++));//frenquent used assignment in Cstring!
    return temp;
}


char *mystrcat(char *dest, const char *str)
{
    if ((dest== NULL)||(str == NULL)) 
    {
        return NULL;
    }//check for valid

    char *tem = dest;
    while(*dest++);//reach the end of the string
    dest--;//one-step back

    while((*dest++ = *str++));//continue copy str to dest to "/0"
    return tem;
}

int getStrLen(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    int len = 0;
    while(*str++ != '\0')
        len++;

    return len;
}

int getStrLen2(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    const char* temp = str;//declare a const pointer to mark the head
    while(*str++ != '\0');


    return (str-tem-1);
}

char* mydelete(char *str, char sub)
{
    if (str == NULL)
    {
        return NULL;
    }

    char* p = str;
    char* head = p;//&head = (&p)

    
    if (*p) //discuss for first char
    {
        *str++ = *p;
    }
    while(*p++)//something wrong here for the first char never stored!
    {
        //every char not equal sub is part of the new str
        if (*p!=sub)
        {
            *str++ = *p;
        }
    }
    *str ='\0';
    return head;
}

char* mydeleteBlock(char* str, int pos, int len)
{
    if(str==NULL||(pos+len)>strlen(str)||pos<1)
    {
        return NULL;
    }
    char* p=str+pos-1; //point to the being deleted part

    while(*p && *(p+len)) //break until reach the end
    {
        //cover the part from p to p+len by move the back elements forward
        *p=*(p+len);
        p++;
    }

    *p='\0';

    return str;
}

char* myreplace(const char* str, const char* sub1, const char* sub2, char* out)
{
    char* pout = out;
    const char* pstr = str;//tem string to find sun-string
    int len1 = strlen(sub1);
    int len2 = strlen(sub2);

    while(*pstr != 0)
    {
        pstr = strstr(pstr,sub1);
        if(pstr!=NULL)
        {
            memcpy(pout,str,pstr-str);//copy the part before the sub1
            pout+=pstr-str;

            memcpy(pout,sub2,len2); //replace sub1 part with sub2
            pout+=len2;

            pstr+=len1; //prepare for the next movement, move pointer to the original string pass over sub1
            str=pstr;
        }
        else
       {
           //cannot find the sub string
           break;
       }
    }
    *pout='\0';
    if(*str!='\0')
    {
        strcpy(pout,str);
    }
    
    return out;//out
}

const char* mystrstr(const char* str,const char* sub)
{
    if (str==NULL || sub ==NULL)
    {
        return str;
    }

    const char* bp;
    const char* sp;
    while(*str)// loop for str
    {
        bp = str;
        sp = sub;
        do
        {
            if(!*sp)
                return str;//find sub and return str
        }while(*bp++ == *sp++);
        str +=1;
    }
    return NULL;
}