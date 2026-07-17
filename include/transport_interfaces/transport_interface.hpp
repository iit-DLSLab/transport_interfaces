#pragma once

template <typename Source, typename Transport>
class TransportInterface {
public:
        TransportInterface(){};
        ~TransportInterface(){};

        void init();

        void consumeInputs(Source& source){};
        void produceOutputs(const Source& source){};

        Transport transport; // Transport layer for high-level communication
};