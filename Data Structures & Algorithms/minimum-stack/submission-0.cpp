class MinStack {
public:

    stack<int> st;
    stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            minSt.push(val);
        }
        else
        {
            st.push(val);
            if(st.top() < minSt.top())
                minSt.push(val);
            else
                minSt.push(minSt.top());
        }
    }
    
    void pop() {
        if(!st.empty())
        {
            st.pop();
            minSt.pop();
        }
    }
    
    int top() {
        if(!st.empty())
            return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
