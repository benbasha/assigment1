#include "../include/cyberpc.h"



CyberPC::CyberPC(std::string cyber_pc_os, std::string cyber_pc_name):cyber_pc_os_(cyber_pc_os), cyber_pc_name_(cyber_pc_name){
    justInfected = false;
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
    cyber_worm_ = &worm;
    cyber_pc_time_to_infect_ = worm.getWormDormancyTime();
    justInfected = true;
    std::cout << "Hack occured on " + getName() << std::endl;
    std::cout << "  " + getName() + " infected by " + worm.getName() << std::endl;
}

void CyberPC::Run(const CyberDNS & server) {        // Activate PC and infect others if worm is active

   server.infectNetwork(cyber_pc_name_);

    /*
    std::vector<std::string> connections(this->getConnections());
    std::map<const std::string, CyberPC &>::const_iterator dns_it;

    std::vector<std::string>::iterator connections_it;
    for(connections_it = connections.begin(); connections_it != connections.end(); ++connections_it) {

        std::map<const std::string, CyberPC &>::const_iterator dns_it = server.find(*connections_it);

        //dns_it = CyberDNS::server.find(*(connections_it));
        if (dns_it->second.getOs() == this->getOs()) {
            dns_it->second.Infect(*(this->getWorm()));
        }
    }
*/
}

void CyberPC::Disinfect() {

    //cleaning the worm
    cyber_worm_ = NULL ;
    cyber_pc_time_to_infect_ = 0;

}

bool CyberPC::decreaseComputerInfectionTimeAndReturnIfGotInfectedNow(){

    if (CyberPC::cyber_pc_time_to_infect_ > 0 && !justInfected){
        CyberPC::cyber_pc_time_to_infect_--;

        if (CyberPC::cyber_pc_time_to_infect_ == 0){
            cyber_worm_->addInfectedComputer();
            //COMPUTER INFECTED! NOW INFECT NETWORK!!
            return true;
        }
    }

    justInfected = false;

    return false;
}

