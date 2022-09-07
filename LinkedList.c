#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *HEAD;

void insertatbegin();
void insertatlast();
void insertrandom();
void deleteatbegin();
void deleteatlast();
void deleterandom();
void print();
void main()
{
  int choice=0;
  while(choice != 8)
  {
      printf("\n1.Insert at beginning\n2.Insertion at last\n3.Insertion at middle \n4.Delete at beginning\n5.Delete at last\n6.Delete at middle\n7.Display\n8.Exit\n");
      printf("\nEnter your choice?\n");
      scanf("\n%d",&choice);
      switch(choice)
      {
          case 1:
          insertatbegin();
          break;
          case 2:
          insertatlast();
          break;
          case 3:
          insertatlast();
          break;
          case 4:
          deleteatbegin();
          break;
          case 5:
          deleteatlast();
          break;
          case 6:
          deleterandom();
          break;
          case 7:
          print();
          break;
          case 8:
          exit(0);
          break;
          default:
          printf("Enter a valid choice ...\n");
      }
  }
}
void insertatbegin()
{
  struct node *point;
  int value;
  point = (struct node *) malloc(sizeof(struct node *));
  if(point == NULL)
  {
      printf("\nInvalid!!");
  }
  else
  {
      printf("\nEnter the value: \n");
      scanf("%d",&value);
      point->data = value;
      point->next = HEAD;
      HEAD = point;
      printf("\nNice, The Node is inserted at the beginning!");
  }

}
void insertatlast()
{
  struct node *point,*tmp;
  int value;
  point = (struct node*)malloc(sizeof(struct node));
  if(point == NULL)
  {
      printf("\nInvalid!!");
  }
  else
  {
      printf("\nEnter the value: \n");
      scanf("%d",&value);
      point->data = value;
      if(HEAD == NULL)
      {
          point -> next = NULL;
          HEAD = point;
          printf("\nNice, The Node is inserted!");
      }
      else
      {
          tmp = HEAD;
          while (tmp -> next != NULL)
          {
              tmp = tmp -> next;
          }
          tmp->next = point;
          point->next = NULL;
          printf("\nNice, The Node is inserted!");

      }
  }
}
void insertrandom()
{
  int a,pos,value;
  struct node *point, *tmp;
  point = (struct node *) malloc (sizeof(struct node));
  if(point == NULL)
  {
      printf("\nInvalid!!");
  }
  else
  {
      printf("\nEnter the value of element: ");
      scanf("%d",&value);
      point->data = value;
      printf("\nEnter the position where you want to insert: ");
      scanf("\n%d",&pos);
      tmp=HEAD;
      for(a=0;a<pos;a++)
      {
          tmp = tmp->next;
          if(tmp == NULL)
          {
              printf("\nSorry, but you cannot insert!\n");
              return;
          }

      }
      point ->next = tmp ->next;
      tmp ->next = point;
      printf("\nNice, The Node is inserted at your given location!");
  }
}
void deleteatbegin()
{
  struct node *point;
  if(HEAD == NULL)
  {
      printf("\nThe List is empty!\n");
  }
  else
  {
      point = HEAD;
      HEAD = point->next;
      free(point);
      printf("\nThe node is deleted from the beginning!\n");
  }
}
void deleteatlast()
{
  struct node *point,*point1;
  if(HEAD == NULL)
  {
      printf("\nThe List is empty!");
  }
  else if(HEAD -> next == NULL)
  {
      HEAD = NULL;
      free(HEAD);
      printf("\nOne node is deleted from the list!\n");
  }
  else
  {
      point = HEAD;
      while(point->next != NULL)
      {
          point1 = point;
          point = point ->next;
      }
      point1->next = NULL;
      free(point);
      printf("\nThe Node is deleted from the last of the node!\n");
  }
}
void deleterandom()
{
  struct node *point,*point1;
  int pos,a;
  printf("\nEnter the position of the node after which you want to delete!\n");
  scanf("%d",&pos);
  point=HEAD;
  for(a=0;a<pos;a++)
  {
      point1 = point;
      point = point->next;

      if(point == NULL)
      {
          printf("\nSorry, but you cannot delete!");
          return;
      }
  }
  point1 ->next = point ->next;
  free(point);
  printf("\nThe Node is deleted at location: %d",pos+1);
}

void print()
{
  struct node *point;
  point = HEAD;
  if(point == NULL)
  {
      printf("Please enter something to print!");
  }
  else
  {
      printf("\nPrinting the values!\n");
      while (point!=NULL)
      {
          printf("%d\t",point->data);
          point = point -> next;
      }
  }
}
