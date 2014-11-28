#pragma once
#include "../../lib/vector.hpp"

class CTransform{
public:
	CTransform() = default;
	CTransform(Vec2f pos, Vec2f rotate, Vec2f scale) :
		m_pos(pos),
		m_rotate(rotate),
		m_scale(scale){}

	//　位置を取得
	Vec2f GetPos()const{ return m_pos; }

	//　Xの座標を取得
	float GetPosX()const{ return m_pos.x(); }

	//　Yの座標を取得
	float GetPosY()const{ return m_pos.y(); }

	//　回転軸を取得
	Vec2f GetRotate()const{ return m_rotate; }

	//　大きさを取得
	Vec2f GetScale()const{ return m_scale; }

	//　横幅を取得
	float GetScaleX()const{ return m_scale.x(); }

	//　縦幅を取得
	float GetScaleY()const{ return m_scale.y(); }

	//　位置を設定
	void Position(const Vec2f& value){
	m_pos = value;
	}
	void Position(const float x,const float y){
		m_pos.x() = x;
		m_pos.y() = y;
	}

	//　移動
	void Translate(const Vec2f& value){
		m_pos += value;
	}
	//　移動
	void Translate(const float x,const float y){
		m_pos.x() += x;
		m_pos.y() += y;
	}

	//　回転軸を設定
	void Rotation(const Vec2f& value){
		m_rotate = value;
	}
	//　回転軸を設定
	void Rotation(const float x,const float y){
		m_rotate.x() = x;
		m_rotate.y() = y;
	}

	//　回転
	void Rotate(const Vec2f& value){
		m_rotate += value;
	}
	//　回転
	void Rotate(const float x,const float y){
		m_rotate.x() += x;
		m_rotate.y() += y;
	}

	//　大きさを設定
	void Scaling(const Vec2f& value){
		m_scale = value;
	}
	//　大きさを設定
	void Scaling(const float x,const float y){
		m_scale.x() = x;
		m_scale.y() = y;
	}

	//　サイズ変更
	void Scale(const Vec2f& value){
		m_scale += value;
	}
	//　サイズ変更
	void Scale(const float x,const float y){
		m_scale.x() += x;
		m_scale.y() += y;
	}

private:
	Vec2f m_pos;				//　位置
	Vec2f m_rotate;				//　回転軸
	Vec2f m_scale;				//　大きさ
};