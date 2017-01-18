//
//  main.c
//  Insertion_sort
//
//  Created by KevinLiu on 16/8/17.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#define MAX 7

int intArray[MAX] = {4,6,3,2,1,9,7};

void printline(int count){
	int i;

	for(i = 0;i <count-1;i++){
		printf("=");
	}
	printf("=\n");
}

void display(){
	int i;
	printf("[");

	//navigate through all item
	for(i = 0;i < MAX;i++){
		printf("%d,",intArray[i]);
	}
	printf("]\n");
}

void insertSort(){
	int valueToInsert;
	int holePosition;
	int i;

	//loop through all numbers
	for(i = 1;i <MAX;i++){

		//select a value to be insert
		valueToInsert = intArray[i];

		//select the hole position where value is to be insert
		holePosition = i;

		//check if previous no. is larger than value tp be insert
		while(holePosition>0 && intArray[holePosition-1] > valueToInsert){
			intArray[holePosition] = intArray[holePosition-1];
			holePosition = holePosition-1;
			printf("item moved: %d ",intArray[holePosition]);
		}
		if(holePosition !=i){
			printf("item inserted :%d, at position: %d ",valueToInsert,holePosition);
			//insert the number at hole position
			intArray[holePosition] = valueToInsert;
		}
		printf("iteration %d# :",i );
		display();
	}
}

int main(int argc, const char * argv[]) {
    printf("Input Array:");
    display();
    printline(50);
    insertSort();
    printf("Output Array:");
    display();
    printline(50);
}
