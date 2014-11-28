#pragma once
#include "../Uncopyable.h"
#include "Transform.h"
#include "../../lib/vector.hpp"
#include <vector>
#include <memory>
#include <list>

//========================================
//オブジェクトクラス(基底クラス)
//========================================

class Object : private Uncopyable{
public:
	Object() = default;
	virtual ~Object() = default;

	//　更新
	virtual void Update() = 0;
	//　描画
	virtual void Draw() = 0;
	
	//　削除するか
	bool isRemove(){ return m_is_delete ? true : false; }

	//　位置を取得
	Vec2f GetHitPos()const{ return m_hit_model.GetPos(); }

	//　位置を取得
	Vec2f GetPos()const{ return m_model.GetPos(); }

	//　位置を取得
	Vec2f GetScale()const{ return m_hit_model.GetScale(); }

	//　アクティブか取得
	bool isActive()const{ return m_is_active; }

protected:
	CTransform m_model;										//　モデルの状態
	CTransform m_hit_model;									//　当たり判定用
	bool m_is_active = true;								//	アクティブな状態か
	bool m_is_delete = false;								//	削除するか
};