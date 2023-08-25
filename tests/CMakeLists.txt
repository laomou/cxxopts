macro(cxxopts_add_test name)
  add_executable(test_${name} test_${name}.cc)
  target_link_libraries(test_${name} PRIVATE cxxopts)

  add_test(
    NAME test_${name}
    COMMAND ${CMAKE_COMMAND} -DTEST_EXECUTABLE=$<TARGET_FILE:test_${name}> -P
            ${CXXOPTS_SOURCE_DIR}/cmake/run_test.cmake)

  # add test to a virtual project group
  set_property(TARGET test_${name} PROPERTY FOLDER "tests")
endmacro()

cxxopts_add_test(main)