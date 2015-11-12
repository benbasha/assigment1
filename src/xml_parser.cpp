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

                        pointA.AddConnection(pointB.getName());
                        std::cout << pointA.getName() + " now connected to " + pointB.getName() << std::endl;
                        pointB.AddConnection(pointA.getName());
                        std::cout << pointB.getName() + " now connected to " + pointA.getName() << std::endl;

                        //std::cout << pointA.getName() + "<------>" + pointB.getName() << std::endl;

                    }
                };

}

void readEvents(CyberDNS &cyberDNS){

    // Create an empty property tree object
    using boost::property_tree::ptree;
    ptree pt;

    read_xml("./events.xml", pt);
    BOOST_FOREACH(const ptree::value_type &v, pt.get_child(""))
    {

            if (v.first == "hack") {
                //new worm details
                std::string name(v.second.get<std::string>("wornName"));
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

            }
            else if (v.first == "termination") {

            }

        //one day left, decrease infects time
        cyberDNS.decreaseComputersInfectionTime();



    }




    }





