#pragma once

#include "yaml-cpp/yaml.h"

// TODO: high level interface map msg ref to robot ref and robot state to msg state
// instead of <GenericRobotInterface, FastDDSTransport> use <RobotRef, RobotState, FastDDSTransport>
// TODO: low level interface map ll state to robot state and robot commands to ll commands
// instead of <GenericRobotInterface, FastDDSTransport> use <RobotState, RobotCommands, FastDDSTransport>
template <typename Source, typename Transport>
class TransportInterface {
public:
        TransportInterface(){};
        ~TransportInterface(){};

        virtual void init(const Source& source, const YAML::Node& config){};
        virtual bool check(){ return true; };

        virtual void read(Source& source){};
        virtual void write(const Source& source){};

        Transport transport; // Transport layer for high-level communication
};