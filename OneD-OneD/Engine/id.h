#pragma once
#include <string>
#include "engine.h"

class ENGINE_API ID
{
public:
	ID();
	ID(const std::string& id) : m_id(id) {}
	ID(const char* id) : m_id(id) {}
	bool operator == (const ID& id) const { return m_id == id.m_id; }
	bool operator != (const ID& id) const { return m_id != id.m_id; }

	bool IsValid() const
	{
		return (m_id != "");
	}

	static size_t ms_uniqueID;
	static std::string GetUniqueID();
	
	std::string GetIDString() { return m_id; }
protected:
	std::string m_id;
};
