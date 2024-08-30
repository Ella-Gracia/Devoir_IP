#include "reseau.h"
int main()
{
    char* ip=NULL;
    getdata(&ip);
    verify_ip(ip);
    return 0;
}