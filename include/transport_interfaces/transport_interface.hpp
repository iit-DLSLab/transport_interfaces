#pragma once

template <typename Source, typename Transport>
class TransportInterface {
public:
        TransportInterface(){};
        ~TransportInterface(){};

        void init();

        void read(Source& source){};
        void write(const Source& source){};

        Transport transport; // Transport layer for high-level communication
};