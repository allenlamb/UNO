cmake_minimum_required(VERSION 3.19)
project(UNO)

set(CMAKE_CXX_STANDARD 14)

add_executable(UNO main.cpp Card.cpp Card.h enums.h Deck.cpp Deck.h handQueue.cpp handQueue.h Hand.cpp Hand.h CardGraphics.cpp CardGraphics.h CIP.cpp CIP.h Node.h LinkedList.cpp LinkedList.h Stack.cpp GAME.cpp GAME.h Splash.cpp Splash.h Queue.cpp Queue.h Stack.h EndScreen.cpp EndScreen.h VICTORY.h)

target_link_libraries(UNO sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)