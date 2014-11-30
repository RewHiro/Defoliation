#include "Score.h"
#include <string>

CScore::CScore(Vec2f& pos,int score,Type type):
m_score(score),
m_alpha(255),
m_font(std::make_unique<Font>(60, L"FatBoy")),
m_type(type)
{
	m_model.Position(pos + Vec2f(0, 50));
	RegistSelectDraw();
}

CScore::CScore(Vec2f& pos, int score, std::chrono::seconds& time, Type type) :
m_score(score),
m_alpha(255),
m_time(time),
m_font(std::make_unique<Font>(60, L"FatBoy")),
m_type(type)
{
	m_model.Position(pos + Vec2f(0, 50));
	RegistSelectDraw();
}

void CScore::Update(){
	m_model.Translate(Vec2f(0, 1));
	m_alpha -= 2;
}

void CScore::Draw(){
	(m_select_draw.find(m_type)->second)();
}

void CScore::Remove(){
	if (m_alpha > 0)return;
	m_is_delete = true;
}

void CScore::PlusScoreDraw(){
	if (!m_font)return;
	m_font->DrawCenter(L"+"+std::to_wstring(m_score), m_model.GetPosX(), m_model.GetPosY(),
		color256(0, 0, 255, m_alpha));
}

void CScore::MinusScoreDraw(){
	if (!m_font)return;
	m_font->DrawCenter(L"-"+std::to_wstring(m_score), m_model.GetPosX(), m_model.GetPosY(),
		color256(255, 0, 0, m_alpha));
}

void CScore::PlusScoreTimeDraw(){
	if (!m_font)return;
	m_font->DrawCenter(L"+" + std::to_wstring(m_score) + L" +sec" + std::to_wstring(m_time.count()), m_model.GetPosX(), m_model.GetPosY(),
		color256(0, 0, 255, m_alpha));
}

void CScore::MinusScoreTimeDraw(){
	if (!m_font)return;
	m_font->DrawCenter(L"+" + std::to_wstring(m_score) + L" -sec" + std::to_wstring(m_time.count()), m_model.GetPosX(), m_model.GetPosY(),
		color256(255, 0, 0, m_alpha));
}

void CScore::RegistSelectDraw(){
	m_select_draw.emplace(Type::PLUS_SCORE, std::bind(&CScore::PlusScoreDraw, this));
	m_select_draw.emplace(Type::MINUS_SCORE, std::bind(&CScore::MinusScoreDraw, this));
	m_select_draw.emplace(Type::PLUS_SCORE_TIME, std::bind(&CScore::PlusScoreTimeDraw, this));
	m_select_draw.emplace(Type::MAINUS_SCORE_TIME, std::bind(&CScore::MinusScoreTimeDraw, this));
}