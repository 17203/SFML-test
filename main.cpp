#include <SFML/Graphics.hpp>
#include "Grid.hpp"
using namespace sf;

int width = 800;
int height = 1000;
int numCells = 1000;
int main()
{
    RenderWindow window(VideoMode(width, height), "SFML works!");
    window.setFramerateLimit(60);

    Grid grid(numCells,numCells,width,height);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        grid.drawTo(window);
        window.display();
    }

    return 0;
}