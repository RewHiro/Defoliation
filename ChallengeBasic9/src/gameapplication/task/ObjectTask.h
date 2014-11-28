#pragma once
#include "../object/manager/ObjectManager.h"
#include <map>
#include <memory>
#include <string>

class CObjectTask{
public:
	CObjectTask() = default;

	//　登録
	void Regist(const int order_of_priority,std::unique_ptr<CObjectManager>manager){
		m_task.emplace(order_of_priority, std::move(manager));
	}

	//　更新
	void Update(){
		for (auto& task : m_task){
			task.second->Update();
		}
	}

	//　描画
	void Draw(){
		for (auto& task : m_task){
			task.second->Draw();
		}
	}

private:
	std::map<int, std::unique_ptr<CObjectManager>, std::greater<int>>m_task;			//　タスク
};