#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *Llink,*Rlink;
};
struct node *head=NULL;
void insfr(int x);
void insed(int x);
void insspc(int key,int x);
void delfr();
void deled();
void delspc();
void display();
int isful();
void search();
void main()
{
        int ch,key,x;
        do
        {
                printf("\n1.Insert @front \n2.Insert @rear \n3.Insert @spc \n4.Delete @front \n5.Delete @rear \n6.Delete @specified \n7.Display \n8.Search \n9.Exit\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:
                                printf("Enter the data :");
                                scanf("%d",&x);
                                insfr(x);
                                break;

                        case 2:
                                printf("Enter the data :");
                                scanf("%d",&x);
                                insed(x);
                                break;

                        case 3:
                                printf("Enter the search key: \n");
                                scanf("%d",&key);
                                printf("Enter the data :\n");
                                scanf("%d",&x);
                                insspc(key,x);
                                break;

                        case 4:
                                delfr();
                                break;

                        case 5:
                                deled();
                                break;

                        case 6:
                                printf("Enter the search key :");
                                scanf("%d",&key);
                                delspc(head,key);
                                break;

                        case 7:
                                display();
                                break;
                        
                        case 8: 
                                printf("Enter the search key :\n");
                                scanf("%d",&key);
                                search(head,key);
                                break;

                        case 9:
                                printf("Menu is closed \n");
                                break;

                        default:
                                printf("Enter Valid Choice \n");
                                break;
                }
        }while(ch!=9);
}
int isempty()
{
        if(head==NULL)
                return 1;
        else
                return 0;
}
void insfr( int x)
{
        struct node *new;
        new=(struct node*) malloc(sizeof(struct node));
        new -> data=x;
        new -> Llink=new -> Rlink = NULL;
        if(isempty()==1)
        {
                head=new;
        }
        else
        {
                new -> Rlink =head;
                head -> Llink=new;
                head=new;
        }
}
void insed(int x)
{
        struct node *new;
        struct node *ptr;
        new=(struct node*) malloc(sizeof(struct node));
        new -> data=x;
        new -> Llink=new -> Rlink = NULL;
        if(isempty()==1)
        {
                head=new;
        }
        else
        {
                ptr=head;
 while(ptr->Rlink!=NULL)
                {
                        ptr=ptr->Rlink;
                }
                ptr->Rlink=new;
                new->Llink=ptr;
        }
}
void insspc(int key, int x)
{
        struct node *new;
        struct node *ptr;
        new=(struct node*) malloc(sizeof(struct node));
        new -> data=x;
        new -> Llink=new -> Rlink = NULL;
        if(isempty()==1)
        {
                printf("Operation not possible \n");
        }
        else
        {
                ptr=head;
                while(ptr->data!=key && ptr->Rlink!=NULL)
                {
                        ptr=ptr->Rlink;
                }
                if(ptr->data!=key)
                {
                        printf("Search not found insertion not possible\n");
                }
                else
                {
                        new->data=x;
                        new->Llink=ptr;
                        new->Rlink=ptr->Rlink;
                        if(new->Rlink!=NULL)
                        {
                                new->Rlink->Llink=new;
                        }
                        ptr->Rlink=new;
                }
        }
}
void delfr()
{
        int temp;
        if(isempty()==1)
        {
                printf("List is empty \n");
        }
        else if(head->Rlink==NULL)
        {
                temp=head;
                head=NULL;
                free(temp);
        }
        else
        {
                head=head->Rlink;
                free(head->Llink);
                head->Llink=NULL;
        }
}
void deled()
{
        struct node *ptr;
        int temp;
        if(isempty()==1)
        {
                printf("List empty");
        }
        else if(head->Rlink==NULL)
        {
                temp=head;
                head=NULL;
                free(temp);
        }
        else
        {
                ptr=head;
                while(ptr->Rlink!=NULL)
                {
                        ptr=ptr->Rlink;
                }
                ptr->Llink->Rlink=NULL;
                free(ptr);
        }
}
void delspc(struct node *head,int key)
{
        int temp;
        struct node *ptr;
        if(isempty()==1)
        {
                printf("Operation not possible \n");
        }
        else if(head->Rlink=NULL)
        {
                if(head->data=key)
                {
                        temp=head;
                        head=NULL;
                        free(temp);
                }
                else
                {
                        printf("Search not found insertion not possible\n");
                }
        }
        else if(head->data=key)
        {
                        head=head->Rlink;
                        free(head->Llink); 
                        head->Llink=NULL;
        }
        else
        {
                ptr=head;
                while(ptr->data!=key && ptr->Rlink!=NULL)
                {
                        ptr=ptr->Rlink;
                }
                if(ptr->data!=key)
                {
                        printf("Search data found \n");
                }
                else
                {
                        ptr->Llink->Rlink=ptr->Rlink;
                        if(ptr->Rlink!=NULL)
                        {
                                ptr->Rlink->Llink=ptr->Llink;
                        }
                        free(ptr);
                }
        }
}
void search(struct node *head,int key)
{
        struct node *ptr;
        if (head==NULL)
        {
                printf("\nThe list is empty.\n");
        }
        else
        {
                ptr=head;
                while(ptr->data!=key && ptr->Rlink!=NULL)
                {
                        ptr=ptr->Rlink;
                }
                if(ptr->data==key)
                {
                        printf("Search data found \n");
                }
                else{
                        printf("Search data not found \n");
                }
        }
        
}
void display()
{
        struct node *ptr;
        if(head==NULL)
        {
                printf("List is empty");
        }
        else
        {
                ptr=head;
                printf("Elements are : \n");
                while(ptr!=NULL)
                {
                        printf("%d \t ",ptr->data);
                        ptr=ptr->Rlink;
                }
        }
}


