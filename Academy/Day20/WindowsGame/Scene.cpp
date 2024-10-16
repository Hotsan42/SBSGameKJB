#include "pch.h"
#include "Scene.h"

void Scene::Init()
{

}
void Scene::Render(HDC hdc)
{
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"CurrentScene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Scene::Update()
{
}
void Scene::Release()
{

}
void Scene::SpawnGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr) return;

	_gameObjects.push_back(gameObject);
}
void Scene::DespawnGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr) return;

	auto findIt = find(_gameObjects.begin(), _gameObjects.end(), gameObject);

	if (findIt !=)
}