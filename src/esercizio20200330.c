// Diaa Nehme  IN0500345  esercizio20200330

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Fibonacci Function (Es. A)
unsigned long fibonacci(unsigned int n){
	unsigned long result;
	if(n < 0)
		return 0;
	else if(n == 0){
		result = 0;
		return result;
	}
	else if(n == 1){
		result = 1;
		return result;
	}
	else {
		result = fibonacci(n-1) + fibonacci(n-2);
		return result;
		}
	return result;
	}

// Fill Array Function (Es. B)
unsigned long * fibonacci_array(unsigned int n){

	unsigned long * array;
	array = calloc(n + 1, sizeof(unsigned long));
	for(int i = 0; i < n + 1; i++){
		array[i] = fibonacci(i);
	}
	return array;
}


// Copy Array Function
unsigned long * make_copy_of_array(unsigned long initial_array [], unsigned int array_dimension) {

	if (initial_array == NULL)
		return NULL;

	unsigned long * result_array;

	result_array = calloc(array_dimension, array_dimension * sizeof(unsigned long));

	if (result_array == NULL) {
		return NULL;
	}

	memcpy(result_array, initial_array, array_dimension * sizeof(unsigned long));

	return result_array;
}

// Swap Elements Function
void swap(unsigned long *a,unsigned long *b){
	unsigned long temp = *a;
	*a = *b;
	*b = temp;
}

// Bubble Sort Algorithm
void bubbleSort(unsigned long *array, int  size){
	if(size < 0){
		printf("Error dimension!!!");
		exit(EXIT_FAILURE);
		}
	{
	int N = size;
	do{
		int newN = 0;
		for(int i = 1; i < N; i++){
			if(array[i-1]>array[i]){
				swap(&array[i-1],&array[i]);
				newN = i;
				}
			}
		N = newN;
	} while(N > 1);
	}
}
// Total Reverse Array Function
unsigned long * total_reverse(unsigned long * array, unsigned int i, unsigned int j){
	while (i < j)
		swap(&array[i++], &array[--j]);

	return array;
}

int main(int argc, char *argv[]) {

  // Es.C:
  unsigned long num1 = fibonacci(39);
  printf("Fibonacci di 39 e': %ld.\n", num1);
  int num2 = 39;
  unsigned long *fibonacci_result = fibonacci_array(num2);

  unsigned long *fibonacci_result_copy = make_copy_of_array(fibonacci_result, num2 + 1);
  fibonacci_result_copy = total_reverse(fibonacci_result_copy, 0, num2 + 1);
  bubbleSort(fibonacci_result_copy, num2 + 1);

// Print Arrays
  for(int i = 0; i < num2 + 1; i++)
	printf("%ld\t%ld\n",fibonacci_result[i], fibonacci_result_copy[i]);

// memcmp() Value [Comparison]
  int x = memcmp(fibonacci_result, fibonacci_result_copy, (num2 + 1) * sizeof(unsigned long));
	if(x != 0)
		printf("\nDifferent arrays");
	else
		printf("\nEquals arrays");

	return EXIT_SUCCESS;
	}
