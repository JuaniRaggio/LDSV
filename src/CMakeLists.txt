file(GLOB_RECURSE APPMODEL_SRC CONFIGURE_DEPENDS app/*.cpp)

add_library(app ${APPMODEL_SRC})

target_include_directories(app PUBLIC ${PROJECT_SOURCE_DIR}/include)

# executable
file(GLOB_RECURSE UI_SRC CONFIGURE_DEPENDS main.cpp ui/*.cpp)

add_executable(LDSV ${UI_SRC})

target_include_directories(LDSV PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(LDSV PRIVATE app Qt6::Widgets)
