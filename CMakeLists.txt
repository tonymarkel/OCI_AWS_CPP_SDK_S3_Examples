cmake_minimum_required(VERSION 3.10)  # Or higher
project(OCI_AWS_CPP_SDK_S3_Examples)
find_package(AWSSDK REQUIRED COMPONENTS s3 core) # Find the AWS SDK. You may need to specify the installation path if CMake can't find it automatically.
add_executable(listObjects listObjectsV2.cpp) # list_objects is the name of your executable
add_executable(listBuckets listBuckets.cpp) # hello_s3 is the name of your executable
target_link_libraries(listObjects PUBLIC ${AWSSDK_LIBRARIES}) # Link the AWS SDK libraries
target_link_libraries(listBuckets PUBLIC ${AWSSDK_LIBRARIES}) # Link the AWS SDK libraries
