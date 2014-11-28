#pragma once
#pragma comment (lib, "freetype253MT.lib")
#pragma comment (lib, "ftgl.lib")

#include <FTGL/ftgl.h>
#include "../Uncopyable.h"
#include <unordered_map>
#include <string>
#include <memory>

//=======================================
//フォントリスト
//=======================================

class FontList : private Uncopyable{
public:
	FontList();

	//　フォントのパスを取得
	std::shared_ptr<FTPixmapFont> GetFontPath(std::wstring& font_name){
		auto it = m_font_list.find(font_name);
		return it != m_font_list.end() ? it->second : std::make_shared<FTPixmapFont>("res/font/msgothic.ttc");
	}

private:
	std::unordered_map <std::wstring, std::shared_ptr<FTPixmapFont> >m_font_list;
};

