#include<bits/stdc++.h>
using namespace std;

class GraphMat{
    vector<int> vertices;
    vector<vector<int>> adjMat;
public :
    //建構子
    GraphMat(vector<int> vertices,vector<pair<int,int>> edges){
        for(int i : vertices){
            Addvertex(i);
        }
        for(auto edge : edges){
            Addedge(edge.first,edge.second);
        }
    }

    void Addvertex(int val){
        for(auto &i : adjMat){
            i.push_back(0);
        }
        vertices.push_back(val);
        adjMat.emplace_back(vector<int> (vertices.size(),0));
    }

    int Find_index(int val){
      auto it = find(vertices.begin(),vertices.end(),val);
      if(it == vertices.end()){
        return -1;
      }
      return distance(vertices.begin(),it);
    }

    void Delvertex(int val,vector<pair<int,int>> &edges){
        int index = Find_index(val);
        if(index >= vertices.size()){
            throw out_of_range("頂點不存在");
        }
        for(auto &i : edges){
            if(edges.first == val||edges.second == val){
                delete i;
            }
        }
        vertices.erase(vertices.begin() + index);
        adjMat.erase(adjMat.begin() + index);
        for(auto &i : adjMat){
            i.erase(i.begin() + index);
        }
    }

    void Addedge(int x,int y){
        int i = Find_index(x);
        int j = Find_index(y);
        if(i < 0||j < 0||i==j||i>=vertices.size()||j>=vertices.size()){
            throw out_of_range("頂點不存在");
        }
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    void Deledge(int x,int y){
        int i = Find_index(x);
        int j = Find_index(y);
        if(i < 0||j < 0||i==j||i>=vertices.size()||j>=vertices.size()){
            throw out_of_range("頂點不存在");
        }
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    void print(){
        cout << "頂點串列 : ";
        for(int i=0;i<vertices.size();i++){
            cout << vertices[i];
            if(i!=vertices.size()-1){
                cout << " ";
            }
        }

        cout << "\n鄰接矩陣 : \n";
        for(int i=0;i<adjMat.size();i++){
            for(int j=0;j<adjMat[i].size();j++){
                cout << adjMat[i][j];
                if(j != adjMat[i].size()-1){
                    cout << " ";
                }
            }
            if(i != adjMat.size()-1){
                    cout << '\n';
            }
        }
    }
};

int main(){
    vector<int> v = {1,2,3,4,5,6};
    vector<pair<int,int>> e = {{1,2},{2,4},{4,5}};
    GraphMat Graph(v,e);
    Graph.print();
    cout <<'\n';
    cout <<"\n刪除頂點後 : \n\n";
    Graph.Delvertex(2,e);
    Graph.print();
}
