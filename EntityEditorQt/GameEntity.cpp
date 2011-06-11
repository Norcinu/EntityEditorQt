#include "GameEntity.h"


GameEntity::GameEntity(void): damage("0"), entity_type("NULL"), name("Entity"), side("NONE"), position("0")
{
}

GameEntity::GameEntity(const char *ent_type) : damage(0), entity_type(ent_type), name("Entity"), side("NONE"), position("0")
{
}

GameEntity::~GameEntity(void)
{
}

GameEntity2D::GameEntity2D()
{
}

GameEntity2D::GameEntity2D(const char *ent_type)
{
	//x = y = damage = 0;
	damage = 
	entity_type = ent_type;
	name = "Entity";
	side = "None";
	position = "0 0";
}

GameEntity2D::~GameEntity2D() 
{
}

GameEntity3D::GameEntity3D()
{
}

GameEntity3D::GameEntity3D(const char *ent_type)
{
	damage = "0";
	entity_type = ent_type;
	name = "Entity";
	side = "None";
	position = "0 0 0";
}

GameEntity3D::~GameEntity3D()
{
}