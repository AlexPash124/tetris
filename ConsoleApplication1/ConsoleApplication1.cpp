#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>

using namespace std;
const int ROW = 20;
const int COL = 17;
struct Figure
{
	int x = 6;
	int y = 0;
	char figure1[3][3] = {
		{'0','-','-'},
		{'0','-', '-'},
		{'0','-', '-'}
	};
	char figure2[3][3] = {
		{'0','0', ' '},
		{'0','0', ' '},
		{' ',' ', ' '}
	};
	char figure3[3][3] = {
		{'0',' ', ' '},
		{'0','0', ' '},
		{' ','0', ' '}
	};
	char figure4[3][3] = {
		{' ','0', ' '},
		{'0','0', ' '},
		{'0',' ', ' '}
	};

	char figure5[3][3] = {
		{'0','0', ' '},
		{'0',' ', ' '},
		{'0',' ', ' '}
	};

	char figure6[3][3] = {
		{' ','0', ' '},
		{'0','0', '0'},
		{' ',' ', ' '}
	};
	char figure7[3][3] = {
		{'0','0', ' '},
		{' ','0', ' '},
		{' ','0', ' '}
	};

	void moveRight() {
		x += 1;
		if (x > COL - 4) {
			x -= 1;
		}
	}
	void moveLeft() {
		x -= 1;
		if (x < 2) {
			x += 1;
		}
	}

	bool moveDown() {
		y += 1;
		if (y > ROW - 4) {
			y -= 1;
			return true; //робити нову фігуру
		}
		return false;
	}

	void showFigure() {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << figure7[i][j] << " ";
			}
			cout << endl;
		}
	}

	void rorationFirure(char matrixFigure[3][3]) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matrixFigure[i][j] = matrixFigure[j][i];
			}
		}
	}
};

struct Scene {
	char poleMatrix[ROW][COL];
	char poleMatrixOriginal[ROW][COL]; //

	void initMatrix() {
		for (int y = 0; y < ROW; y++)
		{
			for (int x = 0; x < COL; x++)
			{
				poleMatrix[0][x] = '*';
				poleMatrix[y][0] = '|';
				poleMatrix[y][x] = '-';
				poleMatrix[19][x] = '*';
			}
			poleMatrix[y][COL - 1] = '|';
		}
	}
	void showScene() {
		for (int y = 0; y < ROW; y++)
		{
			for (int x = 0; x < COL; x++)
			{
				cout << poleMatrix[y][x];
			}
			cout << endl;
		}
	}

	void insertFigure(Figure& figure) {
		int xFigure = figure.x;
		int yFigure = figure.y;
		char figureOne[4][4];

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				figureOne[i][j] = figure.figure1[i][j];
			}
		}
		
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				poleMatrix[y + yFigure][x + xFigure] = figureOne[y][x];
			}

		}
	}
};


int main()
{
	Scene scene;
	scene.initMatrix();
	Figure figure;
	char key = ' ';
	while (true) {
		Sleep(1000);
		system("cls");
		figure.moveDown();
		scene.insertFigure(figure);
		scene.showScene();
		if (_kbhit() && (key = _getch()) == 'r') {
			figure.rorationFirure(figure.figure1);
		}
		if(_kbhit() && (key = _getch()) == 'd') {		
			figure.moveRight();
			if (_kbhit() && (key = _getch()) == 'd') {
				figure.moveRight();
			}
		}
		if (_kbhit() && (key = _getch()) == 'a') {
			figure.moveLeft();
			if (_kbhit() && (key = _getch()) == 'a') {
				figure.moveLeft();
			}
		}
		if (_kbhit() && (key = _getch()) == 's') {
			figure.moveDown();
		}
	}
}
