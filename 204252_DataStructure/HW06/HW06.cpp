#include <bits/stdc++.h>
using namespace std;

class Team{
    public:
    int ID;
    int GD; //Goal Difference = Goal score - Goal conced
    int PTS; //Point (win = 3, draw = 1, lose = 0)

    // Constructor
    Team(int x, int y, int z) : ID(x), GD(y), PTS(z) {}
};

class Scoreboard{
public:
    vector<Team> T;
    int numberOfTeams = 0;
    
    Scoreboard(int n){
        numberOfTeams = n;
        for(int i=0; i<n; i++){
            Team x(i,0,0);
            T.push_back(x);
        }
    }

    void match(int ID1, int ID2,int G1,int G2){
        /* WRITE YOUR CODE HERE */
        // อัพเดตคะแนนที่ match แล้ว
        int GD1 = G1 - G2;
        int GD2 = G2 - G1;
        
        if (GD1 > GD2){
            for (int i = 0; i < T.size(); i++){
                if (T[i].ID == ID1){
                    T[i].PTS += 3;
                    T[i].GD += GD1;
                }
                if (T[i].ID == ID2){
                    T[i].PTS += 0;
                    T[i].GD += GD2;
                }
            }
        } else if (GD1 < GD2) {
            for (int i = 0; i < T.size(); i++){
                if (T[i].ID == ID1){
                    T[i].PTS += 0;
                    T[i].GD += GD1;
                } if (T[i].ID == ID2) {
                    T[i].PTS += 3;
                    T[i].GD += GD2;
                }
            }
        } else {
            for (int i = 0; i < T.size(); i++) {
                if (T[i].ID == ID1) {
                    T[i].PTS += 1;
                    T[i].GD += GD1;
                }
                if (T[i].ID == ID2){
                    T[i].PTS += 1;
                    T[i].GD += GD2;
                }
            }
        }

        // เรียงลำดับคะแนน
        int i, j;
        for (i=0; i<T.size(); i++){
          int min = i;
          for (j=i+1; j<T.size(); j++){
                if (T[j].PTS > T[min].PTS) {
                    min = j;
                } else if (T[j].PTS == T[min].PTS) {
                    if (T[j].GD > T[min].GD){
                        min = j;
                    } else if (T[j].GD == T[min].GD) {
                        if (T[j].ID < T[min].ID){
                            min = j;
                        }
                    }
                }
                
          }
          Team temp = T[i];
          T[i] = T[min];
          T[min] = temp;
        }
    } 
    
    void showTeamAtRank(int i){
        /* WRITE YOUR CODE HERE */
        int id = i-1;
        cout << T[id].ID << " ";
        cout << T[id].PTS << " ";
        cout << T[id].GD << endl;
    }
};