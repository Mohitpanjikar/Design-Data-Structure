//Link - https://leetcode.com/problems/implement-queue-using-stacks/description/
class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        //if the stack is empty return -1 ,else take every element to stack 2 till size != 1
        if(st1.empty()){
            return -1;
        }
        
        while(st1.size() != 1){
            int ele = st1.top();
            st1.pop();
            st2.push(ele);
        }
        int poped_ele = st1.top();
        st1.pop();
        
        while(!st2.empty()){
            int ele = st2.top();
            st2.pop();
            st1.push(ele);
        }
        return poped_ele;
    }
    
    int peek() {
        //if the stack is empty return -1 ,else take every element to stack 2 till size != 1
        if(st1.empty()){
            return -1;
        }
        
        while(st1.size() != 1){
            int ele = st1.top();
            st1.pop();
            st2.push(ele);
        }
        int peek_ele = st1.top();
        while(!st2.empty()){
            int ele = st2.top();
            st2.pop();
            st1.push(ele);
        }
        return peek_ele;
    }
    
    bool empty() {
        if(st1.empty() == true){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
