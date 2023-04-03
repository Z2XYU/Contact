cmake_minimum_required(VERSION 3.0.0)
project(contact VERSION 0.1.0)

aux_source_directory("." SRC_LIST)
add_executable(contact ${SRC_LIST})


