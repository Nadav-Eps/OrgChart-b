#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::string;
using std::vector;
using std::invalid_argument;
using std::ostream;

namespace ariel
{
    class Node{
    public :
        string name;
        vector<Node*>sons; 
        // unsigned int level;

    
        // Node(){
        //     // this->level = 0;
        // };
        Node(string n){
            this->name = std::move(n);
            // this->level = 0;
            
        };
        // string &get_name(){
        //     return this->name;
        // };
        // unsigned int get_level() const {return this->level;};
        // void set_name(string n){
        //     this->name = std::move(n);
        // };
        // void add_child(Node* n){
        //     n->level = this->level + 1;
        //     this->sons.push_back(n);
            
        // };
        // void copy_child( vector<Node*> cpchildrens){
        //     this->sons = std::move(cpchildrens);
        // };
        // vector<Node*> get_sons() {
        //     return sons;
        // }; 
    
    };
}
#endif