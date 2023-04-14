#pragma once
#include "Parts.h"

// Ό³Έν :
class Head : public Parts
{
public:
	// constrcuter destructer
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

	static bool IsPlay;

protected:
	void Update() override;
	void IsBodyCheck();
	void NewBodyCreateCheck();

private:
	int2 Dir = int2::Up;

};

