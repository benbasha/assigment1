#include "../include/cyberworm.h"

CyberWorm::CyberWorm(std::string cyber_worm_os , std::string cyber_worm_name, std::string cyber_worm_dormancy_time):cyber_worm_os_(cyber_worm_os), cyber_worm_name_(cyber_worm_name),
                                                                                                                    cyber_worm_dormancy_time_(cyber_worm_dormancy_time){

}


//copy construvtor
CyberWorm::CyberWorm(const CyberWorm & other) {

    other.cyber_worm_name_ = this->cyber_worm_name_;
    other.cyber_worm_os_ = this->cyber_worm_os_;
    other.cyber_worm_dormancy_time_ = this->cyber_worm_dormancy_time_;

}

CyberWorm::~CyberWorm(){

    if (infectedComputers == 0 )
        delete this;
}

const int CyberWorm::getWormDormancyTime(){

    return cyber_worm_dormancy_time;
}


