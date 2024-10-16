#include "pch.h"
#include "Day21Pannel.h"

void Day21Pannel::Init()
{
	Super::Init();

	{
		Day21Pannel* gameObjecct = new Day21Pannel();
		gameObject->Init();
		gameObject->SetBody(CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 150, 200, 50));
		this->SpawnGameObject(gameObject);
	}

	_name = "pannel";
}
void Day21Pannel::Render(HDC, hdc)
{
	Super::Render(hdc);

	_body.Draw(hdc);
}
void Day21Pannel::Update()
{
	Super::Update();

	if (Input->GetKey(KeyCode::A))
	{
		this->Move(Vector2::Left());
	}

	if (Input->GetKey(KeyCode::D))
	{
		this->Move(Vector2::Right());
	}
}
void Day21Pannel::Release()
{
	Super::Release();
}

void Day21Pannel::Move(Vector2 dir)
{
	this->_body.pos.x -= _speed * Time->GetDeltaTime();
	this->_body.pos.x = clamp(this->_body.pos.x, this->GetWidth() / 2, WIN_SIZE_X - this->GetWidth() / 2);
}