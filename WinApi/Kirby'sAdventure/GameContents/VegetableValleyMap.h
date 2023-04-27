#pragma once

// Ό³Έν :
class VegetableValleyMap
{
public:
	// constrcuter destructer
	VegetableValleyMap();
	~VegetableValleyMap();

	// delete Function
	VegetableValleyMap(const VegetableValleyMap& _Other) = delete;
	VegetableValleyMap(VegetableValleyMap&& _Other) noexcept = delete;
	VegetableValleyMap& operator=(const VegetableValleyMap& _Other) = delete;
	VegetableValleyMap& operator=(VegetableValleyMap&& _Other) noexcept = delete;

protected:

private:

};

