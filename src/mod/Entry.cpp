#include "mod/Entry.h"

#include "ll/api/mod/RegisterHelper.h"

namespace my_mod {

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

bool Entry::load() {
    getSelf().getLogger().debug("Loading...");
    return true;
}

bool Entry::enable() {
    getSelf().getLogger().debug("Enabling...");
    return true;
}

bool Entry::disable() {
    getSelf().getLogger().debug("Disabling...");
    return true;
}

} // namespace my_mod

LL_REGISTER_MOD(my_mod::Entry, my_mod::Entry::getInstance());
