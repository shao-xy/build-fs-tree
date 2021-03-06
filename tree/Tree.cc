#include "Tree.h"

#include "common/PathUtil.h"

bool Tree::hit(string path)
{
	string abs_path = PathUtil::polish(path);
	return root.hit(abs_path);
}

string Tree::show_tree(bool withColor)
{
	return root.show_subtree("/", withColor);
}
