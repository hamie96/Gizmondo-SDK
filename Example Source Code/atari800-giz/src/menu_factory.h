#include <string>

class AMenu;

class AMenuFactory
{
public:
	static AMenu * build(const std::string & config);
};

