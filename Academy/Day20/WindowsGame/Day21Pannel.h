#pragma once
#include "GameObject.h"
class Day21Pannel : public GameObject
{
	DECLARE_CHILD(Day21Pannel, GameObject);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void Move(Vector2 dir);

private:
	float _speed = 300.0f;
};



