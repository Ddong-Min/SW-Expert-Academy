#include<iostream>

using namespace std;

#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = getNode(-1);

}

void function_I(int point, int data) {
	Node* node = getNode(data);
	Node* prenode = head;
	for (int i = 0; i < point; i++) {
		prenode = prenode->next;
	}
	node->next = prenode->next;
	prenode->next = node;

}

void function_D(int point) {
	Node* prenode = head;
	for (int i = 0; i < point; i++) {
		prenode = prenode->next;
	}
	
	if (prenode->next->next != nullptr) prenode->next = prenode->next->next;
	else prenode->next == nullptr;
}

void function_C(int point, int data) {
	Node* prenode = head;

	for (int i = 0; i < point; i++) {
		prenode = prenode->next;
	}
	prenode->next->data = data;

}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M, L, data1;
		int point, data2;
		char cmd;
		init();
		cin >> N >> M >> L;
		Node* prenode = head;
		for (int i = 0; i < N; i++) {
			cin >> data1;
			Node* node = getNode(data1);
			prenode->next = node;
			prenode = prenode->next;
		}
		while (M >= 1) {
			cin >> cmd;
			switch (cmd) {
			case 'I':
				cin >> point >> data2;
				function_I(point, data2);
				break;

			case 'D':
				cin >> point;
				function_D(point);
				break;

			case 'C':
				cin >> point >> data2;
				function_C(point, data2);
				break;
			}
			M--;

		}
		prenode = head;
		for (int i = 0; i < L; i++) {
			if (prenode->next == nullptr) break;
			prenode = prenode->next;
		}
		if (prenode->next == nullptr) cout << "#" << test_case << " " << -1 << endl;
		else cout << "#" << test_case << " " << prenode->next->data << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}