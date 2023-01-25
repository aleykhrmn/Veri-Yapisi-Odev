#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char firstname[20];
    char lastname[20];
    char number[15];
    char eposta[50];
    struct node *next;
};

struct node *start=NULL;

struct node *getnode()
{
    return((struct node *)malloc(sizeof(struct node)));
} 
void display(struct node *start)
{
    struct node *temp;
    temp=start;
    if(temp==NULL){
      printf("The phonebook is empty.\n");
    }
    while(temp!=NULL)
    {
        printf("--------------\n");      
        printf("firstname: %s\n",temp->firstname);
        printf("lastname : %s\n",temp->lastname);
        printf("number   : %s\n",temp->number);
        printf("eposta   : %s\n",temp->eposta);  
        printf("---------------\n");
        temp=temp->next;
    }
}
void insert()
{
    struct node *temp,*nn;
    nn=getnode();
    temp=start;  
    while(temp->next!=NULL)
    {
        temp=temp->next;
        
    }
    printf("---------------\n");  
    printf("Enter First name:\n");
    scanf("%s",&nn->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&nn->lastname);
    printf("Enter number:\n");
    scanf("%s",&nn->number);
    printf("Enter e posta:\n");
    scanf("%s",&nn->eposta);
    temp->next=nn;
    nn->next=NULL;
    display(start);
}

struct node *create()
{
    struct node *temp,*nn;
    if(start!=NULL)
        insert();
    else
    {
    nn=getnode();
    start=nn;
    temp=start;  
    printf("----------------\n");   
    printf("Enter First name:\n");
    scanf("%s",&nn->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&nn->lastname);
    printf("Enter number:\n");
    scanf("%s",&nn->number);
    printf("Enter e posta:\n");
    scanf("%s",&nn->eposta);         
    nn->next=NULL;
    display(start);
    }
}
void del()
{
    struct node *pretemp,*temp;
    char *f,*l;
    temp=start;
    pretemp=start->next;
    printf("----------------\n");  
    printf("Enter firstname : \n");
    scanf("%s",&f);
    printf("Enter lastname : \n");
    scanf("%s",&l);
    while(temp!=NULL)
    {
        if((pretemp->firstname==f)&&(pretemp->lastname==l))
        {
            temp->next=pretemp->next;
            free(pretemp);
            break;
        }
        else 
        {
            temp=temp->next;
            pretemp=pretemp->next;
        }
    }
    display(start);  
}
void search()
{
    struct node *temp;
    char *f,*l;
    temp=start;
    printf("Enter firstname to be searched:\n");
    scanf("%s",&f);
    printf("Enter lastname to be searched:\n");  
    scanf("%s",&l);
    while(temp!=NULL){
      if((temp->firstname==f)&&(temp->lastname==l)){
        printf("%s\n",temp->firstname);
        printf("%s\n",temp->lastname);
        printf("%s\n",temp->number);
        printf("%s\n",temp->eposta);
      }
      temp=temp->next;
    }
}
int main()
{
    int op,ch;
    do{
        printf("           --------Welcome--------\n");
        printf("1.Create\n2.Insert\n3.Display\n4.Delete\n5.Search\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        if(!(ch>0&&ch<6)){
          printf("INVALID VALUE.\n");
        }
        switch(ch)
        {
            case 1: create();
            break;
            case 2: insert();
            break;        
            case 3: display(start);
            break;
            case 4: del();
            break; 
            case 5: search();
            break;           
        }
        printf("Do you want to continue ? 1 for yes / 0 for no:");
        scanf("%d",&op);
        if(!(op==0||op==1)){
          printf("INVALID VALUE.\n");
          printf("Do you want to continue ? 1 for yes / 0 for no:");
          scanf("%d",&op);
        }
    }while(op!=0);
return 0;
}
