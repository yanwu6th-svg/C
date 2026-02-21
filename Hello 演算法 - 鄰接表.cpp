#include<bits/stdc++.h>
using namespace std;

struct Vertex{
    int val;
    Vertex(int x) : val(x){};
};

class GraphadjList{
public:
    unordered_map<Vertex *,vector<Vertex *>> adjlist;

    GraphadjList(vector<vector<Vertex *>> edges){
        for(int i=0;i<edges.size();i++){
            Addvertex(edges[i][0]);
            Addvertex(edges[i][1]);
            Addedge(edges[i][0],edges[i][1]);
        }
    }

    void Remove(vector<Vertex *> &vec,Vertex * vet){
        for(int i=0;i<vec.size();i++){
            if(vec[i] == vet){
                vec.erase(vec.begin() + i);
                return;
            }
        }
    }

    void Addvertex(Vertex * vet){
        adjlist[vet] = vector<Vertex *>();
    }

    void Delvertex(Vertex * vet){
        if(!adjlist.count(vet)){
            throw invalid_argument("頂點不存在");
        }
        adjlist.erase(vet);
        for(auto &i : adjlist){
            Remove(i.second,vet);
        }
    }
    void Addedge(Vertex * vet1 , Vertex * vet2){
        if(!adjlist.count(vet1) || !adjlist.count(vet2) || vet1 == vet2){
            throw invalid_argument("頂點不存在");
        }
        adjlist[vet1].push_back(vet2);
        adjlist[vet2].push_back(vet1);
    }
    void Deledge(Vertex * vet1 , Vertex * vet2){
        if(!adjlist.count(vet1) || !adjlist.count(vet2) || vet1 == vet2){
            throw invalid_argument("頂點不存在");
        }
        Remove(adjlist[vet1],vet2);
        Remove(adjlist[vet2],vet1);
    }

    void print(){
        cout << "鄰接表 : \n";
        for(auto &[a,b] : adjlist){
            cout << a->val<<" : ";
            for(auto i : b){
                cout << i->val <<" ";
            }
            cout <<'\n';
        }

    }
};

int main(){
    Vertex *v1 = new Vertex(1);
    Vertex *v2 = new Vertex(2);
    Vertex *v3 = new Vertex(3);
    Vertex *v4 = new Vertex(4);
    Vertex *v5 = new Vertex(5);
    vector<vector<Vertex *>> edges = {{v1,v3},{v2,v3},{v3,v5},{v2,v1}};
    GraphadjList g(edges);
    g.print();
}
