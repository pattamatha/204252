#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Village{
    int numHouse;
    vector<int> *adjLists;    
    bool *visited;
    
public:
    Village(int V){
     numHouse = V;
     adjLists = new vector<int>[V];
    }

    void addRoad(int src, int dest){
     // ทำให้เป็น undirect
     adjLists[src].push_back(dest);
     adjLists[dest].push_back(src);

     // หลัง addRoad แล้วต้องเรียงลำดับด้วย
     // เพราะลำดับในการตรวจสอบเพื่อนบ้านระหว่างประมวลผลให้เรียงจากน้อยไปมาก
     int min, temp;
     int i, j;
     for (i=0; i<adjLists[src].size()-1; i++){
          min = i;
          for (j=i+1; j<adjLists[src].size(); j++){
               if (adjLists[src][i] > adjLists[src][j])
                    min = j;
          }
          temp = adjLists[src][i];
          adjLists[src][i] = adjLists[src][min];
          adjLists[src][min] = temp;
     }
     for (i=0; i<adjLists[dest].size()-1; i++){
          min = i;
          for (j=i+1; j<adjLists[dest].size(); j++){
               if (adjLists[dest][i] > adjLists[dest][j])
                    min = j;
          }
          temp = adjLists[dest][i];
          adjLists[dest][i] = adjLists[dest][min];
          adjLists[dest][min] = temp;
     }
    }

    void BFS(int firstHouse){
     visited = new bool[numHouse];
     for (int i = 0; i < numHouse; i++)
          visited[i] = false;
     queue<int> q;
     q.push(firstHouse);
     while(!q.empty()){
          int u = q.front();
          q.pop();
          if(visited[u])
               continue;
          visited[u] = true;
          cout << u << " ";
          vector<int>::iterator it;
          for(it = adjLists[u].begin(); it!=adjLists[u].end(); it++){
               if(!visited[*it])
                    q.push(*it);
          }
     }
    }

    void DFS(int firstHouse){
     visited = new bool[numHouse];
     for (int i = 0; i < numHouse; i++)
          visited[i] = false;
     for(int i=firstHouse; i<numHouse; i++){
          if(visited[i]==false)
               DFSVISIT(i);
     }
    }
    
    void DFSVISIT(int vertex){
     visited[vertex] = true;
     cout<< vertex << " ";
     vector<int>::iterator it;
     for(it = adjLists[vertex].begin(); it!=adjLists[vertex].end(); it++){
          if(!visited[*it])
               DFSVISIT(*it);
     }
    }

    void printGraph(){
     for(int i=0; i<numHouse; i++){
          vector<int> adjList = adjLists[i];
          vector<int>::iterator it;
          cout<<i<<"->";
          for(it = adjList.begin(); it!=adjList.end(); it++){
               cout<<*it<<" ";
          }
          cout<<"\n";
     }
     }

};




