#include "Rrectangle.hpp"

Rectangle::Rectangle(Vector2f size, RenderWindow &window){
    this->shape = RectangleShape(size);
    this->shape.setPosition({Mouse::getPosition(window).x, Mouse::getPosition(window).y});
    this->shape.setFillColor(Color::Blue);
    this->speed=Vector2f(4.f,4.f);
    this->acc=Vector2f(0.f, 1.f);
    this->shape.setOutlineThickness(3);
    this->shape.setOutlineColor(Color::Cyan);
}

void Rectangle::update(){
    if(this->shape.getPosition().y+this->shape.getSize().y <= 600){
    this->speed+= this->acc;
    this->shape.move(this->speed);
    }
    if(shape.getPosition().x+shape.getSize().x>=800|| shape.getPosition().x<0){
            
            speed.x*= -1;
            this->shape.setFillColor({Uint8(rand()%255),Uint8(rand()%255),Uint8(rand()%255)});
            this->shape.setOutlineColor({Uint8(rand()%255),Uint8(rand()%255),Uint8(rand()%255)});
    }
    if(shape.getPosition().y+shape.getSize().y>=600|| shape.getPosition().y<0){
            
            this->speed.y*= -1;
            this->shape.setFillColor({Uint8(rand()%255),Uint8(rand()%255),Uint8(rand()%255)});
            this->shape.setOutlineColor({Uint8(rand()%255),Uint8(rand()%255),Uint8(rand()%255)});
            this->shape.setPosition(this->shape.getPosition().x, 600-this->shape.getSize().y);
    }
}

void Rectangle::drawTo(RenderWindow &window){
    window.draw(this->shape);
}