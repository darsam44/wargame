#include "ParamedicCommander.hpp"

using namespace std;

namespace WarGame{
//pass through the board and call every paramedic in the board that in the same player
    void ParamedicCommander :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int i=location.first;
       int j=location.second;
      for (int i = 0; i < board.size(); i++)
      {
          for (int i = 0; i < board[0].size(); i++)
          {
                 Soldier *a=board[i][j];
                 if( a != nullptr){
                 if(  Paramedic *fs = dynamic_cast<Paramedic*> (a)){
                     ParamedicCommander *footcom = dynamic_cast<ParamedicCommander*> (a);
                     if ( footcom == nullptr || ( i == location.first && j == location.second)) {                     
                     if ( fs->getNum() == s->getNum()){
                         fs->Paramedic::attack(board , {i,j});
                     }
                    }
                 }     
             }
          }
      }
      


    }


}