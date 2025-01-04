#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int main()
{   
    int M,N;
    cin>>N>>M;
    vector<vector<char>> maze(N, vector<char>(M));
    for(int i= 0; i< N ; i++){
        for(int j=0 ; j< M ; j++){
            cin>>maze[i][j];
        }
    }
    int Q;
    cin>>Q;
    while(Q--){
        int x, y ,step;
        cin>> x >>y >>step;
        x--;y--;
        for(int i=0 ; i< step ; i++)
    {
        char direction = maze[x][y];
        if(direction == 'U'){
            x= (x == 0) ? N -1 : x-1;
        }
        else if(direction == 'D'){
            x = (x== N-1 ) ? 0 : x+1;
        }
        else if(direction == 'L'){
            y = (y== 0) ? M -1 : y-1;
        }
        else if(direction == 'R'){
            y = (y == M-1) ? 0 : y +1;
        }
    }
    cout<< x+1 <<" "<< y+1<< endl;
    }
}