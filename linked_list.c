#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

void create_linked_list(struct node**);
void print_linked_list(struct node*);
void delete_this(int,struct node**);
void insert_beginning(int,struct node**);
void insert_middle(int,struct node*);
void sorted_list(struct node*);
void concatenate(struct node*, struct node*);
int large(struct node*);

main()
{
    struct node* head1,* head2;
    create_linked_list(&head1);
    create_linked_list(&head2);
    delete_this(1,&head1);
    insert_beginning(1,&head1);
    insert_middle(30,head1);
    sorted_list(head1);
    print_linked_list(head1);
    print_linked_list(head2);
    concatenate(head1,head2);
    print_linked_list(head1);
    return 0;
}

int large(struct node *head)
{
    int i=0;
    struct node *t=head;
    while (t!=NULL)
    {
        ++i;
        t=t->next;
    }
    return i;
}

void create_linked_list(struct node** head0)
{
    struct node *head,*prev, *cur;
    int i,a;
    printf("Escriba el largo que tendra la lista: ");
    scanf("%d", &a);
    head = malloc(sizeof(struct node));
    head->val=1;
    *head0=head;
    prev=head;
    for (i=2;i<=a;i++)
    {
        cur = malloc(sizeof(struct node));
        cur->val=i;
        prev->next=cur;
        prev=cur;
    }
    prev->next=NULL;
}

void print_linked_list(struct node* head)
{
    struct node *t;
    t=head;
    while(t!=NULL)
    {
        printf("%d\n",t->val);
        t=t->next;
    }
}

void delete_this(int key, struct node** head0)
{
    struct node *head,*prev, *cur;
    struct node *temp;
    head=*head0;
    if(head->val==key)
    {
        temp=head;
        head=head->next;
        free(temp);
        *head0=head;
        return;
    }
    prev=head;
    cur=head->next;
    while (cur!=NULL)
    {
        if (cur->val==key)
        {
            prev->next=cur->next;
            free(cur);
            break;
        }
        prev=cur;
        cur=cur->next;
    }
}

void insert_beginning(int h, struct node** head0)
{
    struct node *head,*prev, *cur;
    struct node* temp1;
    head=*head0;
    temp1=malloc(sizeof(struct node));
    temp1->next=head;
    temp1->val=h;
    *head0=temp1;
}

void insert_middle(int h, struct node* head)
{
    struct node *prev, *cur;
    int i=0, c=large(head);
    struct node *temp1, *temp2;
    prev=head;
    cur=head->next;
    while(i<c/2)
    {
        prev=cur;
        cur=cur->next;
        ++i;
    }
    temp2=malloc(sizeof(struct node));
    temp2->next=cur;
    prev->next=temp2;
    temp2->val=h;
}

void sorted_list(struct node* head)
{
    struct node *prev, *cur;
    int i,j,temp, c=large(head);
    prev=head;
    cur=head->next;
    for (j=0;j<c-1;j++)
    {
        for (i=0;i<c-j-1;i++)
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
        cur=head->next;
    }
}

void concatenate(struct node *head1, struct node *head2)
{
     struct node* temp;
     temp=head1;
     while(temp->next!=NULL)
        temp=temp->next;
     temp->next=head2;
}
