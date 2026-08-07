#include "transports/fastdds/fastdds_transport.hpp"
#include "dls2/domains/domains.hpp"

FastDDSTransport::FastDDSTransport()
    : dls::Plugin("FastDDSTransport", dls::domains::signals) {}