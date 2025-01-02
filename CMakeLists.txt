cmake_minimum_required(VERSION 3.12)

project(LOL_stats)

add_executable(lolstats main.c player.c match.c html.c svg.c)

target_compile_options(lolstats PRIVATE -fsanitize=address)
target_link_options(lolstats PRIVATE -fsanitize=address)