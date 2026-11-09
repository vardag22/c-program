#include <raylib.h>
#include <iostream>
#include <limits>

struct Vector2D
{
	float x{};
	float y{};
};

struct Player
{
	Vector2D position;
	Vector2D velocity;
	float speed{};
	float radius{};
	Color color;
};

enum class GameState :char
{
	MainMenu,
	GamePlay,
	GameOver,
};

int get_speed_limit()
{
	int speed_limit{};
	while (true)
	{
		std::cout << "Enter a speed limit for object: ";
		std::cin >> speed_limit;

		if (!std::cin.fail())
			return speed_limit;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

int main()
{
	float speed_limit{static_cast<float>(get_speed_limit())};

	constexpr int screen_width{900};
	constexpr int screen_height{650};

	InitWindow(screen_width, screen_height, "Simple game window");

	Player player;
	player.position = {0.0f, 0.0f};
	player.velocity = {0.0f, 0.0f};
	player.speed = speed_limit;
	player.color = RAYWHITE;

	GameState currentState = GameState::GamePlay;

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		float deltaTime{GetFrameTime()};

		player.velocity = {0.0f, 0.0f};

		if (currentState == GameState::GamePlay)
		{ 
			if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A))  player.velocity.x = -player.speed;
			if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))  player.velocity.x =  player.speed;
			if (IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W))  player.velocity.y = -player.speed;
			if (IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S))  player.velocity.y =  player.speed;
		}

		// player.position.x += player.velocity.x * deltaTime;
		player.position.x = player.position.x + player.velocity.x * deltaTime;
		// player.position.y += player.velocity.y * deltaTime;
		player.position.y = player.position.y + player.velocity.y * deltaTime;

		if (IsKeyDown(KEY_R)) player.color = RED;
		if (IsKeyDown(KEY_B)) player.color = BLUE;
		if (IsKeyDown(KEY_G)) player.color = DARKGREEN;

		BeginDrawing();

		ClearBackground(DARKBROWN);

		if (currentState == GameState::GamePlay)
		{
			DrawText("Drawing some text!", 20, 10, 30, WHITE);
			DrawText("Change color of object 'r' for red 'b' for blue 'g' for green", 20, 50, 20, WHITE);

			DrawCircle (static_cast<int>(player.position.x), static_cast<int>(player.position.y), 20.0f, player.color);
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}