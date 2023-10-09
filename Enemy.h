#pragma once
#include "AActor.h"
#include "Player.h"

class Enemy : public AActor {
	Player* Hero = nullptr;
};