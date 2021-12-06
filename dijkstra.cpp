#include "bots.h"
#include "stdlib.h"
 


cDjikstra::cDjikstra() {
	completed = false;
}
void cDjikstra::ChooseNextGridPosition() { }

void cDjikstra::Build(cBotBase& bot) {
	for (int i = 0; i <= 39; i++) {
		for (int j = 0; j <= 39; j++) {
			closed[i][j] = false;
			cost[i][j] = 100;
			linkX[i][j] = - 1;
			linkY[i][j] = - 1;
			inPath[i][j] = false;
		}
	}
	cost[bot.PositionX()][bot.PositionY()] = 0;
	bool finished = false;
	while (!finished) {
		int timeMS = 1000000;
		for (int i = 0; i <= 39; i++) {
			for (int j = 0; j <= 39; j++) {
				if (timeMS > cost[i][j] && closed[i][j] == false && gLevel.isValid(i, j) == true) {
					timeMS = cost[i][j];
					a = i;
					b = j;
				}
			}
		}
		if (closed[a - 1][b] == false && gLevel.isValid(a - 1, b) == true && (cost[a][b] + 1) < cost[a - 1][b]) {
			cost[a - 1][b] = 1 + cost[a][b];
			linkX[a - 1][b] = a;
			linkY[a - 1][b] = b;
		}
		if (closed[a][b + 1] == false && gLevel.isValid(a, b + 1) == true && (cost[a][b]+1) < cost[a][b + 1]) {
			cost[a][b + 1] = 1 + cost[a][b];
			linkX[a][b + 1] = a;
			linkY[a][b + 1] = b;
		}
		if (closed[a][b - 1] == false && gLevel.isValid(a, b - 1) == true && (cost[a][b] + 1) < cost[a][b - 1]) {
			cost[a][b - 1] = 1 + cost[a][b];
			linkX[a][b - 1] = a;
			linkY[a][b - 1] = b;
		}
		if (closed[a + 1][b + 1] == false && gLevel.isValid(a + 1, b + 1) == true && (cost[a][b] + 1.4) < cost[a + 1][b + 1]) {
			cost[a + 1][b + 1] = 1.4 + cost[a][b];
			linkX[a + 1][b + 1] = a;
			linkY[a + 1][b + 1] = b;
		}
		if (closed[a + 1][b] == false && gLevel.isValid(a + 1, b) == true && (cost[a][b] + 1) < cost[a + 1][b]) {
			cost[a + 1][b] = 1 + cost[a][b];
			linkX[a + 1][b] = a;
			linkY[a + 1][b] = b;
		}
		if (closed[a - 1][b + 1] == false && gLevel.isValid(a - 1, b + 1) == true && (cost[a][b] + 1.4) < cost[a - 1][b + 1]) {
			cost[a - 1][b + 1] = 1.4 + cost[a][b];
			linkX[a - 1][b + 1] = a;
			linkY[a - 1][b + 1] = b;
		}
		if (closed[a - 1][b - 1] == false && gLevel.isValid(a - 1, b - 1) == true && (cost[a][b] + 1.4) < cost[a - 1][b - 1]) {
			cost[a - 1][b - 1] = 1.4 + cost[a][b];
			linkX[a - 1][b - 1] = a;
			linkY[a - 1][b - 1] = b;
		}
		if (closed[a + 1][b - 1] == false && gLevel.isValid(a + 1, b - 1) == true && (cost[a][b] + 1.4) < cost[a + 1][b - 1]) {
			cost[a + 1][b - 1] = 1.4 + cost[a][b];
			linkX[a + 1][b - 1] = a;
			linkY[a + 1][b - 1] = b;
		}
		closed[a][b] = true;
		if (gTarget.PositionX() == a && gTarget.PositionY() == b) {
			finished = true;
		}
	}
	bool done = false; //set to true when we are back at the bot position
	int nextClosedX = gTarget.PositionX(); //start of path
	int nextClosedY = gTarget.PositionY(); //start of path
	while (!done) {
		inPath[nextClosedX][nextClosedY] = true;
		int tmpX = nextClosedX;
		int tmpY = nextClosedY;
		nextClosedX = linkX[tmpX][tmpY];
		nextClosedY = linkY[tmpX][tmpY];
		if ((nextClosedX == bot.PositionX()) && (nextClosedY == bot.PositionY())) {
			done = true;
		} 
	}
	completed = true;
};
cDjikstra gDijkstra;