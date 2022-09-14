#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *root;


void append();
void addBegin();
void display();
void search();
int length();
void deleteBegin();
void deleteEnd();
int main()
{
    int choice;
    while (1)
    {
        printf("1.Append\n");
        printf("2.Add Begin\n");
        printf("3.Display\n");
        printf("4.Search\n");
        printf("5.Length\n");
        printf("6.Delete Begin\n");
        printf("7.Delete End\n");
        printf("8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            append();
            break;
        case 2:
            addBegin();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            printf("%d\n",length());
            break;
        case 6:
            deleteBegin();
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

    }
    
    return 0;
}

void append()
{
    struct node *temp,*p;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d",&temp->data);
    if (root==NULL)
    {
        root = temp;
        temp->right=root;
        temp->left=root;
    }
    else
    {
        p=root;
        while (p->right!=root)
        {
            p=p->right;
        }
        p->right=temp;
        temp->left = p;
        root->left=temp;
        temp->right=root;
        
    }   
}

void addBegin()
{
    struct node *temp,*p;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    if (root==NULL)
    {
        root=temp;
        temp->right=root;
        temp->left=root;
    }
    else
    {
        p=root;
        while (p!=root)
        {
           p = p->right;
        }
        p->right=temp;
        temp->left=p;
        root->left = temp;
        root=temp; 
    }
    
    
}

void display()
{
    struct node *p=root;
    if (root==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        do
        {
            p=p->right;
            printf("%d-->\n",p->data);
        } while (p!=root);    
    }  
}

void search()
{
    struct node *p = root;
    if (root == NULL)
    {
        printf("%d\n",length());
    }
    else
    {
        int n,flag=0;
        printf("Enter element for search: ");
        scanf("%d",&n);
        do
        {
            if (p->data == n)
            {
                flag=1;
                break;
            }
            
        } while (p!=root);

        if (flag!=0)
        {
            printf("Found element\n");
        }
        else
        {
            printf("Not found element\n");
        }    
    }
}

int length()
{
    struct node *p=root;
    int count=0;
    if (root==NULL)
    {
        return count;
    }
    else
    {
        do
        {
            count++;
            p=p->right;
        } while (p!=root);
        return count; 
    }
    
    
}

void deleteBegin()
{
    struct node *node,*p;
    if (root == NULL)
    {
        printf("List is empty");
    }
    else if (root->right==root)
    {
        root=NULL;
        free(root);
        printf("Node deleted\n");
    }
    else
    {
        p=root;
        while (p->right!=root)
        {
           p = p->right;
        }
        p->right=root->right;
        root->right->left=p;
        free(root);
        printf("Node deleted successfully\n");  
    }  
}

void deleteEnd()
{
    struct node *p;
    if (root==NULL)
    {
        printf("List is empty");
    }
    else if (root->right==root)
    {
        root=NULL;
        free(root);
        printf("Node deleted\n");
    }
    else
    {
        p=root;
        if (p->right!=root)
        {
            p=p->right;
        }
        p->left->right=root;
        root->left=p->left;
        free(p);
        printf("Node deleted successfully\n");    
    }   
}