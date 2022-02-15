#include "islandrandom.h"

islandrandom::islandrandom(int A, int B, string C)
{
	x = A;
	y = B;
	type = C;
}
void islandrandom::Texture_Img()
{
	int N = rand() % 3;
	string pic;
	if (N == 0)
	{
		type = "sand";
		pic = "image\\Texture_Sand\\sand.png";
	}
	else if (N == 1)
	{
		type = "solid";
		pic = "image\\Texture_Solid\\solid.png";
	}
	else if (N == 2)
	{
		type = "hill";
		pic = "image\\Texture_Hill\\hill.png";
	}
	img.loadFromFile(pic);
}