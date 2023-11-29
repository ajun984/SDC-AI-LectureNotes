#ifndef __VECTOR_SERVICE_COMMAND_H__
#define __VECTOR_SERVICE_COMMAND_H__

// enum의 목적은 일단 #define 대용으로 사용
// VECTOR_ADD_SERVICE_EXCUTE는 자동으로 0
// VECTOR_SERVICE_END는 자동으로 1
enum vector_service_command
{
    VECTOR_ADD_SERVICE_EXECUTE,
    VECTOR_SUB_SERVICE_EXECUTE,
    VECTOR_SERVICE_END
};

#define VECTOR_SERVICE_EXECUTE_BUFFER_COUNT         (VECTOR_SERVICE_END)
#define VECTOR_SERVICE_EXECUTE_BUFFER               ((VECTOR_SERVICE_END) - 1)

#endif