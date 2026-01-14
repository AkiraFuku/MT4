#pragma once
#include <KamataEngine.h>
#include <Novice.h>
#include "Quanternion.h"
using namespace KamataEngine;

Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis,float angle);

Vector3 RotateVector(const Vector3& vector ,const Quaternion& quaternion);

Matrix4x4 MakeRotateMatrix(const Quaternion& q);

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis,float angle);

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to);