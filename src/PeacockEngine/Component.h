#pragma once
#ifndef PEACOCKENGINE_COMPONENT_H
#define PEACOCKENGINE_COMPONENT_H

#include <memory>
#include "macros.h"

class Entity;
class Core;

class Component
{
public:
	virtual void OnInitialize();
	virtual void OnTick();
	virtual void OnDisplay();

	shared<Entity> GetEntity();
	shared<Core> GetCore();

private:
	friend class Entity;
	weak<Entity> m_entity;
};

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
