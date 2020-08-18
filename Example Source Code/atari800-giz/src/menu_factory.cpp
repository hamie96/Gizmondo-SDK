#include "menu_factory.h"

#include "menu_utils.h"
extern "C"
{
#include "menu_keymap.h"
#include "atari_gp32.h"
}
#include "menu_akeymenu.h"
#include "menu_aheldmenu.h"
#include "menu_atogglemenu.h"
#include "menu_aslidermenu.h"
#include "menu_amenumenu.h"
#include "menu_akeyboardmenu.h"

AMenu * AMenuFactory::build(const std::string & config)
{
	std::deque<std::string> tokens;
	tokenise(config, ':', &tokens);

	if (tokens.size() < 3)
		return 0;

	char type = tokens[0].at(0);
	int driver = toGpKey(tokens[1].c_str());

	tokens.pop_front();
	tokens.pop_front();

	AMenu * amenu = 0;

	switch (type)
	{
	case 'A':
		amenu = new AKeyMenu(driver, tokens, true);
		break;

	case 'D':
		amenu = new AKeyMenu(driver, tokens,false);
		break;

	case 'U':
		amenu = new AKeyMenu(driver, tokens, false, false);
		break;

	case 'H':
		amenu = new AHeldMenu(driver, tokens);
		break;

	case 'T':
		amenu = new AToggleMenu(driver, tokens);
		break;

	case 'S':
		amenu = new ASliderMenu(driver, tokens);
		break;

	case 'M':
		amenu = new AMenuMenu(driver, tokens);
		break;

	case 'K':
		amenu = new AKeyboardMenu(driver, tokens);
		break;
	}

	return amenu;
}

