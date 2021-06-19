
        
#include<stdio.h>
// chdir function is declared
// inside this header
#include<unistd.h> 
#include <string.h>
int main()
{   /*
    char s[100];
  
    // printing current working directory
    printf("%s\n", getcwd(s, 100));
  
    // using the command
    chdir("..");
  
    // printing current working directory
    printf("%s\n", getcwd(s, 100));
  
    // after chdir is executed
    return 0;
    */
    /*
    char s[100];
    char puntos[] = "..";
    char path[100];
    strcpy(path,puntos);
    char cwd[100];
    printf("%s\n", getcwd(s, 100));
    if(puntos[0] != '/')
    {// true for the dir in cwd
        getcwd(cwd,sizeof(cwd));
        strcat(cwd,"/");
        strcat(cwd,path);
        printf("por aca");
        chdir(cwd);
    } else {//true for dir w.r.t. /
        chdir(puntos);
    }
    printf("%s\n", getcwd(s, 100));
    return 0;*/
    char *groups;
    getgroups(1000,groups);
    printf("%s", groups);
}