#pragma once
#include <chrono>

class Time
{
public:
	void Mark()
	{
		deltaTime = std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count();
		last = std::chrono::steady_clock::now();
	}
	float TimeSinceStart() 
	{ 
		return std::chrono::duration<float>(std::chrono::steady_clock::now() - startTime).count();
	}
	float DeltaTime() const { return deltaTime; } 
private:
	std::chrono::steady_clock::time_point last;
	const std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
	float deltaTime = 0;
};