#ifndef __j1PLAYER_H__
#define __j1PLAYER_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"
#include "Animation.h"

class j1Player : public j1Module
{
public:
	j1Player();

	// Destructor
	virtual ~j1Player();
	bool awake::(const pugi::xml_node & frog); //no sé cómo añadir el archivo frog para que lo detecte

private:

	pugi::xml_document frog;
};

#endif // __j1PLAYER_H__