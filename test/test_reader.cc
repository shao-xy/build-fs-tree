#include <iostream>
using std::cout;
using std::endl;

#include "reader/Reader.h"
#include "reader/ColumnSelector.h"

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
	Reader r("/etc/hosts", new Transformer());
	string s;
	while (r.readline(s)) {
		cout << s << endl;
	}

	Reader r2("/etc/hosts", new ColumnSelector(2, " "));
	while (r2.readline(s)) {
		cout << s << endl;
	}
	return 0;
}
