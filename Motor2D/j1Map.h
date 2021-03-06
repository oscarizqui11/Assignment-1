#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// Create a struct for the collisions
struct Collision
{
	SDL_Rect GetColliderRect(Collision* collision) const;

	uint				object_id;
	p2SString			name;
	uint				x;
	uint				y;
	uint				width;
	uint				height;

};

// Create a struct for the map layer
struct MapLayers
{
	p2SString			name;
	uint				width;
	uint				height;

	uint*				tilelist = nullptr;
	inline uint TwoToOneDimension(int x, int y) const;
};

// ----------------------------------------------------
struct TileSet
{
	// TODO 7: Create a method that receives a tile id and returns it's Rectfind the Rect associated with a specific tile id
	SDL_Rect GetTileRect(int id, TileSet* texture) const;

	p2SString			name;
	int					firstgid;
	int					margin;
	int					spacing;
	int					tile_width;
	int					tile_height;
	SDL_Texture*		texture;
	int					tex_width;
	int					tex_height;
	int					num_tiles_width;
	int					num_tiles_height;
	int					offset_x;
	int					offset_y;
};

enum MapTypes
{
	MAPTYPE_UNKNOWN = 0,
	MAPTYPE_ORTHOGONAL,
	MAPTYPE_ISOMETRIC,
	MAPTYPE_STAGGERED
};
// ----------------------------------------------------

struct MapData
{
	int					width;
	int					height;
	int					tile_width;
	int					tile_height;
	SDL_Color			background_color;
	MapTypes			type;
	p2List<TileSet*>	tilesets;
	p2List<MapLayers*>	maplayers;
	p2List<Collision*>	collisions;
};

// ----------------------------------------------------

class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

	// Translates x,y coordinates from map positions to world positions
	iPoint MapToWorld(int x, int y) const;

	void ChangeDebugMode();

private:

	bool LoadMapGeneralProperties();
	bool LoadTilesetDetails(pugi::xml_node& tileset_node, TileSet* set);
	bool LoadTilesetImage(pugi::xml_node& tileset_node, TileSet* set);
	bool LoadSingleLayer(pugi::xml_node& node, MapLayers* layer);
	bool LoadColliderData(pugi::xml_node& node, Collision* collision);

public:

	MapData data;

private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
	bool				debug_mode;
};

#endif // __j1MAP_H__