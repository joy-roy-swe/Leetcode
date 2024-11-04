class Solution {
public:
    struct Node{
        Node*child[26]={NULL};
        int count = 0;
    };
    Node*root = new Node();

    void insert(string &s){
        Node *current = root;
        for(int i=0; i<s.size(); i++){
            int idx = s[i]-'a';
            if(current->child[idx]==NULL){
                current->child[idx] = new Node();
            }
            current = current->child[idx];
            current->count++;
        }
    }

    string longestCommonPrefix(vector<string>& strs) {
        for(int i=0; i<strs.size(); i++){
            insert(strs[i]);
        }
        string answer = "";
        string target = strs.back();
        Node * current = root;
        for(int i=0; i<target.size(); i++){
            int idx = target[i]-'a';
            if(current->child[idx] != NULL && current->child[idx]->count == strs.size()){
                answer.push_back(target[i]);
                current = current->child[idx];
            }
            else{
                break;
            }
        }
        return answer;
    }
};