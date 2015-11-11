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
            CyberPC pc(v.second.get<std::string>("os"),v.second.get<std::string>("name"));
            cyberDNS.AddPC(pc);
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
                        CyberPC *tmpPC = &cyberDNS.GetCyberPC(v.second.get<std::string>("pointA"));
                        CyberPC *tmpPC1 = &cyberDNS.GetCyberPC(v.second.get<std::string>("pointB"));

                        tmpPC->AddConnection(tmpPC1->getName());
                        tmpPC1->AddConnection(tmpPC->getName());

                        //CyberPC pc(v.second.get<std::string>("pointA"),v.second.get<std::string>("pointB"));
                        //cyberDNS.AddPC(pc);
                        //std::cout << v.second.get<std::string>("name") << std::endl;
                        //std::cout << v.second.get<std::string>("os") << std::endl;
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
                int dormant_time(v.second.get<std::string>("wormDormancy"));
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


        //use itertor to go throw the map and update infected PC's infection time
        std::map<const std::string, CyberPC &>::const_iterator it;
        for(it = CyberDNS::cyberDNS.begin(); it != CyberDNS::cyberDNS.end(); it++) {
            it->second.decreaseComputersInfectionTime();
            //std::cout << it->first << std::endl;
        }


    }




    }





