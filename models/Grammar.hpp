#pragma once
#include <string>

class URLGrammar
{
public:
    bool isValidURL(const std::string &url);

private:
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
    // Implementación para analizar el esquema de la URL
}

bool URLGrammar::parseAuthority(const std::string &url, int &pos)
{
    // Implementación para analizar la autoridad de la URL
}

bool URLGrammar::parsePath(const std::string &url, int &pos)
{
    // Implementación para analizar la ruta de la URL
}

bool URLGrammar::parseQuery(const std::string &url, int &pos)
{
    // Implementación para analizar la consulta de la URL
}

bool URLGrammar::parseFragment(const std::string &url, int &pos)
{
    // Implementación para analizar el fragmento de la URL
}