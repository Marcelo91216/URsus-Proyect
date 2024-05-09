#pragma once
#include <string>

class URLGrammar
{
public:
    bool isValidURL(const std::string &url);
    bool parseURL(const std::string &url, int &pos);
    bool parseScheme(const std::string &url, int &pos);
    bool parseAuthority(const std::string &url, int &pos);
    bool parsePath(const std::string &url, int &pos);
    bool parseQuery(const std::string &url, int &pos);
    bool parseFragment(const std::string &url, int &pos);
    bool isValidCharacter(char c);
    std::string getCharacterAlphabet(char c);
};

bool URLGrammar::isValidCharacter(char c)
{
    return (c >= 0 && c <= 127) || (c >= 0x0400 && c <= 0x04FF) || (c >= 0x0600 && c <= 0x06FF);
}

std::string URLGrammar::getCharacterAlphabet(char c)
{
    if (c >= 0 && c <= 127)
        return "latin";
    else if (c >= 0x0400 && c <= 0x04FF)
        return "cyrillic";
    else if (c >= 0x0600 && c <= 0x06FF)
        return "arabic";
    else
        return "unknown";
}

bool URLGrammar::isValidURL(const std::string &url)
{
    int pos = 0;
    return parseURL(url, pos) && pos == url.length();
}

bool URLGrammar::parseURL(const std::string &url, int &pos)
{
    if (!parseScheme(url, pos) || url[pos++] != ':' || url.substr(pos, 2) != "//" || !(pos += 2))
        return false;

    if (!parseAuthority(url, pos))
        return false;

    if (!parsePath(url, pos))
        return false;

    if (url[pos] == '?')
    {
        ++pos;
        if (!parseQuery(url, pos))
            return false;
    }

    if (url[pos] == '#')
    {
        ++pos;
        if (!parseFragment(url, pos))
            return false;
    }

    return pos == url.length();
}


bool URLGrammar::parseScheme(const std::string &url, int &pos)
{
    int start = pos;
    while (pos < url.length() && (isalpha(url[pos]) || isdigit(url[pos]) || url[pos] == '+' || url[pos] == '-' || url[pos] == '.'))
    {
        if (!isValidCharacter(url[pos]))
            return false;
        pos++;
    }
    return pos > start;
}

bool URLGrammar::parseAuthority(const std::string &url, int &pos)
{
    int start = pos;
    while (pos < url.length() && url[pos] != '/')
    {
        if (!isValidCharacter(url[pos]))
            return false;
        pos++;
    }
    return pos > start;
}

bool URLGrammar::parsePath(const std::string &url, int &pos)
{
    int start = pos;
    while (pos < url.length() && url[pos] != '?' && url[pos] != '#')
    {
        if (!isValidCharacter(url[pos]))
            return false;
        pos++;
    }
    return pos > start;
}

bool URLGrammar::parseQuery(const std::string &url, int &pos)
{
    int start = pos;
    while (pos < url.length() && url[pos] != '#')
    {
        if (!isValidCharacter(url[pos]))
            return false;
        pos++;
    }
    return pos > start;
}

bool URLGrammar::parseFragment(const std::string &url, int &pos)
{
    int start = pos;
    while (pos < url.length())
    {
        if (!isValidCharacter(url[pos]))
            return false;
        pos++;
    }
    return pos > start;
}
