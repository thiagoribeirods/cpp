#include <stdio.h>
unsigned long long int fibonacci_vetor[101] = {[0 ... 100] = -1};
int Fibonacci(int n)
{
 if(fibonacci_vetor[n] != -1) return fibonacci_vetor[n];
 else return fibonacci_vetor[n] = Fibonacci(n-1) + Fibonacci(n-2);
}

int main(void) 
{
  fibonacci_vetor[0] = 0; fibonacci_vetor[1] = 1;
  int fibo = 0;
  printf("Fibonacci dinâmico\n");
  printf("Calcular Fibonacci de -> ");
  scanf("%i",&fibo);
  int r = Fibonacci(fibo);
  printf("%d", r);
}
