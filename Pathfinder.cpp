#include "Pathfinder.h"
#include <algorithm>
using namespace std;


 string Pathfinder::toString() const{
    stringstream ss;
    string strMaze = "";
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            for(int k = 0; k < SIZE; k++){
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
    ifstream ifs;
  string line;
  

  // Open file
  ifs.open(file_name, ifstream::in);
  if(!ifs.is_open())
  {
    cout << "file " << file_name << " failed to open" << endl;
    return false;
  }
   
        
  int i, j, k;
  for(i = 0; i < SIZE; i++)
  {
    getline(ifs, line);
    if(ifs.bad() || ifs.fail())
    {
    cout << "line read fail" << endl;
    return false;
    }
    //cout << line << endl;
    while(line[line.size()-1] == ' ' || line[line.size()-1] == '\n' || line[line.size()-1] == '\r')
        line = line.substr(0, line.size()-1);
    //cout << line << " ";
    //cout << line.size() << endl;
    if(line.size() != SIZE*2-1)
    {
        cout << "line wrong size: actual " << line.size() << ", expected: " << SIZE*2-1 << endl;
        return false;
    }
    for(j = 0; j < SIZE; j++)
    {
        for(k = 0; k < SIZE*2; k+=2){
               cout << line[k] << endl;
            maze[i][j][k] = line[k];
            //cout << maze[i][j][k] << endl;
        }
      
    }
  }

  // Check for no extra lines
  getline(ifs, line);
  if(!ifs.bad() && !ifs.fail())
  {
    cout << "too many extra lines found" << endl;
    return false;
  }

  return true;
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
