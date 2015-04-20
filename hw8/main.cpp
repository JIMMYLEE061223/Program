#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

// Coordinate class declaration
class Coordinate
{
private:
    int time;
    int resource=0;

public:
    Coordinate() { time=0; resource=0; }
    Coordinate(int x, int y) { time=x; resource=y; }
    void settime(int x) {  time = x; }
    void setresource(int y) {  resource = y; }
    int gettime() { return time; }
    int getresource() { return resource; }
    /*void inctime() {  time++; }
    void incresource() {  resource++; }
    void decX() {  time--; }
    void decresource() {  resource--; }
    void inctime(int d) {  time+=d; }
    void incresource(int d) {  resource+=d; }
    void dectime(int d) {  time-=d; }
    void decresource(int d) {  resource-=d; }*/
};

class Task
{
private:
    Coordinate ll; // specify (start time, resource)
    int duration;

public:
    Task()
    {
        ll.settime(rand()%101);
        duration=rand()%10+1;
    }
    Task(Coordinate, int);
    Task(int, int, int);
    void SetCoordinate1(int n) //set the time in ll
    {
        ll.settime(n);
    }
    void SetCoordinate(int n) //set the time in ll
    {
        ll.setresource(n);
    }
    Coordinate GetCoordinate() //get all the data from ll
    {
        return ll;
    }

    int GetTime()
    {
        return ll.gettime();
    }
    int GetResource()
    {
        return ll.getresource();
    }
    int GetDuration()
    {
        return duration;
    }

    void Move(Coordinate);
    void MoveX(int);
    void MoveY(int);
};
void examine(vector<Task>& task);
void sequence(vector<Task>& task,int& num);
int main()
{
    int num=100,time1,work=0;
    vector<Task> task;
    srand(time(NULL));
    for(int i=0;i<100;i++)  //push back 100 tasks to the vector to ensure that create the 100 random tasks
    {
        Task all_task;
        task.push_back(all_task);
        task[i].SetCoordinate(0);  //initialize all the tasks are in resources 0
    }
    sequence(task,num); //sort the earlist task to the latest task
    for(int i=1;i<task.size();i++)   //choose two task to compare(start from task 1)
    {
        int buffer=0,resource=0;
        bool check=true;
        while(check){
            for(int j=0;j<i;j++)
            {
                if(task[j].GetResource()==resource&&task[j].GetTime()+task[j].GetDuration()>task[i].GetTime())//check if overlapped
                {
                    buffer++; // just act as a judge equation
                }
            }
            if(buffer!=0)
            {
                resource++; //represent this task is not belong to the resoure now,so +1 to let it go to the next resource
                buffer=0;
            }
            else if(buffer==0)
            {
                task[i].SetCoordinate(resource); //store the correct resorce in task
                check=false;  //break the while loop, so we can check the next task
            }
        }
    }

    for(int i=0;i<task.size();i++)
    {
        cout<<"the task "<<i<<" time is "<<task[i].GetTime()<<" ,duration is "<<task[i].GetDuration()<<endl;
        cout<<"the task "<<i<<" is in the resource "<<task[i].GetCoordinate().getresource()<<endl<<endl;
    }
    examine(task);
    cout<<"Enter the time you want to see how much resources are working"<<endl;
    cin>>time1;
    for(int i=0;i<100;i++)  //calculate and store the number of resources in a vector so that if given time, how much resource we need at the time
    {
        if(time1>=task[i].GetTime()&&time1<=task[i].GetTime()+task[i].GetDuration())
        {
            work++;
        }
    }
    cout<<"We need the working resources are "<<work<<endl;

    return 0;
}
void examine(vector<Task>& task)   //check all tasks again in the vector if indeed there is no overlapping of resources at any time
{
    for(int i=0;i<100;i++)
    {
        int jump=0;
        for(int j=0;j<100;j++)
        {
            if(task[i].GetTime()<task[j].GetTime()+task[j].GetDuration()&&task[i].GetTime()>task[j].GetTime())
            {  if(task[i].GetCoordinate().getresource()==task[j].GetCoordinate().getresource())
                {cout<<"the resource is overlappng"<<endl;}
                else
                    cout<<"the resource is not overlappng"<<endl;
                jump=1;
                break;
            }
        }
        if(jump==1)
            break;
    }
}

void sequence(vector<Task>& task,int& num)
{
    int earliest_task,minindex,mintime;
    for(earliest_task=0;earliest_task<num;earliest_task++)
    {
        minindex=earliest_task;
        mintime=task[earliest_task].GetCoordinate().gettime();
        for(int index=earliest_task+1;index<num;index++)
        {
            if(task[index].GetCoordinate().gettime()<mintime)
            {
                mintime=task[index].GetCoordinate().gettime();
                minindex=index;
            }
        }
        task[minindex].SetCoordinate1(task[earliest_task].GetCoordinate().gettime());
        task[earliest_task].SetCoordinate1(mintime);
    }
}
