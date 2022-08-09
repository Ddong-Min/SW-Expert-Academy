#include <array>
#include <iostream>
#include <string>

using namespace std;

struct Node {
	int key;
	int data;
	Node* left, * right;
	int left_x, right_x;
};

constexpr size_t MAX_NODE = 10000;

int node_count = 0;
Node node_pool[MAX_NODE];
int calcul;

Node* new_node(int x, int data, int left, int right) {
	node_pool[node_count].key = x;
	node_pool[node_count].data = data;
	node_pool[node_count].left = nullptr;
	node_pool[node_count].right = nullptr;
	node_pool[node_count].left_x = left;
	node_pool[node_count].right_x = right;

	return &node_pool[node_count++];
}

class BinarySearchTree {
	Node* root;

public:
	BinarySearchTree() = default;

	void init() {
		root = nullptr;
		node_count = 0;
	}

	void insert(int x, int data, int left, int right) {
		root = insert_rec(root, x, data, left, right, 1);
	}

	void traversal() const {
		calcul = traversal_rec(root);
	}


public:
	Node* insert_rec(Node* node, int x, int data, int left, int right, int T) {
		if (node == nullptr && T == 1) return new_node(x, data, left, right);
		else if (node == nullptr && T == 0) return nullptr;

		if (x == node->left_x) {
			node->left = insert_rec(node->left, x, data, left, right, 1);
		}
		else if (x == node->right_x) {
			node->right = insert_rec(node->right, x, data, left, right, 1);
		}
		else {
			node->left = insert_rec(node->left, x, data, left, right, 0);
			node->right = insert_rec(node->right, x, data, left, right, 0);
		}
		return node;
	}

	int traversal_rec(Node* node) const {
		if (node == nullptr) return 0;
		int left_data, right_data;

		left_data = traversal_rec(node->left);
		
		right_data = traversal_rec(node->right);

		if (node->data == -1 || node->data == -2 || node->data == -3 || node->data == -4) {

			int result = node->data;
			if (node->data == -1) node->data = left_data + right_data;
			if (node->data == -2) node->data = left_data - right_data;
			if (node->data == -3) node->data = left_data * right_data;
			if (node->data == -4) node->data = left_data / right_data;
		}
		return node->data;



	}
};

int main(int argc, char** argv)
{
	BinarySearchTree tree{};
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		tree.init();
		int x, left, right, size;
		int i, data2;
		string data;
		cin >> size;

		for (i = 1; i <= size; i++) {
			cin >> x >> data;
			if (data == "+" || data == "-" || data == "*" || data == "/") {
				cin >> left >> right;
				if (data == "+") data2 = -1;
				if (data == "-") data2 = -2;
				if (data == "*") data2 = -3;
				if (data == "/") data2 = -4;
				tree.insert(x, data2, left, right);
			}
			else {
				data2 = stoi(data);
				tree.insert(x, data2, 0, 0);
			}


		}

		cout << '#' << test_case << ' ';
		tree.traversal();
		cout << calcul << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}