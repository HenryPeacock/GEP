#include <memory>
#include "macros.h"
#include <list>

struct Entity
{
	Entity();
	~Entity();

	template <class T>
	shared<T> addComponent();
};

template<class T>
inline shared<T> Entity::addComponent()
{
	return shared<T>();
}
