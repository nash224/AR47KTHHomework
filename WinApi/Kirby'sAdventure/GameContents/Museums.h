#pragma once

// Ό³Έν :
class Museums
{
public:
	// constrcuter destructer
	Museums();
	~Museums();

	// delete Function
	Museums(const Museums& _Other) = delete;
	Museums(Museums&& _Other) noexcept = delete;
	Museums& operator=(const Museums& _Other) = delete;
	Museums& operator=(Museums&& _Other) noexcept = delete;

protected:

private:

};

