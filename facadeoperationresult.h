#ifndef FACADEOPERATIONRESULT_H
#define FACADEOPERATIONRESULT_H
#include <iostream>

class FacadeOperationResult
{
private:
    std::string error_message;
    bool error;
public:
    FacadeOperationResult();
    std::string getErrorMessage();
    void set_error(std::string err_msg);
    bool isSuccess();
};

#endif // FACADEOPERATIONRESULT_H
