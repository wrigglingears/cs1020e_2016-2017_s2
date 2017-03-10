class superStack() {
private:
    stack<int> _vals;

public:
    void push(int val) {
        _vals.push(val);
    }

    void pop() {
        _vals.pop();
    }

    int top() {
        return _vals.top();
    }

    int size() {
        return _vals.size();
    }

    bool empty() {
        return _vals.empty();
    }

    int min() {

    }

    double average() {

    }
};