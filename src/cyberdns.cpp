#include "../include/cyberdns.h"

///std::map<const std::string, CyberPC &> cyber_DNS_;

CyberDNS::CyberDNS():cyber_DNS_()
{

}

void CyberDNS::AddPC(CyberPC & cyber_pc_) {
    //CyberDNS::cyber_DNS_[cyber_pc_.getName()] = cyber_pc_;
    CyberDNS::cyber_DNS_.insert( std::pair< const std::string , CyberPC & >( cyber_pc_.getName() , cyber_pc_ ));
}

CyberPC & CyberDNS::GetCyberPC(const std::string & cyber_pc_name) const {
    std::map<const std::string, CyberPC &>::const_iterator it = CyberDNS::cyber_DNS_.find(cyber_pc_name);

        return it->second;
}


std::vector<std::string> CyberDNS::GetCyberPCList() {// Return list of PC's as a vector of strings.
    std::vector<std::string> pcList;

    //use itertor to go throw the map
    std::map<const std::string, CyberPC &>::reverse_iterator it;
    for(it = CyberDNS::cyber_DNS_.rbegin(); it != CyberDNS::cyber_DNS_.rend(); it++) {
        pcList.push_back(it->first);
        std::cout << it->first << std::endl;

    }

    return pcList;
}

void CyberDNS::decreaseComputersInfectionTime(){

    //use iterator to go through the map and update infected PC's infection time
    std::map<const std::string, CyberPC &>::reverse_iterator it;

    for(it = CyberDNS::cyber_DNS_.rbegin(); it != CyberDNS::cyber_DNS_.rend(); it++) {

        it->second.decreaseComputerInfectionTime(*this);
    }


}

//going through pc neighbors and infecting them if needed.
void CyberDNS::infectNetwork(std::string pcName) const{

    std::map<const std::string, CyberPC &>::const_iterator dns_it;
    dns_it = CyberDNS::cyber_DNS_.find(pcName);
    CyberPC cyberPC = dns_it->second;

    std::vector<std::string> connections(cyberPC.getConnections());
    std::vector<std::string>::iterator connections_it;

    std::cout <<"   "<< pcName << " infecting..." <<std::endl;
    for(connections_it = connections.begin(); connections_it != connections.end(); ++connections_it) {
        dns_it = CyberDNS::cyber_DNS_.find(*(connections_it));
        if (dns_it->second.getOs() == cyberPC.getOs()) {
            dns_it->second.Infect(*(cyberPC.getWorm()));
        }
        else if(dns_it->second.getOs() != cyberPC.getOs()){
            std::cout << "      "<< "Worm" << cyberPC.getWorm()->getName() << " is incompatible with " << dns_it->second.getName() << std::endl;

        }

        //std::cout << dns_it->second.getName() << "  " << dns_it->second.isJustInfected() << std::endl;

    }
}

std::map<const std::string, CyberPC &> CyberDNS::getMap() {
    return CyberDNS::cyber_DNS_;
};


void CyberDNS::completeSimulation() {

    std::map<const std::string, CyberPC &>::reverse_iterator it;
    for(it = CyberDNS::cyber_DNS_.rbegin(); it != CyberDNS::cyber_DNS_.rend(); it++) {
        (it->second).deleteWorm();
        delete &(it->second);
    }
}

/*
public:
CyberDNS();
void AddPC(CyberPC & cyber_pc_);
CyberPC & GetCyberPC(const std::string & cyber_pc_name) const;
std::vector<std::string> GetCyberPCList(); */