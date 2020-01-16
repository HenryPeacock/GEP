#pragma once
#ifndef RESOURCE_H
#define RESOURCE_H
#include <sr1/noncopyable>
#include <string>
#include "rend/Context.h"
#include "macros.h"

// ToDo: Move others outside of namespace

class Resources;
class Core;

class Resource : public std::sr1::noncopyable
{
public:
	std::string GetPath() { return m_path; }
	void SetPath(std::string _path) { m_path = _path; }
	virtual ~Resource();

	shared<Core> GetCore();
protected:
	friend class Resources;

	std::string m_path;
	weak<Core> m_core;
};


#endif