#include<iostream>

using namespace std;

#define MAX_NODE 10000
extern void init();
extern void addNode2Num(int point, int num);
extern void removeNode(int point, int num);
extern void addNode2Tail(int num);
extern int getList(int output[MAX_NODE]);

static void command() {
	char cmd;
	int point, num, data, i, cnt;
	int output[MAX_NODE] = { 0 };
	cin >> cmd;
	switch (cmd) {
	case 'I':
		cin >> point >> num;
		addNode2Num(point, num);
		break;
	case 'D':
		cin >> point >> num;
		removeNode(point, num);
		break;

	case 'A':
		cin >> num;
		addNode2Tail(num);
		break;
	}

}

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


void addNode2Num(int point, int num)
{
	int data;
	Node* prev_node = head;
	for (int i = 1; i < point; i++) {
		prev_node = prev_node->next;
	}
	for (int i = 0; i < num; i++) {
		cin >> data;
		Node* node = getNode(data);
		if (i == 0 && point == 0) { // x가 0이면 맨 앞에 집어 넣음
			node->next = head->next;
			head->next = node;
			prev_node = node;
			continue;
		}
		node->next = prev_node->next;
		prev_node->next = node;
		prev_node = node;
	}
}

void removeNode(int point, int num)
{

	Node* prev_node = head;

	for (int i = 1; i < point; i++) {
		prev_node = prev_node->next;
	}

	for (int i = 1; i <= num; i++) {
		if (prev_node->next == nullptr) {
			prev_node = nullptr;
			break;
		}
		if (point == 0) {
			head = head->next;
			prev_node = head;
			continue;
		}
		prev_node->next = prev_node->next->next;
	}

}

void addNode2Tail(int num)
{
	int data;

	Node* prev_node = head;
	while (prev_node->next != nullptr) {
		prev_node = prev_node->next;
	}
	for (int i = 1; i <= num; i++) {
		cin >> data;
		Node* node = getNode(data);
		node->next = nullptr;
		prev_node->next = node;
		prev_node = node;

	}

}

int getList(int output[MAX_NODE])
{
	int i = 0;
	Node* node = head->next;
	if (head->next == nullptr) {
		return 0;
	}

	while (node->next != nullptr && i != 10) {
		output[i++] = node->data;
		node = node->next;
	}
	output[i++] = node->data;
	return i;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10, N, pw, M;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N;
		Node* node = head;
		for (int i = 0; i < N; i++) {
			cin >> pw;

			node->next = getNode(pw);
			node = node->next;

		}
		cin >> M;

		for (int i = 0; i < M; i++) {
			command();
		}
		int idx;
		node = head;
		cout << "#" << test_case << " ";
		for (idx = 0; idx < 10; idx++) {
			node = node->next;
			cout << node->data << " ";
		}
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}