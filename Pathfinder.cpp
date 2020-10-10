#include "Pathfinder.h"
using namespace std;


 string Pathfinder::toString(){
    stringstream ss;
    string strMaze = "";
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                ss << maze[i][j][k] << " ";
                ss >> strMaze;
            }
            strMaze += " ";
        }
    }
    return strMaze;
}
void Pathfinder::createRandomMaze(){
    srand(time(NULL));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                maze[i][j][k] = rand() % 2;
            }
        }
    }
    maze [0][0][0] = 1;
    maze [4][4][4] = 1;
    return;
}
bool Pathfinder::importMaze(string file_name){
    ifstream ifs;
  string line;
  int x, y = 0;
  string boardValues[SIZE][SIZE][SIZE];

  // Open file
  ifs.open(file_name, ifstream::in);
  if(!ifs.is_open())
  {
    cout << "file " << file_name << " failed to open" << endl;
    return false;
  }

  for(y = 0; y < SIZE; y++)
  {
    getline(ifs, line);
    if(ifs.bad() || ifs.fail())
    {
      cout << "line read fail" << endl;
      return false;
    }
    while(line[line.size()-1] == ' ' || line[line.size()-1] == '\n' || line[line.size()-1] == '\r')
      line = line.substr(0, line.size()-1);
    if(line.size() != SIZE*2-1)
    {
      cout << "line wrong size: actual " << line.size() << ", expected: " << SIZE*2-1 << endl;
      return false;
    }
    for(x = 0; x < SIZE; x++)
    {
      boardValues[x][y] = line[x*2];
    }
  }

  // Check for no extra lines
  getline(ifs, line);
  if(!ifs.bad() && !ifs.fail())
  {
    cout << "too many extra lines found" << endl;
    return false;
  }

  setBoard(boardValues);
  return true;
}
vector<string> Pathfinder::solveMaze(){
    vector<string> strVec = {""};
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
