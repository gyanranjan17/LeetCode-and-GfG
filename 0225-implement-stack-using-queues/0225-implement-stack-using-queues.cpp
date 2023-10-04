class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int sz=q.size()-1;
        while(sz--){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
        int last=q.front();
        q.pop();
        return last;
    }
    
    int top() {
        int sz=q.size()-1;
        while(sz--){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
        int last=q.front();
        q.pop();
        q.push(last);
        return last;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */