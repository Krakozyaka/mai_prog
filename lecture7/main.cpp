#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class Multithread {
private:
	int cnt;
public: 
	bool flag = true;
	Multithread() {
		cnt = 0;
	}
	void increment() {
        for (int i = 0; i < 100; i++) {
            cnt++;
			this_thread::sleep_for(std::chrono::milliseconds(10));
        }
		flag = false;
	}
	void print() {
		while (flag){
			cout << cnt << endl;
			this_thread::sleep_for(std::chrono::milliseconds(5));
		}
	}
	
};

int main() {
	Multithread a;
	thread incr([&a]() {a.increment(); });
	thread printing([&a]() {a.print(); });
	incr.join();
	printing.join();
	return 0;
}
