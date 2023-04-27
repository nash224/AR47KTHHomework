#pragma once

// Ό³Έν :
class LaserBall
{
public:
	// constrcuter destructer
	LaserBall();
	~LaserBall();

	// delete Function
	LaserBall(const LaserBall& _Other) = delete;
	LaserBall(LaserBall&& _Other) noexcept = delete;
	LaserBall& operator=(const LaserBall& _Other) = delete;
	LaserBall& operator=(LaserBall&& _Other) noexcept = delete;

protected:

private:

};

