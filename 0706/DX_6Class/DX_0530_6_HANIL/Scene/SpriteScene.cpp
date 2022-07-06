#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_zelda = make_shared<Zelda>();
	_zelda->SetAnimation(Zelda::State::F_RUN);
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	if (KEY_PRESS('W'))
	{
		if (_zelda->GetAnimation() != Zelda::State::B_RUN)
			_zelda->SetAnimation(Zelda::State::B_RUN);
	}
	else if (KEY_PRESS('S'))
	{
		if (_zelda->GetAnimation() != Zelda::State::F_RUN)
			_zelda->SetAnimation(Zelda::State::F_RUN);
	}
	else if (KEY_PRESS('A'))
	{
		if (_zelda->GetAnimation() != Zelda::State::L_RUN)
			_zelda->SetAnimation(Zelda::State::L_RUN);
	}
	else if (KEY_PRESS('D'))
	{
		if (_zelda->GetAnimation() != Zelda::State::R_RUN)
			_zelda->SetAnimation(Zelda::State::R_RUN);
	}
	else
	{
		switch (_zelda->GetAnimation())
		{
		case Zelda::State::B_RUN:
		{
			_zelda->SetAnimation(Zelda::State::B_IDLE);
			break;
		}
		case Zelda::State::F_RUN:
		{
			_zelda->SetAnimation(Zelda::State::F_IDLE);
			break;
		}
		case Zelda::State::L_RUN:
		{
			_zelda->SetAnimation(Zelda::State::L_IDLE);
			break;
		}
		case Zelda::State::R_RUN:
		{
			_zelda->SetAnimation(Zelda::State::R_IDLE);
			break;
		}
		default:
			break;
		}
	}
	_zelda->Update();
}

void SpriteScene::Render()
{
	_zelda->Render();
}

void SpriteScene::PostRender()
{
	_zelda->PostRender();
}
