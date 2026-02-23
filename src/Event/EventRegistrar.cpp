#include "Event/EventRegistrar.h"

#include "mod/Global.h"

#include "ll/api/event/EventBus.h"
#include "ll/api/event/player/PlayerJoinEvent.h"

namespace my_mod {

EventRegistrar& EventRegistrar::getInstance() {
    static EventRegistrar instance;
    return instance;
}

bool EventRegistrar::registerAll() {
    if (mPlayerJoinListener) {
        return true;
    }

    auto& bus = ll::event::EventBus::getInstance();
    mPlayerJoinListener =
        bus.emplaceListener<ll::event::PlayerJoinEvent>([](ll::event::PlayerJoinEvent& event) {
            auto& player = event.self();
            if (config.exampleJoinMessageEnable) {
                player.sendMessage(tr("example.player_join_welcome", player.getRealName()));
            }
            if (config.exampleJoinLogEnable) {
                logger.info(tr("example.player_join_log", player.getRealName()));
            }
        });

    if (!mPlayerJoinListener) {
        logger.error(tr("event.register_failed", "PlayerJoinEvent"));
        return false;
    }

    logger.info(tr("event.registered", "PlayerJoinEvent"));
    return true;
}

void EventRegistrar::unregisterAll() {
    if (!mPlayerJoinListener) {
        return;
    }

    ll::event::EventBus::getInstance().removeListener<ll::event::PlayerJoinEvent>(mPlayerJoinListener);
    mPlayerJoinListener.reset();
    logger.info(tr("event.unregistered", "PlayerJoinEvent"));
}

} // namespace my_mod
