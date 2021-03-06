#include "../include/simulation.h"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/xml_parser.hpp"
#include "boost/foreach.hpp"
#include <vector>

void readComputers (CyberDNS &cyberDNS){
    // Create an empty property tree object
    using boost::property_tree::ptree;
    ptree pt;

    read_xml("./computers.xml", pt);
    BOOST_FOREACH(const ptree::value_type &v, pt.get_child("")) {
                    if (v.first == "computer") {
                        //do we need it ????
                        std::cout << "Adding to server: " << v.second.get<std::string>("name") << std::endl;
                        CyberPC *pc = new CyberPC(v.second.get<std::string>("os"), v.second.get<std::string>("name"));
                        cyberDNS.AddPC(*(pc));
                        //std::cout << v.second.get<std::string>("name") << std::endl;
                        //std::cout << v.second.get<std::string>("os") << std::endl;
                    }
                };
}


void readNetwork(CyberDNS &cyberDNS){
    // Create an empty property tree object
    using boost::property_tree::ptree;
    ptree pt;

    read_xml("./network.xml", pt);
    BOOST_FOREACH(const ptree::value_type &v, pt.get_child("")) {
                    if (v.first == "wire") {
                        CyberPC &pointA = cyberDNS.GetCyberPC(v.second.get<std::string>("pointA"));
                        CyberPC &pointB = cyberDNS.GetCyberPC(v.second.get<std::string>("pointB"));

                        std::cout << "Connecting " + pointA.getName() + " to " + pointB.getName() << std::endl;
                        pointA.AddConnection(pointB.getName());
                        pointB.AddConnection(pointA.getName());
                    }
                };
}

void simulate(CyberDNS &cyberDNS) {

    // Create an empty property tree object
    using boost::property_tree::ptree;
    ptree pt;

    int i = 0;
    int terminate = 0;

    //creating new vector that will hold the experts.
    std::vector<CyberExpert *> cyberExperts;

    read_xml("./events.xml", pt);
    boost::property_tree::ptree::iterator v = pt.get_child("").begin();
    while (v != pt.end() || terminate >= 0) {
        std::cout << "Day : " << i << std::endl;
        if (v != pt.end()) {
            if (v->first == "hack") {
                //new worm details
                std::string name(v->second.get<std::string>("wormName"));
                std::string os(v->second.get<std::string>("wormOs"));
                int dormant_time(v->second.get<int>("wormDormancy"));
                std::string computer(v->second.get<std::string>("computer"));
                CyberWorm *worm = new CyberWorm(os, name, dormant_time);

                //check if computer in worm favorite os and infect it
                CyberPC *computerToInfect = &cyberDNS.GetCyberPC(computer);

                std::cout << "   Hack occured on " << computerToInfect->getName() << std::endl;
                if (computerToInfect->getOs() == os) {
                    //calling to Run func in order to activate PC and infect others
                    computerToInfect->Infect(*worm);
                }
                else{
                    std::cout << "      " << "Worm " << name << " is incompatible with "<< computerToInfect->getName() <<std::endl;
                }
                //freeing worm memory
                delete worm;

            }
            else if (v->first == "clock-in") {
                const std::string name(v->second.get<std::string>("name"));
                const int workTime(v->second.get<int>("workTime"));
                const int restTime(v->second.get<int>("restTime"));
                const int efficiency(v->second.get<int>("efficiency"));

                CyberExpert *expert = new CyberExpert(name, workTime, restTime, efficiency);
                cyberExperts.push_back(expert);
            }
            else if (v->first == "termination") {
                int time(v->second.get<int>("time"));
                terminate = time - i;
            }

            v++;
        }
        std::map<const std::string, CyberPC &> map(cyberDNS.getMap());
        std::map<const std::string, CyberPC &>::reverse_iterator computer_it = map.rbegin();
        std::vector<CyberExpert *>::iterator expert_it;
        for (expert_it = cyberExperts.begin(); expert_it != cyberExperts.end(); ++expert_it) {

            if ((*expert_it)->isWorking()) {

                for (int i = 0; computer_it != map.rend() && i < (*expert_it)->getEfficiancy(); i++) {
                    (*expert_it)->Clean(computer_it->second);
                    computer_it++;
                }

            }

            (*expert_it)->decreasWorkTime();

            if (terminate == 0)
                delete *expert_it;

        }

        //one day left, decrease infects time
        cyberDNS.decreaseComputersInfectionTime();

        i++;
        terminate--;
    }
}
//cyberDNS.completeSimulation();

void runSimulation(CyberDNS &cyberDNS) {

    readComputers(cyberDNS);
    readNetwork(cyberDNS);
    simulate(cyberDNS);

}







