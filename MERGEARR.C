#include<stdio.h>
void enter(int[],int);
void merge(int[],int[],int,int,int[]);
void main()
{
 int a[20],b[20],c[20],i,j,m,n,k;
 clrscr();
 printf("\nEnter the limit of first array:");
 scanf("%d",&n);
 enter(a,n);
 printf("\nEnter the limit of second array:");
 scanf("%d",&m);
 enter(b,m);
 merge(a,b,n,m,c);
 getch();
}
void enter(int a[],int n)
{
  int i;
  printf("\nEnter the elements in sorted order: ");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
}
void merge(int a[],int b[],int n,int m,int c[])
{
 int i=0,j=0,k=0;
 while(i<n && j<m)
 {
   if(a[i]<b[j])
   {
    c[k]=a[i];
    i++;
   }
  else if(a[i]>b[j])
   {
    c[k]=b[j];
    j++;
   }
  else
  {
   c[k]=a[i];
   i++;j++;
   }
   k++;
 }
 while(i<n)
 {
  c[k]=a[i];
  i++;
  k++;
 }
 while(j<m)
 {
  c[k]=b[j];
  j++;
  k++;
 }
 printf("\n\n\tMerged array is:");
 {
  for(i=0;i<k;i++)
    printf(" %d",c[i]);
    }
}