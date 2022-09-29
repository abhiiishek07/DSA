class MyCircularQueue {
public:
    int cap;
    int size=0;
    int front=0;
    vector<int>q;
    MyCircularQueue(int k) {
        front=0;
        cap=k;
        q=vector<int>(cap,0);
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        q[(front+size)%cap]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        front=(front+1)%cap;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:q[front];
    }
    
    int Rear() {
        return isEmpty()?-1:q[(front+size-1)%cap];
    }
    
    bool isEmpty() {
       return size==0;
    }
    
    bool isFull() {
        return size==q.size();
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