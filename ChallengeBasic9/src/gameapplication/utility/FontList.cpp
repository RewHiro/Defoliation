#include "FontList.h"


FontList::FontList()
{
	m_font_list.emplace(L"メイリオ", std::make_shared<FTPixmapFont>("res/font/meiryo.ttc"));
	m_font_list.emplace(L"めんまフォント", std::make_shared<FTPixmapFont>("res/font/menma.ttf"));
	m_font_list.emplace(L"MS　ゴシック", std::make_shared<FTPixmapFont>("res/font/msgothic.ttc"));
	m_font_list.emplace(L"MS　明朝", std::make_shared<FTPixmapFont>("res/font/msmincho.ttc"));
	m_font_list.emplace(L"ボクのたんけんニッキ", std::make_shared<FTPixmapFont>("res/font/bokuno.otf"));
	m_font_list.emplace(L"ニコモジ", std::make_shared<FTPixmapFont>("res/font/nicomoji_1.00.ttf"));
	m_font_list.emplace(L"Royal", std::make_shared<FTPixmapFont>("res/font/Royal.ttf"));
	m_font_list.emplace(L"Pacifico", std::make_shared<FTPixmapFont>("res/font/Pacifico.ttf"));
	m_font_list.emplace(L"FatBoy", std::make_shared<FTPixmapFont>("res/font/FatboyUltra.otf"));
}
