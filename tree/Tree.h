#ifndef _TREE_TREE_H_
#define _TREE_TREE_H_

#include <string>
using std::string;

#include "TreeNode.h"

class Tree {
	TreeNode root;

public:
	Tree() {}
	~Tree() {}

	bool hit(string path);
	string show_tree();
};

#endif /* tree/Tree.h */
