#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "LC1B_18_ツシマ_コウタ	";


struct Vector3 {
	float x, y, z;
};

struct Matrix4x4 {
	float m[4][4];
};



//1平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 Make;
	Make.m[0][0] = 1;
	Make.m[1][1] = 1;
	Make.m[2][2] = 1;
	Make.m[3][3] = 1;
	Make.m[3][0] = translate.x;
	Make.m[3][1] = translate.y;
	Make.m[3][2] = translate.z;
	return Make;
}

//2拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 Make;
	Make.m[0][0] = scale.x;
	Make.m[1][1] = scale.y;
	Make.m[2][2] = scale.z;
	Make.m[3][3] = 1;
	return;
}

//3座標変換
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix) {
	return;
}
Vector3 translate{ 4.1f,2.6f,0.8f };
Vector3 scale{ 1.5f,5.2f,7.3f };
Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);
Matrix4x4 scaleMatrix = MakeScaleMatrix(scale);
Vector3 point{ 2.3f,3.8f,1.4f };
Matrix4x4 transformMatrix = {
	1.0f,2.0f,3.0f,4.0f,
	3.0f,1.0f,1.0f,2.0f,
	1.0f,4.0f,2.0f,3.0f,
	2.0f,2.0f,1.0f,3.0f
};
Vector3 transformed = Transform(point, transformMatrix);

static const int kRowHeight = 20;
static const int kColumnWindth = 60;
static const int kColumWidth = 60;
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label) {
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWindth, y + row * kRowHeight, "%6.02f", matrix.m[row][column]);
		}
	}
}
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumWidth * 3, y, "%s", label);
}
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		VectorScreenPrintf(0, 0, transformed, "transformed");
		MatrixScreenPrintf(0, 0, transformMatrix, "transformMatrix");
		MatrixScreenPrintf(0, kRowHeight*5, scaleMatrix, "scaleMatrix");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
