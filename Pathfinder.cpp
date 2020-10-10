#include "Pathfinder.h"
#include <algorithm>
using namespace std;


 string Pathfinder::toString() const{
    stringstream ss;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            for(int k = 0; k < SIZE; k++){
                ss << maze[i][j][k];
                if(k!=4){
                    ss << " ";
                }
            }
            ss << endl;
        }
        ss << endl;
    }
    string strMaze = ss.str();
    strMaze.pop_back(); //removes extra \n
    return strMaze;
}
void Pathfinder::createRandomMaze(){
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            for(int k = 0; k < SIZE; k++){
                maze[i][j][k] = rand() % 2;
            }
        }
    }
    maze [0][0][0] = 1;
    maze [4][4][4] = 1;
    return;
}
bool Pathfinder::importMaze(string file_name){
cout << "importMaze from "<<file_name<<endl;
        //Check to make sure the file has the correct number of lines
        string line;
        int lineCounter = 0;
        ifstream fileCount (file_name.c_str());
        while(getline(fileCount, line)){
            lineCounter++;
            cout << "LINE length: "<< line.length();
            
        }
        fileCount.close();
        cout << "Number of lines: " << lineCounter;
        if(lineCounter != 29) return false;

        int compareString;
		ifstream file (file_name.c_str());
        
		if (file.is_open()) {
			
			int row_count = 0;
            for(int depth = 0; depth < SIZE; depth++){
                for(int row = 0; row < SIZE; row++) {
				getline(file, line);
                
                while (line.length()==0)
                {
                    getline(file, line);
                }
                if(line.length() != 9){
                  return false;
                }
				stringstream ss(line);
				for(int col = 0; col < SIZE; col++) {
					int value;
					ss >> value;
                    if(value != 1 && value != 0){
                        return false;
                    }
					//cout << "["<< depth << "]["<<row<<"]["<<col<<"]="<<value<<endl;
					maze[depth][row][col] = value;
				}
			}
            }
			
		}
        if(maze[4][4][4] != 1 || maze[0][0][0] != 1) {
            return false;
        }
	    return(true);
}
vector<string> Pathfinder::solveMaze(){
    //Copy maze to temMaze so we don't edit the original maze
    int tempMaze[SIZE][SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                tempMaze[i][j][k] = maze[i][j][k];
            }
        }
    }
    
    isSolvable(tempMaze, 0, 0, 0);
	    for(auto s:solution) {
		//cout <<s<<endl;
	    }
        /*
        if(solution.at(SIZE-1) == 3){
            return maze;
        }
        */
        reverse(solution.begin(),solution.end());
	    return solution;

    //Base Cases!
    // if (outside of maze || invalid path || have been here before)
    // strVec.pop_back();
    // return false

    //if(end of maze)
    // return true;

    //maze[x][y][z] = 2;
    // if(up || down || left || right || in || out) We are on the right path
}
bool Pathfinder::isSolvable(int grid[SIZE][SIZE][SIZE], int d, int r, int c)
 {
	  //cout << "find_maze_path ["<<r<<"]["<<c<<"]"<<endl;
	  //cout << this->toString();
	  if (r < 0 || c < 0 || r >= SIZE || c >= SIZE)
	    return false;      // Cell is out of bounds.
	  else if (grid[d][r][c] != 1)
	    return false;      // Cell is on barrier or dead end.
	  else if (r == SIZE - 1 && c == SIZE - 1) {
	    grid[d][r][c] = 3;         // Cell is on path
	    solution.push_back("("+ to_string(d) + ", "+to_string(r)+", "+to_string(c)+")");
	    return true;               // and is maze exit.
	  }
	  else { 
	    // Recursive case.
	    // Attempt to find a path from each neighbor.
	    // Tentatively mark cell as on path.
	    grid[d][r][c] = 3;
	    if (isSolvable(grid, d, r - 1, c) // North
	        || isSolvable(grid, d, r + 1, c) // South
	        || isSolvable(grid, d, r, c - 1) // Left
	        || isSolvable(grid, d, r, c + 1 ) // Right
            || isSolvable(grid, d+1, r, c) // Up
            || isSolvable(grid, d-1, r, c) // Down
            ) { 
	      solution.push_back("(" + to_string(d) + ", " +to_string(r)+", "+to_string(c)+")");
	      return true;
	    }
	    else {
	      grid[d][r][c] = 2;  // Dead end.
	      return false;
	    }
	  }
}