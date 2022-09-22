#include<stdio.h>
#include<stdlib.h>
struct lnode{
	struct lnode *prev;
	struct lnode *next;
	int data;
};
struct lnode* head=NULL;
typedef struct lnode node;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_specified();
void deletion_last();
void deletion_beginning();
void display();
void find();
int main(void){
	int choice;
	while(1){
		printf("\n1.Insert at beginning\n2.Insert at last\n3.Insert at random\n4.Delete from beginning\n5.Delete from last\n6.Delete any node\n7.Display\n8.Exit\n9.Finding data of previous or next \nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1: insertion_beginning();
				break;
			case 2: insertion_last();
				break;
			case 3: insertion_specified();
				break;
			case 4: deletion_beginning();
				break;
			case 5: deletion_last();
				break;
			case 6: deletion_specified();
				break;
			case 7: display();
				break;
			case 8: exit(0);
			case 9: find();
				break;
			default: printf("Enter a valid choice..\n");
		}
	}
}
void insertion_beginning(){
	node ptr=(node)malloc(sizeof(node));
	int item;
	if(ptr==NULL){
		printf("\nOverflow");
	}
	else{
		printf("Enter the data : ");
		scanf("%d",&item);
		if(head==NULL){
			ptr->next=NULL;
			ptr->prev=NULL;
			ptr->data=item;
			head=ptr;
		}
		else{
			ptr->data=item;
			ptr->prev=NULL;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
		}
		printf("\nNode inserted");
	}
}
void insertion_last(){
	node *ptr,*temp;
	int item;
	ptr=(node*)malloc(sizeof(node));
	if(ptr==NULL){
		printf("\nOverflow");	
	}
	else{
		printf("\nEnter value : ");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL){
			ptr->next=NULL;
			ptr->prev=NULL;
			head=ptr;
		}
		else{
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
			ptr->next=NULL;
		}
	}
	printf("\nNode inserted");
}
void insertion_specified(){
	node *ptr,*temp;
	int item,loc,i;
	ptr=(node*)malloc(sizeof(node));
	if(ptr==NULL){
		printf("\nOverflow");
	}
	else{
		temp=head;
		printf("Enter the location : ");
		scanf("%d",&loc);
		for(i=0;i<loc;i++){
			temp=temp->next;
			if(temp==NULL){
				printf("There is not a possibility");
				return ;
			}
		}
		printf("Enter value : ");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=temp->next;
		ptr->prev=temp;
		temp->next=ptr;
		temp->next->prev=ptr;
		printf("\nNode inserted");
	}
}
void deletion_beginning(){
	node *ptr;
	if(head==NULL){
		printf("\nOverflow");
	}
	else if(head->next==NULL){
		head=NULL;
		free(head);
		printf("\nNode deleted");
	}
	else{
		ptr=head;
		head=head->next;
		head->prev=NULL;
		free(ptr);
		printf("\nNode deleted");
	}
}
void deletion_last(){
	node *ptr;
	if(head==NULL){
		printf("Undeflow");
	}
	else if(head->next==NULL){
		head=NULL;
		free(head);
		printf("\nNode deleted");
	}
	else{
		ptr=head;
		if(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->prev->next=NULL;
		free(ptr);
		printf("\nNode deleted");
	}
}
void deletion_specified(){
	node *temp,*ptr;
	int val;
	printf("Enter the data after which the node is to be deleted : ");
	scanf("%d",&val);
	ptr=head;
	while(ptr->data!=val){
		ptr=ptr->next;
	}
	if(ptr->next==NULL){
		printf("Cant delete");
	}
	else if(ptr->next->next==NULL){
		ptr->next=NULL;
	}
	else{
		temp=ptr->next;
		ptr->next=temp->next;
		temp->next->prev=ptr;
		free(temp);
		printf("\nNode deleted");
	}
}
void display(){
	node *ptr;
	printf("\nPrinting values ....\n");
	ptr=head;
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}
void find(){
	node *temp;
	int val;
	if(head==NULL){
		printf("List is empty");
	}
	printf("Enter any value present in the list : ");
	scanf("%d",&val);
	temp=head;
	while(temp->data!=val){
		if(temp==NULL){
			printf("Not possible ..");
			return ;
		}
		temp=temp->next;
	}
	printf("\nPrevious node's  data : %d\n",temp->prev->data);
	printf("Next node's data : %d\n",temp->next->data);	
}
