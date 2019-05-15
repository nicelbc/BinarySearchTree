#include<iostream>
#include<deque>
using namespace std;

template<typename Key, typename Value>
class BST {

private:

	struct Node {
		Key key;
		Value value;
		Node *left;
		Node *right;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};

	Node *root;
	int count;

public:
	BST() {

		root = NULL;
		count = 0;
	}

	~BST() {
		//TODO
		destroy(root);
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}

	void insert(Key key, Value value) {

		root = insert(root, key, value);
	}

	bool contain(Key key) {
		return contain(root, key);
	}

	Value* search(Key key) {
		return search(root, key);
	}
	//≤„–Ú±È¿˙ level order
	void levelOrder() {

		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {

			Node *node = q.front();
			q.pop();

			cout << node->key << endl;
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}


private:
	//insert node(key,value) to the binarysearchTree whose treenode is node
	//return the new root
	Node * insert(Node *node, Key key, Value value) {

		if (node == NULL) {
			count++;
			return new Node(key, value);
		}

		if (key == node->key)
			node->value = value;
		else if (key < node->key)
			node->left = insert(node->left, key, value);
		else
			node->right = insert(node->right, key, value);

		return node;
	}

	bool contain(Node* node, Key key) {

		if (node == NULL)
			return false;
		if (key == node->key)
			return true;
		else if (key < node->key)
			return contain(node->left, key);
		else
			return contain(node->right, key);
	}

	Value* search(Node* node, Key key) {

		if (node == NULL)
			return NULL;
		if (key == node->key)
			return &(node->value);
		else if (key < node->key)
			return search(node->left, key);
		else
			return search(node->right, key);
	}

	void destroy(Node* node) {

		if (node != NULL) {
			destroy(node->left);
			destroy(node->right);

			delete node;
			count--;
		}
	}
};