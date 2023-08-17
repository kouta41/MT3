#pragma once
#include <Novice.h>
#include <Vector3.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <Matrix4x4.h>
#include <cmath>
#include <cassert>
#include <algorithm>

struct Sphere {
	Vector3 center;
	float radius;
};

struct Line {
	Vector3 origin;//始点
	Vector3 diff;//終点への差分ベクトル
};
struct Ray {
	Vector3 origin;//始点
	Vector3 diff;//終点への差分ベクトル
};
struct Segment {
	Vector3 origin;//始点
	Vector3 diff;//終点への差分ベクトル
};

Vector3 Add(const Vector3& v1, const Vector3& v2);
Vector3 Subtract(const Vector3& v1, const Vector3& v2);
Vector3 Transforme(const Vector3& vector, const Matrix4x4& matrix);
void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);
void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, unsigned int color);

Vector3 Multiply(float scalar, const Vector3& v);
float Dot(const Vector3& v1, const Vector3& v2);
Vector3 Normalize(const Vector3& v1);
Matrix4x4 Multiply(Matrix4x4 m1, Matrix4x4 m2);

Vector3 Project(const Vector3& v1, const Vector3& v2);
Vector3 ClosestPoint(const Vector3& point, const Segment& segment);