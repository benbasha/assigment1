#include "../include/cyberexpert.h"

CyberExpert::CyberExpert(std::string cyber_expert_name, int cyber_expert_work_time, int cyber_expert_rest_time, int cyber_expert_efficiency):

        cyber_expert_name_(cyber_expert_name), cyber_expert_work_time_(cyber_expert_work_time), cyber_expert_rest_time_(cyber_expert_rest_time),
        cyber_expert_efficiency_(cyber_expert_efficiency),cyber_expert_DaysUntilRest(cyber_expert_work_time) {

    std::cout <<"   " + cyber_expert_name_ + " clocked in" << std::endl;


};


void CyberExpert::Clean(CyberPC & cyber_pc){

    std::cout <<"   " + cyber_expert_name_ + " examining " + cyber_pc.getName() << std::endl;

    //cleaning the pc
    cyber_pc.Disinfect();

}

bool CyberExpert::isWorking(){

    return (CyberExpert::cyber_expert_DaysUntilRest > 0) ;

}

void CyberExpert::decreasWorkTime(){

    CyberExpert::cyber_expert_DaysUntilRest -- ;
    if (cyber_expert_DaysUntilRest == 0) {
        std::cout <<"   "+ cyber_expert_name_ + " is taking a break" << std::endl;
    }

    if (CyberExpert::cyber_expert_DaysUntilRest == ( -1 * (CyberExpert::cyber_expert_rest_time_)) ){
        CyberExpert::cyber_expert_DaysUntilRest = CyberExpert::cyber_expert_work_time_;
        std::cout <<"   " + cyber_expert_name_ + " is back to work" << std::endl;
    }
}

int CyberExpert::getEfficiancy(){

    return CyberExpert::cyber_expert_efficiency_;
}


