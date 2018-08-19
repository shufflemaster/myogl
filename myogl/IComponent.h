#pragma once

namespace JOY
{
	//The base class for all components
	class IComponent
	{
	public:
		IComponent();
		virtual ~IComponent();

		virtual void Init() = 0;
		virtual void Activate() = 0;
		virtual void Deactivate() = 0;
	};
}
