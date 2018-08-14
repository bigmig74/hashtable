//Made by Miguel Chavarria UIN 652215109 mchava1@uic.edu
//This is program week 13 due April 18th Midnight
#include "hash.h"

//method initialize changed for project 12
void initialize(int quantity)
{
	hashTable = (airport **)malloc(quantity*sizeof(airport *));
	int i;
	for(i=0;i<quantity;i++)
	{
		hashTable[i] = NULL;
	}	
}	


//method enterIntoHashTable changed for project 12
int enterIntoHashTable(int startAirport,int endAirport,int quantity)
{
	//int hashLocation = hashFunction(a);
	if(startAirport <= 0 || startAirport > quantity)
		return 0;
	
	if(hashTable[startAirport-1] == NULL)
	{
		airport *newEntry = (airport*)malloc(1*sizeof(airport));
		newEntry->locationNumber = endAirport;
		newEntry->nextAirport = NULL;
		hashTable[startAirport - 1] = newEntry;
		return 1;
	}	
	airport * tempLocation;
	tempLocation = hashTable[startAirport - 1];
	while(tempLocation != NULL)
	{
		if(tempLocation->locationNumber == endAirport)
			return 0;
		if(tempLocation->nextAirport == NULL)
			break;
		else
			tempLocation = tempLocation->nextAirport;
	}
	airport *newEntry = (airport*)malloc(1*sizeof(airport));
	newEntry->locationNumber = endAirport;
	newEntry->nextAirport = NULL;
	tempLocation->nextAirport = newEntry;
	return 1;		
}	


int delete(int startAirport,int endAirport, int quantity)
{
	if(startAirport <= 0 || startAirport > quantity)
		return 0;
	if(hashTable[startAirport-1] == NULL)
		return 0;
	//1.) node is the first node in the list and is the only node
	//2.) node is the first node in the list and there are other nodes after it
	if(hashTable[startAirport-1]->locationNumber == endAirport)
	{
		airport * temp = hashTable[startAirport-1];
		if(hashTable[startAirport - 1]->nextAirport == NULL)
		{
			free(temp);
			hashTable[startAirport - 1] = NULL;
		}
		else
		{
			hashTable[startAirport - 1] = hashTable[startAirport - 1]->nextAirport;
			free(temp);
		}		
		return 1;
	}
	if(hashTable[startAirport - 1]->nextAirport == NULL)
		return 0;	
	airport * tempLocation, *tempLocationPrevious;
	tempLocation = hashTable[startAirport - 1]->nextAirport;
	tempLocationPrevious = hashTable[startAirport - 1];
	
	/*	3.) node is somewhere in the middle of the list
		4.) node is the last node.*/
	while(tempLocation != NULL)
	{
		if(tempLocation->locationNumber == endAirport)
		{
			if(tempLocation->nextAirport == NULL)
			{	
				tempLocationPrevious->nextAirport = NULL;
				free(tempLocation);
			}
			else
			{
				tempLocationPrevious->nextAirport = tempLocation->nextAirport;
				free(tempLocation);
			}
			return 1;	
		}
		else if(tempLocation->nextAirport == NULL)
			return 0;
		tempLocation = tempLocation->nextAirport;
		tempLocationPrevious = tempLocationPrevious->nextAirport;
	}
	return 0;
}	


/*int hashFunction(char a[5])
{
	int location=9999;
	if(strcmp(a,"hhhh")==0)
		location = 0;
	else if(strcmp(a,"hhht")==0)
		location = 1;
	else if(strcmp(a,"hhth")==0)
		location = 2;
	else if(strcmp(a,"hhtt")==0)
		location = 3;
	else if(strcmp(a,"hthh")==0)
		location = 4;
	else if(strcmp(a,"htht")==0)
		location = 5;
	else if(strcmp(a,"htth")==0)
		location = 6;
	else if(strcmp(a,"httt")==0)
		location = 7;
	else if(strcmp(a,"thhh")==0)
		location = 8;
	else if(strcmp(a,"thht")==0)
		location = 9;
	else if(strcmp(a,"thth")==0)
		location = 10;
	else if(strcmp(a,"thtt")==0)
		location = 11;
	else if(strcmp(a,"tthh")==0)
		location = 12;
	else if(strcmp(a,"ttht")==0)
		location = 13;
	else if(strcmp(a,"ttth")==0)
		location = 14;
	else if(strcmp(a,"tttt")==0)
		location = 15;
	return location;
}*/	

