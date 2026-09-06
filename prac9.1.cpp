#include <iostream>
using namespace std;

#define MAZ 10
class GraphMatrix{
    private:
    int adj[MAZ][MAZ];
    int numV;
    public:
    GraphMatrix(int ver){
        numV=ver;
        for (int i = 0; i < numV; i++) {
            for(int j=0;j<numV;j++)
            adj[i][j]=0;
        }
    }
    void addEdge(int i,int j){
        adj[i][j]=adj[j][i]=1;
    }
    void dis(){
        cout<<"\nAdjacery Matrix:\n";
        for (int i = 0; i < numV; i++) {
            for(int j=0;j<numV;j++)
            cout << adj[i][j] << " ";
            cout<<endl;
        }
    }
};

int main() 
{
    int ver=5;
    GraphMatrix g(ver);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.dis();
    
    return 0;
}
