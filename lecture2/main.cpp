#include <iostream>
#include <string>

using namespace std;

class FooString {
    string buf;
public:
    FooString(string tbuf) {
        buf = tbuf;
    };
    ~FooString() {
        buf.erase();
    };
    void show() {
        cout << buf << endl;
    };
    int compare(FooString tbuf) {
        if (buf == tbuf.buf) {
            return true;
        }
        return false;
    };
};

int main() {
    FooString a("123");
    FooString b("slkjsdflkjsd");
    FooString c("Cry");
    FooString d("Anaconda");
    a.show();
    cout<<a.compare(a)<<endl;
    cout << a.compare(b)<< endl;
    cout << a.compare(c)<< endl;
    cout << a.compare(d)<< endl;
    return 0;
}