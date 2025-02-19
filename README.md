# OCI_AWS_CPP_SDK_S3_Examples

OCI Provides an S3 API Compatible endpoint for Object Storage. For customers using the AWS C++ SDK, authentication may pose a problem. This repository contains two samples of listing buckets and objects in OCI object storage using the AWS C++ SDK.

## Prerequisites:
* Linux (Ubuntu/RHEL Clone)
* CMake
* g++
* cmake
* zlib1g-dev
* libcurl4-gnutls-dev
* libssl-dev
* unzip
* libcurl4-openssl-dev 
* AWS C++ SDK from source
* AWS CLI
* OCI CLI

## To Build:
```
mkdir build
cd build
cmake ..
make
```

## To Use:
```
export AWS_ACCESS_KEY_ID="da34baaa4ab029f51c34c1cee83d40f0dEXAMPLE"
export AWS_SECRET_ACCESS_KEY="7w3uMS6kYiYkUpziSlLFcBimBsYDJfojwCWKEXAMPLE="
export OCI_REGION="<REGION>"
export S3_ENDPOINT="https://<NAMESPACE>.compat.objectstorage.<REGION>.oraclecloud.com"
export OCI_BUCKET="<BUCKET>"
export OCI_PREFIX="<PREFIX>"
```
Where Region, Namespace, Bucket, and Prefix are taken from your Buckets in the OCI Console.
AWS_ACCESS_KEY_ID and AWS_SECRET_KEY_ID are generated in your profile in the OCI Console.
```
./listBuckets $S3_ENDPOINT $OCI_REGION $AWS_ACCESS_KEY_ID $AWS_SECRET_ACCESS_KEY
```
Output:
```
LISTING BUCKETS
Found 5 buckets
Demo
OCIDocAI
External-Collaboration
Images
Cats
```
```
./listObjects $S3_ENDPOINT $OCI_REGION $AWS_ACCESS_KEY_ID $AWS_SECRET_ACCESS_KEY $OCI_BUCKET $OCI_PREFIX
```
Output:
```
LISTING OBJECTS
Found 3 objects
2024/12/18/Camera/Image1.jpeg
2024/12/18/Camera/Image2.jpeg
2024/12/18/Camera/DefinitelyNotACat.jpeg
```
