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
    std::map<const std::string, CyberPC &>::reverse_iterator it;
    for(it = CyberDNS::cyber_DNS_.rbegin(); it != CyberDNS::cyber_DNS_.rend(); it++) {
        pcList.push_back(it->first);
        std::cout << it->first << std::endl;

    }

    return pcList;
}

void CyberDNS::decreaseComputersInfectionTime(){
    //use itertor to go throw the map and update infected PC's infection time
    std::map<const std::string, CyberPC &>::reverse_iterator it;

    //std::cout << "printing the order which we check the PC's" << std::endl;
    //std::cout << "" << std::endl;

    for(it = CyberDNS::cyber_DNS_.rbegin(); it != CyberDNS::cyber_DNS_.rend(); it++) {

        //printing the order which we check the PC's

      //  std::cout << it->second.getName() << std::endl;


        it->second.decreaseComputerInfectionTime(*this);



       /*f (it->second.decreaseComputerInfectionTimeAndReturnIfGotInfectedNow()){
            //Time to infect network!
            //infectNetwork(it->second); //pass cyberPC   ---before my change
            it->second.Run(*this);
        }*/
    }


}

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
            //std::cout <<"       " << dns_it->second.getName() << " infected by " << cyberPC.getWorm()->getName() << std::endl;

        }
        else{
            std::cout << "      Worm Netbuster is incompatible with " << dns_it->second.getName() << std::endl;

        }
    }
}

std::map<const std::string, CyberPC &>::const_iterator CyberDNS::getMapIterator() {
    return CyberDNS::cyber_DNS_.begin();
};

/*
public:
CyberDNS();
void AddPC(CyberPC & cyber_pc_);
CyberPC & GetCyberPC(const std::string & cyber_pc_name) const;
std::vector<std::string> GetCyberPCList(); */