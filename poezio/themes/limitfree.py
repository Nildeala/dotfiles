import theming

class DarkTheme(theming.Theme):
    COLOR_INFORMATION_BAR = (39, -1)
    COLOR_STATUS_XA = (53, -1)
    COLOR_STATUS_AWAY = (214, -1)
    COLOR_STATUS_DND = (160, -1)
    COLOR_STATUS_CHAT = (34 , -1)
    COLOR_STATUS_UNAVAILABLE = (242 , -1)
    COLOR_STATUS_ONLINE = (27 , -1)
    COLOR_STATUS_NONE = (27 , -1)

    COLOR_VERTICAL_SEPARATOR = (4, -1)
    COLOR_NEW_TEXT_SEPARATOR = (35, -1)
    COLOR_MORE_INDICATOR = (6, 4)

    COLOR_HIGHLIGHT_NICK = (236, 202, 'b')

    COLOR_TAB_NORMAL = (-1, -1)
    COLOR_TAB_CURRENT = (232, 221)
    COLOR_TAB_NEW_MESSAGE = (3, -1)
    COLOR_TAB_HIGHLIGHT = (1, -1)
    COLOR_TAB_ATTENTION = (232, 3)
    COLOR_TAB_PRIVATE = (232, 2)
    COLOR_TAB_DISCONNECTED = (13, -1)

    COLOR_TOPIC_BAR = (250, -1)
    COLOR_SCROLLABLE_NUMBER = (220, 236, 'b')
    COLOR_SELECTED_ROW = (3, -1, 'b')
    COLOR_PRIVATE_NAME = (2, -1)
    COLOR_CONVERSATION_NAME = (2, -1)
    COLOR_GROUPCHAT_NAME = (2, -1)
    COLOR_COLUMN_HEADER = (36, 236)

    COLOR_VERTICAL_TAB_NORMAL = (240, -1)
    COLOR_VERTICAL_TAB_CURRENT = (-1, 236)
    COLOR_VERTICAL_TAB_NEW_MESSAGE = (3, -1)
    COLOR_VERTICAL_TAB_HIGHLIGHT = (1, -1)
    COLOR_VERTICAL_TAB_PRIVATE = (2, -1)
    COLOR_VERTICAL_TAB_ATTENTION = (6, -1)
    COLOR_VERTICAL_TAB_DISCONNECTED = (13, -1)


theme = DarkTheme()

