//
//  main.cpp
//  lab3
//
//  Created by Shashadhar Das on 17/09/21.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Process class
class Customer{
private:
    int pId;
    int nextSeriviceTime;
    int serviceTime;
    int arrivalTime;
    int priority;
    long waitTime;
    long turnaroundTime;
    int numOfContextSwitching;
    int timeOfCompletion;
    int responseTime;
    bool isFinished;
public:
    Customer(){
        pId = 0;
        nextSeriviceTime = 0;
        serviceTime = 0;
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
    
    void setNextServiceTime(int _cpuTime){
        nextSeriviceTime = _cpuTime;
    };
    void setSeriviceTime(int _burstTime){
        serviceTime = _burstTime;
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
    int getNextServiceTime() const {
        return nextSeriviceTime;
    };
    
    int getServiceTime() const{
        return serviceTime;
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
    void operator=(Customer p);
};


void Customer::operator=(Customer p){
    pId = p.getPId();
    nextSeriviceTime = p.getNextServiceTime();
    serviceTime = p.getServiceTime();
    arrivalTime = p.getArrivalTime();
    priority = p.getPriority();
    waitTime = p.getWaitTime();
    turnaroundTime = p.getTurnaroundTime();
    numOfContextSwitching = p.getNumOfContextSwitching();
    timeOfCompletion  = p.getTimeOfCompletion();
    responseTime = p.getResponseTime();
    isFinished = p.getIsFinished();
}

bool operator<(const Customer &p1, const Customer &p2){
    return p1.getNextServiceTime() < p2.getNextServiceTime();
};

void readData(int noOfProcess, vector<Customer>&processes);
void sortProcessesOnArrivalTime(vector<Customer>&processes);
void RR(int quantum,vector<Customer>processes);

// Main method
int main(int argc, const char * argv[]){
    int noOfProcess;
    cout<<"Enter the no of processes: ";
    cin>>noOfProcess;
    
    // no of process in the range of 4 - 10
    if(noOfProcess>=4 && noOfProcess<=10){
        vector<Customer>processes;
        readData(noOfProcess,processes);
        sortProcessesOnArrivalTime(processes);
        
        // check constraint arrival time of atlease one process should be 0
        if(!processes.empty() && processes[0].getArrivalTime()>0){
            cout<<endl<<"Arrival Time of at least one process should be 0."<<endl;
            return 0;
        }else{
            int quantum;
            cout<<"Enter Time Quantum: ";
            cin>>quantum;
            RR(quantum,processes);
        }
    }else{
        cout<<endl<<"The no of processes should be in the range of 4 to 10"<<endl;
        return 0;
    }
    
    return 0;
}


// Read the data from the console
void readData(int noOfProcess, vector<Customer>&processes){
    
    cout<<endl;
    string inputStr;
    for(int j=0;j<noOfProcess;j++){
        int arrivalTime,burstTime,pId;
        cout <<"Enter arrival time and burst time for process P"<<j<<": ";
        cin>>arrivalTime;
        cin>>burstTime;
        pId=j;
        Customer *process = new Customer();
        process->setPID(pId);
        process->setArrivalTime(arrivalTime);
        process->setNextServiceTime(burstTime);
        process->setSeriviceTime(burstTime);
        processes.push_back(*process);
        delete process;
    }
    
    
}

// Sort processes on arrival time
void sortProcessesOnArrivalTime(vector<Customer>&processes){
    //Bubble sort is fine as we are not dealing with a big nos
    Customer temp;
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

// RR scheduling algorithm
void RR(int quantum, vector<Customer>processes){
    int time = 0, counter = 0, runTime = 0;
    bool next = false, change = false;
    
    // current process in execution
    Customer *run = nullptr;
    
    // scheduled process list
    deque<Customer>schedule;
    
    // initial process list
    vector<Customer>clonedProcesses;
    
    // complet process list
    vector<Customer>completedProcesses;
    
    cout <<endl<< "Gnatt Chart:" << endl<<"0";
    
    // allocate the memory for the cloned processes
    for(int i = 0; i < processes.size(); ++i){
        Customer *p = new Customer();
        clonedProcesses.push_back(*p);
        delete p;
    }
    
    // clone the processes
    for(int i = 0; i < processes.size(); ++i){
        clonedProcesses[i] = processes[i];
    }
    
    // if process arrived after zero of cpu time , this should be in our case as we are checking constraint
    // of atleast one process should arrive at zero
    // but keeping it here should do no harm
    while(true){
        if(clonedProcesses[0].getArrivalTime() > time){
            ++time;
        }else{
            break;
        }
    }
    
    // run the scheduling as long as cloned process list is not empty or schedule list is not empty or counter is not
    //empty
    while(!clonedProcesses.empty() || !schedule.empty() || counter != 0){
        while(true){
            if(clonedProcesses[0].getArrivalTime() <= time && !clonedProcesses.empty()){
                schedule.push_back(clonedProcesses[0]);
                clonedProcesses.erase(clonedProcesses.begin());
            }else{
                break;
            }
        }
        
        // quantum is over , try to get a new process
        if(counter <= 0){
            if(!schedule.empty()){
                run = &schedule.front();
                schedule.pop_front();
                run->incNumOfContextSwitching();
            }else if(!clonedProcesses.empty()){
                cout<<endl<<"Cpu is in idle state, we can not continue."<<endl;
                return;
            }
            
            // our quantum is over , try to get a new process
        }else if(counter == quantum){
            
            // current process has finished execution
            if(run->getNextServiceTime() <= 0){
                run->setTimeOfCompletion(time);
                cout << " -> " << "[P"<<run->getPId() <<"]"<< " <- " << time;
                change = true;
                completedProcesses.push_back(*run);
                counter = -1;
                next = true;
                --time;
            }else{
                cout << " -> " << "[P"<<run->getPId() <<"]"<< " <- " << time;
                change = true;
                schedule.push_back(*run);
                counter = -1;
                next = true;
                --time;
            }
        }
        
        // if no switch required
        if(!next){
            // current process has finished execution
            if(run->getNextServiceTime() <= 0){
                cout << " -> " << "[P"<<run->getPId()<<"]" << " <- " << time;
                change = true;
                run->setTimeOfCompletion(time);
                completedProcesses.push_back(*run);
                counter = -1;
                --time;
            }else{
                run->setNextServiceTime(run->getNextServiceTime() - 1);
            }
        }
        
        if(next){
            next = false;
        }
        
        // increase runtime , time, counter
        ++runTime;
        ++counter;
        ++time;
        
        if(change){
            change = false;
            runTime = 0;
        }
    }
    
    // sort the processes based on arrival time
    sortProcessesOnArrivalTime(completedProcesses);
    
    cout << endl;
    double avgWaitingTime,avgTurnAroundTime;
    double sumWaitingTime=0,sumTurnAroundTime=0,totalContextSwitch=0;
    int size = (int)completedProcesses.size();
    for(int i=0;i<size;i++){
        
        Customer process= completedProcesses[i];
        // calculate waittime, turnaroundtime
        process.addTurnaroundTime(process.getTimeOfCompletion()-process.getArrivalTime());
        process.addWaitTime(process.getTimeOfCompletion()-process.getArrivalTime()-process.getServiceTime());
        
        sumWaitingTime = sumWaitingTime + process.getWaitTime();
        sumTurnAroundTime = sumTurnAroundTime + process.getTurnaroundTime();
        totalContextSwitch =totalContextSwitch + process.getNumOfContextSwitching();
        
        cout<<endl;
        cout<<"P"<<process.getPId()<<"    ";
        cout<<"AT:"<<process.getArrivalTime()<<"    ";
        cout<<"BT:"<<process.getServiceTime()<<"    ";
        cout<<"TAT:"<<process.getTurnaroundTime()<<"    ";
        cout<<"WT:"<<process.getWaitTime();
        cout<<endl;
    }
    
    
    avgWaitingTime = (double)sumWaitingTime/size;
    avgTurnAroundTime = (double)sumTurnAroundTime/size;
    
    
    cout<<endl<<endl;
    cout<<"Average waiting time:"<<avgWaitingTime<<endl<<endl;
    cout<<"Average turnaround time:"<<avgTurnAroundTime<<endl<<endl;
    cout<<"Total Context Switches:"<<totalContextSwitch-1<<endl;
    
    
    
}






