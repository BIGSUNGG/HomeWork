#pragma once
class DungreedScene : public Scene
{
public:
	DungreedScene();
	virtual ~DungreedScene();

	virtual void Update() override;
	virtual void Render() override;

	virtual void PostRender() override;

private:
	shared_ptr<Player> _player;
	shared_ptr<Player> _enemy;
	shared_ptr<Aim> _aim;
};

