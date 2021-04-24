#ifndef EXCEPTIONLOADFILE_H
#define EXCEPTIONLOADFILE_H
#include <iostream>


class ExceptionLoadFile : public std::exception
{
private:
    std::string error_message;

public:
    ExceptionLoadFile(std::string err_msg);
    std::string getError();
};

#endif // EXCEPTIONLOADFILE_H
