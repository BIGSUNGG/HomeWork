#pragma once

class RectCollider;
class CircleCollider;

class Collider
{
protected:
	enum class Type
	{
		DEFALUT,
		CIRCLE,
		RECT
	};
public:
	
	virtual ~Collider();

	virtual void CreateData();

	virtual void Update();
	virtual void Render();

	Vector2& GetPos() { return _transform->GetPos(); }
	const Vector2& GetWorldPos() { return _transform->GetWorldPos(); }
	float& GetAngle() { return _transform->GetAngle(); }
	shared_ptr<Transform> GetTransform() { return _transform; }

	void SetColorRed() { _colorBuffer->SetColor(RED); }
	void SetColorGreen() { _colorBuffer->SetColor(GREEN); }

	bool IsCollision(shared_ptr<Collider> col , bool isObb = false);

	virtual bool IsCollision(const Vector2& pos) abstract;
	virtual bool IsCollision(shared_ptr<RectCollider> rect, bool isObb = false) abstract;
	virtual bool IsCollision(shared_ptr<class CircleCollider> circle, bool isObb = false) abstract;

	void SetParent(shared_ptr<Transform> parent) { _transform->SetParent(parent); }

protected:
	vector<VertexPos> _vertices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	// color버퍼는 상수버퍼, world, view projection 처럼 상수 정보들을 PS에 세팅할 용도
	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<PixelShader> _pixelShader;
	shared_ptr<VertexShader> _vertexShader;

	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _parent;

	Type _type;
};

