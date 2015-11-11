
#include "include/cyberdns.h"
#include "include/xml_parser.h"



int main() {

    CyberDNS cyberDNS;

    readComputers(cyberDNS);

    cyberDNS.GetCyberPCList();
}