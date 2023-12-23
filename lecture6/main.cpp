#include <iostream>
#include <memory>

using namespace std;


class Binary_tree {
private:
	struct Node {
		int data;
		shared_ptr<Node> right_child;
		shared_ptr<Node> left_child;
	}; shared_ptr<Node> root;
public:
	Binary_tree(int root_data) {
		root = make_shared<Node>(root_data);
	}
	~Binary_tree() {};

	void insert(int insert_data,shared_ptr<Node> cur_node = nullptr) {
		if (cur_node == nullptr) {
			cur_node = root;
		}
		if (cur_node->data >= insert_data){
			if (cur_node->left_child == nullptr) {
				cur_node->left_child = make_shared<Node>(insert_data);
			}
			else {
				insert(insert_data, cur_node->left_child);
			}
		}
		else {
			if (cur_node->right_child == nullptr) {
				cur_node->right_child = make_shared<Node>(insert_data);
			}
			else {
				insert(insert_data, cur_node->right_child);
			}
		}
	}
	void print() {
		shared_ptr<Node> cur_node_pr = root;
		_print(cur_node_pr);
	}
	void _print(shared_ptr<Node> cur_node_pr){
		if (cur_node_pr != nullptr) {
			cout << cur_node_pr->data <<endl;
			_print(cur_node_pr->left_child);
			_print(cur_node_pr->right_child);
		}
	}
};




int main() {
	Binary_tree tree{50};
	tree.insert(40);
	tree.insert(30);
	tree.insert(1000);
	tree.insert(500);
	tree.insert(7);
	tree.print();
}