enable_testing()

if(NOT TARGET GTest::gtest)
	find_package(GTest QUIET CONFIG)
endif()

if(NOT TARGET GTest::gtest)
	include(FetchContent)

	set(GTEST_VERSION_STABLE release-1.12.1 CACHE STRING "Stable GTest version")
	set(GTEST_VERSION_LATEST v1.16.0 CACHE STRING "Latest GTest version")

	if(NOT DEFINED GTEST_REPO)
		set(GTEST_REPO "https://github.com/google/googletest.git" CACHE STRING "GTest repository")
	endif()

	if(NOT DEFINED GTEST_VERSION)
		set(GTEST_VERSION ${GTEST_VERSION_STABLE} CACHE STRING "GTest version")
	endif()

	FetchContent_Declare(
			GTest
			GIT_REPOSITORY ${GTEST_REPO}
			GIT_TAG        ${GTEST_VERSION}
			GIT_SHALLOW    TRUE
	)

	FetchContent_MakeAvailable(GTest)
endif()

add_subdirectory(main)
