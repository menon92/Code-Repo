/**
  * Problem: 1210 - Sum of Consecutive Prime Numbers.
  * Starus : Accepted.
  * Author : Md.Mehadi Hasan Menon.
  * Date   : 05.04.2015.
  **/
#include <iostream>
#include <cstdio>
#include <cmath>

#define MAX 10010
int ara[MAX];
int prime[MAX];

void sieve()
{
    for(int i = 2; i <= MAX; i++) {
        ara[i] = 1;
    }

    for(int i = 2; i <= sqrt(MAX); i++) {
        if(ara[i]) {
            for(int j = 2; i * j <= MAX; j++) {
                ara[i*j] = 0;
            }
        }

    }
}
int isPrime(int n)
{
    if(n < 2) {
        return 0;
    }
    return ara[n];
}
void generatePrime()
{
    int k = 0;
    for(int i = 1; i <= MAX; i++) {
        if(isPrime(i)) {
            prime[k++] = i;

        }
    }
}
int main()
{
    sieve();
    generatePrime();

    int n, sum, counts;
    while(scanf("%d", &n) && n != 0)
    {
        counts = 0;
        for(int i = 0; prime[i] <= n; i++) {
            sum = 0;
            for(int j = i; prime[j] <= n; j++) {
                sum += prime[j];
                if(sum > n) {
                    break;
                }
                if(sum == n) {
                    counts++;
                    break;
                }
            }
        }
        printf("%d\n", counts);
    }

    return 0;
}
