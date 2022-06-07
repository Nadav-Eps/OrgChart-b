#include "OrgChart.hpp"

using namespace std;
using namespace ariel;
using std::invalid_argument;
namespace ariel{
    

    OrgChart OrgChart::add_root(string const &node_name){
        if(this->root == nullptr){
        this->root = new Node(node_name);
        }else{
           this->root->name = node_name;
        }

        return *this;
    };
    OrgChart OrgChart::add_sub(string const &nod, string const &nod1 ){
        if(this->root == nullptr){
            throw invalid_argument("Cant add sub to empty chart");
        };
        (*find_n(nod)).sons.push_back(new Node(nod1));

        
        return *this;
    };
    Iter OrgChart::begin_level_order(){
        Iter it;
        if(this->root == nullptr){
            throw invalid_argument("Empty Tree");
        };
        if(root == nullptr){
            throw invalid_argument("Empty Tree");
        };
        list<Node*> n_ls;
        
        n_ls.push_back(root);
        bool flag = n_ls.empty();
        while (!flag)
        {
            Node* node = n_ls.front();
            it.nodes.push_back(node);
            n_ls.pop_front();
            for (auto *nodi : (*node).sons)
            {
                n_ls.push_back(nodi);
            }
            flag = n_ls.empty();
        }

        return it;


    };

    Iter OrgChart::end_level_order(){
        Iter it;
        if(this->root == nullptr){
            throw invalid_argument("Empty Tree");
        };
        if(root == nullptr){
            throw invalid_argument("Empty Tree");
        };
        list<Node*> n_ls;
        n_ls.push_back(root);
        bool flag = n_ls.empty();
        while (!flag)
        {
            Node* node = n_ls.front();
            it.nodes.push_back(node);
            n_ls.pop_front();
            for (auto *nodi : (*node).sons)
            {
                n_ls.push_back(nodi);
            }
            flag = n_ls.empty();
        }
        it.it_idx = it.nodes.size();
        return it;

    };

    

    Iter OrgChart::begin_reverse_order(){
        Iter it;
        if(this->root == nullptr){
            throw invalid_argument("Empty Tree");
        };
           if(root == nullptr){
            throw invalid_argument("Empty Tree");
        };
        list<Node*> n_ls;
        list<Node*> n_l;
        n_ls.push_back(root);
        bool flag = n_ls.empty();
        while (!flag)
        {
            Node* node = n_ls.front();
            n_l.insert(n_l.begin(),node);
            vector<Node*> rev_it = (*node).sons;
            it.nodes.push_back(node);
            std::reverse(rev_it.begin(), rev_it.end());
            n_ls.pop_front();
            for (auto *child :rev_it )
            {
                n_ls.push_back(child);
            }
            flag = n_ls.empty();
        }
        std::reverse(it.nodes.begin(),it.nodes.end());
        return it;
    };

    Iter OrgChart::reverse_order(){
        Iter it;
        if(this->root == nullptr){
            throw invalid_argument("Empty Tree");
        };
           if(root == nullptr){
            throw invalid_argument("Empty Tree");
        };
        list<Node*> n_ls;
        list<Node*> n_l;
        n_ls.push_back(root);
        bool flag = n_ls.empty();
        while (!flag)
        {
            Node* node = n_ls.front();            
            n_l.insert(n_l.begin(),node);
            vector<Node*> rev_it = (*node).sons;
            it.nodes.push_back(node);
            std::reverse(rev_it.begin(), rev_it.end());
            n_ls.pop_front();
            for (auto *child :rev_it )
            {
                n_ls.push_back(child);
            }
            flag = n_ls.empty();
        }
        std::reverse(it.nodes.begin(),it.nodes.end());
        it.it_idx = it.nodes.size();
        return it;
    };




    Iter OrgChart::begin_preorder(){
        Iter it;
        if(this->root == nullptr){
            throw invalid_argument("Empty Tree");
        };
        pre_or_f(this->root, it);
        
        return it;
    };

    Iter OrgChart::end_preorder(){
        Iter it;
        if(this->root == nullptr){
            throw invalid_argument("Empty Tree");
        };
        pre_or_f(this->root, it);
        it.it_idx = it.nodes.size();
        return it;
    };

    Iter OrgChart::begin(){
       return this->begin_level_order();
    };
    Iter OrgChart::end(){
        return this->end_level_order();
    };



    Node* OrgChart::find_n(string const &nod){
       if(this->root == nullptr){
            throw invalid_argument("Empty Tree");
        };
        list<Node*> nods;
        nods.push_back(this->root);
        bool flag = nods.empty();
        while (!flag)
        {
            Node* node = nods.front();
            if(node->name == nod){
                return node;
            }
            nods.pop_front();
            for (auto *nodi : (*node).sons)
            {
                nods.push_back(nodi);
            }
            flag = nods.empty();
        }
        
        throw invalid_argument("cant find node");
    };

 
    void OrgChart::pre_or_f(Node *node, Iter &it){
        if (node == nullptr){
            return;
        }

        it.nodes.push_back(node);

        for (Node *nod : (*node).sons){
            pre_or_f(nod, it);
        }
    }

    

   
    std::ostream &operator<<(std::ostream &output, OrgChart &n) {
        for (auto it = n.begin_level_order(); it != n.end_level_order(); ++it)
  {
    cout << (*it) << " " ;
  }
        return output;
    }


}