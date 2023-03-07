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
    lptr->check_value(2);
    lptr->check_value(2);
    lptr->check_value(2);
    lptr->check_value(2);
    lptr->check_value(4);
    std::cout << std::endl;
    lptr->print_all_nodes();
    std::cout << std::endl;
    lptr->delete_node(1);
    lptr->print_all_nodes();
    delete lptr;
    lptr = nullptr;

    
/* test2
    lptr->check_value(1);
    lptr->check_value(4);
    lptr->check_value(5);
    lptr->check_value(3);
    lptr->check_value(3);
    lptr->check_value(3);
    lptr->check_value(2);
    lptr->check_value(2);
    lptr->check_value(2);
    lptr->check_value(4);
    lptr->check_value(3);
    lptr->check_value(4);
    lptr->check_value(4);
    lptr->check_value(5);
    lptr->check_value(5);
    lptr->print_all_nodes();
*/
}