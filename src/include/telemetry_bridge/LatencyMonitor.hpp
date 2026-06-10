#ifndef TELEMETRY_BRIDGE__LATENCY_MONITOR_HPP_
#define TELEMETRY_BRIDGE__LATENCY_MONITOR_HPP_

#include <vector>
#include <mutex>
#include <algorithm>
#include <chrono>

namespace telemetry_bridge {

class LatencyMonitor {
public:

    void add_sample(double duration_ms)
    {
        std::lock_guard<std::mutex> lock(mutex_); 
        samples_.push_back(duration_ms);
    }

    double get_p95()
    {
        return calculate_percentile(0.95); 
    }

    double get_p99()
    {
        return calculate_percentile(0.99); 
    }

private:
    std::vector<double> samples_;
    mutable std::mutex mutex_; // Protects samples_ from concurrent access [9]

    double calculate_percentile(double percentile)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (samples_.empty()) return 0.0;

        // Sort a copy or the original to find the percentile index [10]
        std::vector<double> sorted_samples = samples_;
        std::sort(sorted_samples.begin(), sorted_samples.end());

        size_t index = static_cast<size_t>(percentile * sorted_samples.size());
        // Bounds check to avoid overflow [11]
        index = std::min(index, sorted_samples.size() - 1);
        
        return sorted_samples[index];
    }
};

} // namespace telemetry_bridge

#endif
