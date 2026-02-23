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
        if(adjlist.count(vet)) return;
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

    vector<Vertex *> BFS(Vertex *vet){
        vector<Vertex *> res;
        queue<Vertex *> q;
        unordered_set<Vertex *> visited;
        q.push(vet);
        visited.insert(vet);
        while(!q.empty()){
                Vertex * h = q.front();
                res.push_back(h);

                for(auto v : adjlist[h]){
                    if(visited.find(v) == visited.end()){
                        q.push(v);
                        visited.insert(v);
                    }
                }
                q.pop();
        }
        return res;
    }

     void dfs(vector<Vertex *> &res,unordered_set<Vertex *> &visited,   Vertex * &curr){
        visited.insert(curr);
        res.push_back(curr);
        if(!adjlist[curr].empty()){
            for(auto i : adjlist[curr]){
                if(!visited.count(i)){
                    dfs(res,visited,i);
                }
            }
        }
        return;
    }

    vector<Vertex *> DFS(Vertex * start){
        vector<Vertex *> res;
        unordered_set<Vertex *> visited;
        dfs(res,visited,start);
        return res;
    }
};

void vec_print(vector<Vertex *> v){
    for(auto i : v){
        cout << i->val <<" ";
    }
}
int main(){
    Vertex *v1 = new Vertex(1);
    Vertex *v2 = new Vertex(2);
    Vertex *v3 = new Vertex(3);
    Vertex *v4 = new Vertex(4);
    Vertex *v5 = new Vertex(5);
    vector<vector<Vertex *>> edges = {{v2,v4},{v1,v4},{v1,v3},{v2,v3},{v3,v5},{v2,v1}};
    GraphadjList g(edges);
    vector<Vertex *> res = g.DFS(v1);
    vec_print(res);

}
