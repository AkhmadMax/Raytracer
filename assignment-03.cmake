cmake_minimum_required(VERSION 3.0)

set(MY_ADDITIONAL_SOURCES
	rt/groups/bvh.cpp
    rt/groups/kdtree.cpp
	main/statistics.h
	main/statistics.cpp
	main/a_teapot.cpp
    # Please add your source files here
)

set(ASSIGNMENT_SOURCES
    rt/groups/bvh.h
    rt/groups/kdtree.h
    rt/loaders/obj.cpp
    rt/loaders/obj.h
    ${MY_ADDITIONAL_SOURCES}
    main/a_indexing.cpp
)

file(COPY
    models/cow.obj
    models/cow.mtl
    DESTINATION ${CMAKE_BINARY_DIR}/models
)
