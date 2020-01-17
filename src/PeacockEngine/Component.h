#pragma once
#ifndef PEACOCKENGINE_COMPONENT_H
#define PEACOCKENGINE_COMPONENT_H

#include <memory>
#include "macros.h"

class Entity;
class Core;

/**
 * Component class, which is the parent class of all components
 */
class Component
{
public:
	virtual void OnInitialize(); 
	virtual void OnTick();
	virtual void OnDisplay();

	shared<Entity> GetEntity(); ///< Gets the entity, allowing easy access to entity throughout the engine
	shared<Core> GetCore();     ///< Gets the core, allowing easy access to core throughout the engine

private:
	friend class Entity;
	weak<Entity> m_entity;
};

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
