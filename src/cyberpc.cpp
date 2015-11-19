#include "../include/cyberpc.h"



CyberPC::CyberPC(std::string cyber_pc_os, std::string cyber_pc_name): cyber_pc_os_(cyber_pc_os), cyber_pc_name_(cyber_pc_name) ,
                                                                      cyber_pc_connections_(
                                                                              std::vector<std::string>(0)),
                                                                      cyber_pc_time_to_infect_(0)
{
    std::cout << getName() + " connected to server" << std::endl;
}

const std::string CyberPC::getName() {
    return cyber_pc_name_;
}


void CyberPC::AddConnection(std::string second_pc) {
    cyber_pc_connections_.push_back(second_pc);
    std::cout << "  " + getName() + " now connected to " + second_pc << std::endl;
}

void CyberPC::Infect(CyberWorm & worm) {

    if (cyber_worm_ != NULL)
        delete cyber_worm_;

    cyber_worm_ = new CyberWorm(worm);
    cyber_pc_time_to_infect_ = worm.getWormDormancyTime();

    // std::cout << "  Hack occured on " + getName() << std::endl;
    std::cout << "      " + getName() + " infected by " + worm.getName() << std::endl;
}

void CyberPC::Run(const CyberDNS & server) {        // Activate PC and infect others if worm is active
    server.infectNetwork(cyber_pc_name_);
}

void CyberPC::Disinfect() {

    if (cyber_worm_ != NULL) {
        std::cout << "      Worm " + cyber_worm_->getName() + " successfully removed from " + getName() << std::endl;
    }

    if (cyber_worm_ != NULL)
        delete cyber_worm_;

    //cleaning the worm
    cyber_worm_ = NULL ;
    cyber_pc_time_to_infect_ = 0;

}

void CyberPC::decreaseComputerInfectionTime(const CyberDNS & server){

    if (CyberPC::cyber_pc_time_to_infect_ > 0) {
        CyberPC::cyber_pc_time_to_infect_--;

        if (CyberPC::cyber_worm_ != NULL) {
            std::cout <<"   "<< CyberPC::cyber_pc_name_ <<": Worm "<< CyberPC::cyber_worm_->getName() << " is dormant" << std::endl;
        }
    }
    else if (CyberPC::cyber_pc_time_to_infect_ == 0 && CyberPC::cyber_worm_ != NULL){
        //COMPUTER INFECTED! NOW INFECT NETWORK!!
        Run(server);
    }
}

std::string CyberPC::getOs(){
    return CyberPC::cyber_pc_os_;
}
std::vector<std::string> CyberPC::getConnections() {
    return cyber_pc_connections_;
};
CyberWorm* CyberPC::getWorm() {
    return cyber_worm_;
};
void CyberPC::deleteWorm() {
    if (cyber_worm_ != NULL)
        delete cyber_worm_;
}

CyberPC::~CyberPC() {

    if(cyber_worm_ != NULL)
        delete cyber_worm_;
    std::cout << "cyberPC disractur" << std::endl;

}
