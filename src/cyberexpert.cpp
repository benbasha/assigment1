#include "../include/cyberexpert.h"

CyberExpert::CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_):cyber_expert_name_(cyber_expert_name_), cyber_expert_work_time_(cyber_expert_work_time_), cyber_expert_rest_time_(cyber_expert_rest_time_), cyber_expert_efficiency_(cyber_expert_efficiency_) {

    cyber_expert_DaysUntilRest = cyber_expert_work_time_;
};

void CyberExpert::Clean(CyberPC & cyber_pc){

    //cleaning the pc
    cyber_pc.Disinfect();

}

bool CyberExpert::isWorking(){

    return !(CyberExpert::cyber_expert_DaysUntilRest > 0) ;

}

void CyberExpert::decreasWorkTime(){

    CyberExpert::cyber_expert_DaysUntilRest -- ;
    if (CyberExpert::cyber_expert_DaysUntilRest == ( -1 * (CyberExpert::cyber_expert_rest_time_)) ){
        CyberExpert::cyber_expert_DaysUntilRest == CyberExpert::cyber_expert_work_time_;
    }
}

int CyberExpert::getEfficiancy(){

    return CyberExpert::cyber_expert_efficiency_;
}