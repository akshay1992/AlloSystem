
find_package(LibSndFile QUIET)

if(SNDFILE_LIBRARIES)
message("Building libsndfile module.")

#list(APPEND ALLOCORE_SRC
#  src/graphics/al_Image.cpp)

# There are no allocore sources that use libsndfile!

list(APPEND ALLOCORE_DEP_INCLUDE_DIRS
  ${SNDFILE_INCLUDE_DIRS})

list(APPEND ALLOCORE_LINK_LIBRARIES
  ${SNDFILE_LIBRARIES})

else()
message("NOT Building libsndfile module.")
endif(SNDFILE_LIBRARIES)
