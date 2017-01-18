//
//  main.c
//  selection_sort
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

void selectionSort(){
	int indexMin,i,j;

	//loop through all numbers
	for(i=0;i<MAX-1;i++){

		//set current element as minimum
		indexMin = i;

		//check the element to be minimum
		for(j=i+1;j<MAX;j++){
			if(intArray[j]<intArray[indexMin]){
				indexMin = j;
			}
		}
		if(indexMin != 0){
			printf("iterm swapped:[ %d, %d]\n",intArray[i],intArray[indexMin]);

			//swap the numbers
			int temp = intArray[indexMin];
			intArray[indexMin]= intArray[i];
			intArray[i]=temp;
		}

		printf("Iteration %d:",(i+1));
		display();
	}
}



int main(int argc, const char * argv[]) {
    printf("Input Array:");
    display();
    printline(50);
    selectionSort();
    printf("Ouput Array:");
    display();
    printline(50);

}
