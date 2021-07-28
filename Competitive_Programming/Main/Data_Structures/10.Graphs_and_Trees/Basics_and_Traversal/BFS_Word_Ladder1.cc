// https://leetcode.com/problems/word-ladder/
// This is just application of STANDARD BFS only.

class Solution {
public:
        
        string a,b;
        vector<string> p;
        map<string, vector<string>> adjhelper;
    
        void preprocess(){
            
            for(auto word: p){
                for(int i = 0; i <word.size(); i++){     
                    string inter =  word.substr(0,i) + "*" +  word.substr(i+1);
                    adjhelper[inter].push_back(word);
                }
            }
        }

        int BFS(){
            
            queue <string> myqueue;
            map<string, int> distance;
            for(auto i : p) distance[i] = INT_MAX;
            
            distance[a] = 1;
            myqueue.push(a);
     
            while(!myqueue.empty()){
                string currword = myqueue.front();
                myqueue.pop(); 
                if (currword == b){
                    return distance[b];
                }
                for(int i = 0; i <currword.size(); i++){       

                    string inter =  currword.substr(0,i) + "*" +  currword.substr(i+1);

                    for(auto word: adjhelper[inter]){
                        
                        if (distance[word] > 1 + distance[currword]){
                            distance[word] = 1 + distance[currword]; myqueue.push(word);
                        } 

                    }
                }
            }
            
            return 0;
        }

    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        a = beginWord; b = endWord; p = wordList;
        preprocess();
        int res = BFS();
        return res;   
    }
};