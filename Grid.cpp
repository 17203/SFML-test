#include "Grid.hpp"
/*
Grid::Grid(int rows, int cols){
    
    this->rows = rows;
    this->cols = cols;

    for(int i=0; i<rows; i++){
        this->grid.push_back({});
        for(int j=0; j<cols; j++){
            this->grid[i].push_back(0);

        }

    }
}*/
Grid::Grid(int rows, int cols, int width, int height){
    
    this->rows = rows;
    this->cols = cols;
    this->sizeX = width/cols;
    this->sizeY = height/rows;

    for(int i=0; i<rows; i++){
        this->grid.push_back({});
        for(int j=0; j<cols; j++){
            this->grid[i].push_back(rand()%2);

        }

    }
}

void Grid::drawTo(RenderWindow &window){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            

            RectangleShape rect(Vector2f(this->sizeX,this->sizeY));
            rect.setOutlineColor(Color::Magenta);
            rect.setOutlineThickness(1);
            if(grid[j][i]==0)
            rect.setFillColor(Color(34,117,56));
            else
            rect.setFillColor(Color(129,53,35));
            rect.setPosition(Vector2f(j*this->sizeX,i*this->sizeY));
            window.draw(rect);
        }
    }

}

void Grid::click(int x, int y){
    int indexX=x/this->sizeX;
    int indexY=y/this->sizeY;
    //grid[indexX][indexY]=(grid[indexX][indexY]+1)%2;

    if(grid[indexX][indexY]==0){
        grid[indexX][indexY]=1;
    }else
    {grid[indexX][indexY]=0;}
}
