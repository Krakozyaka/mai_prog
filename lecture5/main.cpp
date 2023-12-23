#include<iostream>
#include <string>

using namespace std;

template<typename PointerType>
class SP {
private:
	PointerType* pData; 
public:
	SP(PointerType* pValue) : pData(pValue) {
	}
	SP() {
		pData = nullptr;
	}
	~SP() {
		delete pData;
	}
	PointerType& operator* () {
		return *pData;
	}
	PointerType* operator-> () {
		return pData;
	}
};
struct Node {
	int data;
	SP<Node>* right_child;
	SP<Node>* left_child;
};

int main() {
	SP<string> smart = new string("abracadabra");
	SP<string> smart2 = new string("Student");
	cout << *smart<<endl;
	smart2->append("307");
	cout << *smart2<<endl;
}