#pragma once

#include <cmath>

/// <summary>
/// 2次元ベクトル
/// </summary>
/// <typeparam name="T">テンプレート</typeparam>
template <typename T>
struct MyVector2 final {
    T x;
    T y;

    /// <summary>
    /// ベクトル同士の加算
    /// </summary>
    /// <param name="other">加算するベクトル</param>
    /// <returns>加算後のベクトル</returns>
    MyVector2 operator+(const MyVector2 &other) const {
        return { x + other.x, y + other.y };
    }

    /// <summary>
    /// ベクトル同士の減算
    /// </summary>
    /// <param name="other">減算するベクトル</param>
    /// <returns>減算後のベクトル</returns>
    MyVector2 operator-(const MyVector2 &other) const {
        return { x - other.x, y - other.y };
    }

    /// <summary>
    /// スカラー乗算
    /// </summary>
    /// <param name="scalar">乗数</param>
    /// <returns>乗算後のベクトル</returns>
    MyVector2 operator*(T scalar) const {
        return { x * scalar, y * scalar };
    }

    /// <summary>
    /// スカラー除算
    /// </summary>
    /// <param name="scalar">除数</param>
    /// <returns>除算後のベクトル</returns>
    MyVector2 operator/(T scalar) const {
        return { x / scalar, y / scalar };
    }

    /// <summary>
    /// 等価比較
    /// </summary>
    /// <param name="other">比較対象のベクトル</param>
    /// <returns>等しい場合にtrue、そうでない場合にfalse</returns>
    bool operator==(const MyVector2 &other) const {
        return x == other.x && y == other.y;
    }

    /// <summary>
    /// 不等価比較
    /// </summary>
    /// <param name="other">比較対象のベクトル</param>
    /// <returns>等しくない場合にtrue、そうでない場合にfalse</returns>
    bool operator!=(const MyVector2 &other) const {
        return !(*this == other);
    }

    /// <summary>
    /// 加算代入
    /// </summary>
    /// <param name="other">加算するベクトル</param>
    /// <returns>加算後のベクトル</returns>
    MyVector2 &operator+=(const MyVector2 &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    /// <summary>
    /// 減算代入
    /// </summary>
    /// <param name="other">減算するベクトル</param>
    /// <returns>減算後のベクトル</returns>
    MyVector2 &operator-=(const MyVector2 &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    /// <summary>
    /// スカラー乗算代入
    /// </summary>
    /// <param name="scalar">乗数</param>
    /// <returns>乗算後のベクトル</returns>
    MyVector2 &operator*=(T scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    /// <summary>
    /// スカラー除算代入
    /// </summary>
    /// <param name="scalar">除数</param>
    /// <returns>除算後のベクトル</returns>
    MyVector2 &operator/=(T scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    /// <summary>
    /// 正規化
    /// </summary>
    /// <returns>正規化されたベクトル</returns>
    MyVector2 Normalized() const {
        T length = std::sqrt(x * x + y * y);

        if (length == 0) {
            return { 0, 0 };
        }

        return { x / length, y / length };
    }

    /// <summary>
    /// 正規化 (自身を更新)
    /// </summary>
    /// <returns>正規化された自身の参照</returns>
    MyVector2 &Normalize() {
        T length = std::sqrt(x * x + y * y);

        if (length == 0) {
            x = 0;
            y = 0;
            return *this;
        }

        x /= length;
        y /= length;

        return *this;
    }
};