//
// Created by lvwei on 2023/12/18.
//

#ifndef LIBCURLTEST_CURLTEST_H
#define LIBCURLTEST_CURLTEST_H

#include <string>

class CurlTest {
public:
    explicit CurlTest();

public:
    void testCurlhttpGet();
    void handleCurlGetJsonParse(std::string& jsonData);
    void testCurlHttpPost();
    void handleCurlPostJsonParse(const std::string& json);
};


#endif //LIBCURLTEST_CURLTEST_H
