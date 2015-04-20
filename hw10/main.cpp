#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Node class declaration
class path1  //used to stored the link between two nodes in all the condition
{
private:
    int pair_1;
    int pair_2;
public:
    void setpair_1(int i){ pair_1=i ; }
    void setpair_2(int i){ pair_2=i ; }
    int getpair_1(){ return pair_1;}
    int getpair_2(){ return pair_2;}
};

class Node
{
private:
    int id;
    int level; //used in BFS
    vector<Node*> neighbor; //pointers to neighbor Node

public:
    Node():neighbor(0) { id=0; level=0;}
    Node(int i):neighbor(0) { id=i; level=0;}
    void setID(int i) {  id = i; }
    int getID() { return id; }
    void setLevel(int l) {  level = l; }
    int getLevel() { return level; }
    void AddNeighbor(Node* ptr) {  neighbor.push_back(ptr); }
    int getSize() { return neighbor.size(); }
    Node* GetNeighbor(int i) { return neighbor[i]; }
};

void FindPathLengthsFromNode(vector<Node> all_nodes, int n);

int main(){
    int n,a,b;
    srand(time(NULL));
    cout<<"Please enter the nodes number:"<<endl;
    cin>>n;
    vector<Node> all_nodes(n);   //generate n nodes
    vector<path1> path; // to store  the pair of nodes
    //Setup nodes
    for(int i=0;i<n;i++)  //set the ID to every nodes
    {
        all_nodes[i].setID(i);
        cout<<"we have node: "<<all_nodes[i].getID()<<endl;
    }
    //link these nodes
    all_nodes[0].AddNeighbor(&(all_nodes[n-1])); //the original point and the last point have to be linked respectively
    for(int i=0;i<n-1;i++)
    {
        all_nodes[i].AddNeighbor(&(all_nodes[i+1]));
        all_nodes[i+1].AddNeighbor(&(all_nodes[i]));
    }
    all_nodes[n-1].AddNeighbor(&(all_nodes[0]));//the original point and the last point have to be linked respectively
    FindPathLengthsFromNode(all_nodes,0);// search the farhest node's distance from the all_nodes[0](original point)

    //Randomly choose one pair of nodes and add links at a time
    //first:generate all the possible ligatures in the ring
    for(int i=1;i<n-2;i++) //start from node 1, link to node 3,node 4...(because the neighbor nodes have been linked),then change to nodes 2
    {
        for(int j=i+2;j<n;j++)
        {
            path1 line;
            line.setpair_1(i);  line.setpair_2(j);  //store them into a class
            path.push_back(line); //store them into a vector
        }
    }
    for(int i=2;i<n-1;i++)  //start from node 0,link to node2,3...until n-1 nodes(node 1,node n have already been linked)
    {
        path1 line;
        line.setpair_1(0);  line.setpair_2(i);
        path.push_back(line);
    }
    for(int i=0;i<100;i++)   //scatter sequence in the vector<path1> path
    {
        a=rand()%path.size();
        b=rand()%path.size();
        while(a==b)   //if choose the same element, do it again.
        {
            a=rand()%path.size();
            b=rand()%path.size();
        }
        path1 temp;
        temp=path[a];
        path[a]=path[b];
        path[b]=temp;
    }
    for(int i=0;i<path.size();i++) //take the path nodes out,and point them into the all_nodes to set the neighbor
    {
        int c,d;
        c=path[i].getpair_1();
        d=path[i].getpair_2();
        all_nodes[c].AddNeighbor(&(all_nodes[d]));
        all_nodes[d].AddNeighbor(&(all_nodes[c]));
        FindPathLengthsFromNode(all_nodes,0);//search the farhest node's distance from the all_nodes[0](original point)
    }
    return 0;
}

void FindPathLengthsFromNode(vector<Node> all_nodes, int n){
    vector<Node*> currentShell; //Nodes to be processed now
    vector<Node*> nextShell; //Store nodes to be processed next
    int distance =0;
    for(int i=0;i<all_nodes.size();i++)
    {
        cout << "The Node " << i << " is the neighbor with Node: ";
        for(int n=0;n<all_nodes[i].getSize();n++)
        {
            cout<< all_nodes[i].GetNeighbor(n)->getID() <<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<all_nodes.size();i++) //reset all the nodes have initial level=0
    {
        for(int j=0;j<all_nodes[i].getSize();j++)
        {
            all_nodes[i].GetNeighbor(j)->setLevel(0);
        }
    }
    currentShell.push_back(&(all_nodes[n])); //Starting node
    while(currentShell.size()!=0){
        nextShell.clear();
        distance++;
        for(int i=0;i<currentShell.size();i++)//each node in currentShell
        {
            for(int j=0;j<currentShell[i]->getSize();j++)//each neighbor of node
            {
                if(currentShell[i]->GetNeighbor(j)->getID()!=0&&currentShell[i]->GetNeighbor(j)->getLevel()==0)
                { //level of neighbor is not assigned
                    nextShell.push_back(currentShell[i]->GetNeighbor(j));
                    currentShell[i]->GetNeighbor(j)->setLevel(distance);
                }
            }
        }
        currentShell=nextShell;
    }
    cout<<"the farthest node is "<<distance-1<<" distance "<<endl; //because we add the distance in advence, we need to substract it
}


