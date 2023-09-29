//come back to this later

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>

struct IdVolume {
    int64_t id;
    int64_t volume;
};

struct PriceVolume {
    int64_t id;
    double price;
    int64_t volume;
};

class TestSolution {
private:
    std::unordered_map<std::string, std::vector<IdVolume>> buyOrders;
    std::unordered_map<std::string, std::vector<PriceVolume>> sellOrders;
    std::unordered_map<std::string, int64_t> orderCount;
    std::unordered_map<int64_t, std::string> sellOrderTimestamps;  // Added for timestamps

public:
    TestSolution(const std::vector<std::string>& data);

    std::unordered_map<std::string, int64_t> OrderCounts(){
        return orderCount;
    }
    std::vector<IdVolume> BiggestBuyOrders(const std::string& symbol);
    PriceVolume BestSellAtTime(const std::string& symbol, const std::string& timestamp);
};

TestSolution::TestSolution(const std::vector<std::string>& data) {
    for (const auto& line : data) {
        size_t prev = 0, next = 0;
        next = line.find(';');
        std::string timestamp = line.substr(prev, next - prev);
        prev = next + 1;
        next = line.find(';', prev);
        std::string symbol = line.substr(prev, next - prev);
        prev = next + 1;
        next = line.find(';', prev);
        int64_t id = std::stoll(line.substr(prev, next - prev));
        prev = next + 1;
        next = line.find(';', prev);
        std::string operation = line.substr(prev, next - prev);
        prev = next + 1;
        next = line.find(';', prev);
        std::string side = line.substr(prev, next - prev);
        prev = next + 1;
        next = line.find(';', prev);
        int64_t volume = std::stoll(line.substr(prev, next - prev));
        prev = next + 1;
        double price = std::stod(line.substr(prev));

        if (operation.empty() || operation == "I") {
            orderCount[symbol]++;
            if (side == "BUY") {
                buyOrders[symbol].push_back({ id, volume });
            }
            else if (side == "SELL") {
                sellOrders[symbol].push_back({id, price, volume });
                sellOrderTimestamps[id] = timestamp;  // Keep track of timestamp
            }
        }
        else if (operation == "C") {
            if (side == "BUY") {
                auto& vec = buyOrders[symbol];
                vec.erase(std::remove_if(vec.begin(), vec.end(),
                    [&id](const IdVolume& iv) { return iv.id == id; }),
                    vec.end());
            }
            else if (side == "SELL") {
                auto& vec = sellOrders[symbol];
                vec.erase(std::remove_if(vec.begin(), vec.end(),
                    [&id](const PriceVolume& pv) { return pv.id == id; }), 
                    vec.end());
                sellOrderTimestamps.erase(id);
            }
        }
        else if (operation == "A") {
            if (side == "BUY") {
                buyOrders[symbol].push_back({ id, volume });
            }
            else if (side == "SELL") {
                sellOrders[symbol].push_back({id, price, volume });
                sellOrderTimestamps[id] = timestamp;
            }
        }
    }
}

std::vector<IdVolume> TestSolution::BiggestBuyOrders(const std::string& symbol) {
    auto& vec = buyOrders[symbol];
    std::sort(vec.begin(), vec.end(), [](const IdVolume& a, const IdVolume& b) {
        if (a.volume == b.volume) return a.id < b.id;
        return a.volume > b.volume;
    });

    std::vector<IdVolume> result(vec.begin(), vec.begin() + std::min(size_t(3), vec.size()));
    return result;
}

PriceVolume TestSolution::BestSellAtTime(const std::string& symbol, const std::string& timestamp) {
    auto& vec = sellOrders[symbol];
    if (vec.empty()) return {0, 0.0, 0 };

    PriceVolume bestSell = {0, std::numeric_limits<double>::max(), 0 }; // Initialized price to max
    for (const auto& pv : vec) {
        const std::string& orderTimestamp = sellOrderTimestamps[pv.id];
        if (orderTimestamp <= timestamp && pv.price < bestSell.price) {
            bestSell = pv;
        }
    }
    return bestSell;
}

int main()
{
    std::vector<std::string> data;
    std::string line;
    while (std::getline(std::cin, line)) {
        data.emplace_back(line);
    }
    
    TestSolution solution{data};
    std::cout << "Order counts:\n";
    for (const auto& [symbol, count] : solution.OrderCounts()) {
        std::cout << symbol << " " << count << "\n";
    }
    
    std::cout << "\nBiggest buys:\n";
    for (const IdVolume& idVolume : solution.BiggestBuyOrders("DVAM1")) {
        std::cout << idVolume.id << " " << idVolume.volume << "\n";
    }
    
    std::cout << "\nBest sell:\n";
    PriceVolume priceVolume = solution.BestSellAtTime("DVAM1", "15:30:00");
    std::cout << priceVolume.price << " " << priceVolume.volume << "\n";
    
    return 0;
}
