#ifndef APP_STATUS_HPP
#define APP_STATUS_HPP
namespace AppStatus{
    enum class State {
        INIT,
        PLAYING,
        ENCYCLOPEDIA,
        STATISTICS,
        SETTINGS,
        UPDATE_CONTENT_LIST,
        END
    };
}
#endif