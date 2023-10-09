#pragma once

class Game {
public:
	void Initialize();
	void Update();
	void Shutdown();
	
private:
	int ScreenWidth = 800;
	int ScreenHeight = 600;
};