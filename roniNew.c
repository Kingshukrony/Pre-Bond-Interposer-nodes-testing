#include<stdio.h>
#include<conio.h>
#include<malloc.h>
//structure for node of existing connection
struct existConnectionNode{
	char nodeName;
	int nodeNumber;
	struct existConnectionNode *next;
};
int main(){
	int connectionNo;
	int i, j;
	int nodeNo;
	int attachedToHead;	
	char nodeNameChar;

	printf("Enter Total No. of Connection : ");
	scanf("%d", &connectionNo);
	printf("Enter node name U or D, else next connection :\n\n");
	struct existConnectionNode *con[connectionNo];
	struct existConnectionNode *temp;
	struct existConnectionNode *end;
	
	int conCount[2][connectionNo];
	
	//input the node details for each connection
	for(i=0; i<connectionNo; i++){
		printf("\nEnter details for connection %d :-\n",i);
		
		conCount[0][i]=i;
		conCount[1][i]=0;		
		attachedToHead=0;
		
		//clear the buffer
		fflush(stdin);
		printf("Node name(U/D) : ");
		scanf("%c", &nodeNameChar);
		
		while(nodeNameChar=='U' || nodeNameChar=='D'){
			//create a temporary node			
			temp = (struct existConnectionNode *)malloc(sizeof(struct existConnectionNode));
			temp->nodeName = nodeNameChar;
			printf("Node number : ");
			scanf("%d", &temp->nodeNumber);
			temp->next=NULL;
			
			if(attachedToHead==0){
				con[i]=temp;
				end=temp;
				attachedToHead=1;
			}else{
				end->next=temp;
				end=temp;
			}
			
			conCount[1][i]++;
			MAX
			fflush(stdin);
			printf("Enter node name (U/D) : ");
			scanf("%c", &nodeNameChar);			
		}		
	}
	//print the nodes for each connection
	printf("\n\n\nThe Connections are :-\n\n");
	for(i=0; i<connectionNo; i++){
		end = con[i];
		while(end!=NULL){
			printf("%c%d-",end->nodeName,end->nodeNumber);
			end=end->next;
		}
		printf("\b \n");
	}
	
	//sorting the connections according node numbers
	int tempSwap;
	for(i=0; i<connectionNo; i++){
		for(j=0; j<connectionNo-i-1; j++){
			if(conCount[1][j]<conCount[1][j+1]){
				tempSwap = conCount[1][j];
				conCount[1][j]=conCount[1][j+1];
				conCount[1][j+1]=tempSwap;
				
				tempSwap = conCount[0][j];
				conCount[0][j]=conCount[0][j+1];
				conCount[0][j+1]=tempSwap;
			}
		}
	}
		
	//print the nodes for each connection
	printf("\n\n\nThe Connections are :-\n\n");
	for(i=0; i<connectionNo; i++){
		end = con[conCount[0][i]];
		while(end!=NULL){
			printf("%c%d-",end->nodeName,end->nodeNumber);
			end=end->next;
		}
		printf("\b \n");
	}
	
	return 0;
}
