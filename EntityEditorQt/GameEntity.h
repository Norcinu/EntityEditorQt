#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <string>

class GameEntity
{
public:
	virtual ~GameEntity(void);
	
	std::string damage;
	std::string position;
	std::string entity_type;
	std::string name;
	std::string side;

protected:
	GameEntity(void);
	GameEntity(const char *ent_type);	
};

class GameEntity2D : public GameEntity
{
public:
	GameEntity2D();
	GameEntity2D(const char *ent_type);
	~GameEntity2D();

	//VisImage *img;
};

class GameEntity3D : public GameEntity
{
public:
	GameEntity3D();
	GameEntity3D(const char *ent_type);
	~GameEntity3D();

	int z;

	//VisModel *model;
};


#endif
