#ifndef grid_h
#define grid_h
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Grid{
private:
int rows, cols;
vector <vector<int>> grid;

public:
    Grid(int rows, int cols);

    void drawTo(RenderWindow &window);

};

#endif