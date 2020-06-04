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

string PathUtil::basename(const string path, bool remove_suffix)
{
	size_t pos = path.rfind('/');
	if (pos == string::npos)
		pos = -1;

	string bn = path.substr(pos + 1);
	if (remove_suffix) {
		pos = bn.rfind('.');
		if (pos != string::npos) {
			bn = bn.substr(pos + 1);
		}
	}
	return bn;
}
