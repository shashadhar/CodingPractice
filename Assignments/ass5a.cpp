//
//  main.cpp
//  lab3
//
//  Created by Shashadhar Das on 08/09/21.
//

#include <iostream>
#include <vector>
using namespace std;

// Process class
class Process{
private:
    int pId;
    int nextCpuTime;
    int burstTime;
    int arrivalTime;
    int priority;
    long waitTime;
    long turnaroundTime;
    int numOfContextSwitching;
    int timeOfCompletion;
    int responseTime;
    bool isFinished;
public:
    Process(){
        pId = 0;
        nextCpuTime = 0;
        burstTime = 0;
        arrivalTime = 0;
        priority = 0;
        waitTime = 0;
        turnaroundTime = 0;
        numOfContextSwitching = 0;
        timeOfCompletion = 0;
        responseTime = 0;
        isFinished = false;
    };
    void setPID(int _pid){
        pId = _pid;
        };
    
    void setNextCpuTime(int _cpuTime){
        nextCpuTime = _cpuTime;
    };
    void setBurstTime(int _burstTime){
        burstTime = _burstTime;
    }
    void setArrivalTime(int _arrivalTime){
        arrivalTime = _arrivalTime;
    };
    void setPriority(int _priority){
        priority = _priority;
    };
    void addWaitTime(double time){
        waitTime += time;
    };
    void addTurnaroundTime(double time){
        turnaroundTime += time;
    };
    void incNumOfContextSwitching(){
        ++numOfContextSwitching;
    };
    void setTimeOfCompletion(int _timeOfCompletion){
        timeOfCompletion = _timeOfCompletion;
    };
    void setResponseTime(int _responseTime){
        responseTime=_responseTime;
    }
    void setIsFinished(bool _finished){
        isFinished = _finished;
    }
    int getPId() const {
        return pId;
    };
    int getNextCpuTime() const {
        return nextCpuTime;
    };
    
    int getBurstTime() const{
        return burstTime;
    }
    int getArrivalTime() const {
        return arrivalTime;
    };
    int getPriority() const {
        return priority;
    };
    long getWaitTime() const {
        return waitTime;
    };
    long getTurnaroundTime() const {
        return turnaroundTime;
    };
    int getNumOfContextSwitching() const {
        return numOfContextSwitching;
    };
    int getTimeOfCompletion() const {
        return timeOfCompletion;
    };
    int getResponseTime() const{
        return responseTime;
    }
    bool getIsFinished() const{
        return isFinished;
    }
    void operator=(Process p);
};


void Process::operator=(Process p){
    pId = p.getPId();
    nextCpuTime = p.getNextCpuTime();
    burstTime = p.getBurstTime();
    arrivalTime = p.getArrivalTime();
    priority = p.getPriority();
    waitTime = p.getWaitTime();
    turnaroundTime = p.getTurnaroundTime();
    numOfContextSwitching = p.getNumOfContextSwitching();
    timeOfCompletion  = p.getTimeOfCompletion();
    responseTime = p.getResponseTime();
    isFinished = p.getIsFinished();
}

bool operator<(const Process &p1, const Process &p2){
    return p1.getNextCpuTime() < p2.getNextCpuTime();
};

void readData(vector<Process>&processes);
void sortProcessesOnArrivalTime(vector<Process>&processes);
void sortProcessesOnPid(vector<Process>&processes);
void SRTF(vector<Process>processes);

// Main method
int main(int argc, const char * argv[]){
    int noOfTestCases;
    cout<<"Enter no of test cases: ";
    cin>>noOfTestCases;
    
    for(int i=0;i<noOfTestCases;i++){
        cout<<endl;
        vector<Process>processes;
        readData(processes);
        sortProcessesOnArrivalTime(processes);
        cout <<endl<<"Shortest Remaining Time First" << endl;
        SRTF(processes);
    }
    return 0;
}


// Read the data from the console
void readData(vector<Process>&processes){
    int noOfProcess;
    cout<<"Enter the no of processes: ";
    cin>>noOfProcess;
    cout<<endl;
    string inputStr;
    for(int j=1;j<=noOfProcess;j++){
        int arrivalTime,burstTime,pId;
        cout <<"Enter arrival time and burst time of process "<<j<<":";
        cin>>arrivalTime;
        cin>>burstTime;
        pId=j;
        Process *process = new Process();
        process->setPID(pId);
        process->setArrivalTime(arrivalTime);
        process->setNextCpuTime(burstTime);
        process->setBurstTime(burstTime);
        processes.push_back(*process);
        delete process;
    }
    
}

