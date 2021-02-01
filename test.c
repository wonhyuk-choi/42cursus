#include "stdio.h"
int main(void)
{
    int nul;
    char c;
    
    c = '\0';
    nul = !c;
    printf ("%d",nul);
    return (0);
}
