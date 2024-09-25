#pragma once

namespace Draw
{
	void TextOut(HDC hdc, int x, int y, wstring str);
	void Rectangle(HDC hdc, int x, int y, int width, int height);
	void Ellipse(HDC hdc, int x, int y, int width, int height);
};