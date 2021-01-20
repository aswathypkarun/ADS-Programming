#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*link;
};
struct node *TOP=NULL;
void push()
{
 struct node *ne=(struct node*)malloc(sizeof(struct node));
 if(ne==NULL)
 {
  printf("\nOut of memory");
  return;
 }
 printf("\nEnter the element to push: ");
 scanf("%d",&ne->data);
 ne->link=TOP;
 TOP=ne;
}
void pop()
{
 struct node *ptr;
 if(TOP==NULL)
 {
  printf("\nStack is empty");
  return;
  }
 printf("\nPoped element is %d",TOP->data);
 ptr=TOP;
 TOP=TOP->link;
 free(ptr);
}
void search()
{
 struct node *ptr;
 int x,pos=1;
 if(TOP==NULL)
 {
  printf("\nStack is empty");
  return;
 }
 ptr=TOP;
 printf("\nEnter the element to be searched:");
 scanf("%d",&x);
 while(ptr!=NULL)
 {
  if(ptr->data==x)
  {
    printf("\nElement found at %d position from top ",pos);
    break;
  }
 ptr=ptr->link;
 pos++;
 }
 if(ptr==NULL)
  printf("\nElement not found");
}
void display()
{
 struct node *ptr=TOP;
 if(TOP==NULL)
 {
  printf("\nStack is empty");
  return;
 }
 ptr=TOP;
 printf("\nThe elements are:");
 while(ptr!=NULL)
 {
  printf("\t%d",ptr->data);
  ptr=ptr->link;
 }
}
void main()
{
 int ch=0;
 clrscr();
 while(ch!=5)
 {
  printf("\n\t\tMenu\n1.PUSH\n2.POP\n3.SEARCH\n4.DISPLAY\n5.EXIT");
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:push();
	  break;
   case 2:pop();
	  break;
   case 3:search();
	  break;
   case 4:display();
	  break;
   case 5:printf("\nExit from loop");
	  exit(0);
  }
 }
}