#pragma once

// Ό³Έν :
class KirbySAbillity
{
public:
	// constrcuter destructer
	KirbySAbillity();
	~KirbySAbillity();

	// delete Function
	KirbySAbillity(const KirbySAbillity& _Other) = delete;
	KirbySAbillity(KirbySAbillity&& _Other) noexcept = delete;
	KirbySAbillity& operator=(const KirbySAbillity& _Other) = delete;
	KirbySAbillity& operator=(KirbySAbillity&& _Other) noexcept = delete;

protected:

private:

};

