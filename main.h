// p-value seeder for Mersenne Primes
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <sys/time.h>

short get_next_prime();
short* get_all_primes();
bool test_candidate(unsigned long long p);
int main();
unsigned long long ipow(unsigned long long, unsigned long long);