#include <SFML/Graphics.hpp>
using namespace sf;

float speedX = 1.f;
float speedY = 1.f;
int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    RectangleShape shape({60.f, 30.f});
    shape.setFillColor(Color::Red);
    window.setFramerateLimit(120);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if(Mouse::isButtonPressed(Mouse::Left)){
            shape.rotate(15);
        }
        window.clear();
        if(shape.getPosition().x + shape.getSize().x >=800 || shape.getPosition().x < 0){
        speedX *= -1;
        shape.setFillColor({rand()%255,rand()%255,rand()%255});
        }
        if(shape.getPosition().y + shape.getSize().y >=600 || shape.getPosition().y < 0){
        speedY *= -1;
        shape.setFillColor({rand()%255,rand()%255,rand()%255});
        }
        shape.move({speedX,speedY});
        window.draw(shape);
        window.display();
    }

    return 0;
}