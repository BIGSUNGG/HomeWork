#pragma once
class Monster
{
public:
	Monster();
	~Monster();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	shared_ptr<Collider> GetCollider() { return _collider; }

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _collider;
};

