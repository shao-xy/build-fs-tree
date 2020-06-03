#include "PathUtil.h"

string PathUtil::polish(const string path)
{
	string rpath;
	if (path.substr(0, 4) == "#0x1") {
		rpath = path.substr(4);
	}
	else {
		rpath = path;
	}

	return rpath;
}
