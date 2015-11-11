#include "../include/cyberdns.h"

///std::map<const std::string, CyberPC &> cyber_DNS_;

CyberDNS::CyberDNS(){
}

void CyberDNS::AddPC(CyberPC & cyber_pc_) {
    CyberDNS::cyber_DNS_[cyber_pc_.getName()] = &cyber_pc_;
}

CyberPC & CyberDNS::GetCyberPC(const std::string & cyber_pc_name) const {

}

std::vector<std::string> CyberDNS::GetCyberPCList() {// Return list of PC's as a vector of strings.

}

