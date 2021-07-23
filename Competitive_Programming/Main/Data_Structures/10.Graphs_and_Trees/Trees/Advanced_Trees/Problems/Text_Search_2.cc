#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void){
	struct TrieNode* pNode = new TrieNode;
	pNode->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;
	return pNode;
}

// If not present, inserts key into trie. If the key is prefix of trie node, just marks leaf node.
// O(p),  p = key.size()
void insert(struct TrieNode* root, string key){
	struct TrieNode* trackPointer = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!trackPointer->children[index])
			trackPointer->children[index] = getNode();
		trackPointer = trackPointer->children[index];
	}
	trackPointer->isEndOfWord = true;
}

// Returns true if key is present in trie.
// O(p),  p = key.size()
bool search(struct TrieNode* root, string key){
	struct TrieNode* trackPointer = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!trackPointer->children[index])
			return false;
		trackPointer = trackPointer->children[index];
	}
	return (trackPointer != NULL && trackPointer->isEndOfWord);
}

// Returns true if there is word(key) that starts with `key` among the previously inserted words.
// O(p),  p = key.size()
bool startsWith(struct TrieNode* root, string key){
	struct TrieNode* trackPointer = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!trackPointer->children[index])
			return false;
		trackPointer = trackPointer->children[index];
	}
	return (trackPointer != NULL);
}

// Returns true if root has no children, else false
bool isEmpty(TrieNode* root){
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return false;
	return true;
}

// Recursive function to delete a key from given Trie
// O(p),  p = key.size()
TrieNode* remove(TrieNode* root, string key, int depth = 0){

	// If tree is empty
	if (!root)
		return NULL;

	// If last character of key is being processed
	if (depth == key.size()) {

		// This node is no more end of word after removal of given key
		if (root->isEndOfWord)
			root->isEndOfWord = false;

		// If given is not prefix of any other word
		if (isEmpty(root)) {
			delete (root);
			root = NULL;
		}

		return root;
	}

	// If not last character, recur for the child obtained using ASCII value
	int index = key[depth] - 'a';
	root->children[index] = remove(root->children[index], key, depth + 1);

	// If root does not have any child (its only child got deleted), and it is not end of another word.
	if (isEmpty(root) && root->isEndOfWord == false) {
		delete (root);
		root = NULL;
	}

	return root;
}

vector<vector<int>> offset={{0,1},{1,0},{-1,0},{0,-1}}; //useful to move in 4 directions

//check if the char exists in the board
    void checkWord(TrieNode* curr,vector<vector<char>>& board,int i,int j,vector<string>& res,string s)
    {
        
        s.push_back(board[i][j]);
        if(curr->isEndOfWord>0)
        {
            //we have got a word
            res.push_back(s);
            curr->isEndOfWord-=1; //since  not to push again the same word from other possibility
        }
        char orig=board[i][j];
        board[i][j]='#';
        for(int k=0;k<4;k++)
        {
            int x=offset[k][0]+i;
            int y=offset[k][1]+j;
            
            //dont move in these directions
            if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]=='#' || curr->children[board[x][y]-'a']==NULL)
                continue;
            checkWord(curr->children[board[x][y]-'a'],board,x,y,res,s);
        }
        board[i][j]=orig;
        
        
    }

int main(){
    struct TrieNode* root = getNode();
    int m,n; cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for(int i =0 ;i <m; i++){
           for(int j =0 ;j <n; j++){
               cin >> board[i][j];
           }
    }
    int t; cin >> t;
    vector<string> words(t); 
    for(int i =0 ;i <t; i++){cin >> words[i];   insert(root, words[i]); }


    vector<string> res;
    //now search the words in the grid
    int rows=board.size();
    int cols=board[0].size();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(root->children[board[i][j]-'a']!=NULL){ //if a starting letter of a wod exists in the words dict
                checkWord(root->children[board[i][j]-'a'],board,i,j,res,"");
            }
        }
    }

    sort(res.begin(), res.end());
    for(auto e: res){
        cout << e << " ";
    }

	return 0;
}