#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N, M;
	cin >> T;


	for (test_case = 1; test_case <= T; ++test_case)
	{	
		int t = 0;
		cin >> N >> M;
		int x;
		
		x = ((1 << N) - 1);
		if ((M & x) == x) printf("#%d ON\n", test_case);
		else printf("#%d OFF\n", test_case);	
	
	}	
	return 0;
}