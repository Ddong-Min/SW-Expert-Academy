#include<iostream>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	
	for (int i = 1; i <= T; i++) {
		cin >> N;
		int k = N;
		int t = 0;
		while (1) {	
			int s = k;
			while (s) {
				t |= (1 << (s % 10));
				s /= 10;
				
			}
			if (t == 1023) break;
			k += N;

		}
		printf("#%d %d", i, k);
	}


}