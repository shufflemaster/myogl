// Include standard headers
#include "stdafx.h"
// Include standard headers
#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>

#include "MatrixTests.h"

static void __cdecl odprintf(const char *format, ...)
{
	char    buf[4096], *p = buf;
	va_list args;
	int     n;

	va_start(args, format);
	n = _vsnprintf(p, sizeof buf - 3, format, args); // buf-3 is room for CR/LF/NUL
	va_end(args);

	p += (n < 0) ? sizeof buf - 3 : n;

	while (p > buf  &&  isspace(p[-1]))
		*--p = '\0';

	*p++ = '\r';
	*p++ = '\n';
	*p = '\0';

	OutputDebugStringA(buf);
}

void CreateLookAtForObject(glm::mat4& mat44, const glm::vec3& from, const glm::vec3& to)
{
	glm::vec3 forward = to - from;
	forward = glm::normalize(forward);

	glm::vec3 up(0.f, 1.f, 0.f);
	
	glm::vec3 right = glm::cross(up, forward);
	right = glm::normalize(right);

	up = glm::cross(forward, right);
	up = glm::normalize(up);

	//Set the first Column
	mat44[0][0] = right.x;
	mat44[0][1] = right.y;
	mat44[0][2] = right.z;
	mat44[0][3] = 0.f;
	//Set the second Column
	mat44[1][0] = up.x;
	mat44[1][1] = up.y;
	mat44[1][2] = up.z;
	mat44[1][3] = 0.f;
	//Set the third column
	mat44[2][0] = forward.x;
	mat44[2][1] = forward.y;
	mat44[2][2] = forward.z;
	mat44[2][3] = 0.f;
	//Set the fourth column
	mat44[3][0] = from.x;
	mat44[3][1] = from.y;
	mat44[3][2] = from.z;
	mat44[3][3] = 1.f;
}

void CreateLookAtForCamera(glm::mat4& mat44, const glm::vec3& from, const glm::vec3& to, bool dumpIntermediate)
{
	glm::vec3 forward = from - to;
	forward = glm::normalize(forward);

	glm::vec3 up(0.f, 1.f, 0.f);

	glm::vec3 right = glm::cross(up, forward);
	right = glm::normalize(right);

	up = glm::cross(forward, right);
	up = glm::normalize(up);

	//Set the first Column
	mat44[0][0] = right.x;
	mat44[0][1] = right.y;
	mat44[0][2] = right.z;
	mat44[0][3] = 0.f;
	//Set the second Column
	mat44[1][0] = up.x;
	mat44[1][1] = up.y;
	mat44[1][2] = up.z;
	mat44[1][3] = 0.f;
	//Set the third column
	mat44[2][0] = forward.x;
	mat44[2][1] = forward.y;
	mat44[2][2] = forward.z;
	mat44[2][3] = 0.f;
	//Set the fourth column
	mat44[3][0] = from.x;
	mat44[3][1] = from.y;
	mat44[3][2] = from.z;
	mat44[3][3] = 1.f;

	if (dumpIntermediate)
	{
		DumpMat44("CamLookAt44 Before Inversion", mat44);
	}

	//Need to invert!
	mat44 = glm::inverse(mat44);
}


void DumpMat44(const char * name, const glm::mat4& mat44)
{
	odprintf("%s Matrix Name: %s.\n", __func__, name);
	odprintf("r0c0=%f, r0c1=%f, r0c2=%f, r0c3=%f\n", mat44[0][0], mat44[1][0], mat44[2][0], mat44[3][0]);
	odprintf("r1c0=%f, r1c1=%f, r1c2=%f, r1c3=%f\n", mat44[0][1], mat44[1][1], mat44[2][1], mat44[3][1]);
	odprintf("r2c0=%f, r2c1=%f, r2c2=%f, r2c3=%f\n", mat44[0][2], mat44[1][2], mat44[2][2], mat44[3][2]);
	odprintf("r3c0=%f, r3c1=%f, r3c2=%f, r3c3=%f\n", mat44[0][3], mat44[1][3], mat44[2][3], mat44[3][3]);
}

void DoMat44Tests()
{
	glm::mat4 mat44;
	glm::vec3 from(0.f, 0.f, 10.f);
	glm::vec3 to(0.f, 0.f, 0.f);
	CreateLookAtForCamera(mat44, from, to, true);
	DumpMat44("CamLookAt44", mat44);

}