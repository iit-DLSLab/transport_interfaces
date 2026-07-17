#pragma once

template <typename Source, typename Transport>
class TransportInterface {
public:
        TransportInterface(){};
        ~TransportInterface(){};

        void init();

        void consumeInputs(const Source& source){};
        void produceOutputs(const Source& source){};

        Transport transport; // Transport layer for high-level communication
};

// class DLS2HLInterface : public TransportInterface<GenericRobotInterface, DLS2Transport> {
//     public:
//         DLS2HLInterface() = default;
//         ~DLS2HLInterface() = default;

//         void init(){
//             transport.init();
//             transport.buildInput<dls2_interface::msg::RobotState>(dls::topics::low_level_estimation::robot_state);
//             transport.buildOutput<dls2_interface::msg::RobotCommands>(dls::topics::low_level_control::robot_commands);
//         }

//         void consumeInputs(const GenericRobotInterface& source) override;
//         void produceOutputs(const GenericRobotInterface& source) override;
// };



