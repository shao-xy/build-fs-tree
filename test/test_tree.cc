#include <iostream>
using std::cout;
using std::endl;

#include "tree/Tree.h"

int main(int argc, char * argv[])
{
	Tree t;
	//t.hit("/test/1/2/3/4/a/b/c/d/e");
	//t.hit("/test/1/2/6/7/a/b/c/d/");
	t.hit("/test/1/2");
	t.hit("/test/1/3");
	t.hit("/test/2/3");
	cout << t.show_tree(true) << endl;
	return 0;
}
