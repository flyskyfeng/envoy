#pragma once

#include "extensions/common/tap/tap.h"

namespace Envoy {
namespace Extensions {
namespace TransportSockets {
namespace Tap {

/**
 * Per-socket tap implementation. Abstractly handles all socket lifecycle events in order to tap
 * if the configuration matches.
 */
class PerSocketTapper {
public:
  virtual ~PerSocketTapper() = default;

  /**
   * fixfix
   */
  virtual bool closeSocket(Network::ConnectionEvent event) PURE;

  /**
   * fixfix
   */
  virtual void onRead(absl::string_view data) PURE;

  /**
   * fixfix
   */
  virtual void onWrite(absl::string_view data, bool end_stream) PURE;
};

using PerSocketTapperPtr = std::unique_ptr<PerSocketTapper>;

/**
 * Abstract socket tap configuration.
 */
class SocketTapConfig : public Extensions::Common::Tap::TapConfig {
public:
  /**
   * @return a new per-socket tapper which is used to handle tapping of a discrete socket.
   * fixfix
   */
  virtual PerSocketTapperPtr createPerSocketTapper(const Network::Connection& connection) PURE;
};

using SocketTapConfigSharedPtr = std::shared_ptr<SocketTapConfig>;

} // namespace Tap
} // namespace TransportSockets
} // namespace Extensions
} // namespace Envoy
