#include <stdio.h>

int stren(char *s, char *t)
{
    char *q=t;
    char *p=s;
    while (*q != '\0')
        *++q;
    while (*p != '\0')
        *++p;
    int len;
    len=(t-q)-(s-p);
    while (--len!=0)
        *++s;
    *++s;
    while (*s!='\0')
    {
        if (*s!=*t)
            return 0;
        *++s;
        *++t;
    }
    return 1;
}
main()
{
    char a[100]="ooioo";
    char b[100]="iooi";
    printf("%d", stren(a,b));
}
