#include<stdio.h>
#include<stdlib.h>
struct node
{
 struct node *left;
 int data;
 struct node *right;
};
struct node *head=NULL;
struct node *GetNode();
void insertlast();
void insertfirst();
void disp();
void search();
void insertpos();
void delfirst();
void dellast();
void delpos();
void main()
{
  int opt=0;
  clrscr();
  while(opt!=9)
  {
    printf("\n\t\tMENU\n1.INSERT FIRST\n2.INSERT LAST\n3.INSERT AT POSITION\n4.DELETE FIRST\n5.DELETE LAST\n6.DELETE AT POSITION\n7.SEARCH\n8.DISPLAY\n9.EXIT\nEnter your choice:");
    scanf("%d",&opt);
    switch(opt)
    {
     case 1:insertfirst();
	    break;
     case 2:insertlast();
	    break;
     case 3:insertpos();
	    break;
     case 4:delfirst();
	    break;
     case 5:dellast();
	    break;
     case 6:delpos();
	    break;
     case 7:search();
	    break;
     case 8:disp();
	    break;
     case 9:exit(0);
	    break;
    }
  }
 getch();
}
void disp()
{
 struct node *ptr=head;
 if(head==NULL)
 {
  printf("\nList Empty");
  return;
 }
 printf("\nThe elements are:");
 while(ptr!=NULL)
 {
  printf("%d\t",ptr->data);
  ptr=ptr->right;
 }
}
struct node *GetNode()
{
 int x;
 struct node *ne=(struct node*)malloc(sizeof(struct node));
 if(ne==NULL)
   printf("\nInsufficient memory");
 else
 {
  printf("\nEnter the value to insert:");
  scanf("%d",&x);
  ne->left=NULL;
  ne->right=NULL;
  ne->data=x;
 }
 return ne;
}
void insertfirst()
{
 struct node *ne;
 ne=GetNode();
 if(ne==NULL)
   return;
 if(head==NULL)
   head=ne;
 else
 {
  head->left=ne;
  ne->right=head;
  head=ne;
 }
 disp();
}
void insertlast()
{
 struct node *ne,*ptr;
 ne=GetNode();
 if(ne==NULL)
   return;
 if(head==NULL)
   head=ne;
 else
 {
  ptr=head;
  while(ptr->right!=NULL)
  {
  ptr=ptr->right;
  }
  ptr->right=ne;
  ne->left=ptr;
 }
 disp();
}
void insertpos()
{
 int value;
 struct node *ne,*ptr,*ptr1;
 ne=GetNode();
 if(ne==NULL)
   return;
 if(head==NULL)
 {
  printf("\nList is empty,so the node is inserted as the first node");
   head=ne;
   return;
   }
 printf("\nEnter the key value after which the node has to be inserted:\n");
 scanf("%d",&value);
 ptr=head;
 while(ptr->right!=NULL && ptr->data!=value)
 {
  ptr=ptr->right;
 }
 if(ptr->right==NULL)
 {
  ptr->right=ne;
  ne->left=ptr;
  printf("\nNode is inserted at the last position");
 }
 else
 {
  ptr1=ptr->right;
  ne->right=ptr1;
  ne->left=ptr;
  ptr->right=ne;
  ptr1->left=ne;
 }
 printf("\nElement is inserted");
 disp();
}
void delfirst()
{
 struct node *ptr;
 if(head==NULL)
 {
  printf("\nList is empty");
  return;
 }
 ptr=head;
 head=head->right;
 if(head!=NULL)
   head->left=NULL;
   free(ptr);
   disp();
}
void dellast()
{
 struct node *ptr,*prev;
 if(head==NULL)
 {
  printf("\nList is empty");
  return;
  }
  if(head->right==NULL)
  {
   free(head);
   head=NULL;
  }
  ptr=head->right;
  while(ptr->right!=NULL)
  {
   ptr=ptr->right;
  }
  prev=ptr->left;
  prev->right=NULL;
  free(ptr);
  disp();
}
void delpos()
{
 struct node *ptr,*prev,*next;
 int x;
 if(head==NULL)
 {
  printf("\nList is empty");
  return;
  }
 printf("\nEnter the element to delete:");
 scanf("%d",&x);
 if(head->data==x)
 {
  ptr=head;
  head=ptr->right;
  if(head!=NULL)
  {
   head->left=NULL;
   }
   free(ptr);
   return;
  }
 ptr=head;
 while(ptr->data!=x&&ptr->right!=NULL)
 {
   ptr=ptr->right;
 }
 if(ptr->data==x)
 {
  next=ptr->right;
  prev=ptr->left;
  prev->right=ptr->right;
   if(next!=NULL)
     next->left=ptr->left;
    free(ptr);
    return;
 }
 printf("\nElement not present in the list");
 }
void search()
{
 struct node *ptr;
 int x;
 if(head==NULL)
 {
  printf("\nLinked List Empty");
  return;
 }
 printf("\nEnter the element to search:");
 scanf("%d",&x);
 ptr=head;
 while(ptr!=NULL)
 {
   if(ptr->data==x)
   {
    printf("\nElement present in the list");
    break;
   }
  ptr=ptr->right;
 }
if(ptr==NULL)
  printf("\nElement not in the list");
}