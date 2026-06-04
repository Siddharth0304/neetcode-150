class MinStack {
public:
    stack<long long> st;
    long long min = LLONG_MAX;

    MinStack() {}
    
    void push(int val) {
        long long v = val;
        if (st.empty()) {
            st.push(v);
            min = v;
        } else {
            if (v <= min) {
                st.push(2 * v - min);
                min = v;
            } else {
                st.push(v);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        if (st.top() < min)
            min = 2 * min - st.top();
        st.pop();
    }
    
    int top() {
        if (st.empty()) return -1;
        return (st.top() > min) ? st.top() : min;
    }
    
    int getMin() {
        if (st.empty()) return -1;
        return min;
    }
};
