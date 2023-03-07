#include <iostream>

class lru_list
{
private:
    /* data */
    struct ListNode
    {
        int key;
        int value;
        ListNode *pre, *next;
        ListNode(int k, int v) : key(k), value(v), pre(nullptr), next(nullptr){};
        ListNode(int k, int v, ListNode *pre_node, ListNode *next_node) : key(k), value(v), pre(pre_node), next(next_node){};
    };

    ListNode *head = nullptr;

public:
    void add_node(int k, int v)
    {
        head = new ListNode(k, v, nullptr, head);
        if(head->next!=nullptr)
        head->next->pre = head;
    }
    
    int check_value(int k)
    {
        ListNode *node = head;
        while (node != nullptr)
        {
            /* code */
            if (node->key == k)
            {
                std::cout << "the value of " << k << " is " << node->value << std::endl;

                if(node->pre!=nullptr){          
                    node->pre->next = node->next; 
                    
                    if(node->next!=nullptr)
                    node->next->pre = node->pre;

                    node->next=node->pre;

                    if(node->pre->pre!=nullptr){
                        node->pre->pre->next = node;
                        node->pre = node->pre->pre;                               
                    }
                    else{
                        head = node;
                        node->pre =nullptr;   
                    }          
                
                }
                
                return node->value;
            }
            node = node->next;
        }

        std::cout << "the key is not in the list" << std::endl;
        return -1;
    }

    bool delete_node(int k)
    {
        ListNode *node = head;
        while (node != nullptr)
        {
            /* code */
            if (node->key == k)
            {
                std::cout << "the value of " << k << " is " << node->value << std::endl;
                if(node->pre!=nullptr)
                node->pre->next = node->next;
                else
                head = node->next;

                if(node->next!=nullptr)
                node->next->pre = node->pre;
                delete node;
                return 1;
            }
            node = node->next;
        }
        
        return 0;
    }
    void print_all_nodes(){
        ListNode* node = head;
        while ((node!=nullptr))
        {
            /* code */
            std::cout<<"key is : " << node->key << " value is : "<< node->value<<std::endl;
            node = node->next;
        }

  
        /*
        while ((node!=nullptr))
        {
            
            std::cout<<"反着 key is : " << node->key << " value is : "<< node->value<<std::endl;
            node = node->pre;
        }*/
  
    }
};