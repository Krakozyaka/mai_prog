#pragma once
#include <string>
#include <optional>

using namespace std;
template <typename DataType>
class List {
private:
	struct Node {
		Node* next;
		DataType data;
	} *head;
public:
	List() {
		head = nullptr;
	}
	List(List&& list_move) {
		head = list_move;
	} // move contructor;
	~List() {
		while (head != nullptr) {
			Node* cur_node = head;
			head = cur_node->next;
			delete cur_node;
		}
	}
	void InsertNode(DataType new_data, int position) {
		Node* new_Node = new Node{ nullptr, new_data };
		if (head == nullptr) {
			head = new_Node;
		}
		else if (position == 0) {
			new_Node->next = head;
			head = new_Node;
		}
		else {
			Node* prev_Node = GetNode(position - 1);
			new_Node->next = prev_Node->next;
			prev_Node->next = new_Node;
		}
	}
	void RemoveNode(int position) {
		if (position == 0) {
			Node* del = head;
			head = head->next;
			delete del;
		}
		else {
			Node* del_Node = GetNode(position);
			Node* prev_Node = GetNode(position - 1);
			prev_Node->next = del_Node->next;
			delete del_Node;
		}

	}
	Node* GetNode(size_t position) {
		Node* cur_node = head;
		for (int i = 0; i < position; i++) {
			cur_node = cur_node->next;
		}
		return cur_node;
	}
	optional <DataType> GetElement(size_t position) {
		Node* cur_node = head;
		for (int i = 0; i < position; i++) {
			cur_node = cur_node->next;
		}
		return cur_node->data;
	}
	void PrintList() {
		for (Node* cur_node = head; cur_node != nullptr; cur_node = cur_node->next) {
			cout << cur_node->data << '\t';
		}
		cout << endl;
	}
};