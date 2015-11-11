#include "../include/xml_parser.h"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/xml_parser.hpp"
#include "boost/foreach.hpp"

void read (CyberDNS &cyberDNS){
    // Create an empty property tree object
    using boost::property_tree::ptree;
    ptree pt;

    read_xml("./computers.xml", pt);
    BOOST_FOREACH(const ptree::value_type &v, pt.get_child(""))
    {
        if (v.first == "computer") {
            CyberPC pc(v.second.get<std::string>("name"), v.second.get<std::string>("os"));
            cyberDNS.AddPC(pc);
            //std::cout << v.second.get<std::string>("name") << std::endl;
            //std::cout << v.second.get<std::string>("os") << std::endl;
        }
    };
};
