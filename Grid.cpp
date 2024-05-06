#include "Grid.hpp"

Grid::Grid(int rows, int cols){
    
    this->rows = rows;
    this->cols = cols;

    for(int i=0; i<rows; i++){
        this->grid.push_back({});
        for(int j=0; j<cols; j++){
            this->grid[i].push_back(0);

        }

    }
}


void Grid::drawTo(RenderWindow &window){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            

            RectangleShape rect(Vector2f(40,40));
            rect.setOutlineColor(Color::Magenta);
            rect.setOutlineThickness(1);
            rect.setPosition(Vector2f(j*40,i*40));
            window.draw(rect);
        }
    }

}
