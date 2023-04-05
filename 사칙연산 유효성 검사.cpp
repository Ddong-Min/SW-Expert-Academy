#include <array>
#include <iostream>
#include <string>

using namespace std;

struct Node {
	int key;
	char data;
	Node* left, * right;
	int left_x, right_x;
};

constexpr size_t MAX_NODE = 100;

int node_count = 0;
Node node_pool[MAX_NODE];

Node* new_node(int x, char data, int left, int right) {
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

	void insert(int x, char data, int left, int right) {
		root = insert_rec(root, x, data, left, right, 1);
	}

	void traversal() const {
		traversal_rec(root);
	}


public:
	Node* insert_rec(Node* node, int x, char data, int left, int right, int T) {
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

	void traversal_rec(Node* node) const {
		if (node == nullptr) return;

		traversal_rec(node->left);

		std::cout << node->data;

		traversal_rec(node->right);
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
		int i;
		char data;
		cin >> size;

		for (i = 1; i <= (size - 1) / 2; i++) {
			cin >> x >> data >> left >> right;
			tree.insert(x, data, left, right);
		}

		if (size % 2 == 0) {
			cin >> x >> data >> left;
			tree.insert(x, data, left, 0);
		}
		else {
			cin >> x >> data;
			tree.insert(x, data, 0, 0);
		}
		for (i;i < size;i++) {
			cin >> x >> data;
			tree.insert(x, data, 0, 0);
		}
		cout << '#' << test_case << ' ';
		tree.traversal();
		cout << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}