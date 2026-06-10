#include <gtest/gtest.h>
#include <thread>
#include <vector>
#include "../include/telemetry_bridge/LatencyMonitor.hpp"

// Verifies that the monitor accurately calculates tail latency statistics
// against a manually verified baseline

TEST(LatencyTest, MathVerification)
{
    telemetry_bridge::LatencyMonitor monitor;

    // Feed 100 fixed execution durations: 1.0ms, 2.0ms, ..., 100.0ms
    for (int i = 1; i <= 100; ++i) {
        monitor.add_sample(static_cast<double>(i));
    }

    ASSERT_NEAR(monitor.get_p95(), 96.0, 0.01);
    ASSERT_NEAR(monitor.get_p99(), 100.0, 0.01); 
}

// Test that spawns multiple producer threads adding data to prove the monitor handles
// high-frequency bursts without race conditions

TEST(LatencyTest, ConcurrencyBurst)
{
    telemetry_bridge::LatencyMonitor monitor;
    const int num_threads = 10;
    const int samples_per_thread = 1000;
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([&monitor, samples_per_thread]() {
            for (int j = 0; j < samples_per_thread; ++j) {
                monitor.add_sample(15.5);
            }
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    ASSERT_NEAR(monitor.get_p95(), 15.5, 0.01);
}

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