/*void shift(char playerguess,char a[5])
{
	char first, second ,third;
	first = a[1];
	second = a[2];
	third = a[3];
	a[0] = first;
	a[1] = second;
	a[2] = third;
	a[3] = playerguess;
}	*/

//Method printHashTable changed for project 12
void printHashTable(int quantity)
{
	int i;
	for(i=0;i<quantity;i++)
	{
		if(hashTable[i] == NULL)
			printf(" Airport %d:\t Flights do not leave this airport\n",i+1);
		else
		{
			airport * temp = hashTable[i];
			printf(" Airport %d:\t Flights go to airports: ",i+1);
			while(temp != NULL)
			{
				printf(" %d,",temp->locationNumber);
				temp = temp->nextAirport;
			}	
			printf("\n");
		}	
	}	
	printf("\n");
}	


//Method freeTheArray changed for project 12
void freeHashTable(int quantity)
{
	airport *temp1,*temp2;
	int i;
	for(i=0;i<quantity;i++)
	{
		if(hashTable[i]==NULL)
			continue;
		temp1 = hashTable[i];
		temp2 = hashTable[i];
		while(temp1 != NULL)
		{
			if(temp1->nextAirport == NULL)
			{
				free(temp1);
				break;
			}	
			temp1 = temp1->nextAirport;
			free(temp2);
			temp2 = temp1;
		}	
	}
	free(hashTable);	

}	


void initializeVisited(int quantity)
{
	visited = (int *)malloc(quantity * sizeof(int));
	int i;
	for(i = 0;i<quantity;i++)
		visited[i] = 0;
}	


void depthFirstSearchHelper(int startAirport, int endAirport, int quantity)
{
	initializeVisited(quantity);
	if ( dfs(startAirport,endAirport)== 1)	
		printf("You can get from airport %d to airport %d in one or more flights\n",startAirport,endAirport);
	else
		printf("You can not get from airport %d to airport %d in one or more flights\n",startAirport,endAirport);
	free(visited);
}


int dfs(int startAirport, int endAirport)
{
	airport *temp;
	temp = hashTable[startAirport - 1];
	while(temp != NULL)
	{	
		if (temp->locationNumber == endAirport)
			return 1;
		if (visited[temp->locationNumber - 1] == 0)
		{
			visited[temp->locationNumber - 1] = 1;
			if ( dfs(temp->locationNumber,endAirport)== 1)
				return 1;
		}
		temp = temp->nextAirport;
	}
	return 0;
}

void whereToHelper(int x, int numberOfAirports)
{
	if(hashTable[x-1] == NULL)
	{
		printf("Planes to not leave airport %d\n", x);
		return;
	}
	
	int *a = (int *)malloc(numberOfAirports*sizeof(int));
	int i;
	for(i=0;i<numberOfAirports;i++)
		a[i] = 0;
	a[x-1] = x;
	
	whereTo(x,a,numberOfAirports);
	
	printf("The airports that can be reached from airport %d are: ",x);
	for(i=0;i<numberOfAirports;i++)
	{
		if(a[i] == 0 || a[i]==x)
			continue;
		printf(" %d ",a[i]);
	}
	printf("\n");	
}


void whereTo(int x, int *a, int numberOfAirports)
{
	if(hashTable[x-1]==NULL)
		return;
	
	airport *temp = hashTable[x-1];
	
	while(temp != NULL)
	{
		if(a[temp->locationNumber - 1] == 0)
		{
			a[temp->locationNumber - 1] = temp->locationNumber;
			whereTo(temp->locationNumber,a,numberOfAirports);
		}
		
		if(temp->nextAirport == NULL)
			break;
		
		temp = temp->nextAirport;	
	}	
}	






	