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
};
bool URLGrammar::isValidURL(const std::string &url)
{
    int pos = 0;
    return parseURL(url, pos) && pos == url.length();
}

bool URLGrammar::parseURL(const std::string &url, int &pos)
{
    return parseScheme(url, pos) && url[pos++] == ':' && url.substr(pos, 2) == "//" && (pos += 2) &&
           parseAuthority(url, pos) && parsePath(url, pos) &&
           (url[pos] == '?' ? (++pos && parseQuery(url, pos)) : true) &&
           (url[pos] == '#' ? (++pos && parseFragment(url, pos)) : true);
}

bool URLGrammar::parseScheme(const std::string &url, int &pos)
{
    int start = pos;
    while (pos < url.length() && (isalpha(url[pos]) || isdigit(url[pos]) || url[pos] == '+' || url[pos] == '-' || url[pos] == '.'))
        pos++;
    return pos > start;
}

bool URLGrammar::parseAuthority(const std::string &url, int &pos)
{
    int start = pos;
    while (pos < url.length() && url[pos] != '/')
        pos++;
    return pos > start;
}

bool URLGrammar::parsePath(const std::string &url, int &pos)
{
    int start = pos;
    while (pos < url.length() && url[pos] != '?' && url[pos] != '#')
        pos++;
    return pos > start;
}

bool URLGrammar::parseQuery(const std::string &url, int &pos)
{
    int start = pos;
    while (pos < url.length() && url[pos] != '#')
        pos++;
    return pos > start;
}

bool URLGrammar::parseFragment(const std::string &url, int &pos)
{
    return pos < url.length();
}