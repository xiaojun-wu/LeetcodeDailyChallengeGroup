class Skiplist {
public:
    Skiplist() {
        head = make_shared<Node>();
        srand (time(NULL));
    }
    
    bool search(int target) {
        bool isFound = false;
        for(auto node = head;node && !isFound;node = node->down){
            while(node->next && node->next->val < target)
                node = node->next;
            if(node->next && node->next->val == target)
                isFound = true;
        }
        
        return isFound;
    }
    
    void add(int num) {
        vector<shared_ptr<Node>> stack;
        shared_ptr<Node> down;
        bool isInsert = false;
        
        for(auto node = head;node;node = node->down){
            while(node->next && node->next->val < num)
                node = node->next;
            stack.push_back(node);
        }
        
        while(!isInsert && !stack.empty()){
            auto node = stack.back();
            stack.pop_back();
            node->next = make_shared<Node>(num,node->next,down);
            down = node->next;
            isInsert = rand() % 2;
        }
        
        if(!isInsert){
            head = make_shared<Node>(-1,nullptr,head);
            head->next = make_shared<Node>(num,nullptr,down);
        }
    }
    
    bool erase(int num) {
        bool isFound = false;
        
        for(auto node = head;node;node = node->down){
            while(node->next && node->next->val < num)
                node = node->next;
            if(node->next && node->next->val == num){
                node->next = node->next->next;
                isFound = true;
            }
        }
        
        return isFound;
    }
private:
    struct Node{
        int val;
        shared_ptr<Node> next;
        shared_ptr<Node> down;
        Node(int _val = -1,shared_ptr<Node> _next = nullptr, shared_ptr<Node> _down = nullptr) : val(_val), next(_next), down(_down) {}
    };
    shared_ptr<Node> head;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

