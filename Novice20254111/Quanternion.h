#pragma once
#include <KamataEngine.h>
#include <Novice.h>
using namespace KamataEngine;

struct Quaternion{
	float x;
	float y;
	float z;
	float w;
};


Quaternion Multiply(const Quaternion& lhs,const Quaternion& rhs );
Quaternion idetityQuaternion();
Quaternion Conjugate(const Quaternion& quaternion);
float Norm(const Quaternion& quaternion);
Quaternion Normalize(const Quaternion& quaternion);
Quaternion Inverse(const Quaternion& quaternion);

void  QuaternionScreenPrintf(Vector2 pos,const Quaternion& quaternion, const char* label);