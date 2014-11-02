#include "signal_manager.hpp"

#include "jengine/utils/logging/easylogging++.h"

namespace game {

std::map<const std::shared_ptr<const Signaler>, std::map<Signal, std::vector<Callback>>> SignalManager::s_subscriptions;

Signaler::Signaler(const std::shared_ptr<SignalManager>& signal_receiver)
  : m_signal_receiver(signal_receiver)
{}

void Signaler::signal(Signal signal) const
{ LOG(DEBUG) << "Sending signal " << signal;
  m_signal_receiver->signal(shared_from_this(), signal);
}

void SignalManager::signal(const std::shared_ptr<const Signaler> signaler, Signal signal) const
{ LOG(DEBUG) << "Handling signal " << signal << " from signaler " << signaler;
  // Find signaler signals
  auto found_signals = s_subscriptions.find(signaler);
  if(found_signals == s_subscriptions.end())
    return;
LOG(DEBUG) << "found signals";
  // Find signal related subscriptions
  auto signaler_signals = found_signals->second;
  auto found_subscriptions = signaler_signals.find(signal);
  if(found_subscriptions == signaler_signals.end())
    return;
LOG(DEBUG) << "found subsccriptions: " << found_subscriptions->second.size();
  // Call each subscriptions
  for( auto subscription : found_subscriptions->second )
    subscription();
}

void SignalManager::connect(std::shared_ptr<const Signaler> signaler, Signal signal, Callback callback)
{ LOG(DEBUG) << "Subscribing " << signaler << " to signal " << signal << std::endl;
  s_subscriptions[signaler][signal].push_back( callback );
}

} // game
