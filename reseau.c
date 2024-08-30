#include "reseau.h"
void getdata(char** ip)
{
    int d=255;
    *ip=(char*)malloc(d*sizeof(char));
    printf("Entrer l'IP:");
    scanf("%s",*ip);
}
void verify_ip(char* ip)
{
    int i=0;
    int x1=255;
    int x2=0;
    int n=0;
    int tmp=0;
    int val[4];
    char *t = NULL;
    int point = 0;
    int j;
    for (j = 0; j < strlen(ip); j++)
    {
        if (ip[j] == '.')
        {
            point++;
        }
    }
    if (!strchr(ip, '.') || point != 3)
    {
        printf("ip non valid\n");
        //main();
    }
    else
    {
        t = strtok(ip, ".");
        while (t != NULL)
        {
            if (atoi(t) > 255 || atoi(t) < 0 || strcmp(t, "\[0-9]+?") == 0)
            {
                printf("ip non valid\n");
               // main();
                break;
            }
            else if (atoi(t) == 0 && (!strchr(t, '0') && strlen(t) != 0))
            {
                printf("ip non valid\n");
               // main();
                break;
            }    
            val[i]=atoi(t);
            i++;
            t = strtok(NULL, ".");
        }
        printf("ip valid\n");
    }
        if(val[0]>=0 && val[0]<=127)
        {
            n=24;
            tmp=(pow(2,n)-2);
            printf("ip de classe A\n");
            printf("Nombre de machine: %d\n",tmp);
            printf("Netmask:%d.%d.%d.%d\n",x1,x2,x2,x2);
            printf("@Réseau:%d.%d.%d.%d\n",val[0],x2,x2,x2);
            printf("@Broadcast:%d.%d.%d.%d\n",val[0],x1,x1,x1);
        }
        if(val[0]>=128&& val[0]<=191)
        {
            n=16;
            tmp=(pow(2,n)-2);
            printf("ip de classe B\n");
            printf("Netmask:%d.%d.%d.%d\n",x1,x1,x2,x2);
            printf("@Réseau:%d.%d.%d.%d\n",val[0],val[1],x2,x2);
            printf("@Broadcast:%d.%d.%d.%d\n",val[0],val[1],x1,x1);
        }
        if(val[0]>=192&& val[0]<=223)
        {
            n=8;
            tmp=(pow(2,n)-2);
            printf("ip de classe C\n");
            printf("Netmask:%d.%d.%d.%d\n",x1,x1,x1,x2);
            printf("@Réseau:%d.%d.%d.%d\n",val[0],val[1],val[2],x2);
            printf("@Broadcast:%d.%d.%d.%d\n",val[0],val[1],val[2],x1);
        }
        if(val[0]>=224&& val[0]<=239)
        {
            printf("ip de classe D\n");
        }
        if(val[0]>=240&& val[0]<=255)
        {
            printf("ip de classe E\n");
        }
}