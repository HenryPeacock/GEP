#pragma once
#ifndef PEACOCKENGINE_COMPONENT_H
#define PEACOCKENGINE_COMPONENT_H

#include <memory>
#include <iostream>
#include "macros.h"



namespace Peacock
{
	class Entity;

	class Component
	{
	public:
		virtual void onInitialize();
		virtual void onTick();
		virtual void onDisplay();
		shared<Entity> getEntity();

	private:
		weak<Entity> entity;
	};
}
#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
