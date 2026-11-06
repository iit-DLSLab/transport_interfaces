#include "transports/fastdds/fastdds_transport.hpp"
#include "dls2/domains/domains.hpp"

FastDDSTransport::FastDDSTransport(const std::string& ID)
    : dls::Plugin(ID, dls::domains::signals) {}