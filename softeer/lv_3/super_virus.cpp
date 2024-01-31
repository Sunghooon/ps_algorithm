// https://softeer.ai/practice/6292
#include <iostream>

#define RANGE 1000000007

using namespace std;

long long int divide(long long int P, long long int N)
{
	if (N == 1) return P;
	long long int answer = divide(P, N / 2);

	if(N % 2 == 0)
		answer = (answer % RANGE * answer % RANGE) % RANGE;
	else  // N%2 == 1
		answer = (answer%RANGE * answer % RANGE * P % RANGE) % RANGE;
	
	return answer;
}
int main()
{
	long long int K, P, N;
	cin >> K >> P >> N;
	// N : 1 0000 0000 0000 0000 (2^39...)
	//      10 0000 0007
	
	cout << (divide(P, 10*N) * K) % RANGE;
	return 0;
}