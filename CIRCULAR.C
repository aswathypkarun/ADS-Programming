#include<stdio.h>
int front=-1,rear=-1,q[10],max=5,sz;
void insert(int q[])
{
  int num;
  if(front==(rear+1)%max)
  {
   printf("\nQueue is full.");
   return;
  }
  else
  {
  printf("\nEnter the element to insert:");
  scanf("%d",&num);
  if(front==-1)
   front=rear=0;
  else
   rear=(rear+1)%max;
   q[rear]=num;
  }
 return;
}
void delete(int q[])
{
 int num;
  if(front==-1)
  {
   printf("\nQueue is empty.");
   return;
  }
  else
  {
  num=q[front];
  printf("\nDeleted Element is %d",num);
  if(front==rear)
    front=rear=-1;
  else
  front=(front+1)%max;
  }
  return;
}
void search(int q[])
{
 int x,f,pos;
 printf("\nEnter the element to be searched:");
 scanf("%d",&x);
 if(front==-1)
 {
  printf("\nQueue is empty");
  return;
   }

  f=front;
  pos=1;
  while(1)
  {
    if(q[f]==x)
    {
     printf("\nElement found location at %d",pos);
     break;
    }
   if(f==rear)
   {
    printf("\nElement not found");
    break;
   }
 f=(f+1)%max;
 pos=pos+1;
 }
 }
void display(int q[])
{
  int i=0;
  if(front==-1)
  {
    printf("\nQueue is empty");
    return;
    }
  else
  {
   printf("\nThe status of the queue:");
   for(i=front;i<=rear;i++)
   {
    printf(" %d",q[i]);
   }
  }
   if(front>rear)
   {
    for(i=front;i<max;i++)
    {
    printf(" %d",q[i]);
    }
   for(i=0;i<=rear;i++)
   {
    printf(" %d",q[i]);
    }
  }
}
void main()
{
 int ch;
 clrscr();
 while(1)
 {
  printf("\n\tMENU");
  printf("\n\n1.INSERT\n2.DELETE\n3.SEARCH\n4.DISPLAY\n5.EXIT");
  printf("\n Enter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:insert(q);
	   break;
    case 2:delete(q);
	   break;
    case 3:search(q);
	   break;
    case 4:display(q);
	   break;
    case 5:printf("\nExit");
	   exit();
  }
 }
}