/*****************************************************
*  Assignment    : 4                                 *
*  Name          : Ngoc Duy Nguyen                   *
*  Student ID    : 00231123                          *
*  Date          : December 8th                      *
*  Game of life                                      *
******************************************************/
#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
// Global constants
    int Generation;
    const int MAXGEN = 3; // maximum no. of generations
    const int n = 10 ;    // no. of rows
    const int m = 10 ;    // no. of colums

void initialize1(int grid[n][m], int x, int y){
    cout << "Please initialize live/dead cells (1 for live, 0 for dead):" <<endl;
    for (int i = 0; i<x; i++){
        for( int j = 0; j<y; j++){
            cin >> grid[i][j];
        }
    }
}

int initialize2(int grid[n][m], int x, int y){
    int density;
    srand(time(0));
    int tempArray[n][m];
    cout << "Please input density level (%): ";
    cin >> density;
    ///random number will be stored in a temporary array
     for (int i = 0; i<x; i++){
        for( int j = 0; j<y; j++){
            if((rand() %100) <= density)
            tempArray[i][j]=1;
        else
             tempArray[i][j]=0;
        }
     }

    ///load random array and put into grid[][]
     for (int i = 0; i<x; i++){
        for( int j = 0; j<y; j++){
            grid[i][j]=tempArray[i][j];
        }
    }
    return grid[n][m];
}

int nextGeneration(int life_array[n][m], int row, int col){
    int nextGen[row][col];
    int num_neighbors;

    ///****** This loop count neighbors around cells that's not around the border*******///
    for(int i=0; i < row; i++){
        for(int j=0; j < col; j++){
             num_neighbors = 0;
             if(i < (row-1) && j < (col-1) && i > 0 && j > 0){
                 for(int l=(i-1); l<=(i+1); l++){
                    for(int m=(j-1); m<=(j+1); m++){
                     if((life_array[l][m])== 1)
                        num_neighbors++;
                    }
                }
                num_neighbors = num_neighbors - life_array[i][j];
             }
            ///****** Checking 4 corners of 2D array ******///
             else if (j==0 && i==0){ ///top-left corner
                 for(int l=0; l<2;l++){
                     for(int m=0; m<2; m++){
                            if(life_array[l][m]== 1)
                            num_neighbors++;
                        }
                 }
                if ((life_array[i+row-1][j])== 1){num_neighbors++;}
                if ((life_array[i+row-1][j+1])== 1){num_neighbors++;}
                if ((life_array[i][j+col-1])== 1){num_neighbors++;}
                if ((life_array[i+1][j+col-1])== 1){num_neighbors++;}
                if ((life_array[i+row-1][j+col-1])== 1){num_neighbors++;}

                num_neighbors = num_neighbors - life_array[i][j];
             }
             else if(j == col-1 && i==0){ ///top-right corner
                for(int l=0; l<2;l++){
                     for(int m=j-1; m<j+1; m++){
                            if(life_array[l][m]== 1)
                            num_neighbors++;
                        }
                 }
                if ((life_array[row-1][j-1])== 1){num_neighbors++;}
                if ((life_array[i+row-1][j])== 1){num_neighbors++;}
                if ((life_array[i][j-col+1])== 1){num_neighbors++;}
                if ((life_array[i+1][0])== 1){num_neighbors++;}
                if ((life_array[i+row-1][0])== 1){num_neighbors++;}
                num_neighbors = num_neighbors - life_array[i][j];
             }
             else if(i == row-1 && j == col-1){///bottom-right corner
                 for(int l = i-1; l<row; l++){
                     for(int m = j-1; m<col; m++){
                         if(life_array[l][m]== 1)
                            num_neighbors++;
                     }
                 }
                if ((life_array[i-1][0])== 1){num_neighbors++;}
                if ((life_array[i][0])== 1){num_neighbors++;}
                if ((life_array[0][j-1])== 1){num_neighbors++;}
                if ((life_array[0][j])== 1){num_neighbors++;}
                if ((life_array[0][0])== 1){num_neighbors++;}
                 num_neighbors = num_neighbors - life_array[i][j];
             }
             else if(i == row-1 && j == 0){///bottom-left corner
                 for(int l = i-1; l<row; l++){
                     for(int m = 0; m<2; m++){
                         if(life_array[l][m]== 1)
                            num_neighbors++;
                     }
                 }
                if ((life_array[0][j])== 1){num_neighbors++;}
                if ((life_array[0][j+1])== 1){num_neighbors++;}
                if ((life_array[i-1][col-1])== 1){num_neighbors++;}
                if ((life_array[i][col-1])== 1){num_neighbors++;}
                if ((life_array[0][col-1])== 1){num_neighbors++;}
                 num_neighbors = num_neighbors - life_array[i][j];
             }
            ///****** Check remaining edges ********///
            else if(i>0 && i<row-1 && j==0){
                for(int l = i-1; l<i+2; l++){
                     for(int m = 0; m<2; m++)
                     {
                         if(life_array[l][m]== 1)
                            num_neighbors++;
                     }
                 }
                if ((life_array[i-1][col-1])== 1){num_neighbors++;}
                if ((life_array[i][col-1])== 1){num_neighbors++;}
                if ((life_array[i+1][col-1])== 1){num_neighbors++;}
                 num_neighbors = num_neighbors - life_array[i][j];
            }

            else if(i>0 && i<row-1 && j==col-1){
                for(int l = i-1; l<i+2; l++){
                     for(int m = j-1; m<j+1; m++)
                     {
                         if(life_array[l][m]== 1)
                            num_neighbors++;
                     }
                 }
                if ((life_array[i-1][0])== 1){num_neighbors++;}
                if ((life_array[i][0])== 1){num_neighbors++;}
                if ((life_array[i+1][0])== 1){num_neighbors++;}
                 num_neighbors = num_neighbors - life_array[i][j];
            }
             else if(i==0 && j>0 && j<col-1){
                for(int l = i; l<i+2; l++){
                     for(int m = j-1; m<j+2; m++)
                     {
                         if(life_array[l][m]== 1)
                            num_neighbors++;
                     }
                 }
                if ((life_array[row-1][j-1])== 1){num_neighbors++;}
                if ((life_array[row-1][j])== 1){num_neighbors++;}
                if ((life_array[row-1][j+1])== 1){num_neighbors++;}
                 num_neighbors = num_neighbors - life_array[i][j];
            }
            else{
                for(int l = i-1; l<i+1; l++){
                     for(int m = j-1; m<j+2; m++)
                     {
                         if(life_array[l][m]== 1)
                            num_neighbors++;
                     }
                 }
                if ((life_array[0][j-1])== 1){num_neighbors++;}
                if ((life_array[0][j])== 1){num_neighbors++;}
                if ((life_array[0][j+1])== 1){num_neighbors++;}
                 num_neighbors = num_neighbors - life_array[i][j];
            }
                ///Applying live/dead rules for the population
                ///1 cell die caused by under population
                 if ((life_array[i][j] == 1) && (num_neighbors < 2))
                        nextGen[i][j] = 0;

                ///more than 3 cells dies due to over population
                 else if  ((life_array[i][j] == 1) && (num_neighbors > 3))
                    nextGen[i][j] = 0;

                /// 2 or 3 cells lives
                 else if ((life_array[i][j] == 0) && (num_neighbors == 3))
                    nextGen[i][j] = 1;

                /// Remains the same
                else
                    nextGen[i][j] = life_array[i][j];
        }
    }

    cout << "-------------------\n";
    for (int i = 0; i<row; i++){
        for( int j = 0; j<col; j++){
            if(nextGen[i][j]==0)
                cout << "0 ";
            else
                cout << "1 ";
        }
        cout <<endl;
    }
    cout <<"-------------------";
    ///This loop is to put nextGen 2d array into life_array so
    ///it can be scanned in next Generation
    for (int i = 0; i<row; i++){
        for( int j = 0; j<col; j++){
            life_array[i][j]=nextGen[i][j];
        }
    }
    return life_array[n][m];
}

