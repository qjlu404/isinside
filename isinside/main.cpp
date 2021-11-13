#include <iostream>
#include <vector>
#include <cstdlib>
using std::vector;
struct coord
{
	short x;
	short y;
};
struct line
{
	float slope;
	coord a;//where line "begins"
	coord b;// where line "ends"
};

void findslope(line* inval) 
{
	inval->slope = (inval->a.y - inval->b.y) / (inval->a.x - inval->b.x);
}
void debugdisplay(vector<coord> coords, vector<line> lines)
{
	std::cout << "\ndebug equations\n";
	for (size_t i = 0; i < lines.size(); i++)
	{
		printf("(%i, %i)(%i, %i) | ", lines[i].a.x, lines[i].a.y, lines[i].b.x, lines[i].b.y);
		printf("(%i) | y = %f(x - %i)+(%i) \n", i, lines[i].slope, lines[i].a.x, lines[i].a.y);
	}
	std::cout << "\ndebug coords\n";
	for (size_t i = 0; i < coords.size(); i++)
	{
		printf("(%i) | (%i, %i)\n", i, coords[i].x, coords[i].y);
	}
}
int main(int argc, char* argv[])
{
	vector<coord> coords;
	vector<line> lines;
	for (int i = 1; i < argc; i+=2)
	{
		coord loop{};
		loop.x = atoi(argv[i]);
		loop.y = atoi(argv[i + 1]);
		coords.push_back(loop);
	}
	for (size_t i = 1; i < coords.size(); i++)
	{
		line loop{};
		loop.a = coords[i-1];
		loop.b = coords[i];
		findslope(&loop);
		lines.push_back(loop);
	}
	line last{};
	last.b = coords[0];
	last.a = coords[lines.size()-1];
	findslope(&last);
	lines.push_back(last);
	debugdisplay(coords, lines);
	
}