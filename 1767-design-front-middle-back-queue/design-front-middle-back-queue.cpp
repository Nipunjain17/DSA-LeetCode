class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class FrontMiddleBackQueue {
public:
    Node* head;
    Node* tail;
    int size;

    FrontMiddleBackQueue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void pushFront(int val) {
        Node* temp = new Node(val);

        if(head == NULL){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

        size++;
    }

    void pushBack(int val) {
        Node* temp = new Node(val);

        if(tail == NULL){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        size++;
    }

    void pushMiddle(int val) {

        if(size == 0){
            pushFront(val);
            return;
        }

        int mid = size / 2;

        Node* curr = head;

        for(int i = 0; i < mid; i++){
            curr = curr->next;
        }

        Node* temp = new Node(val);

        if(curr == head){
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else{
            temp->next = curr;
            temp->prev = curr->prev;

            curr->prev->next = temp;
            curr->prev = temp;
        }

        size++;
    }

    int popFront() {

        if(size == 0)
            return -1;

        int val = head->data;

        if(size == 1){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }

        size--;
        return val;
    }

    int popBack() {

        if(size == 0)
            return -1;

        int val = tail->data;

        if(size == 1){
            delete tail;
            head = tail = NULL;
        }
        else{
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }

        size--;

        return val;
    }

    int popMiddle() {

        if(size == 0)
            return -1;

        int mid = (size - 1) / 2;

        Node* curr = head;

        for(int i = 0; i < mid; i++){
            curr = curr->next;
        }

        int val = curr->data;

        if(size == 1){
            delete curr;
            head = tail = NULL;
        }
        else{
            if(curr == head){
                head = curr->next;
                head->prev = NULL;
            }
            else if(curr == tail){
                tail = curr->prev;
                tail->next = NULL;
            }
            else{
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }

            delete curr;
        }

        size--;

        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */