#pragma once

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace JOY
{

	class Transform
	{
	public:
		Transform();
		virtual ~Transform();

		const glm::mat4& getMatrix44() const { return m_Matrix44; }

		void SetIdentity() { m_Matrix44 = glm::mat4(1.f); }

	private:
		glm::mat4 m_Matrix44;
	};

}

