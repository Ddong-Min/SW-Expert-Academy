#include<iostream>

using namespace std;

const int MAX = 10000;
struct  Node {
	int parent, left, right;
	void init() {
		parent = left = right = 0;
	}
}tree[MAX];

int parent, child, cur;
int V, E, tg1, tg2;
bool check[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		tree[i].init();
		check[i] = false;
	}
}

void input() {
	cin >> V >> E >> tg1 >> tg2;

	for (int i = 0; i < E; i++) {
		cin >> parent >> child;
		//아직 왼쪽 자식이 존재하지 x
		if (tree[parent].left == 0)
			tree[parent].left = child;

		else
			tree[parent].right = child;

		tree[child].parent = parent;
	}
}

int DFS(int cur) {
	int ans = 1;

	if (tree[cur].left != 0)
		ans += DFS(tree[cur].left);

	if (tree[cur].right != 0)
		ans += DFS(tree[cur].right);

	return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		input();

		cur = tree[tg1].parent;
		while (true) {
			check[cur] = true;

			if (cur == 1) break;

			cur = tree[cur].parent;
		}
		
		cur = tree[tg2].parent;
		while (true) {
			if (check[cur]) {
				cout << '#' << test_case << ' '  << cur << ' ' << DFS(cur) << endl;
				break;
			}
			cur = tree[cur].parent;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}