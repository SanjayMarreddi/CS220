#include <bits/stdc++.h>
using namespace std;

class UnionFind {

public:

    // link[i] : The next element of `i` in the chain or the parent of node `i` 
    // size[i] : The size of the corresponding set where `i` is representative. Size should be Initialised with 1.
    vector<int> link, size;
    int distinctComponents;

    UnionFind(int n) {
        // Initially all 'n' nodes are in different components.
        // components have values from 0 to n-1
	    distinctComponents = n;
        for(int i = 0; i <n; i++){
            link.push_back(i);
        }
        size = vector<int>(n,1);
    }

    // Unites two nodes by linking small tree root to large tree root.
    // Also Returns true when two nodes 'a' and 'b' are initially in different components. Otherwise returns false.
    bool unite(int a, int b) {

        int ParentA = find(a);
        int ParentB = find(b);
        if (ParentA == ParentB){
            return false;
        }
        
        // This helps in making union by rank.
        if (size[ParentA] < size[ParentB])  
            swap(ParentA,ParentB);
            
        size[ParentA] += size[ParentB];
        link[ParentB] = ParentA;
        distinctComponents--;
        return true;
     }

    // Returns what component does the node 'x' belong to using Path Compression.
    int find(int x) {
        if (x != link[x])
            link[x] = find(link[x]) ;
        return link[x];
    }

    // Are all nodes united into a single component?
    bool united() {
        return distinctComponents == 1;
    }
};

// Usage of Class with an example
int main(){

    // Input
    int n; cin >> n;
    string name, email;
    unordered_map<string, vector<int> > store;
    map<int, vector<string>> input;
    for(int i=0; i<n;i++){
       
        cin >> name;
        vector<string> tmp = {name};
        int c; cin >> c;
        for(int j = 0; j <c; j++){
            cin >> email;
            store[email].push_back(i);
            tmp.push_back(email);
        }

        input[i] = tmp;
    }

    // Calling class.
    UnionFind uf(n);

    for(auto e : store){
        auto indices = e.second;
        int start = indices[0];
        for(int i = 1; i < indices.size(); i++){
            if ( uf.find(start) != uf.find(indices[i]) ){
                uf.unite( start, indices[i] );
            }
        }
    }


    map<int, vector<int>> components;
    for(int i=0; i<n; i++){
        components[uf.find(i)].push_back(i);
    } 
    
    vector<   pair< string, set<string> >   > ans;
    for(auto i : components){
        string name = input[i.first][0];
        set<string> mails;
        
        for(int j = 1; j <  input[i.first].size(); j++){
            mails.insert(input[i.first][j]);
        }

        for(auto each : i.second){
            for(int j = 1; j <  input[each].size(); j++){
                mails.insert(input[each][j]);
            }
        }
        ans.push_back({name, mails});
    }
    
    sort(ans.begin(), ans.end());

    for(auto i : ans){
        cout << i.first << " ";
        for(auto email : i.second){
            cout << email << " " ;
        }
        cout << endl;
    }
}