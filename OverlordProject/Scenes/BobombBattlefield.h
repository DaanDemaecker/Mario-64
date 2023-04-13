#pragma once
class BobombBattlefield final : public GameScene
{
public:
	BobombBattlefield() : GameScene(L"Bob-omb battleField") {};
	~BobombBattlefield() override = default;

	BobombBattlefield(const BobombBattlefield& other) = delete;
	BobombBattlefield(BobombBattlefield&& other) noexcept = delete;
	BobombBattlefield& operator=(const BobombBattlefield& other) = delete;
	BobombBattlefield& operator=(BobombBattlefield&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnGUI() override;

private:
	GameObject* m_pLevel;
};
