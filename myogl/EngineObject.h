#pragma once

#include <vector>
#include <string>

namespace JOY
{
	class IComponent;

	class EngineObject
	{
	public:
		EngineObject(const char *name) : m_name(name) {}
		virtual ~EngineObject();

		const std::string& GetName() const { return m_name; }

	private:
		EngineObject();

		std::string m_name;
		std::vector<IComponent*> m_components;
	};

}