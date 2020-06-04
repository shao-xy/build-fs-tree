#ifndef _COMMON_PATHUTIL_H_
#define _COMMON_PATHUTIL_H_

#include <string>
using std::string;

class PathUtil {
public:
	static string polish(const string path);
	static string basename(const string path, bool remove_suffix = false);
};

#endif /* common/PathUtil.h */
