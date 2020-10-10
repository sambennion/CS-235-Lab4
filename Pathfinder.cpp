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
		ifstream file (file_name.c_str());
		if (file.is_open()) {
			string line;
			int row_count = 0;
            for(int depth = 0; depth < SIZE; depth++){
                for(int row = 0; row < SIZE; row++) {
				getline(file, line);
                while (line.length()==0)
                {
                    getline(file, line);
                }
				stringstream ss(line);
				for(int col = 0; col < SIZE; col++) {
					int value;
					ss >> value;
					cout << "["<< depth << "]["<<row<<"]["<<col<<"]="<<value<<endl;
					maze[depth][row][col] = value;
				}
			}
            }
			
		}
	    return(true);
}
vector<string> Pathfinder::solveMaze(){
    vector<string> strVec;
    strVec.push_back("(x, y, z)");
    //Base Cases!
    // if (outside of maze || invalid path || have been here before)
    // strVec.pop_back();
    // return false

    //if(end of maze)
    // return true;

    //maze[x][y][z] = 2;
    // if(up || down || left || right || in || out) We are on the right path
    return strVec;
}
