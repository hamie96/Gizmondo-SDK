#include <vector>
#include <string>

class AMenu;

class MenuContainer
{
	std::vector<AMenu *> d_menus;
public:
	AMenu * d_blocking;
	typedef std::vector<AMenu *>::const_iterator const_iterator;

public:
	MenuContainer();
	~MenuContainer();

	int loadMenu(const std::string & filename);

	const_iterator begin() const
	{ return d_menus.begin(); }
	const_iterator end() const
	{ return d_menus.end(); }

	void addMenuEntry(const std::string & line);	
};