int populationScan(int grid[n][m], int x, int y, int stable_state){
    int live_cell = 0;
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++){
        if((grid[i][j]==1))
            live_cell++;
    }

    int stable = (x*y)/2;///Ideally stable state should have more than 50% of live cells
    if (live_cell >= stable)
        return -1;
    else if (live_cell == 0)
        return 1;
    else
        return 0;
}

int main(){

    int rows, cols;
    int grid[n][m];
    int aliveNeighbours = 0;
    int current_state;
    int choices;

    cout << "----------------GAME OF LIFE----------------\n\n";
    cout << "Please enter rows and columns: ";
    cin >> rows >> cols;

    cout << "\nPlease choose way of initialization\n";
    cout << "'1' to input population\n";
    cout << "'2' to generate randomly base on density\n";
    cin >> choices;

    switch(choices){
        case 1: initialize1(grid, rows, cols); break;///User input
        case 2: initialize2(grid, rows, cols); break;///randomize according to density
    }




    cout << "\nInitial cells: \n";
    cout << "-------------------\n";
    for (int i = 0; i<rows; i++){
        for( int j = 0; j<cols; j++){
            cout << grid[i][j] << " ";
        }
        cout<<endl;
    }
    cout << "-------------------\n";
    Generation = 1;
    while(Generation <= MAXGEN){
        cout << "\nGeneration number " << Generation <<endl;
        nextGeneration(grid, rows, cols);
        Generation++;

        ///stable state check. Check if population is stable/ no cells left or not
        ///Please comment this part out to see 3 Generation printed
        current_state = populationScan(grid, rows, cols, current_state);

        if(current_state == 0) continue;
        else if(current_state == 1){
            cout << "\nAll cells are dead!\n";
            break;
        }
        else{
            cout << "\nPopulation has reached stable state!\n";
            break;
        }
    }
    return 0;
}
