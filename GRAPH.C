#include<stdio.h>
#include<conio.h>
void insert_vertex(char);
void delete_vertex(char);
void delvertex_edge(char);
void insert_edge(char,char);
void display();
struct vertex
{
 struct vertex *next;
 char data;
 struct edge *adj;
}*first='\0',*p;
struct edge
{
 char dest;
 struct edge *link;
};
struct vertex* find_vertex(char);
main()
{
 int choice;
 char x,origin,destin;
 clrscr();
 while(1)
 {
  printf("1.Insert vertex\n2.Insert Edge\n3.Delete vertex\n4.Find vertex\n5.Display\n6.Exit");
  printf("Enter your choice ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:printf("enter a vertex to be inserted");
	  fflush(stdin);
	  scanf("%c",&x);
	  insert_vertex(x);
	  break;
   case 2:printf("enter an edge to be inserted ");
	  fflush(stdin);
	  scanf("%c%c",&origin,&destin);
	  break;
   case 3:printf("enter a vertex to be deleted");
	  fflush(stdin);
	  scanf("%c",&x);
	  delete_vertex(x);
	  break;
   case 4:printf("enter a vertex to find");
	  fflush(stdin);
	  scanf("%c",&x);
	  p=find_vertex(x);
	  if(p=='\0')
	   printf("\nvertex not found ");
	  else
	   printf("\nvertex %c found",p->data);
	  break;
   case 5:display();
	  break;
   case 6:exit();
  }
 }
}
void insert_vertex(char x)
{
 struct vertex *temp,*newnode;
 newnode=(struct vertex*)malloc(sizeof(struct node*));
 newnode->data=x;
 newnode->next='\0';
 newnode->adj='\0';
 if(first=='\0')
 {
  first=newnode;
  return;
 }
 temp=first;
 while(temp->next!='\0')
  temp=temp->next;
 temp->next=newnode;
}
void delete_vertex(char x)
{
 struct vertex *temp,*ptr;
 if(first->data==x)
 {
  temp=first;
  first=first->next;
  free(temp);
  return;
 }
 temp=first;
 while(temp->next!='\0')
 {
  if(temp->next->data==x)
  {
   ptr=temp->next;
   temp->next=ptr->next;
   free(ptr);
   return;
  }
  temp=temp->next;
 }
 if(temp->next->data==x)
 {
  ptr=temp->next;
  temp->next=ptr->next;
  free(ptr);
  temp->next='\0';
 }
}
void delvertex_edge(char x)
{
 struct vertex *temp;
 struct edge *ptr,*temp1;
 temp=first;
 while(temp!='\0')
 {
  if(temp->adj->data==x)
  {
   temp=temp->adj;
   temp->adj=temp->adj->link;
   free(temp);
  }
  temp1=temp->adj;
  while(temp1->link->link!='\0')
  {
   if((temp->link)->dest==x)
   {
    ptr=temp->link;
    temp1->link=ptr->link;
    free(ptr);
   }
   temp1=temp1->link;
  }
  if((temp->link)->dest==x)
  {
   ptr=temp1->link;
   free(ptr);
   temp1->link='\0';
  }
  temp=temp->next;
 }
}
void insert_edge(char s,char d)
{
 struct vertex *locs,*locd;
 struct edge *newnode,*temp;
 locs=find_vertex(s);
 newnode=(struct edge*)malloc(sizeof(struct edge*));
 newnode->dest=d;
 newnode->link='\0';
 if(locs->adj=='\0')
 {
  locs->adj=newnode;
  return;
 }
 temp=locs->adj;
 while(temp->link!='\0')
  temp=temp->link;
 temp->link=newnode;
}
struct vertex* find_vertex(char x)
{
 struct vertex *temp,*loc='\0';
 temp=first;
 while(temp!='\0')
 {
  if(temp->data==x)
  {
   loc=temp;
   return loc;
  }
  else
   temp=temp->next;
 }
 return loc;
}
void display()
{
 struct vertex *temp;
 struct edge *temp1;
 temp=first;
 while(temp!='\0')
 {
  printf("%c->",temp->data);
  temp1=temp->adj;
  while(temp!='\0')
  {
   printf("%c->",temp->data);
   temp1=temp1->link;
  }
  printf("\n");
  temp=temp->next;
 }
}
