#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

#include "j1Player.h"

j1Player::j1Player() : j1Module()
{
	name.create("player");
	bool j1Player::awake(const pugi::xml_node & frog) {

		frog.front_idle_loop = frog.child("frog").child("animation").child("front_idle").attribute("loop").as_bool();
		frog.front_idle_speed = frog.child("frog").child("front_idle").attribute("speed").as_float();

		pugi::xml_node it = frog.child("frog").child("animation").child("front_idle").first_child;
		while (it != nullptr)
		{
			SDL_Rect rect;

			rect.x = it.attribute("x").as_int();
			rect.y = it.attribute("y").as_int();
			rect.w = it.attribute("w").as_int();
			rect.h = it.attribute("h").as_int();

			front_idle.push_back(rect);

			it.next_sibling();
	}

		frog.side_idle_loop = frog.child("frog").child("animation").child("side_idle").attribute("loop").as_bool();
		frog.side_idle_speed = frog.child("frog").child("side_idle").attribute("speed").as_float();

		pugi::xml_node it = frog.child("frog").child("animation").child("side_idle").first_child;
		while (it != nullptr)
		{
			SDL_Rect rect;

			rect.x = it.attribute("x").as_int();
			rect.y = it.attribute("y").as_int();
			rect.w = it.attribute("w").as_int();
			rect.h = it.attribute("h").as_int();

			side_idle.push_back(rect);

			it.next_sibling();
		}

		frog.jump = frog.child("frog").child("animation").child("jump").attribute("loop").as_bool();
		frog.side_idle_speed = frog.child("frog").child("jump").attribute("speed").as_float();

		pugi::xml_node it = frog.child("frog").child("animation").child("jump").first_child;
		while (it != nullptr)
		{
			SDL_Rect rect;

			rect.x = it.attribute("x").as_int();
			rect.y = it.attribute("y").as_int();
			rect.w = it.attribute("w").as_int();
			rect.h = it.attribute("h").as_int();

			jump.push_back(rect);

			it.next_sibling();
		}
}

// Destructor
j1Player::~j1Player()
{}