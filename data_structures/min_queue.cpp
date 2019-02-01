struct min_stack {
    stack<int> st, pr;
    void push(int x) {
        st.push(x);
        pr.push(min(x, pr.top()));
    }
    void pop() { st.pop(); pr.pop(); }
    int top() { return st.top(); }
    int mn() { return pr.top(); }
    bool empty() { return st.empty(); }
};

struct min_queue {
    min_stack toPush, toPop;
    void fix() {
        if(toPop.empty()) {
            while(!toPush.empty()) {
                toPop.push(toPush.top());
                toPush.pop();
            }
        }
    }
    bool empty() { return toPush.empty() && toPop.empty(); }
    void push(int x) { toPush.push(x); }
    void pop() { fix(); toPop.pop(); }
    int top() { fix(); toPop.top(); }
    int mn() {
        if(toPush.empty()) return toPop.mn();
        if(toPop.empty()) return toPush.mn();
        return min(toPush.mn(), toPop.mn());
    }
};
