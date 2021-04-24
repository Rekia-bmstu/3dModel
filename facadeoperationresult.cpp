#include "facadeoperationresult.h"

FacadeOperationResult::FacadeOperationResult() : error_message("NO error"), error(false)
{

}

bool FacadeOperationResult::isSuccess()
{
    return error;
}

std::string FacadeOperationResult::getErrorMessage()
{
    return error_message;
}

void FacadeOperationResult::set_error(std::string err_msg)
{
    error_message = err_msg;
    error = true;
}
