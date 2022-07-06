#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_rectCollider1 = make_shared<RectCollider>(Vector2(50,50));
	//_rectCollider2 = make_shared<RectCollider>(Vector2(100,50));
	_circleCollider1 = make_shared<CircleCollider>(50);
	//_circleCollider2 = make_shared<CircleCollider>(100);

	//_rectCollider2->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.5f };
	_circleCollider1->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.5f };
	_rectCollider1->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.5f };
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_rectCollider1->Update();
	//_rectCollider2->Update();
	_circleCollider1->Update();
	//_circleCollider2->Update();

	if (_circleCollider1->IsCollision(_rectCollider1 ,true))
		_circleCollider1->SetColorRed();
	else
		_circleCollider1->SetColorGreen();
}

void CollisionScene::Render()
{
	_rectCollider1->Render();
	//_rectCollider2->Render();
	_circleCollider1->Render();
	//_circleCollider2->Render();
}

void CollisionScene::PostRender()
{
	ImGui::SliderFloat("rect1PosX", &_rectCollider1->GetPos().x, 0, WIN_WIDTH);
	ImGui::SliderFloat("rect1PosY", &_rectCollider1->GetPos().y, 0, WIN_HEIGHT);
	ImGui::SliderFloat("rect1Angle", &_rectCollider1->GetAngle(), 0,  2*PI);

	//ImGui::SliderFloat("circle2PosX", &_circleCollider2->GetPos()._x, 0, WIN_WIDTH);
	//ImGui::SliderFloat("circle2PosY", &_circleCollider2->GetPos()._y, 0, WIN_HEIGHT);
}
