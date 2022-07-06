#pragma once
class Player
{
public:
	Player();
	~Player();

	void Update();
	void Render();

	void Move();
	void SetGun();
	void Fire();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	shared_ptr<Collider> GetCollider() { return _col; }

	vector<shared_ptr<class Bullet>>& GetBullets() { return _bullets; }

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _col;

	shared_ptr<Transform> _gunParent;
	shared_ptr<class Gun> _gun;

	vector<shared_ptr<class Bullet>> _bullets;
	UINT _poolCount = 30;

	float _speed = 150.0f;
};

