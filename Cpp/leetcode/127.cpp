#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    void add_edge(map<string, vector<string>> &G, string& word){
        string s = word;
        for (char& it : word){
            char tmp = it;
            it = '*';
            G[s].push_back(word);
            G[word].push_back(s);
            it = tmp;
        }
    }
    void create_map(map<string, vector<string>> &G,vector<string>& wordList){
        for (int i = 0; i < wordList.size(); i++){
            add_edge(G, wordList[i]);
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        int n = wordList.size();
        map<string, vector<string>> G;
        map<string, int> dis;
        add_edge(G,beginWord);
        create_map(G,wordList);
        q.push(beginWord);
        while (!q.empty()){
            int q_size = q.size();
            for (int i = 0; i < q_size; i++){
                string front = q.front(); q.pop();
                if (front == endWord)
                    return dis[front] / 2 + 1;
                for (string node : G[front]){
                    if (dis[node] == 0){
                        dis[node] = dis[front] + 1;
                        q.push(node);
                    }
                }
            }
        }
        return 0;
    }
};
int main(){

}