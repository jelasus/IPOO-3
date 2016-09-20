#include <stdio.h>

//A=65 01000001
//a=97 01100001
char converter(char s)
{
    if ('a'<=s && s<='z')
        s=s^32;
    else if ('A'<=s && s<='Z')
        s=s|32;
    return s;
}
 main()
{
    int c;
    while((c=getchar())!=EOF)
    {
        putchar(converter(c));
    }
    return 0;
}
