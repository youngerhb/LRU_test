#include<iostream>

class lru_list
{
private:
    /* data */
    struct ListNode {
    int key;
    int value;        
    ListNode *pre,*next;
    ListNode(int k,int v) : key(k), value(v), pre(nullptr), next(nullptr) {};
    ListNode(int k, int v,ListNode *pre_node, ListNode*next_node) : key(k),value(v), pre(pre_node), next(next_node) {};
    };

    ListNode *head = nullptr;
public:
    
    void add_node(int k, int v){
        head = new ListNode(k,v,nullptr,head);
    }

    int check_value(int k){
        ListNode* node = head;
        while (node!=nullptr)
        {
            /* code */
            if(node->value==k){
                std::cout<<"the value of "<< k << "is" << node->value <<std::endl;
                return node->value;
            }
            node = node->next;
        }
        
        std::cout << "the key is not in the list" <<std::endl;
        return -1;
    }

    bool delete_node(int k){
        ListNode* node = head;
        while (node!=nullptr)
        {
            /* code */
            if(node->value==k){
                std::cout<<"the value of " << k <<"is" << node->value <<std::endl;
                node->pre->next = node->next;
                node->next->pre = node->pre;
                delete node;
                return 1;
            }
            node = node->next;
        }
        return 0;
    }
};