// Sort processes on arrival time
void sortProcessesOnArrivalTime(vector<Process>&processes){
    //Since we won't be be sorting large quantities bubblesort O(n^2) will be ok.
    Process temp;
    for(int i = 0 ; i < ( processes.size() - 1 ); ++i){
        for(int j = 0 ; j < processes.size() - i - 1; ++j){
            if(processes[j].getArrivalTime() > processes[j + 1].getArrivalTime()){ //smallest to largest
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Sort processes on pid
void sortProcessesOnPid(vector<Process>&processes){
    //Since we won't be be sorting large quantities bubblesort O(n^2) will be ok.
    Process temp;
    for(int i = 0 ; i < ( processes.size() - 1 ); ++i){
        for(int j = 0 ; j < processes.size() - i - 1; ++j){
            if(processes[j].getPId() > processes[j + 1].getPId()){ //smallest to largest
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}


// Sortest remaining time
void SRTF(vector<Process>processes){
    int time = 0, runTime = 0;
    bool firstRun = true, change = false;
    vector<Process>schedule;
    Process run;
    vector<Process>copy;
    vector<Process>finished;
    cout<<endl;
    cout <<"Gnatt Chart -- (PID->CPU Burst Time)" << endl << "|";
    
    for(int i = 0; i < processes.size(); ++i){
        Process *p = new Process();
        copy.push_back(*p);
        delete p;
    }
    
    for(int i = 0; i < processes.size(); ++i){
        copy[i] = processes[i];
    }
    
    while(true){
        if(processes[0].getArrivalTime() > time){
            ++time;
        }else{
            break;
        }
    }
    
    while(finished.size() < processes.size()){
        while(true){
            
            // schedule the processes which has arrived on the time
            if(copy[0].getArrivalTime() <= time && !copy.empty()){
                schedule.push_back(copy[0]);
                sort(schedule.begin(), schedule.end());
                copy.erase(copy.begin());
            }else{
                break;
            }
        }
        if(firstRun){
            run = schedule.at(0);
            schedule.erase(schedule.begin());
            firstRun = false;
            
            // update response time if we are scheduling first time
            if(run.getNumOfContextSwitching()==0){
                run.setResponseTime(time);
            }
            run.incNumOfContextSwitching();
        }
        
        
        // check if we have any process scheduled which has lesser next cpu time
        if(!schedule.empty() && schedule.at(0).getNextCpuTime() < run.getNextCpuTime()){
            cout << " " << run.getPId() << "->" << runTime << " |";
            schedule.push_back(run);
            sort(schedule.begin(), schedule.end());
            
            run = schedule.at(0);
            change = true;
            schedule.erase(schedule.begin());;
            
            // update response time if we are scheduling first time
            if(run.getNumOfContextSwitching()==0){
                run.setResponseTime(time);
            }
            run.incNumOfContextSwitching();
            
        }else if(run.getNextCpuTime() <= 0){
            if(!run.getIsFinished()){
                run.setTimeOfCompletion(time);
                run.setIsFinished(true);
                cout << " " << run.getPId() << "->" << runTime << " |";
                finished.push_back(run);
            }
            
            if(!schedule.empty()){
                run = schedule.at(0);
                change = true;
                schedule.erase(schedule.begin());
                
                // update response time if we are scheduling first time
                if(run.getNumOfContextSwitching()==0){
                    run.setResponseTime(time);
                }
                run.incNumOfContextSwitching();
            }
        }
        
        run.setNextCpuTime(run.getNextCpuTime() - 1);
        
        ++runTime;
        ++time;
        
        if(change){
            change = false;
            runTime = 1;
        }
    }
    
    // sort the processes based on pid
    sortProcessesOnPid(finished);
    
    cout << endl;
    double avgWaitingTime,avgResponseTime,avgTurnAroundTime,avgCompletionTime;
    double sumWaitingTime=0,sumResponseTime=0,sumTurnAroundTime=0,sumCompletionTime=0;
    int size = (int)finished.size();
    for(int i=0;i<size;i++){
        
        Process process= finished[i];
        // calculate responsetime,waittime, turnaroundtime
        process.setResponseTime(process.getResponseTime()- process.getArrivalTime());
        process.addTurnaroundTime(process.getTimeOfCompletion()-process.getArrivalTime());
        process.addWaitTime(process.getTimeOfCompletion()-process.getArrivalTime()-process.getBurstTime());
        sumResponseTime = sumResponseTime + process.getResponseTime();
        sumWaitingTime = sumWaitingTime + process.getWaitTime();
        sumTurnAroundTime = sumTurnAroundTime+process.getTurnaroundTime();
        sumCompletionTime = sumCompletionTime + process.getTimeOfCompletion();
        
        cout<<endl;
        cout<<"Process P"<<process.getPId()<<"(response, waiting, turnaround and completion time):";
        cout<<process.getResponseTime()<<",";
        cout<<process.getWaitTime()<<",";
        cout<<process.getTurnaroundTime()<<",";
        cout<<process.getTimeOfCompletion();
    }
    
    avgResponseTime = (double)sumResponseTime/size;
    avgWaitingTime = (double)sumWaitingTime/size;
    avgTurnAroundTime = (double)sumTurnAroundTime/size;
    avgCompletionTime = (double)sumCompletionTime/size;
    
    cout<<endl<<endl;
    cout<<"Average response time:"<<avgResponseTime<<endl;
    cout<<"Average waiting time:"<<avgWaitingTime<<endl;
    cout<<"Average turnaround time:"<<avgTurnAroundTime<<endl;
    cout<<"Average completion time:"<<avgCompletionTime<<endl;
    
}






