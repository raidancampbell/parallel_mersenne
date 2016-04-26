#include "main.h"

#define MAX_CANDIDATE 500000
#define IS_PRIME 1
#define NOT_PRIME 0

int current_prime_index = 0;
short* prime_array;

int main() {

	struct timeval start_time, stop_time, elapsed_time;
	gettimeofday(&start_time,NULL);

	for(int num_runs = 0; num_runs < 1000; num_runs++) {
		get_all_primes();

		for(int i = 0; i < 11; i++) {
			unsigned long long p = get_next_prime();
		}
		free (prime_array);
		current_prime_index = 0;
	}


	gettimeofday(&stop_time,NULL);
	timersub(&stop_time, &start_time, &elapsed_time);
	printf("%f\n", elapsed_time.tv_sec+elapsed_time.tv_usec/1000000.0);
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
	int mult = 1;

    for(int iterator = 2; iterator < sqrt(MAX_CANDIDATE); iterator++) {
    	if(prime_array[iterator] == IS_PRIME) {
        	for(int j = iterator * iterator; j < MAX_CANDIDATE; j = (iterator * iterator) + (mult++ * iterator)) {
            	prime_array[j] = NOT_PRIME;
         	}
        	mult = 1;
      	}
    }
}

bool test_candidate(unsigned long long p) {
	unsigned long long s = 4;
	unsigned long long M = (ipow(2,p)) - 1;
	double MAX_ULL = (double) (0ull - 1ull);

    for(int iterator = 0; iterator < p-2; iterator++) { // lucas-lehmer primality test
    	if(s > sqrt(MAX_ULL)) {
    		printf("we're going to overflow unsigned long long. invalid math is occurring.\n");
    	}
    	s = (ipow(s,2) - 2) % M;
    }
    return s == 0; // if s is 0, it is prime.
}

// unsigned long long exponentiation.  Just shift the bits.
unsigned long long ipow(unsigned long long base, unsigned long long exp) { 
// thanks, http://stackoverflow.com/questions/101439/the-most-efficient-way-to-implement-an-integer-based-power-function-powint-int
    unsigned long long result = 1;
    while (exp) {
        if (exp & 1) result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}