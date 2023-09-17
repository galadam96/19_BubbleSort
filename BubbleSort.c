//DATE: 2023.09.13
//PURPOSE: A program that sorts the strings of 
//an array using a bubble sort

#include <stdio.h>
#include <string.h>

//function prototypes

void bubbleSort(char originalArr[3][50], char sortedArr[3][50]);

int main()
{
	char myArr[3][50]; //creates an array with 3 rows and 50 columns (3 strings with 50 letters each)
	char sortedArr[3][50]; //result array will be stored in this
	//Asking for 3 input and storing it
	for (int i = 0;i < 3;i++) {
		printf("Please input your string to be sorted by letters:", i);
		scanf("%s", myArr[i]);
	}

	//Displaying the 3 input
	for (int i = 0;i < 3; i++) {
		printf("\nYour input string is:%s ",myArr[i]);
	}
	
	//Invoking the custom function
	bubbleSort(myArr, sortedArr);

	//Displaying the sorted list
	for (int i = 0;i < 3;i++) {
		printf("\nThe bubble sorted array is: %s", sortedArr[i]);
	}
	
	return 0;
}

void bubbleSort(char originalArr[3][50], char sortedArr[3][50]) {
	char tmpChar[50];

	//Copying originalArr into sortedArr
	for (int i = 0; i < 3;i++) {
		strcpy(sortedArr[i], originalArr[i]);
	}
	
	//Sorting the array
	//We need to check only the n - 1 strings, because we are looking at  n and n+1 in one iteration.
	
	for (int i = 0; i < 3 - 1; i++) {
		for (int j = 0; j < 3 -i - 1; j++) { //  -i in condition is making sure, that we do not check the already sorted ones. Optimizing..
			if (strcmp(sortedArr[j], sortedArr[j + 1]) > 0) {
				strcpy(tmpChar, sortedArr[j]);
				strcpy(sortedArr[j], sortedArr[j + 1]);
				strcpy(sortedArr[j + 1], tmpChar);
			}
		}
	}
}

