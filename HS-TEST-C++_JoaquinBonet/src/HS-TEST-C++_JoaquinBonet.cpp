//============================================================================
// Name        : HS-TEST-C++_JoaquinBonet.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<assert.h>
#include<limits.h>
#include<math.h>
#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

char* readline();
char** split_string(char*);

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void bubbleMethod(int TAM, int* list){
	int temp;
	for(int i=1; i<TAM; i++){
		 for(int j=0 ; j<TAM - 1; j++){
		    if (list[j] < list[j+1]){
		        temp = list[j];
		        list[j] = list[j+1];
		        list[j+1] = temp;
		           }
		       }
		 }
}

int* climbingLeaderboard(int scores_count, int* scores,int alice_count,int* alice ) {
	bubbleMethod(alice_count,alice);

    for (int i = 0; i < alice_count; i++) {
        int result = binarySearch(scores, 0, scores_count - 1, alice[i]);
        if (result == -1)
            cout << "Elemento " << alice[i] << " no encontrado\n";
        else
            cout << "Elemento " << alice[i] << " encontrado en la posicion " << result << "\n";
    }
    return alice;
}

int main() {

	FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

	char *scores_count_endptr;
	char *scores_count_str = readline();
	int scores_count = strtol(scores_count_str, &scores_count_endptr, 10);

	if (scores_count_endptr == scores_count_str
			|| *scores_count_endptr != '\0') {
		exit(EXIT_FAILURE);
	}

	char **scores_temp = split_string(readline());

	int *scores = malloc(scores_count * sizeof(int));

	for (inti = 0; i < scores_count; i++) {
		char *scores_item_endptr;
		char *scores_item_str = *(scores_temp + i);
		intscores_item = strtol(scores_item_str, &scores_item_endptr, 10);
		if (scores_item_endptr == scores_item_str
				|| *scores_item_endptr != '\0') {
			exit(EXIT_FAILURE);
		}
		*(scores + i) = scores_item;
	}

	char *alice_count_endptr;

	char *alice_count_str = readline();
	intalice_count = strtol(alice_count_str, &alice_count_endptr, 10);
	if (alice_count_endptr == alice_count_str || *alice_count_endptr != '\0') {
		exit(EXIT_FAILURE);
	}
	char **alice_temp = split_string(readline());
	int *alice = malloc(alice_count * sizeof(int));
	for (inti = 0; i < alice_count; i++) {
		char *alice_item_endptr;
		char *alice_item_str = *(alice_temp + i);
		intalice_item = strtol(alice_item_str, &alice_item_endptr, 10);
		if (alice_item_endptr == alice_item_str || *alice_item_endptr != '\0') {
			exit(EXIT_FAILURE);
		}
		*(alice + i) = alice_item;
	}
	intresult_count;
	int *result = climbingLeaderboard(scores_count, scores, alice_count, alice,
			&result_count);
	for (inti = 0; i < result_count; i++) {
		fprintf(fptr, "%d", *(result + i));
		if (i != result_count - 1) {
			fprintf(fptr, "\n");
		}
	}
	fprintf(fptr, "\n");
	fclose(fptr);
	return0;
}
	char* readline() {
	size_t alloc_length = 1024;
	size_t data_length = 0;
	char *data = malloc(alloc_length);
	while (true) {
		char *cursor = data + data_length;
		char *line = fgets(cursor, alloc_length - data_length, stdin);
		7if(!line)
		{
			break;
		}
		data_length += strlen(cursor);
		if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
			break;
		}
		size_t new_length = alloc_length << 1;
		data = realloc(data, new_length);
		if (!data) {
			break;
		}
		alloc_length = new_length;
	}
	if (data[data_length - 1] == '\n') {
		data[data_length - 1] = '\0';
	}
	data = realloc(data, data_length);
	returndata;
}
	char** split_string(char *str) {
	char **splits = NULL;
	char *token = strtok(str, " ");
	intspaces = 0;
	while (token) {
		splits = realloc(splits, sizeof(char*) * ++spaces);
		if (!splits) {
			returnsplits;
		}
		splits[spaces - 1] = token;
		token = strtok(NULL, " ");
	}
	returnsplits;
}
return 0;
}
