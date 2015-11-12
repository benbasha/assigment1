
#include "include/cyberdns.h"
#include "include/xml_parser.h"



int main() {

    CyberDNS cyberDNS;

    std::cout << "\n\nnow reading computers\n";
    readComputers(cyberDNS);

    cyberDNS.GetCyberPCList();

    std::cout << "\n\nnow reading networks\n";

    readNetwork(cyberDNS);

    std::cout << "\n\nnow reading events\n";

    //readEvents(cyberDNS);

}