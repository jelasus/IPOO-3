#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
}*head,*prev,*cur;

void create_linked_list(int);
void print_linked_list(int);
void delete_this(int);
void insert_beginning(int);
void insert_middle(int,int);
void sorted_list(int);
void aumentar(void);

int n;

main()
{
    printf("Escriba el largo que tendra la lista: ");
    scanf("%d\n", &n);
    create_linked_list(n);
    delete_this(1);
    insert_beginning(1);
    insert_middle(n,30);
    printf("---%d---\n", n);
    sorted_list(n);
    print_linked_list(n);
    return 0;
}

void create_linked_list(int n)
{
    int i;
    head = malloc(sizeof(struct node));
    head->val=1;
    prev=head;
    for (i=2;i<=n;i++)
    {
        cur = malloc(sizeof(struct node));
        cur->val=i;
        prev->next=cur;
        prev=cur;
    }
    prev->next=NULL;
}

void print_linked_list(int n)
{
    struct node *t;
    t=head;
    while(t!=NULL)
    {
        printf("%d\n",t->val);
        t=t->next;
    }
}


void delete_this(int key)
{
    struct node *temp;
    if(head->val==key)
    {
        --n;
        temp=head;
        head=head->next;
        free(temp);
    }
    prev=head;
    cur=head->next;
    while (cur!=NULL)
    {
        if (cur->val==key)
        {
            --n;
            prev->next=cur->next;
            free(cur);
            break;
        }
        prev=cur;
        cur=cur->next;
    }
}

void insert_beginning(int h)
{
    struct node* temp1;
    temp1=malloc(sizeof(struct node));
    temp1->next=head;
    temp1->val=h;
    head=temp1;
    ++n;
}

void insert_middle(int n,int h)
{
    int i;
    struct node *temp1, *temp2;
    prev=head;
    cur=head->next;
    while(i<n/2)
    {
        prev=cur;
        cur=cur->next;
        i++;
    }
    temp2=malloc(sizeof(struct node));
    temp2->next=cur;
    prev->next=temp2;
    temp2->val=h;
    aumentar();
}

void aumentar(void)
{
    ++n;
}

void sorted_list(int n)
{
    int i,j,temp;
    prev=head;
    cur=head->next;
    for (j=0;j<n-1;j++)
    {
        for (i=0;i<n-j-1;i++)
        {
            if (prev->val > cur->val)
            {
                temp=prev->val;
                prev->val=cur->val;
                cur->val=temp;
            }
            prev=cur;
            cur=cur->next;
        }
        prev=head;
    }
}

void concatenate(int a, int b)
{
    while (temp2!=NULL)
        temp1=temp2;
        temp2=temp2->next;
    temp2->next=temp3;
    temp4=temp3
    while (temp4!=NULL)
        temp1=temp4;
        temp1=temp2;
        temp2=temp2->next;
        temp4=temp5;
        temp5=temp5->next;

}
