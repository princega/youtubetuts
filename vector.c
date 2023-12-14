#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 2000000

int main(){
	char input[MAX];
	int count = 8, i = 0;
	int* arr = (int*)malloc(count*sizeof(int));
	if(arr == NULL){
		printf("Memory allocation failed.\n");
		return 1;
	}
	while(true){
		scanf("%s",input);
		int temp = atoi(input);
		if(temp==0)break;
		else{
			if(i<count) arr[i++] = temp;
			else if(i==count){
				count *= 2;
				arr = realloc(arr, count*sizeof(int));
				if(arr == NULL){
				printf("Memory allocation failed.\n");
				return 1;
				}
				arr[i++] = temp;
			}
		}
	}
	printf("Do you want to print the elements?: \n1. Yes\n2. No\n");
	int y;
	scanf("%d",&y);
	if(y==1){
		for(int j=0;j<i;j++){
			printf("%d, ",arr[j]);
		}
	}
	free(arr);
	return 0;
}