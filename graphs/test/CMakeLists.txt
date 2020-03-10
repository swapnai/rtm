
set(SRC
    main.cpp
    make_graph.cpp
    )

add_executable(unit-test ${SRC})


target_link_libraries(unit-test PRIVATE graphs gtest gtest_main)
