#pragma once
#include <Novice.h>
#include<Vector3.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<Matrix4x4.h>
#include<cmath>
#include<cassert>

struct Sphere {
	Vector3 center;
	float radius;
};

Vector3 Add(const Vector3& v1, const Vector3& v2);
Vector3 Transforme(const Vector3& vector, const Matrix4x4& matrix);
void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);
void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, unsigned int color);