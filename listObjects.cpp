#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <iostream>
#include <aws/s3/model/ListObjectsV2Request.h>
#include <aws/core/auth/AWSCredentialsProviderChain.h>
using namespace Aws;
using namespace Aws::Auth;

// usage listObjects s3-url region accesskey secretkey bucket prefix

int main(int argc, char **argv) {
    Aws::SDKOptions m_options;
    Aws::InitAPI(m_options);
    Aws::Client::ClientConfiguration cfg;
    // first param is S3 compatible URL, e.g. https://namespace.compat.objectstorage.region.oraclecloud.com/ 
    cfg.endpointOverride = argv[1];
    cfg.scheme = Aws::Http::Scheme::HTTP;
    // no need to turn off ssl verification, we have the SANs in the certs
    cfg.verifySSL = true;
    // 2nd param is the region - actually, we can also have namespace and region to create the URL 
    cfg.region = argv[2];
    // 3rd param is access key, 4th param is secret key
    Aws::S3::S3Client m_client(Aws::Auth::AWSCredentials(argv[3], argv[4]), cfg,
          Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never, false);
    int result = 0;
    {
        std::cout << "LISTING OBJECTS" << std::endl;
        Aws::Client::ClientConfiguration clientConfig;
        auto objects = m_client.ListObjectsV2(Aws::S3::Model::ListObjectsV2Request().WithBucket(argv[5]).WithPrefix(argv[6]));
        if (!objects.IsSuccess()) {
            std::cerr << "Failed with error: " << objects.GetError() << std::endl;
            result = 1;
        } else {
            std::cout << "Found " << objects.GetResult().GetContents().size()
                      << " objects\n";
            for (auto &object: objects.GetResult().GetContents()) {
                std::cout << object.GetKey() << std::endl;
            }
        }
    }
    Aws::ShutdownAPI(m_options); // Should only be called once.
    return result;
}
