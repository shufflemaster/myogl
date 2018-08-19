#pragma once


// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void Mat44CreateLookAt(glm::mat4& mat44, const glm::vec3& from, const glm::vec3& to);
void DumpMat44(const char * name, const glm::mat4& mat4);
void DoMat44Tests();