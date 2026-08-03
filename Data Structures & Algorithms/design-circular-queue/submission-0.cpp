class MyCircularQueue {
public:
    vector<int> queue;
    int capacity;
    MyCircularQueue(int k) {
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(queue.size() == capacity)
            return false;
        queue.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(queue.empty())
            return false;
        queue.erase(queue.begin());
        return true;
    }
    
    int Front() {
        if(!queue.empty())
            return queue.front();
        return -1;
    }
    
    int Rear() {
        if(!queue.empty())
            return queue.back();
        return -1;
    }
    
    bool isEmpty() {
        return queue.empty();
    }
    
    bool isFull() {
        return(queue.size() == capacity);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */