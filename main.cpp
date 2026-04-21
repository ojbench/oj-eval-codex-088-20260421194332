#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    Node* next;
    Node(long long v) : val(v), next(nullptr) {}
};

struct QueueLL {
    Node* head = nullptr;
    Node* tail = nullptr;
    size_t sz = 0;
    ~QueueLL(){ clear(); }
    void push(long long v){
        Node* n = new Node(v);
        if(tail == nullptr){ head = tail = n; }
        else { tail->next = n; tail = n; }
        ++sz;
    }
    bool empty() const { return head == nullptr; }
    long long front() const { return head ? head->val : -1; }
    void pop(){
        if(head == nullptr) return;
        Node* n = head;
        head = head->next;
        if(head == nullptr) tail = nullptr;
        delete n;
        --sz;
    }
    void move_front_to_back(){
        if(head == nullptr || head == tail) return;
        Node* n = head;
        head = head->next;
        n->next = nullptr;
        tail->next = n;
        tail = n;
    }
    void clear(){
        while(head){ Node* n = head; head = head->next; delete n; }
        tail = nullptr;
        sz = 0;
    }
};

static inline long long last_card(long long n){
    if(n <= 1) return n;
    unsigned long long un = (unsigned long long)n;
    int lg = 63 - __builtin_clzll(un);
    long long p = 1LL << lg;
    if(p == n) return 1;
    return 2*(n - p) + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long id, n;
    if(!(cin >> id >> n)) return 0;

    if(id == 1){
        QueueLL q;
        for(long long i = 1; i <= n; ++i) q.push(i);
        for(long long round = 1; round <= n - 1; ++round){
            q.move_front_to_back();
            q.pop();
            if(!q.empty()) cout << q.front() << '\n';
        }
    } else if(id == 2){
        cout << last_card(n) << '\n';
    } else {
        cout << last_card(n) << '\n';
    }
    return 0;
}

