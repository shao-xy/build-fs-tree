#include "Tree.h"

#include "common/PathUtil.h"

bool Tree::hit(string path)
{
	string abs_path = PathUtil::polish(path);
	return root.hit(path);
}

string Tree::show_tree()
{
	return root.show_subtree("/");
}
