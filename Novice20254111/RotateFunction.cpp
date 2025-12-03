#include "RotateFunction.h"
#include "MathFunction.h"
#include "DrawFunction.h"
#include <numbers>
Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle)
{
    Vector3 a = Normalize(axis);
    float x = a.x, y = a.y, z = a.z;

    float c = std::cos(angle);
    float s = std::sin(angle);
    float t = 1.0f - c;

    Matrix4x4 m{};

    m.m[0][0] = t * x * x + c;
    m.m[0][1] = t * x * y - s * z;
    m.m[0][2] = t * x * z + s * y;
    m.m[0][3] = 0;

    m.m[1][0] = t * x * y + s * z;
    m.m[1][1] = t * y * y + c;
    m.m[1][2] = t * y * z - s * x;
    m.m[1][3] = 0;

    m.m[2][0] = t * x * z - s * y;
    m.m[2][1] = t * y * z + s * x;
    m.m[2][2] = t * z * z + c;
    m.m[2][3] = 0;

    m.m[3][0] = 0;
    m.m[3][1] = 0;
    m.m[3][2] = 0;
    m.m[3][3] = 1;

    return m;
}

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to)
{
    // 安全のためまず正規化
    Vector3 f = Normalize(from);
    Vector3 t = Normalize(to);

    float c = Dot(f, t);
    float s = Length(Cross(f, t));

    // 完全に同方向 (0度)
    if (c > 0.9999f) {
        return Makeidetity4x4();
    }

    // 完全に反対方向 (180度)
    if (c < -0.9999f) {
        // from に直交する安定した軸を生成
        Vector3 ortho =
            (std::abs(f.x) > std::abs(f.z)) ?
            Vector3{-f.y, f.x, 0.0f} :
            Vector3{0.0f, -f.z, f.y};

        ortho = Normalize(ortho);
        return MakeRotateAxisAngle(ortho, std::numbers::pi_v<float>);
    }

    // 一般ケース: 軸 = f × t
    Vector3 axis = Normalize(Cross(f, t));

    // 角度 = atan2(|f×t|, dot(f,t))
    float angle = std::atan2(s, c);

    return MakeRotateAxisAngle(axis, angle);
}