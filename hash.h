//Made by Miguel Chavarria UIN 652215109 mchava1@uic.edu
//This is program week 13 due April 18th Midnight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct anAirport{
	int locationNumber;
	struct anAirport * nextAirport;
}airport;

airport **hashTable;
int *visited;

void initialize(int quantity);
int enterIntoHashTable(int startAirport,int endAirport,int quantity);
int delete(int startAirport,int endAirport, int quantity);
void printHashTable(int quantity);
void freeHashTable(int quantity);

void initializeVisited(int quantity);
void depthFirstSearchHelper (int startAirport, int endAirport, int quantity);
int dfs(int startAirport, int endAirport);

void whereToHelper(int x, int numberOfAirports);
void whereTo(int x, int *a, int numberOfAirports);