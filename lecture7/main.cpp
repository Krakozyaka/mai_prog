#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mutex1;
int cnt = 0;
class Multithread {
public: 
	bool flag = true;
	void increment() {
        for (int i = 0; i < 100; i++) {
            cnt++;
			this_thread::sleep_for(std::chrono::milliseconds(10));
        }
		flag = false;
	}
	void print() {
		while (flag) {
			cout << cnt << endl;
			this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
	
};

int main() {
	Multithread a;
	thread incr(&Multithread:: increment,&a);
	thread printing(&Multithread:: print,&a);
	incr.join();
	printing.join();
	return 0;
}
