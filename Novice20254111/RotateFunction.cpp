#include "RotateFunction.h"
#include "MathFunction.h"
#include "DrawFunction.h"

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle)
{
	float c=std::cos(angle);
	float s=std::sin(angle);
	float t=1.0f-c;
	
	Matrix4x4 mat={};

// 1行目
    mat.m[0][0] = t * axis.x * axis.x + c;
    mat.m[0][1] = t * axis.x * axis.y + axis.z * s;
    mat.m[0][2] = t * axis.x * axis.z - axis.y * s;
    mat.m[0][3] = 0.0f; // 平行移動なし

    // 2行目
    mat.m[1][0] = t * axis.y * axis.x - axis.z * s;
    mat.m[1][1] = t * axis.y * axis.y + c;
    mat.m[1][2] = t * axis.y * axis.z + axis.x * s;
    mat.m[1][3] = 0.0f;

    // 3行目
    mat.m[2][0] = t * axis.z * axis.x + axis.y * s;
    mat.m[2][1] = t * axis.z * axis.y - axis.x * s;
    mat.m[2][2] = t * axis.z * axis.z + c;
    mat.m[2][3] = 0.0f;

    // --- 最下行 (同次座標成分) ---
    mat.m[3][0] = 0.0f;
    mat.m[3][1] = 0.0f;
    mat.m[3][2] = 0.0f;
    mat.m[3][3] = 1.0f; // 重要: ここは必ず 1


	
	return mat;


}
