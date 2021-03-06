#include "framework.h"
#include "Zelda.h"

Zelda::Zelda()
{
	_sprite = make_shared<Sprite>(L"Resource/zelda.png", Vector2(10, 8));
	SetPosition({ WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.5f });

	_collider = make_shared<RectCollider>(_sprite->GetFrameHalfSize());
	_collider->SetParent(_sprite->GetTransform());

	CreateActions();
}

Zelda::~Zelda()
{
}

void Zelda::Update()
{
	_sprite->Update();
	_collider->Update();
	
	for (auto& action : _actions)
	{
		action->Update();
		if (action->IsPlay())
			_sprite->SetActionToActionBuffer(action->GetCurClip());
	}

}

void Zelda::Render()
{
	_sprite->Render();
}

void Zelda::PostRender()
{
	_collider->Render();
}

void Zelda::CreateActions()
{
	// 앞쪽 가만히
	// 왼쪽 가만히
	// 뒤쪽 가만히
	// 오른쪽 가만히

	// 앞쪽 뜀
	vector<Action::Clip> clips;
	clips.reserve(10);
	float w = 1200.0f / 10.0f;
	float h = 1040.0f / 8.0f;


	// F_IDLE
	{
		clips.emplace_back(1200 * 0	       , 0, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w    , 0, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2, 0, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "F_IDLE", Action::PINGPONG, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// L_IDLE
	{
		clips.emplace_back(1200 * 0			, h * 1, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, h * 1, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2 , h * 1, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "L_IDLE", Action::PINGPONG, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// B_IDLE
	{
		clips.emplace_back(1200 * 0, h * 2, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "B_IDLE", Action::PINGPONG, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// R_IDLE
	{
		clips.emplace_back(1200 * 0			, h * 3, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, h * 3, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2 , h * 3, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "R_IDLE", Action::PINGPONG, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}

	// F_RUN
	{
		clips.emplace_back(1200 * 0			, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 3	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 4	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 5	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 6	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 7	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 8	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 9	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "F_RUN");
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// L_RUN
	{
		clips.emplace_back(1200 * 0			, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 3	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 4	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 5	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 6	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 7	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 8	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 9	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "L_RUN");
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// B_RUN
	{
		clips.emplace_back(1200 * 0			, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2 , h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 3 , h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 4 , h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 5 , h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 6 , h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 7 , h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 8 , h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 9 , h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "B_RUN");
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// R_RUN
	{
		clips.emplace_back(1200 * 0			, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2 , h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 3 , h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 4 , h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 5 , h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 6 , h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 7 , h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 8 , h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 9 , h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "R_RUN");
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
}

void Zelda::SetAnimation(Zelda::State state)
{
	_state = state;

	for (auto& action : _actions)
		action->Reset();

	_actions[static_cast<UINT>(_state)]->Play();
}

