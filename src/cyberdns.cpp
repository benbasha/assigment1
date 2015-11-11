#include "../include/cyberdns.h"

///std::map<const std::string, CyberPC &> cyber_DNS_;

CyberDNS::CyberDNS(){
}

void CyberDNS::AddPC(CyberPC & cyber_pc_) {
    CyberDNS::cyber_DNS_[cyber_pc_.getName()] = &cyber_pc_;
    //CyberDNS::cyber_DNS_.insert( std::pair< std::string , std::string >( cyber_pc_.getName() , &cyber_pc_ ));
}

CyberPC & CyberDNS::GetCyberPC(const std::string & cyber_pc_name) const {
    std::map<std::string, CyberPC &>::iterator it;
    it = CyberDNS::cyber_DNS_.find(cyber_pc_name);

    if (it != CyberDNS::cyber_DNS_.end())
        return it->second;

    return NULL;
}

std::vector<std::string> CyberDNS::GetCyberPCList() {// Return list of PC's as a vector of strings.

}

