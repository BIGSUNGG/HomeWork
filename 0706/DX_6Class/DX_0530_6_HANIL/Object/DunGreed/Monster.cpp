#include "framework.h"
#include "Monster.h"

Monster::Monster()
{
	_quad = make_shared<Quad>(L"Resource/monster.png");
	_quad->GetTransform()->GetScale() = { 0.7f,0.7f };

	_collider = make_shared<RectCollider>(_quad->GetHalfSize());
	_collider->SetParent(_quad->GetTransform());
}

Monster::~Monster()
{
}

void Monster::Update()
{
	_quad->Update();
	_collider->Update();
}

void Monster::Render()
{
	_quad->Render();
	_collider->Render();
}
