#include <iostream>
#include <string>
ีusing namespace std;
class islandrandom
{
	int x;
	int y;
	string type;

public:
	random(int, int, string);
	void Texture_Img();
};
islandrandom::random(int A, int B)
{
	x = A;
	y = B;
}
void islandrandom::Texture_Img()
{
	int N = rand() % 3;
	string = pic;
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
}
img.loadFromFile(pic);
}