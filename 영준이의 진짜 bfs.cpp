
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int, int> p;

int n, m;
vector<int> adj[100001];
int parent[100001][18];        //parent[i][j] : i�� ����� 2^j��° ����
int level[100001], maxlevel;

void set_tree(int node, int pnode, int lv) {
    level[node] = lv;
    parent[node][0] = pnode;

    for (int i = 1; i <= maxlevel; i++) {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }

    for (int i = 0; i < adj[node].size(); i++) {
        int childnode = adj[node][i];
        if (childnode == pnode) continue;
        set_tree(childnode, node, lv + 1);
    }
}

int LCA(int a, int b) {
    //a, b�� LCA�� ã�� ��ȯ
    if (a == 1 || b == 1) return 1;

    //a, b�� level�� �� ���� ��忡 ����, 2^k��° ���� ��带 ã�� �ö󰣴�.
    int target = a, compare = b;
    if (level[a] < level[b]) swap(target, compare);

    //�� ����� level�� ���������� ����
    if (level[target] != level[compare]) {
        for (int i = maxlevel; i >= 0; i--) {
            if (level[parent[target][i]] >= level[compare])
                target = parent[target][i];
        }
    }

    //���� level�� �������Ƿ�, ���� ������ ã�´�.
    int ret = target;
    if (target != compare) {
        for (int i = maxlevel; i >= 0; i--) {
          

            if (parent[target][i] != parent[compare][i]) {
                target = parent[target][i];
                compare = parent[compare][i];
            }
            ret = parent[target][i];    
        }
    }

    return ret;
}

void init() {
    int p, c;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> p >> c;
        adj[p].push_back(c);
        adj[c].push_back(p);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    init();
    maxlevel = (int)floor(log2(100001));

    set_tree(1, 0, 1);

    cin >> m;
    int f, s;
    for (int i = 0; i < m; i++) {
        cin >> f >> s;
        printf("%d\n", LCA(f, s));
    }

    return 0;
}