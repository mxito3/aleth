#include "checkPermission.h"

string checkPermission::generateMD5(const char* password)
{
    unsigned char md[MD5_DIGEST_LENGTH];
    unsigned char* result = MD5((unsigned char*)password, strlen(password), md);
    std::stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        ss << hex << int(result[i]);
    }
    return ss.str();
}

bool checkPermission::check(string md5String)
{
    bool result = false;
    std::vector<string> source;
    string cipherFileName = "cipherText.out";
    std::ifstream file;
    file.open(cipherFileName);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            source.push_back(line);
        }
        file.close();
    }
    if (search(source,md5String))
    {
        result = true;
    }
    return result;
}


bool checkPermission::search(std::vector<std::string> source, std::string needFind)
{
    bool result = false;
    for (unsigned int i =0;i<source.size();i++)
    {
        if (source[i] == needFind)
        {
            result = true;
            break;
        }
    }
    return result;
}