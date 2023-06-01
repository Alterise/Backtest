#include "strategies.hxx"

// Пусть нашей стратегией будет покупать акции в понедельник утром в 8:00,
// а продавать в пятницу вечером в 20:00 :)
double Strategy::Apply(const std::span<const Price>& prices) const {
    double profit = 0;
    bool is_bought = false;
    double bought_for;
    for (const auto& price : prices) {
        std::chrono::hh_mm_ss<std::chrono::seconds> time{
            std::chrono::seconds(std::chrono::floor<std::chrono::seconds>(price.time) - 
            std::chrono::floor<std::chrono::days>(price.time))
        };
        std::chrono::weekday weekday(std::chrono::sys_days(std::chrono::floor<std::chrono::days>(price.time)));
        if (weekday == std::chrono::Monday && time.hours() == std::chrono::hours(8)) {
            bought_for = price.open_price;
            is_bought = true;
        }

        if (is_bought && weekday == std::chrono::Friday && time.hours() == std::chrono::hours(20)) {
            profit += price.close_price - bought_for;
            is_bought = false;
        }
    }

    if(is_bought) {
        profit += prices.back().close_price - bought_for;
    }

    return profit;
}

double Strategy::Apply(const std::vector<Price>& prices) const {
    return Apply(std::span<const Price>(prices));
}