#pragma once

#include "Transform.h"

namespace JOY
{

	class EngineObject;

	class TransformComponent
	{
		friend class EngineObject;

	public:
		TransformComponent() : m_engineObject(nullptr) {};
		TransformComponent(EngineObject* engineObject) : m_engineObject(engineObject) {}
		virtual ~TransformComponent();

		Transform m_transform;

	private:
		EngineObject* m_engineObject;
	};

}