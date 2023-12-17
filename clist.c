#include <stdio.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
void insfr(int x);
void insed(int x);
void insspc(int key, int x);
void deled();
void delfr();
void delspc();
void display();
void main()
{
    int ch, key, x;
    do
    {
        printf("\n1.Insert @front \n2.Insert @rear \n3.Insert @spc \n4.Delete @front \n5.Delete @rear \n6.Delete @specified \n7.Display \n8.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data :");
            scanf("%d", &x);
            insfr(x);
            break;

   /*     case 2:
            printf("Enter the data :");
            scanf("%d", &x);
            insed(x);
            break;

        case 3:
            printf("Enter the search key: \n");
            scanf("%d", &key);
            printf("Enter the data :\n");
            scanf("%d", &x);
            insspc(key, x);
            break;

        case 4:
            delfr();
            break;

        case 5:
            deled();
            break;

        case 6:
            printf("Enter the search key :");
            scanf("%d", &key);
            delspc(head, key);
            break;
*/
        case 7:
            display();
            break;

        case 8:
            printf("Menu is closed \n");
            break;

        default:
            printf("Enter Valid Choice \n");
            break;
        }
    } while (ch != 9);
}
void display()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    // else
    // {
    //     ptr = head;
    //     while (ptr->link != head)
    //     {
    //         printf("%d", &ptr->data);
    //         ptr = ptr->link;
    //     }
    //     printf("%d", &ptr->data);
    // }
            else
        {
                ptr=head;
                printf("Elements are : \n");
                while(ptr->link!=head)
                {
                        printf("%d \t ",ptr->data);
                        ptr=ptr->link;
                }
}
}
void insfr(int x)
{
    struct node *ptr;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->link=NULL;
    if(head==NULL)
    {
        head=new;
        new->link=new;
    }
    else
    {
        ptr=head;
        while (ptr->link!=head)
        {
            ptr=ptr->link;
        }
        new->link=head;
        head=new;
        ptr->link=head;
    }
}