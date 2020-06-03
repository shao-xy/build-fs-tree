#include <iostream>
using std::cout;
using std::endl;

#include "tree/Tree.h"

int main(int argc, char * argv[])
{
	Tree t;
	t.hit("/test/1/2/3/4/a/b/c/d/e");
	t.hit("/test/1/2/6/7/a/b/c/d/");
	cout << t.show_tree() << endl;
	return 0;
}
