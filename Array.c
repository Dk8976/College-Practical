#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 50
int arr[MAX_SIZE];
int size = 0;


void display(){
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",arr[i]);

}
void insertAtPos(int pos,int val){
    int i;

    for(i=size-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }

    arr[pos]= val;
    size++;
    printf("Inserted %d at pos %d",val,pos);
}
void deleteFromBeginning(){
    int i;
    int del=arr[0];
    for(i=0;i<size;i++){
      arr[i]=arr[i+1];
    }
    size--;
    printf("Deleted %d from the beginning ",del);
}
void deleteFromPos(int pos){
    int i;
    int del = arr[pos];
    for(i=pos;i<size;i++){
        arr[i] = arr[i+1];
    }
    size--;
    printf("Deleted %d at pos %d",del,pos);
}
void deleteEnd(){
    int del=arr[size];
    size--;
    printf("Deleted %d from the end ",del);
}
int main(){
	int choice,val,pos;
	while(1){
		printf("\n--------List Menu--------\n");
		printf("1.Insert at beginning\n2.Insert at middle\n3.Insert at end\n4.Delete at beginning\n5.Delete at middle\n6.Delete at end\n7.Display\n8.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter a data to insert at beginning : ");
		        	scanf("%d",&val);
		        	if(size== MAX_SIZE){
		            		printf("Array is full");
		            		break;
		        	}
		        	pos=0;
		        	insertAtPos(pos,val);
		        	break;
                	
                	case 2:  if(size == MAX_SIZE){
				    printf("Array is full");
				    break;
				}
				printf("Enter the pos *pos starts at 0*:  ");
				scanf("%d",&pos);
				if(pos<0 || pos>=size)
				{
				    printf("Invalid position");
				    break;
				}
				printf("Enter the data: ");
				scanf("%d",&val);
				insertAtPos(pos,val);
				break;
				
			case 3: if(size == MAX_SIZE){
				    printf("Array is full");
				    break;
				}
				printf("Enter the data: ");
				scanf("%d",&val);
				arr[size++] = val;
				break;
				
			case 4: if(size==0){
				    printf("Array is empty ");
				    break;
				}
				deleteFromBeginning();
				break;
				
			case 5: if(size==0){
				    printf("Array is empty");
				    break;
				}
				printf("Enter the pos: ");
				scanf("%d",&pos);
				if(pos<0 || pos>=size)
				    printf("Invalid position");
				else
				    deleteFromPos(pos);
				break;
				
			case 6: if(size==0){
				    printf("Array is empty");
				    break;
				}
				deleteEnd();
				break;
			
			case 7: display();
				break;
				
			case 8: exit(0);
		
			default: printf("Enter a valid choice ...\n");


		}
	}
}
