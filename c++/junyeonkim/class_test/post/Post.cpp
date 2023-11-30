#include "Post.h"

#include <utility>

//
// Created by eddi on 23. 11. 30.
//
Post::Post(std::string title, std::string content, std::string date)
        : title(std::move(title)), content(std::move(content)), date(std::move(date))
{
}

Post::~Post()
{
}

std::string Post::getTitle() const
{
    return title;
}

std::string Post::getContent() const
{
    return content;
}

std::string Post::getDate() const
{
    return date;
}
