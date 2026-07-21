#pragma once

template <typename Source, typename Transport>
class TransportInterface {
public:
        TransportInterface(){};
        ~TransportInterface(){};

        virtual void init(const Source& source){};
        virtual bool check(){ return true; };

        virtual void read(Source& source){};
        virtual void write(const Source& source){};

        Transport transport; // Transport layer for high-level communication
};