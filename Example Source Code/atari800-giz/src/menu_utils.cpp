#include "menu_utils.h"

void tokenise(const std::string & str, char div, std::deque<std::string> * tokens)
{
	int lastPos = 0;
	int pos = 0;

	while (true)
	{
		pos = str.find(div, lastPos);
		int len = (pos != std::string::npos) ? (pos - lastPos) : std::string::npos;
		std::string token = str.substr(lastPos, len);
		tokens->push_back(token);

		if (pos == std::string::npos)
			break;
		else
			lastPos = pos+1;
	}
}

