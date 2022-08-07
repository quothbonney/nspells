cmake_minimum_required(VERSION 2.8)
project(bin/spells)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CURSES_NEED_NCURSES "TRUE")
set(CURSES_NEED_WIDE "TRUE")

if (!Curses_FOUND)
    add_definitions("-DNOCURSES")
endif()

# Add ncurses wide for unicode support
add_compile_options("-lncursesw -lstdc++fs")
link_libraries("-lncursesw -lstdc++fs")

add_executable(bin/spells
        src/main.cpp
        src/Element.cpp
        src/GameWindow.cpp
        src/Rectangle.cpp
        include/Element.h
        include/GameWindow.h
        include/Rectangle.h
        )
target_link_libraries(bin/spells ${CURSES_LIBRARIES})