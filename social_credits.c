#include <stdio.h>
#include <stdlib.h>

long int binarymds(long int s[], long int l, long int r, long int key)
{
	while(r - l > 1)
	{
		long int m = l + (r - l) / 2;

		if(s[m] <= key)
		{
			r = m;
		}

		else
		{
			l = m;
		}
	}

	return r;

}

long int binarymis(long int s[], long int l, long int r, long int key)
{
	while(r - l > 1)
	{
		long int m = l + (r - l) / 2;

		if(s[m] >= key)
		{
			r = m;
		}

		else
		{
			l = m;
		}
	}

	return r;

}

void MaxDecreasingSubseq(long int s[], long int N, long int right[])
{
	long int length, i, *m;

	m = malloc(sizeof(long int) * N);

	length = 1;
	m[0] = s[0];
	right[0] = length;

	for(i = 1; i < N; i++)
	{
		if(s[i] > m[0])
		{
			m[0] = s[i];
			right[i] = length;
		}

		else if(s[i] < m[length - 1])
		{
			m[length++] = s[i];
			right[i] = length;
		}

		else
		{
			m[binarymds(m, -1, length - 1, s[i])] = s[i];
			right[i] = length;
		}
	}
}


void MaxIncreasingSubseq(long int s[], long int N, long int left[])
{
	long int length, i, *m;

	m = malloc(sizeof(long int) * N);

	length = 1;
	m[0] = s[0];
	left[0] = length;

	for(i = 1; i < N; i++)
	{
		if(s[i] < m[0])
		{
			m[0] = s[i];
			left[i] = length;
		}

		else if(s[i] > m[length - 1])
		{
			m[length++] = s[i];
			left[i] = length;
		}

		else
		{
			m[binarymis(m, -1, length - 1, s[i])] = s[i];
			left[i] = length;
		}
	}
}

int main() {

	long int N, i;

	scanf("%li", &N);

	long int *s, *rev_s, *left, *right;

	s = malloc(sizeof(long int) * N);
	rev_s = malloc(sizeof(long int) * N);

	for(i = 0; i < N; i++)
	{
		scanf("%li", &s[i]);
		rev_s[N - 1- i] = s[i];
	}

	left = malloc(sizeof(long int) * N);

	MaxIncreasingSubseq(s, N, left);

	right = malloc(sizeof(long int) * N);

	MaxDecreasingSubseq(rev_s, N, right);

	long int max = left[0] + right[N - 1];

	for(i = 1; i < N; i++)
	{
		if(left[i] + right[N - 1 - i] > max)
		{
			max = left[i] + right[N - 1 - i];
		}
	}

	printf("%li\n", max);

	return 0;
}
