#ifndef _TREE_TREENODE_H_
#define _TREE_TREENODE_H_

#include <map>
using std::map;

#include <string>
using std::string;

class TreeNode {
	TreeNode * parent;
	map<string, TreeNode*> children;
	int pop;	// popularity

public:
	TreeNode(TreeNode * parent_ = NULL)
		: parent(parent_), pop(0) {}
	bool hit(string relative_path, int depth = 0);

	string show_subtree(string myname, int depth = 0);

	int get_pop() { return pop; }
};

#endif /* tree/TreeNode.h */
