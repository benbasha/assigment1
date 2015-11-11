#include "../include/cyberdns.h"

///std::map<const std::string, CyberPC &> cyber_DNS_;

CyberDNS::CyberDNS(){

}

void CyberDNS::AddPC(CyberPC & cyber_pc_) {
    //CyberDNS::cyber_DNS_[cyber_pc_.getName()] = cyber_pc_;
    CyberDNS::cyber_DNS_.insert( std::pair< const std::string , CyberPC & >( cyber_pc_.getName() , cyber_pc_ ));
}

CyberPC & CyberDNS::GetCyberPC(const std::string & cyber_pc_name) const {
    std::map<const std::string, CyberPC &>::const_iterator it = CyberDNS::cyber_DNS_.find(cyber_pc_name);

    //if (it != CyberDNS::cyber_DNS_.end())
        return it->second;

}


std::vector<std::string> CyberDNS::GetCyberPCList() {// Return list of PC's as a vector of strings.
    std::vector<std::string> pcList;

    //use itertor to go throw the map
    std::map<const std::string, CyberPC &>::const_iterator it;
    for(it = CyberDNS::cyber_DNS_.begin(); it != CyberDNS::cyber_DNS_.end(); it++) {
        pcList.push_back(it->first);
        std::cout << it->first << std::endl;

    }

    return pcList;
}
/*
public:
CyberDNS();
void AddPC(CyberPC & cyber_pc_);
CyberPC & GetCyberPC(const std::string & cyber_pc_name) const;
std::vector<std::string> GetCyberPCList(); */