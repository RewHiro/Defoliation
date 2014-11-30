#pragma once
#include "../Object.h"
#include "../../../lib/vector.hpp"
#include "../../utility/Font.h"
#include <functional>
#include <chrono>

class CScore : public Object{
public:

	enum class Type{
		PLUS_SCORE,
		MINUS_SCORE,
		PLUS_SCORE_TIME,
		MAINUS_SCORE_TIME,
	};

	CScore(Vec2f& pos, int score, Type type);
	CScore(Vec2f& pos, int score, std::chrono::seconds& time, Type type);

	void Update();

	void Draw();

private:
	int m_score;
	int m_alpha;
	std::chrono::seconds m_time;
	std::unique_ptr<Font>m_font;
	Type m_type;
	std::unordered_map<Type, std::function<void()>>m_select_draw;

	void Remove();

	void PlusScoreDraw();
	void MinusScoreDraw();
	void PlusScoreTimeDraw();
	void MinusScoreTimeDraw();

	void RegistSelectDraw();
};

