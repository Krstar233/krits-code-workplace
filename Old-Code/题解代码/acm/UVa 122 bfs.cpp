#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1000;
char s[maxn];
bool failed;

struct Node{
	bool have_value;
	int v;
	Node *left, *right;
	Node():have_value(false), left(NULL), right(NULL) {}
};
Node* root;

Node* newnode(){
	return new Node();
}
void addnode(int v, char *s){
	int n = strlen(s);
	Node* u = root;
	for (int i = 0;i < n; i++){
		if (s[i] == 'L'){
			if (u->left == NULL)	u->left = newnode();
			u = u->left;
		}else if (s[i] == 'R'){
			if (u->right == NULL)	u->right = newnode();
			u = u->right;
		}
	}
	if (u->have_value)	failed = true;
	u->v = v;
	u->have_value = true;                                                       
}
void remove_tree(Node* u){
	if (u == NULL)	return;
	remove_tree(u->left);
	remove_tree(u->right);
	delete u;
}
bool read_input(){
	failed = false;
	remove_tree(root);
	root = newnode();
	while(true){
		if (scanf("%s", s) != 1) return false;
		if (!strcmp(s,"()"))	break;
		int v;
		sscanf(&s[1], "%d", &v);
		addnode(v, strchr(s, ',') + 1);
	}
	return true;
}
/**************************
		IMPORTANT:
**************************/
bool bfs(vector<int> &ans){
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while (!q.empty()){
		Node* u = q.front(); q.pop();
		if (!u->have_value)	return false;
		ans.push_back(u->v);
		if (u->left != NULL)
			q.push(u->left);
		if (u->right != NULL)
			q.push(u->right);
	}
	return true;
}

int main(){
	vector<int> ans;
	
	while (read_input()){
		if (failed){
			printf("-1\n");
			continue;
		}
		else if (!bfs(ans)){
			printf("-1\n");
			continue;
		}
		for (int i = 0; i < ans.size(); i++){
			printf("%d", ans[i]);
			if (i != ans.size())
				printf(" ");
		}
		printf("\n");
	}
}
