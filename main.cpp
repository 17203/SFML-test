#include <SFML/Graphics.hpp>
#include "Grid.hpp"
using namespace sf;

int width = 800;
int height = 1000;
int numCells = 20;
int main()
{
    RenderWindow window(VideoMode(width, height), "Game of life");
    window.setFramerateLimit(5);

    Grid grid(numCells,numCells,width,height);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(event.type==Event::MouseButtonPressed){
                if(event.mouseButton.button==Mouse::Left){
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    grid.click(x,y);
                }
            if(event.type==Event::MouseButtonPressed){
                if(event.mouseButton.button==Mouse::Right){
                    grid.uptdate();
                }
            }
        }

        window.clear();
        grid.drawTo(window);
        window.display();
    }

    return 0;
}
}