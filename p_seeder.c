#include "p_seeder.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_CANDIDATE 50000
#define IS_PRIME 1
#define NOT_PRIME 0

int current_prime_index = 0;
short* prime_array;

int main() {
	printf("getting all primes\n");
	get_all_primes();
	printf("grabbing first prime\n");
	printf("%d\n", get_next_prime());
	printf("%d\n", get_next_prime());
	printf("%d\n", get_next_prime());
	printf("%d\n", get_next_prime());
	printf("%d\n", get_next_prime());
	printf("%d\n", get_next_prime());
	printf("%d\n", get_next_prime());
	printf("%d\n", get_next_prime());
	printf("%d\n", get_next_prime());
	printf("%d\n", get_next_prime());

	free (prime_array);
}

short get_next_prime() {
	while (prime_array[current_prime_index] == NOT_PRIME) {
		current_prime_index++;
	}
	return current_prime_index++;
}

short* get_all_primes() {
	prime_array = (short*) calloc(MAX_CANDIDATE, sizeof(short));
	prime_array[2] = IS_PRIME; // 2 is prime. past that it's only odd numbers
	for(long iterator = 3; iterator <= MAX_CANDIDATE; iterator+=2) {  // really basic wheel factorization for 2
		prime_array[iterator] = IS_PRIME;
	}
	for(long iterator = 6; iterator <= MAX_CANDIDATE; iterator +=3) {
		prime_array[iterator] = NOT_PRIME;
	}
	int mult = 1;
	int j = 0;

    for(int iterator = 2; iterator < sqrt(MAX_CANDIDATE); iterator++) {
    	if(prime_array[iterator] == IS_PRIME) {
        	for(int j = iterator * iterator; j < MAX_CANDIDATE; j = (iterator * iterator) + (mult++ * iterator)) {
            	prime_array[j] = NOT_PRIME;
         	}
        	mult = 1;
      	}
    }

}
