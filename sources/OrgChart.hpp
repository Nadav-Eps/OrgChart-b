#ifndef OrgChart_H
#define OrgChart_H
#include "Node.hpp"
namespace ariel
{
    class Iter{
        public :
        unsigned int it_idx;
        vector<Node*> nodes;
            Iter(){
                it_idx = 0;
            };
            string *operator->(){
                return &(nodes[it_idx]->name);};
            string operator*(){
                return nodes.at(it_idx)->name;};
            Iter operator++(){
                if(!(it_idx < nodes.size())){
                    throw;
                }
                it_idx +=1;
                return *this;
            };
            
            friend bool operator==(const Iter &t_it,const Iter  &o_it){
                bool flag = false;
                if(t_it.nodes.empty()){
                    throw invalid_argument("At least one of the iterators are empty");
                }
                if(o_it.nodes.empty()){
                    throw invalid_argument("one of the iterators are empty");
                }
                if((t_it.nodes==o_it.nodes)&&(t_it.it_idx == o_it.it_idx)){
                    flag = true;;
                }
                return flag;
            };
            friend bool operator!=(const Iter &t_it,const Iter  &o_it){
                return !(t_it==o_it);
            };
    };
    class Node;
    class OrgChart
    {
    Node *root;
    public:
        OrgChart(){
            root = nullptr;
        };
        
        OrgChart add_root(string const &node_name);
        OrgChart add_sub(string const &nod, string const &nod1 );
        Iter begin_level_order();
        Iter end_level_order();
        Iter begin_reverse_order();
        Iter reverse_order();
        Iter begin_preorder();
        Iter end_preorder();
        Iter begin();
        Iter end();
        friend ostream &operator << ( ostream &output,  OrgChart &n);
        Node* find_n(string const &nod);
        void pre_or_f(Node *node, Iter &it);

    };

    
}
#endif