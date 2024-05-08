#include <iostream>
#include <raylib.h>


int main()
{

	const int screenWidth = 1200;
	const int screenHeight = 800;

	int ballX = screenWidth/2;
	int ballY = screenHeight/2;
	int ballSpeedX = 10;
	int ballSpeedY = 10;
	int ballRadius = 10;

	int paddleWidth{ 20 };
	int paddleHeight{ 200 };
	int paddle1X{ screenWidth - paddleWidth*2 };
	int paddle1Y{ screenHeight / 2 - paddleHeight/2 };

	int paddle2X{ paddleWidth };
	int paddle2Y{ screenHeight / 2 - paddleHeight / 2 };

	int score1{};
	int score2{};
	

	InitWindow(screenWidth, screenHeight, "Pong");
	SetTargetFPS(30);



	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		
		ballX += ballSpeedX;
		ballY += ballSpeedY;

		if (IsKeyDown(KEY_W) && paddle2Y >= 0 ) paddle2Y -= 10;
		if (IsKeyDown(KEY_S) && (paddle2Y+paddleHeight) <= screenHeight) paddle2Y += 10;
		if (IsKeyDown(KEY_UP) && paddle1Y >= 0) paddle1Y -= 10;
		if (IsKeyDown(KEY_DOWN) && (paddle1Y + paddleHeight) <= screenHeight) paddle1Y += 10;


		if ((ballX + ballRadius >= screenWidth) || (ballX - ballRadius <= 0)) {
			ballSpeedX *= -1;
			if (ballX + ballRadius >= screenWidth)  score2++;
			if (ballX - ballRadius <= 0)  score1++;
		}

		if ((ballY + ballRadius >= screenHeight) || (ballY - ballRadius <= 0)) {
			ballSpeedY *= -1;
		}

		if (ballY <= (paddle1Y + paddleHeight) && ballY >= paddle1Y)
		{
			if ((ballX+ballRadius) >= paddle1X) {
				if (ballSpeedX > 0 )
					ballSpeedX *= -1;
			}
		}

		

		if (ballY <= (paddle2Y + paddleHeight) && ballY >= paddle2Y )
		{
			if ((ballX - ballRadius) <= (paddle2X + paddleWidth) ) {
				if (ballSpeedX < 0)
					ballSpeedX *= -1;
			}
		}
		
		DrawText(TextFormat("%i",score1), screenWidth/2 + (screenWidth / 5), 20, 80, BLUE);
		DrawText(TextFormat("%i", score2), screenWidth / 2 - (screenWidth / 5), 20, 80, RED);
		DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, GRAY);
		DrawCircle(ballX, ballY, ballRadius, WHITE);
		DrawRectangle(paddle1X, paddle1Y, paddleWidth, paddleHeight, BLUE);
		DrawRectangle(paddle2X, paddle2Y, paddleWidth, paddleHeight, RED);
		EndDrawing();
	}

}