#include <iostream>
using std::cout;
using std::endl;

#include "reader/Reader.h"

class Transformer : public LineManipulator {
public:
	Transformer() {}

	bool manipulate(string orig, string & ret) override {
		ret = orig.substr(0, 4);
		return true;
	}
};

int main(int argc, char * argv[])
{
	Reader r("/home/ceph/hosts", new Transformer());
	string s;
	while (r.readline(s)) {
		cout << s << endl;
	}
	return 0;
}
