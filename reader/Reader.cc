#include "LineManipulator.h"
#include "Reader.h"

bool Reader::readline(string & line)
{
	if (!is_open() || ifs.eof())	return false;

	string bufferline;
	if (!std::getline(ifs, bufferline))	return false;

	if (!manip) {
		line = bufferline;
		return true;
	}
	else {
		return manip->manipulate(bufferline, line);
	}
}
