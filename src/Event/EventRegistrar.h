#pragma once

#include "ll/api/event/ListenerBase.h"

namespace my_mod {

class EventRegistrar {
public:
    static EventRegistrar& getInstance();

    bool registerAll();
    void unregisterAll();

private:
    ll::event::ListenerPtr mPlayerJoinListener;
};

} // namespace my_mod
