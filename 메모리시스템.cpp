#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace  std;

int total;
set<pair<int, int>> empty_blocks;
map<int, int> alloc;

void init(int N) {
	total = N;
	empty_blocks.clear();
	empty_blocks.emplace(N, 0);

}

int allocate(int mSize) {
	auto it  = empty_blocks.lower_bound()
}
