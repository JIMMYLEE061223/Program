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

class Student: public Node
{
private:
    int id;

public:
    Student():Node(){ id=0;}
    //Student(int i, int ID):Node(i) { id=ID;}
    void setStudentID(int i) {  id = i; }
    int getStudentID() { return id; }
    int getYear();
    int getDepartment(){  return (id/10000)-((id/10000)/100)*100;}
};
void FindPathLengthsFromNode(vector<Student> &all_students, int search);

int main(){
    int n,a,b,department,tree=0,Student1,Student2;
    srand(time(NULL));
    cout<<"enter how many students you want to create:"<<endl;
    cin>>n;
    vector<Student> all_students(n);   //generate n nodes
    vector<path1> path; // to store  the pair of nodes
    //Setup nodes
    for(int i=0;i<n;i++)  //set the ID to every nodes
    {
        all_students[i].setID(i);
        all_students[i].setStudentID(100000000+rand()%100000000);//generate the StudentID
    }
    for(int i=0;i<n;i++)
    {
        cout<<all_students[i].getID()<<" "<<all_students[i].getStudentID()<<" "<<all_students[i].getDepartment()<<endl;
    }
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
    for(int i=0;i<all_students.size()*0.5;i++) //take the path nodes out,and point them into the all_nodes to set the neighbor
    {
        int c,d;
        c=path[i].getpair_1();
        d=path[i].getpair_2();
        all_students[c].AddNeighbor(&(all_students[d]));
        all_students[d].AddNeighbor(&(all_students[c]));
        //search the farhest node's distance from the all_nodes[0](original point)
    }
    for(int i=0;i<all_students.size();i++)  //print the Student ID and their neighbor StudentID
    {
        cout<<"the student "<<all_students[i].getStudentID()<<" has the neighbor";
        for(int j=0;j<all_students[i].getSize();j++)
        {
            cout<<static_cast<Student*>(all_students[i].GetNeighbor(j))->getStudentID()<<" ";
        }
        cout<<endl;
    }
    cout<<"which department would you like to search:"<<endl;
    cin>>department;
    for(int i=0;i<all_students.size();i++)//count trees for the department which is entered
    {
        if(all_students[i].getDepartment()==department && all_students[i].getLevel()==0)
        {
            FindPathLengthsFromNode(all_students,i);
            tree++;
        }
    }
    cout<<"we need "<<tree <<" trees to find all the same department "<<department<<" students."<<endl;

    for(int i=0;i<all_students.size();i++) //reset all the nodes have initial level=0
    {
        for(int j=0;j<all_students[i].getSize();j++)
        {
            all_students[i].GetNeighbor(j)->setLevel(0);
        }
    }
    cout<<"enter two students to find closet link:"<<endl;
    cin>>Student1>>Student2;
    FindPathLengthsFromNode(all_students,Student1);// use student1 to generate a tree
    if(all_students[Student2].getLevel()==0) //if the tree generates from student 1 doesn't include student 2,then these students don't have relationship
    {
        cout<<"there in the different tree:"<<endl;
    }
    else  //if they are in the same tree, to substract their level substract is their closet distance
    {
        cout<<"there distance is "<<all_students[Student2].getLevel()-all_students[Student1].getLevel()+1<<endl;
        //because I set the start student level=1 previously,so when the function FindPathLengthsFromNode
        //executes, the student1's level will be 1,however, it's actually level 0.That's why I have to add 1 after substract their level.
    }
    return 0;
}

void FindPathLengthsFromNode(vector<Student> &all_students, int i){
    vector<Node*> currentShell; //Nodes to be processed now
    vector<Node*> nextShell; //Store nodes to be processed next
    int distance=0;
    all_students[i].setLevel(1);
    currentShell.push_back(&(all_students[i])); //Starting node
    while(currentShell.size()!=0){
        nextShell.clear();
        distance++;
        for(int i=0;i<currentShell.size();i++)//each node in currentShell
        {
            for(int j=0;j<currentShell[i]->getSize();j++)//each neighbor of node
            {
                if(currentShell[i]->GetNeighbor(j)->getID()!=0&&currentShell[i]->GetNeighbor(j)->getLevel()==0)
                {   //level of neighbor is not assigned
                    nextShell.push_back(currentShell[i]->GetNeighbor(j));
                    currentShell[i]->GetNeighbor(j)->setLevel(distance);
                }
            }
        }
        currentShell=nextShell;
    }
}
