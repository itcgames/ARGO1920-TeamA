
#ifndef PLAYER_H
#define PLAYER_H


#include <SDL.h>
#include <SDL_image.h>

#include <vector>
#include "Tile.h"
#include <iostream>
#include "Graph.h"
#include "Entity.h"
#include <random>

/// <summary>
/// @Authors:
///		@Aaron O'Dea		@C00217820
/// </summary>
/// 
/// 



class Player : public Entity 
{
public:
	Player(int entityIdNum);
	~Player();

	void assignSprite(SDL_Texture* t_PlayerTexture);
	void SetUp();
	void update();
	void render(SDL_Renderer* t_renderer);
	void setPosition(float t_x, float t_y);

	int randomNumber(int t_max, int t_min)
	{
		std::random_device device;
		std::mt19937 rng(device());
		std::uniform_int_distribution<std::mt19937::result_type> dist(t_min, t_max);
		diceRoll = dist(rng);
		return dist(rng);
	}

	SDL_Rect * getPlayerRectRef();

	SDL_Rect getPosition() { return rect; };
	int getDiceRoll() { return diceRoll; };
private:

	SDL_Rect rect;//temp rect for a player square 
	SDL_Texture* m_PlayerTexture;
	int diceRoll{2};


};
#endif // !PLAYER_H