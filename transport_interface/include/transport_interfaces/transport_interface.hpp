#pragma once

#include "yaml-cpp/yaml.h"

#include <string>

// TODO: high level interface map msg ref to robot ref and robot state to msg state
// instead of <GenericRobotInterface, FastDDSTransport> use <RobotRef, RobotState, FastDDSTransport>
// TODO: low level interface map ll state to robot state and robot commands to ll commands
// instead of <GenericRobotInterface, FastDDSTransport> use <RobotState, RobotCommands, FastDDSTransport>
template <typename Source, typename Transport>
class TransportInterface {
public:
        TransportInterface(){};
        // Forwards transport_id to the transport (e.g. the DDS participant name of FastDDSTransport).
        explicit TransportInterface(const std::string& transport_id) : transport(transport_id) {};
        ~TransportInterface(){};

        virtual void init(Source& source, const YAML::Node& config){};
        virtual bool check(){ return true; };

        virtual void read(Source& source){};
        virtual void write(const Source& source){};
        // Publish the events detected in the source's robot interface (e.g. anomalies/safety events).
        virtual void writeEvents(const Source& source){};

        Transport transport; // Transport layer for high-level communication
};