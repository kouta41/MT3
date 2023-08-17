#include"MathFunction.h"

Vector3 Add(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	return Vector3{ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
}

Vector3 Transforme(const Vector3& vector, const Matrix4x4& matrix) {
	Vector3 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;
}

// 回転行列
Matrix4x4 Multiply(Matrix4x4 m1, Matrix4x4 m2) {
	Matrix4x4 m4;
	m4.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] +
		m1.m[0][3] * m2.m[3][0];
	m4.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] +
		m1.m[0][3] * m2.m[3][1];
	m4.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] +
		m1.m[0][3] * m2.m[3][2];
	m4.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] +
		m1.m[0][3] * m2.m[3][3];

	m4.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] +
		m1.m[1][3] * m2.m[3][0];
	m4.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] +
		m1.m[1][3] * m2.m[3][1];
	m4.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] +
		m1.m[1][3] * m2.m[3][2];
	m4.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] +
		m1.m[1][3] * m2.m[3][3];

	m4.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] +
		m1.m[2][3] * m2.m[3][0];
	m4.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] +
		m1.m[2][3] * m2.m[3][1];
	m4.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] +
		m1.m[2][3] * m2.m[3][2];
	m4.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] +
		m1.m[2][3] * m2.m[3][3];

	m4.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] +
		m1.m[3][3] * m2.m[3][0];
	m4.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] +
		m1.m[3][3] * m2.m[3][1];
	m4.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] +
		m1.m[3][3] * m2.m[3][2];
	m4.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] +
		m1.m[3][3] * m2.m[3][3];
	return m4;
}

Vector3 Multiply(float scalar, const Vector3& v) {
	return { v.x * scalar,v.y * scalar,v.z * scalar };
}

void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix) {
	const float kGridHalfwidth = 2.0f;
	const uint32_t kSubdivision = 10;
	const float kGridEvery = (kGridHalfwidth * 2.0f) / float(kSubdivision);
	Vector3 worldVerticles[2];
	Vector3 screenVerticles[2];
	Vector3 ndcVertices;
	//横
	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex) {
		worldVerticles[0] = { kGridEvery * xIndex - kGridHalfwidth,0.0f,kGridHalfwidth };
		worldVerticles[1] = { kGridEvery * xIndex - kGridHalfwidth,0.0f,-kGridHalfwidth };
		for (uint32_t i = 0; i < 2; ++i) {
			ndcVertices = Transforme(worldVerticles[i], viewProjectionMatrix);
			screenVerticles[i] = Transforme(ndcVertices, viewportMatrix);
		}
		Novice::DrawLine((int)screenVerticles[0].x, (int)screenVerticles[0].y, (int)screenVerticles[1].x, (int)screenVerticles[1].y, 0x0000FF);
	}

	for (uint32_t zIndex = 0; zIndex <= kSubdivision; ++zIndex) {
		worldVerticles[0] = { kGridHalfwidth,0.0f,kGridEvery * zIndex - kGridHalfwidth };
		worldVerticles[1] = { -kGridHalfwidth,0.0f, kGridEvery * zIndex - kGridHalfwidth };

		for (uint32_t i = 0; i < 2; ++i) {
			ndcVertices = Transforme(worldVerticles[i], viewProjectionMatrix);
			screenVerticles[i] = Transforme(ndcVertices, viewportMatrix);
		}
		Novice::DrawLine((int)screenVerticles[0].x, (int)screenVerticles[0].y, (int)screenVerticles[1].x, (int)screenVerticles[1].y, 0x000000FF);
	}
}

void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, unsigned int color) {
	const uint32_t kSubDivision = 30;
	const float kLonEvery = 2.0f * (float)M_PI / float(kSubDivision);
	const float kLatEvery = (float)M_PI / float(kSubDivision);

	for (uint32_t latIndex = 0; latIndex < kSubDivision; ++latIndex) {
		float lat = -1.0f * (float)M_PI / 2.0f + kLatEvery * latIndex;

		for (uint32_t lonIndex = 0; lonIndex < kSubDivision; ++lonIndex) {
			float lon = lonIndex * kLonEvery;

			Vector3 a, b, c;
			a = { sphere.radius * std::cosf(lat) * std::cosf(lon), sphere.radius * std::sinf(lat), sphere.radius * std::cosf(lat) * std::sinf(lon) };
			a = Add(a, sphere.center);
			b = { sphere.radius * std::cosf(lat + kLatEvery) * std::cosf(lon), sphere.radius * std::sinf(lat + kLatEvery), sphere.radius * std::cosf(lat + kLatEvery) * std::sinf(lon) };
			b = Add(b, sphere.center);
			c = { sphere.radius * std::cosf(lat) * std::cosf(lon + kLonEvery), sphere.radius * std::sinf(lat), sphere.radius * std::cosf(lat) * std::sinf(lon + kLonEvery) };
			c = Add(c, sphere.center);

			a = Transforme(a, viewProjectionMatrix);
			a = Transforme(a, viewportMatrix);
			b = Transforme(b, viewProjectionMatrix);
			b = Transforme(b, viewportMatrix);
			c = Transforme(c, viewProjectionMatrix);
			c = Transforme(c, viewportMatrix);


			Novice::DrawLine(
				int(a.x), int(a.y),
				int(b.x), int(b.y),
				color
			);

			Novice::DrawLine(
				int(a.x), int(a.y),
				int(c.x), int(c.y),
				color
			);

		}
	}

};

float Dot(const Vector3& v1, const Vector3& v2) {
	float result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return result;
}

Vector3 Normalize(const Vector3& v1) {
	Vector3 Result = v1;
	float length = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	assert(length != 0);
	Result.x /= length;
	Result.y /= length;
	Result.z /= length;
	return Result;
}

//正射影ベクトル
Vector3 Project(const Vector3& v1, const Vector3& v2)
{
	Vector3 result;
	result = Multiply(Dot(v1, Normalize(v2)), Normalize(v2));
	return result;
}
//最近接点
Vector3 ClosestPoint(const Vector3& point, const Segment& segment)
{
	float length = sqrt(segment.diff.x * segment.diff.x + segment.diff.y * segment.diff.y + segment.diff.z * segment.diff.z);
	Vector3 normaliseSegment = { segment.diff.x / length,segment.diff.y / length,segment.diff.z / length };

	float distance = Dot(Subtract(point, segment.origin), normaliseSegment);
	distance = std::clamp(distance, 0.0f, length);
	Vector3 proj = Multiply(distance, normaliseSegment);
	return Add(segment.origin, proj);
};