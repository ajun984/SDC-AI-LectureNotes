//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_POST_H
#define CLASS_TEST_POST_H

#include <string>

class Post {
private:
    std::string title;
    std::string content;
    std::string date;

public:
    Post(std::string title, std::string content, std::string date);
    ~Post();

    std::string getTitle() const;
    std::string getContent() const;
    std::string getDate() const;
};

#endif //CLASS_TEST_POST_H
