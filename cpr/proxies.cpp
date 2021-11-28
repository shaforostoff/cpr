#include "cpr/proxies.h"

#include <initializer_list>
#include <map>
#include <string>
#include <utility>

namespace cpr {

Proxies::Proxies(const std::initializer_list<std::pair<const std::string, std::string>>& hosts) : hosts_{hosts} {}
Proxies::Proxies(const std::map<std::string, std::string, std::less<>>& hosts) : hosts_{hosts} {}

bool Proxies::has(std::string_view protocol) const {
    return hosts_.find(protocol) != hosts_.end();
}

const std::string& Proxies::operator[](const std::string& protocol) {
    return hosts_[protocol];
}

} // namespace cpr
