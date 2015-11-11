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
                        CyberPC *tmpPC = cyberDNS.GetCyberPC(v.second.get<std::string>("pointA"));
                        cyberPC *tmpPC1 = cyberDNS.GetCyberPC(v.second.get<std::string>("pointB"));


                        //CyberPC pc(v.second.get<std::string>("pointA"),v.second.get<std::string>("pointB"));
                        //cyberDNS.AddPC(pc);
                        //std::cout << v.second.get<std::string>("name") << std::endl;
                        //std::cout << v.second.get<std::string>("os") << std::endl;
                    }
                };

}