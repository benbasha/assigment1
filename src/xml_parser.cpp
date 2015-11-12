#include "../include/xml_parser.h"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/xml_parser.hpp"
#include "boost/foreach.hpp"

void readComputers (CyberDNS &cyberDNS){
    // Create an empty property tree object
    using boost::property_tree::ptree;
    ptree pt;

    read_xml("./computers.xml", pt);
    BOOST_FOREACH(const ptree::value_type &v, pt.get_child(""))
    {
        if (v.first == "computer") {
            //do we need it ????
            CyberPC *pc = new CyberPC(v.second.get<std::string>("os"),v.second.get<std::string>("name"));
            cyberDNS.AddPC(*pc);
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
    BOOST_FOREACH(const ptree::value_type &v, pt.get_child(""))
                {
                    if (v.first == "wire") {
                        CyberPC &pointA = cyberDNS.GetCyberPC(v.second.get<std::string>("pointA"));
                        CyberPC &pointB = cyberDNS.GetCyberPC(v.second.get<std::string>("pointB"));

                        std::cout << "Connecting " + pointA.getName() + " to " + pointB.getName() << std::endl;
                        pointA.AddConnection(pointB.getName());
                        pointB.AddConnection(pointA.getName());


                        //std::cout << pointA.getName() + "<------>" + pointB.getName() << std::endl;

                    }
                };

}

void readEvents(CyberDNS &cyberDNS){

    // Create an empty property tree object
    using boost::property_tree::ptree;
    ptree pt;

    int i = 0;

    std::vector<&CyberExpert> cyberExperts;

    read_xml("./events.xml", pt);
    BOOST_FOREACH(const ptree::value_type &v, pt.get_child(""))
    {

        std::cout << "\nDay : " << i << std::endl;

            if (v.first == "hack") {
                //new worm details
                std::string name(v.second.get<std::string>("wormName"));
                std::string os(v.second.get<std::string>("wormOs"));
                int dormant_time(v.second.get<int>("wormDormancy"));
                std::string computer(v.second.get<std::string>("computer"));
                CyberWorm *worm = new CyberWorm(os, name, dormant_time);

                //check if computer in worm favorite os and infect it
                CyberPC *computerToInfect = &cyberDNS.GetCyberPC(computer);
                if (computerToInfect->getOs() == os) {
                    computerToInfect->Infect(*worm);
                }
            }
            else if (v.first == "clock-in"){
                std::string name(v.second.get<std::string>("name"));
                int workTime(v.second.get<int>("workTime"));
                int restTime(v.second.get<int>("restTime"));
                int efficiency(v.second.get<int>("efficiency"));

                CyberExpert expert = new CyberExpert(name, workTime, restTime, efficiency);
                cyberExperts.push_back(expert);

            }
            else if (v.first == "termination") {

            }

        std::map<const std::string, CyberPC &>::const_iterator computer_it = CyberDNS::getMapIterator();
        std::vector<CyberExpert>::iterator expert_it;
        for(expert_it = expert.begin(); expert_it != expert.end(); ++expert_it) {
            if (expert_it->isWorking()) {
                for (int i = 0; i < expert_it->getEfficiency(); i++) {
                    expert_it->Clean(computer_it->second);
                    computer_it++;
                }
            }

            expert_it->decreaseWorkTime();
        }
        //one day left, decrease infects time
        cyberDNS.decreaseComputersInfectionTime();


        i++;
    }

}





