#include "menu_container.h"

#include "menu_factory.h"
#include "menu_amenu.h"

MenuContainer::MenuContainer():
	d_blocking(0)
{
}

MenuContainer::~MenuContainer()
{
	std::vector<AMenu *>::const_iterator i;
	for (i=d_menus.begin(); i!=d_menus.end(); ++i)
		delete *i;
}

int MenuContainer::loadMenu(const std::string & filename)
{
	d_menus.clear();

	// Add default -> press all buttons to get back to main menu
	addMenuEntry("H:L|R|B|A|Y|X:UI:100");

	FILE * file = fopen(filename.c_str(), "r");
	if (file)
	{
		fseek(file, 0, SEEK_END);
		int length = ftell(file);
		fseek(file, 0, SEEK_SET);

		char * fileMem = (char *)malloc(length);
		fread(fileMem, length, 1, file);

		char * lineBuffer = (char *) malloc(1025);
		int lineCount = 0;
		for (int i=0; i<length; ++i)
		{
			if ((lineCount>=1024) || fileMem[i] == '\n' || fileMem[i] == '\r' )
			{
				lineBuffer[lineCount] = 0;
				addMenuEntry(lineBuffer);
				lineCount = 0;
				continue;
			}
			lineBuffer[lineCount++] = fileMem[i];
		}

		free(fileMem);
		free(lineBuffer);

		fclose(file);
		return 1;
	}
	else
		return 0;
}

void MenuContainer::addMenuEntry(const std::string & line)
{
	if (line.empty())
		return;

	if (line[0] == '#')
		return;

	AMenu * menu = AMenuFactory::build(line);
	if (menu != 0)
	{
		d_menus.push_back(menu);
	}
}

