#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_player = make_shared<Player>();
	_player->GetMain() = true;

	_enemy = make_shared<Player>();

	_aim = make_shared<Aim>();
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{
	for (auto bullet : _player->GetBullet())
	{
		if (bullet->_isActive == false)
			continue;
		if (bullet->GetCollider()->IsCollision(_enemy->GetCollider()))
		{
			bullet->_isActive = false;
			_enemy->GetTransform()->GetPos()._x = rand() % WIN_WIDTH;
			_enemy->GetTransform()->GetPos()._y = rand() % WIN_HEIGHT;
		}
	}

	_player->Update();
	_enemy->Update();
	_aim->Update();
}

void DungreedScene::Render()
{
	_player->Render();
	_enemy->Render();
	_aim->Render();
}

void DungreedScene::PostRender()
{
	ImGui::SliderFloat("PlayerPos X", &_player->GetTransform()->GetPos()._x, 0, 1000);
	ImGui::SliderFloat("PlayerPos Y", &_player->GetTransform()->GetPos()._y, 0, 1000);
}
