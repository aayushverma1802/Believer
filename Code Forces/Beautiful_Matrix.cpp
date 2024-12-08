#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    int mat[5][5];
    int row=0,col=0;
    for (int i = 0; i < 5; i++)
    {
        string strn;
        getline(cin, strn);
        stringstream ss(strn);
        for (int j = 0; j < 5; j++)
        {
            ss >> mat[i][j];
            if(mat[i][j]==1){
                row=i;
                col=j;
            }
        }
    }
    //<Main coordinates>
    int rm=2,cm=2;
    int coordinates_calucation=abs(rm-row)+abs(cm-col);
    cout<<coordinates_calucation;

    //Display Function for the 5*5 matrix
    // for(auto &i:mat){
    //     for(auto &j:i){
    //         cout<<j<<" ";
    //     }
    // }
}