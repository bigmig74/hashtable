//created by Miguel Chavarria UIN 652215109 mchava1@uic.edu
//Project Week 13 for cs 211 Due April 18th at Midnight
#include "hash.h"

int numberOfAirports = 10;


int getTwoNumbers(int* number1,int* number2, char *copy)
{
	//printf("%s\n",copy);
	char *tok ;	
	char *tok1, *tok2;
	tok = strtok(copy, " ");
	tok1 = strtok(NULL, " ");
	if(tok1 == NULL)
		return 0;
	tok2 = strtok(NULL, " ");
	if(tok2 == NULL)
		return 0;
	//printf("%s\t%s\n",tok1,tok2);
	*number1 = atoi(tok1);
	if(number1 == NULL)
		return 0;
	*number2 = atoi(tok2);
	if(number2 == NULL)
		return 0;
	free(tok);
	return 1;
	//free(tok1);
	//free(tok2);
	//printf("%d\t%d\n",*number1,*number2);

}	

int getOneNumber(int * number1,char *copy)
{
	char *tok = copy;
	char *tok1;
	tok = strtok(tok, " ");
	tok1 = strtok(NULL, " ");
	if(tok1 == NULL)
		return 0;
	*number1 = atoi(tok1);
	if(number1 == NULL)
		return 0;
	free(tok);
	return 1;
	//free(tok1);
}	

void displayInstructions(void)
{
	printf("q - quit the program\n");
	printf("t <int1> <int2> display a message stating whether person can fly from airport <int1> to airport <int2> in one or more flights\n");
	printf("r <int1> remove all values from the traffic network and resize the array to contain the number of airports given by the integer\n");
	printf("i <int1> <int2> insert the edge to indicate a plane flys from airport <int1> to airport <int2>\n");
	printf("d <int1> <int2> delete the edge that indicates a plane flying from airport <int1> to airport <int2>\n");
	printf("l - list the travel network\n");
	printf("f <filename>  take commands that are read from a file\n");
	printf("p - print instructions\n");
	printf("w <int1> displays all the airports that can be reached from airport <int1>\n\n");
}	

void doFromFile(FILE *fpSource)
{
	int start, end;
	size_t len = 25;
	char * line = (char *)malloc(len*sizeof(char));
	ssize_t read;
	int proceed = 1;
	int newNumberOfAirports;
	int airportNumber;
	int boolean;
	while ((read = getline(&line, &len, fpSource)) != -1)
	{
		char * copy = (char *)malloc((read+1)*sizeof(char));
		strcpy(copy,line);
		char choice = copy[0];
		switch (choice)
		{
			case 'q':
			freeHashTable(numberOfAirports);
			printf("Thank you for using this program.\n");	
			exit(0);
			break;
			case 't':
			boolean = getTwoNumbers(&start,&end,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			depthFirstSearchHelper(start,end,numberOfAirports);
			break;
			case 'r':
			boolean = getOneNumber(&newNumberOfAirports,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			freeHashTable(numberOfAirports);
			numberOfAirports = newNumberOfAirports;
			initialize(numberOfAirports);
			break;
			case 'i':
			boolean = getTwoNumbers(&start,&end,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			if(enterIntoHashTable(start,end,numberOfAirports))
				printf("your entry has been inserted into the hashTable.\n");
			else
				printf("that entry is already in the hashTable.\n");
			break;
			case 'd':
			boolean = getTwoNumbers(&start,&end,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			if(delete(start,end,numberOfAirports))
				printf("Your entry has been deleted from the hashTable.\n");
			else
				printf("That entry does not exist in the hashTable.\n");
			break;
			case 'l':
			printHashTable(numberOfAirports);
			break;
			case 'f':
			break;		
			case 'p':
			displayInstructions();
			break;
			case 'w':
			boolean = getOneNumber(&airportNumber,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}	
			whereToHelper(airportNumber, numberOfAirports);
			break;
			default:
			printf("You did not type in a correct option.  Try again.\n");
			break;
		}	
	}
	free(line);	
	
}	




int main(void)
{
	int start, end;
	size_t len = 25;
	char * line = (char *)malloc(len*sizeof(char));
	ssize_t read;
	int proceed = 1;
	int newNumberOfAirports;
	int airportNumber;
	int boolean;
	initialize(numberOfAirports);
	printf("This is airplane network.\n");
	displayInstructions();
	while (proceed)
	{
		read = getline(&line, &len, stdin);
		char * copy = (char *)malloc((read+1)*sizeof(char));
		strcpy(copy,line);
		//free(line);
		char choice = copy[0];
		switch (choice)
		{
			case 'q':
			proceed = 0;
			freeHashTable(numberOfAirports);
			break;
			case 't':
			boolean = getTwoNumbers(&start,&end,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			depthFirstSearchHelper(start,end,numberOfAirports);
			break;
			case 'r':
			boolean = getOneNumber(&newNumberOfAirports,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			freeHashTable(numberOfAirports);
			numberOfAirports = newNumberOfAirports;
			initialize(numberOfAirports);
			break;
			case 'i':
			boolean = getTwoNumbers(&start,&end,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			if(enterIntoHashTable(start,end,numberOfAirports))
				printf("your entry has been inserted into the hashTable.\n");
			else
				printf("that entry is already in the hashTable.\n");
			break;
			case 'd':
			boolean = getTwoNumbers(&start,&end,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			if(delete(start,end,numberOfAirports))
				printf("Your entry has been deleted from the hashTable.\n");
			else
				printf("That entry does not exist in the hashTable.\n");
			break;
			case 'l':
			printHashTable(numberOfAirports);
			break;
			case 'f':
			{
			char *tok = copy;
			tok = strtok(tok," ");
			char *filename = strtok(NULL," ");
			if(filename == NULL)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}	
			int size = strlen(filename);
			char *filename2 = (char *) malloc(size*sizeof(char));
			strncpy(filename2,filename,size-1);
			filename2[size-1] = '\0';
			free(tok);
			//free(filename);
			//printf("outside function: p%sp\n",filename);
			FILE *fpSource;
			fpSource = fopen(filename2,"r");
			if(fpSource == NULL)
			{
                fprintf(stderr,"Cannot open source file, program will terminate. \n");
                exit(0);
			}
			doFromFile(fpSource);
			fclose(fpSource);
			//free(filename);	
			}
			break;
			case 'p':
			displayInstructions();
			break;
			case 'w':
			boolean = getOneNumber(&airportNumber,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			whereToHelper(airportNumber, numberOfAirports);
			break;		
			default:
			printf("You did not type in a correct option.  Try again.\n");
			break;
		}	
	}	
	free(line);
	printf("Thank you for using this program.\n");
	return 0;
}	
