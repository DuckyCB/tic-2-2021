#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 100
#define MAXWORD 100

int line = 1;

struct tnode {
    char *word;
    char lines[MAXWORD];
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    
    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]))
            root = addtree(root, word);
        treeprint(root);
        return 0;    
}

struct tnode *talloc(void);
char *my_strdup(char *);
struct tnode *addtree(struct tnode *p, char *w){
    int cond;
    char lin[5];
    sprintf(lin,"%d", line);
    if(p==NULL) {
        p = talloc();
        p->word = my_strdup(w);
        strcat(p->lines,lin);
        p->left = p->right = NULL;
    }else if ((cond = strcmp(w, p->word)) == 0){
        strcat(p->lines,", ");
        strcat(p->lines,lin);
    }
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w); 
    else /* greater than into right subtree */ 
        p->right = addtree(p->right, w);
    return p;
}


void treeprint(struct tnode *p)
{
    if(p != NULL){
        treeprint(p->left);
        printf("    %s [%s]\n", p->word, p->lines);
        treeprint(p->right);
    }
}


struct tnode *talloc(void)
{
    return(struct tnode  *) malloc(sizeof(struct tnode));
}

char *my_strdup(char *s){
    char *p;
    p= (char *) malloc(strlen(s)+1);
    if(p!= NULL)
        strcpy(p,s);
    return p;    
}


char buf[BUFSIZE];
int bufp=0;

int getch(void)
{
        return(bufp>0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if(bufp>= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}

int getword(char *word, int lim){
    int c, getch();
    void ungetch(int);
    char *w = word;

    while (isspace(c=getch())){
        if (c == '\n'){
            line++;
        }
    }

    if(c != EOF){
        *w++=c;
    }

    if(!isalpha(c)) {
        *w = '\0';
    
        return c;
    }

    for( ; --lim >0; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}