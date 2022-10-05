cmake_minimum_required(VERSION 3.23)
project(example)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract( example example example.cpp )
target_include_directories( example PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( example ${CMAKE_SOURCE_DIR}/../ricardian )
