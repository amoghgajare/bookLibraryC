#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
char title[50];
char author[50];
int id;
};
struct user
{
char name[50];
int id
};
int main()
{
    struct book x;
    struct user users;
    int m,p,i,j,n=0;
    char ch;
    FILE *books,*hist,*status,*user;
    hist=fopen("history.txt","a");
    fprintf(hist,"\n________________________________________________________________________________________\nSession Start\n");
    fclose(hist);
    //Infinite loop
    while(1){
    //Menu___________________________________________________________________________________________________________________________________________________________________
    printf("Welcome to Library\n\nMenu (Enter number of menu item)\n\n1) Add book\n2) Register a user\n3) Lend/Return the book\n4) Exit\n\n");
    //Taking a choice from the user
    scanf("%d",&m);
    //Counter
    n=n+1;
    //Action for invalid input and respective cases
    //Invalid input for first attempt
    if(((m!=1)&&(m!=2)&&(m!=3)&&(m!=4))&&(n==1))
    {
    n=n-1;
    hist=fopen("history.txt","a");
    fprintf(hist,"\n%d processes were done in total\nSession End\n________________________________________________________________________________________",n);
    fseek(hist, 0, SEEK_SET);
    fclose(hist);
    printf("\nInvalid Input\nEnding the program execution...\nProgram has ended.Start a new session to continue\n");
    return 0;
    }
    //Invalid input in other than first attempt
    if(((m!=1)&&(m!=2)&&(m!=3)&&(m!=4))&&(n!=1)&&(n!=0))
    {
    hist=fopen("history.txt","a");
    fprintf(hist,"\n%d processes were done in total\nSession End\n________________________________________________________________________________________",n-1);
    fseek(hist, 0, SEEK_SET);
    fclose(hist);
    printf("\nInvalid Input\n%d processes were done in the session\n",n-1);
    printf("Ending the program execution...\nProgram has ended\nStart a new session to continue\n");
    return 0;
    }
    //Adding a book_______________________________________________________________________________________________________________________________________________________
    if(m==1){
    books=fopen("booklist.txt","a");
    hist=fopen("history.txt","a");
    x.id=0;
    printf("Use '_' (Underscore) instead of blank spaces\n\n");
    printf("Enter name of title : ");
    scanf("%s",x.title);
    printf("Enter name of author : ");
   scanf("%s",x.author);
   //Book ID Algorithm
   for (i=0;i<strlen(x.title);i++)
   {
    x.id=x.id+((i+1)*(int)x.title[i]);
   }
   for (i=0;i<strlen(x.author);i++)
   {
    x.id=x.id+((i+3)*(int)x.author[i]);
   }
    printf("Book ID is %d\n\n",x.id);
    //File Storage
    fprintf(hist,"Added book with ID %d\n",x.id );
    fprintf(books,"%d\t%s\t\t%s\n",x.id,x.title,x.author );
    fclose(hist);
    fclose(books);
    }
    //Register a user_________________________________________________________________________________________________________________________
    else if(m==2)
    {
    hist=fopen("history.txt","a");
    user=fopen("users.txt","a");
    users.id=0;
    printf("Use '_' (Underscore) instead of blank spaces\n\n");
    printf("Enter name of user : ");
    scanf("%s",users.name);
    //User ID Algorithm
    for (i=0;i<strlen(users.name);i++)
   {
    users.id=users.id+((i+3)*(i+2)*(i+1)*(int)users.name[i]);
   }
   printf("User ID is %d\n\n",users.id);
    //File Storage
    fprintf(hist,"Added user with ID %d\n",users.id );
    fprintf(user,"%d\t%s\n\n",users.id,users.name);
    fclose(hist);
    fclose(user);
    }
    //Exiting the program__________________________________________________________________________________________________________________________
    else if(m==4){
            hist=fopen("history.txt","a");
            fprintf(hist,"\n%d processes were done in total\nSession End\n________________________________________________________________________________________",n-1);
            fseek(hist, 0, SEEK_SET);
            fclose(hist);
            printf("\n%d processes were done in the session\n",n-1);
            return 0;}
    }
    return 0;
}
