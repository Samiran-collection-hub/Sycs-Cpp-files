#include <iostream>
#include <vector>
using namespace std;
class GraphList{
    private:
    int numV;
    vector<vector<int>> adjList;
    public:
    GraphList(int ver){
        numV=ver;
        adjList.resize(ver);
    }
    void addEdge(int u,int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void dis(){
        cout << "Adjacency List:\n";
        for (int i = 0; i < numV; i++) {
            cout << i<< "->";
            for(int j: adjList[i]) cout<<j<<" ";
            cout<<endl;
        }
    }
};
int main() 
{
    int ver=5;
    GraphList g(ver);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.dis();
    return 0;
}
