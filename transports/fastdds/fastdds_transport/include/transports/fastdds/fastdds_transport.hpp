#pragma once

#include "dls2/plugin/plugin.hpp"

#include <string>

class FastDDSTransport : public dls::Plugin{

public:
    // ID is the DDS participant name. The safety layer's TopicMonitor maps it (part before "::")
    // to <ID>.yaml in DLS_SCHEDULER_PATH to get the desired frequency of the published topics.
    explicit FastDDSTransport(const std::string& ID = "FastDDSTransport");
};