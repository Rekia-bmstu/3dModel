#include "exceptionloadfile.h"

using namespace std;

ExceptionLoadFile::ExceptionLoadFile(string err_msg) : error_message(err_msg)
{

}

string ExceptionLoadFile::getError()
{
    return error_message;
}
