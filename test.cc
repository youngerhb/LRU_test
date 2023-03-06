#include "lru.cc"

int main(){
    lru_list * lptr = new lru_list();
    lptr->add_node(1,-1);
    lptr->add_node(2,-2);
    lptr->add_node(3,-3);
    lptr->add_node(4,-4);
    lptr->add_node(5,-5);

    lptr->print_all_nodes();
    std::cout << std::endl;
    lptr->check_value(1);
    std::cout << std::endl;
    lptr->print_all_nodes();
    std::cout << std::endl;
    lptr->delete_node(3);
    lptr->print_all_nodes();

    delete lptr;
    lptr = nullptr;

}