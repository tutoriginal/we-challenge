#include <time.h>
#include <stdio.h>
#include <stddef.h>
size_t ft_strlen(char *);

int n = 0;
unsigned long long average_score = 0;

void print_speed(char *s)
{
	time_t start = clock();
	ft_strlen(s);
	average_score += clock() - start;
	n++;
}

int main()
{
	print_speed("Short\n");
	print_speed("2C");
	print_speed("Un autre test avec beaucoup de mots encore qqe mots ok je crois que c'est bon mtn non mtn enft");

	printf("Score = %llu\n", average_score /= n); // The higher the score the slower is the function on average
}
