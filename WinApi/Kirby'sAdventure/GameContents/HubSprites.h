#pragma once

// Ό³Έν :
class HubSprites
{
public:
	// constrcuter destructer
	HubSprites();
	~HubSprites();

	// delete Function
	HubSprites(const HubSprites& _Other) = delete;
	HubSprites(HubSprites&& _Other) noexcept = delete;
	HubSprites& operator=(const HubSprites& _Other) = delete;
	HubSprites& operator=(HubSprites&& _Other) noexcept = delete;

protected:

private:

};

