#include "framework.h"
#include "Player.h"

Player::Player()
{
	_texture = make_shared<Texture>(L"Resource/Player.png");
	_texture->GetTransform()->GetScale() = { 0.7f,0.7f };

	// Gun Setting
	_gunParent = make_shared<Transform>();
	_gunParent->SetParent(_texture->GetTransform());
	_gunParent->GetPos()._x = 70.0f;

	_gun = make_shared<Gun>();
	_gun->SetPlayer(_gunParent);

	// Bullets
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->_isActive = false;

		_bullets.emplace_back(bullet);
	}

	_col = make_shared<RectCollider>(Vector2(100,100));
	_col->SetParent(_texture->GetTransform());
}

Player::~Player()
{
}

void Player::Update()
{
	if (_isActive == false)
		return;
	Move();
	SetGun();
	Fire();

	_texture->Update();
	_gunParent->UpdateWorld();
	_gun->Update();
	_col->Update();

	for (auto& bullet : _bullets)
		bullet->Update();
}

void Player::Render()
{
	if (_isActive == false)
		return;
	_texture->Render();
	_gun->Render();
	_col->Render();

	for (auto& bullet : _bullets)
		bullet->Render();
}

void Player::Move()
{
	if (_isMain == false)
		return;
	if (KEY_PRESS('W'))
	{
		_texture->GetTransform()->GetPos()._y += _speed * DELTA_TIME;
	}
	if (KEY_PRESS('S'))
	{
		_texture->GetTransform()->GetPos()._y -= _speed * DELTA_TIME;
	}
	if (KEY_PRESS('A'))
	{
		_texture->GetTransform()->GetPos()._x -= _speed * DELTA_TIME;
	}
	if (KEY_PRESS('D'))
	{
		_texture->GetTransform()->GetPos()._x += _speed * DELTA_TIME;
	}
}

void Player::SetGun()
{
	// Gun Angle
	Vector2 dir = MOUSE_POS - _gunParent->GetWorldPos();
	dir.Normalize();
	_gun->GetTransform()->GetAngle() = dir.Angle();
}

void Player::Fire()
{
	if (_isMain == false)
		return;
	if (KEY_DOWN(VK_LBUTTON))
	{
		// ������� for��
		//for (auto& bullet : _bullets)
		//{
		//	if (bullet->_isActive == false)
		//	{
		//		bullet->_isActive = true;

		//		bullet->GetTransform()->GetPos() = _gunParent->GetWorldPos();

		//		Vector2 dir = MOUSE_POS - _gunParent->GetWorldPos();
		//		dir.Normalize();
		//		bullet->SetDirection(dir);
		//		
		//		break;
		//	}
		//}

		// ����
		vector<shared_ptr<Bullet>>::iterator iter = _bullets.begin();

		iter = std::find_if(_bullets.begin(), _bullets.end(), [](const shared_ptr<Bullet> bullet) -> bool
			{
				if (bullet->_isActive == false)
					return true;

				return false;
			});

		if (iter == _bullets.end())
			return;

		shared_ptr<Bullet> bullet = *iter;
		bullet->_isActive = true;

		bullet->GetTransform()->GetPos() = _gunParent->GetWorldPos();
		
		Vector2 dir = MOUSE_POS - _gunParent->GetWorldPos();
		dir.Normalize();
		bullet->SetDirection(dir);
	}
}