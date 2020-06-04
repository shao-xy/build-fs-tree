#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>

#include "common/PathUtil.h"
#include "reader/Reader.h"
#include "reader/ColumnSelector.h"
#include "tree/Tree.h"

void usage(const char * arg0)
{
	cout << "Usage: " << arg0 << " <input-file>" << endl;
}

string parse_args(int argc, char * argv[])
{
	if (argc != 2) {
		usage(argv[0]);
		exit(-1);
	}
	return string(argv[1]);
}

int main(int argc, char * argv[])
{
	string targetfile = parse_args(argc, argv);
	Tree t;
	Reader r(targetfile, new ColumnSelector(8));
	string s;
	int count = 0;
	while (r.readline(s)) {
		cout << "\rReading line: " << ++count;
		cout.flush();
		if (s.length())
			t.hit(s);
	}
	cout << endl;

	cout << t.show_tree(true) << endl;

	string outputfile = "result/" + PathUtil::basename(targetfile, true) + ".tree";
	std::ofstream ofs(outputfile);
	if (ofs.is_open()) {
		ofs << t.show_tree(false);
		ofs.close();
	}
	return 0;
}
