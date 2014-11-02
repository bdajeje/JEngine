#ifndef JENGINE_SIGNAL_MANAGER_HPP
#define JENGINE_SIGNAL_MANAGER_HPP

#include <map>
#include <memory>
#include <vector>

#include "jengine/defines.hpp"

namespace game {

typedef uint Signal;

class SignalManager;

class Signaler : public std::enable_shared_from_this<Signaler>
{
  public:

    Signaler(const std::shared_ptr<SignalManager>& signal_receiver);

  protected:

    void signal(Signal signal) const;

  private:

    const std::shared_ptr<SignalManager> m_signal_receiver;
};

class SignalManager : public std::enable_shared_from_this<SignalManager>
{
  public:

    /* A signal is raised */
    void signal(const std::shared_ptr<const Signaler> signaler, Signal signal) const;

  protected:

    void connect(const std::shared_ptr<const Signaler> signaler, Signal signal, Callback callback);

  private:

    static std::map<const std::shared_ptr<const Signaler>, std::map<Signal, std::vector<Callback>>> s_subscriptions;
};

} // game

#endif // JENGINE_SIGNAL_MANAGER_HPP
