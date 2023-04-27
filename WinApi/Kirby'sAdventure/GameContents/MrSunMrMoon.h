#pragma once

// Ό³Έν :
class MrSunMrMoon
{
public:
	// constrcuter destructer
	MrSunMrMoon();
	~MrSunMrMoon();

	// delete Function
	MrSunMrMoon(const MrSunMrMoon& _Other) = delete;
	MrSunMrMoon(MrSunMrMoon&& _Other) noexcept = delete;
	MrSunMrMoon& operator=(const MrSunMrMoon& _Other) = delete;
	MrSunMrMoon& operator=(MrSunMrMoon&& _Other) noexcept = delete;

protected:

private:

};

