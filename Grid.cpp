#include "Grid.hpp"
#include <iostream>
Grid::Grid(int rows, int cols){
    
    this->rows = rows;
    this->cols = cols;

    for(int i=0; i<rows; i++){
        this->grid.push_back({});
        for(int j=0; j<cols; j++){
            this->grid[i].push_back(0);

        }

    }
    this->next = vector<vector<int>>(rows,vector<int>(cols,0));
}
Grid::Grid(int rows, int cols, int width, int height){
    
    this->rows = rows;
    this->cols = cols;
    this->sizeX = width/cols;
    this->sizeY = height/rows;

    for(int i=0; i<rows; i++){
        this->grid.push_back({});
        for(int j=0; j<cols; j++){
            this->grid[i].push_back(0);

        }

    }
    this->next = vector<vector<int>>(rows,vector<int>(cols,0));
}

void Grid::drawTo(RenderWindow &window){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            

            RectangleShape rect(Vector2f(this->sizeX,this->sizeY));
            rect.setOutlineColor(Color::Black);
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

int Grid::contarVecinos(int x, int y){
    int vecinos=0;
    if(grid[x+1][y]==1){
        vecinos++;}
    if(grid[x-1][y]==1){
        vecinos++;}
    if(grid[x+1][y+1]==1){
        vecinos++;}
    if(grid[x+1][y-1]==1){
        vecinos++;}
    if(grid[x][y+1]==1){
        vecinos++;}
    if(grid[x][y-1]==1){
        vecinos++;}
    if(grid[x-1][y+1]==1){
        vecinos++;}
    if(grid[x-1][y-1]==1){//esquina sup izq
        vecinos++;}
    std::cout<<vecinos<< endl;
    return vecinos;
 }

void Grid::click(int x, int y){
    int indexX=x/this->sizeX;
    int indexY=y/this->sizeY;
    //grid[indexX][indexY]=(grid[indexX][indexY]+1)%2;

    if(grid[indexX][indexY]==0){
        grid[indexX][indexY]=1;
        //contarVecinos(indexX,indexY);
    }else
    {grid[indexX][indexY]=0;}
}

void Grid::uptdate(){
    int vecinos=0;
    for(int i=0; i<rows;i++){
        for(int j=0; j<cols; j++){
        if(grid[i][j]==0){
           vecinos = this->contarVecinos(i,j);
           if(vecinos = 3){
            next[i][j]=1;
           } 
        }
        if(grid[i][j]==1){
            if(vecinos > 3 || vecinos<=1){
                next[i][j] = 0;
            }
           }
    }
}  
        this->grid=this->next;
}

 