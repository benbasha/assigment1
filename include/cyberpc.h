#ifndef CYBER_PC
#define CYBER_PC
#include <iostream>
#include <string>
#include "../include/cyberworm.h"
#include "../include/cyberdns.h"

class CyberDNS; // Forward decleration

class CyberPC
{
private:
    const std::string cyber_pc_os_;
    const std::string cyber_pc_name_;
    std::vector<std::string> cyber_pc_connections_;
    CyberWorm * cyber_worm_ = NULL;
    int cyber_pc_time_to_infect_ ;
    CyberPC(); // Prevent the use of an empty constructor
	bool justInfected;
 
public:
    CyberPC(std::string cyber_pc_os, std::string cyber_pc_name);// Only use this constructor
    const std::string getName();
	void AddConnection(std::string  second_pc);					// Add a connection to this PC
	void Infect(CyberWorm & worm); 								// Add a worm to this PC
	void Run(const CyberDNS & server); 							// Activate PC and infect others if worm is active	
	void Disinfect();
	virtual ~CyberPC();
	// called by cyber expert, disinfect PC

	//Add additional functions here if necessary
	std::string getOs(){
		return CyberPC::cyber_pc_os_;
	}
	void decreaseComputerInfectionTime(const CyberDNS & server); //decrease specific computer infected time and return if the computer is infected now+
	std::vector<std::string> getConnections() {
		return cyber_pc_connections_;
	};
	CyberWorm* getWorm() {
		return cyber_worm_;
	};

	bool isJustInfected();
	void setBoolToFalse();
};


#endif