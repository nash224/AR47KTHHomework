#pragma once

// Ό³Έν :
class BroomHatter
{
public:
	// constrcuter destructer
	BroomHatter();
	~BroomHatter();

	// delete Function
	BroomHatter(const BroomHatter& _Other) = delete;
	BroomHatter(BroomHatter&& _Other) noexcept = delete;
	BroomHatter& operator=(const BroomHatter& _Other) = delete;
	BroomHatter& operator=(BroomHatter&& _Other) noexcept = delete;

protected:

private:

};

