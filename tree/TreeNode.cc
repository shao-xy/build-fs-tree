#include <sstream>
using std::stringstream;
using std::endl;

#include "TreeNode.h"

#define MAX_TREE_DEPTH 5

bool TreeNode::hit(string relative_path, int depth)
{
	// if relative path is null, we succeed here.
	if (relative_path.length() == 0 || depth == MAX_TREE_DEPTH) {
		pop += 1;
		return true;
	}

	if (relative_path[0] != '/')	return false;

	pop += 1;

	size_t pos = relative_path.find('/', 1);
	string name = relative_path.substr(1, pos - 1);
	string child_relpath = (pos != string::npos) ? relative_path.substr(pos) : "";

	// Check if it ends with '/'. (We think it invalid)
	if (name.length() == 0)	return false;

	map<string, TreeNode*>::iterator it = children.find(name);
	TreeNode * child = NULL;
	if (it == children.end()) {
		// We don't have that node
		child = new TreeNode(this);
		children.insert(std::make_pair(name, child));
	}
	else {
		child = it->second;
	}

	return child->hit(child_relpath, depth + 1);
}

string TreeNode::show_subtree(string myname, bool withColor, int depth)
{
	stringstream ss;
	// indent
	if (depth) {
		ss << "   ";
	}
	for (int i = 0; i < depth - 1; i++) {
		ss << "|  ";
	}

	int children_size = children.size();
	string flag = children_size ? "*--+" : "*-->";
	ss << flag
	   << (withColor ? " \033[1;31m(" : " (")
	   << pop
	   << (withColor ? ")\033[0m " : ") ")
	   << myname << endl;

	for (map<string, TreeNode*>::iterator it = children.begin();
		it != children.end(); it++) {
		ss << it->second->show_subtree(it->first, withColor, depth + 1);
	}
	return ss.str();
}
