#include "../include/cyberpc.h"



CyberPC::CyberPC(std::string cyber_pc_os, std::string cyber_pc_name):cyber_pc_os_(cyber_pc_os), cyber_pc_name_(cyber_pc_name){

}

const std::string CyberPC::getName() {
    return cyber_pc_name_;
}

void CyberPC::AddConnection(std::string second_pc) {
    cyber_pc_connections_.push_back(second_pc);
}

void CyberPC::Infect(CyberWorm & worm) {
    cyber_worm_ = &worm;
    cyber_pc_time_to_infect_ = worm.getWormDormancyTime();
}

void CyberPC::Run(const CyberDNS & server) {

}

void CyberPC::Disinfect() {

}

bool CyberPC::decreaseComputerInfectionTimeAndReturnIfGotInfectedNow(){

    if (CyberPC::cyber_pc_time_to_infect_ > 0){
        CyberPC::cyber_pc_time_to_infect_ -- ;
        if (CyberPC::cyber_pc_time_to_infect_ == 0){
            cyber_worm_->addInfectedComputer();
            //COMPUTER INFECTED! NOW INFECT NETWORK!!
            return true;
        }
    }

    return false;
}


 std::string CyberPC::getOs(){

    return CyberPC::cyber_pc_os_;
}

/*
private:
    const std::string cyber_pc_os_; done
    const std::string cyber_pc_name_; done
    std::vector<std::string> cyber_pc_connections_; done
    CyberWorm * cyber_worm_ = NULL; done
    int cyber_pc_time_to_infect_;
    CyberPC(); // Prevent the use of an empty constructor

public:
    CyberPC(std::string cyber_pc_os, std::string cyber_pc_name);// Only use this constructor
    const std::string getName();
	void AddConnection(std::string  second_pc);					// Add a connection to this PC
	void Infect(CyberWorm & worm); 								// Add a worm to this PC
	void Run(const CyberDNS & server); 							// Activate PC and infect others if worm is active
	void Disinfect();											// called by cyber expert, disinfect PC
	//Add additional functions here if necessary

*/