#pragma once

// Ό³Έν :
class Object
{
public:
	// constrcuter destructer
	Object();
	~Object();

	// delete Function
	Object(const Object& _Other) = delete;
	Object(Object&& _Other) noexcept = delete;
	Object& operator=(const Object& _Other) = delete;
	Object& operator=(Object&& _Other) noexcept = delete;


protected:

private:

	virtual void Start();
	virtual void Update();
	virtual void End();
	virtual void Release();

	bool DeathValue;
	bool UpdateValue;

};

