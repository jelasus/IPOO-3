#include <stdio.h>
#define MAX 100

void strca(char *s, char *t)
{
    while (*s)
        *++s;
    while ((*s=*t) != '\0')
    {
        *++s;
        *++t;
    }
}
main()
{
    char a[MAX]="Hola";
    char b[MAX]=" Mundo";
    strca(a,b);
    printf("%s", a);
    return 0;
}
