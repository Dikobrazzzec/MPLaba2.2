#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define ARRLENGHT 20

using namespace std;

void BinarySort(int* numbers, int LEFT, int RIGHT)
{
	int MainElement;
	int L_HOLD = LEFT;
	int R_HOLD = RIGHT;
	MainElement = numbers[LEFT];
	while (LEFT < RIGHT)
	{
		while ((numbers[RIGHT] >= MainElement) && (LEFT < RIGHT))
			RIGHT--;
		if (LEFT != RIGHT) 
		{
			numbers[LEFT] = numbers[RIGHT]; 
			LEFT++; 
		}
		while ((numbers[LEFT] <= MainElement) && (LEFT < RIGHT))
			LEFT++; 
		if (LEFT != RIGHT)
		{
			numbers[RIGHT] = numbers[LEFT]; 
			RIGHT--; 
		}
	}
	numbers[LEFT] = MainElement; 
	MainElement = LEFT;
	LEFT = L_HOLD;
	RIGHT = R_HOLD;
	if (LEFT < MainElement)
		BinarySort(numbers, LEFT, MainElement - 1);
	if (RIGHT > MainElement)
		BinarySort(numbers, MainElement + 1, RIGHT);
}
int main()
{
	int MainArr[ARRLENGHT]; 
	for (int i = 0; i < ARRLENGHT; i++) MainArr[i] = 1+ rand() % 1000;
	for (int i = 0; i < ARRLENGHT; i++) cout << MainArr[i] << " ";
	BinarySort(MainArr, 0, ARRLENGHT - 1);
	cout << endl;
	for (int i = 0; i < ARRLENGHT; i++) cout << MainArr[i] << " ";
	return 0;
}