#ifndef __j1PLAYER_H__
#define __j1PLAYER_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

class j1Player : public j1Module
{
public:
	j1Player();

	// Destructor
	virtual ~j1Player();
};

#endif // __j1PLAYER_H__