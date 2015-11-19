#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberpc.h"


class CyberExpert
{
private:
	const std::string 	cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
	int cyber_expert_DaysUntilRest ;
    CyberExpert(); // Prevent the use of an empty constructor
	// Add your own variables here
 
public:
    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc);
	bool isWorking();
	void decreasWorkTime();
	int getEfficiancy();
	// Add your own functions here
    std::string getName(){
        return cyber_expert_name_;
    }

    int startedIsBreak() {
        return  cyber_expert_DaysUntilRest == 0;
    }

};


#endif