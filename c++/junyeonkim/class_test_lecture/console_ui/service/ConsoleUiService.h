//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_CONSOLEUISERVICE_H
#define CLASS_TEST_CONSOLEUISERVICE_H

#include "../../account/controller/request_form/AccountRegisterRequestForm.h"
#include "../../account/controller/request_form/AccountLoginRequestForm.h"
#include "../../board/controller/request_form/BoardRegisterRequestForm.h"

class ConsoleUiService {
public:
    virtual ~ConsoleUiService() = default;

    virtual AccountRegisterRequestForm *makeAccountRegisterForm() = 0;
    virtual AccountLoginRequestForm *makeAccountLoginForm() = 0;

    virtual BoardRegisterRequestForm *makeBoardRegisterForm(int sessionId) = 0;

    virtual void storeSession(int uniqueId) = 0;
    virtual int getSignInSession() = 0;
};

#endif //CLASS_TEST_CONSOLEUISERVICE_H
