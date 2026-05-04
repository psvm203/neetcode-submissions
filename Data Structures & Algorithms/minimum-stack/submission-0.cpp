class MinStack {
public:
    vector<int> stk;
    vector<int> mins;

    MinStack() {
    }
    
    void push(int val) {
        if (mins.empty() || val <= mins.back()) mins.emplace_back(val);
        stk.emplace_back(val);
    }
    
    void pop() {
        if (mins.size() && stk.back() == mins.back()) mins.pop_back();
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return mins.back();
    }
};
